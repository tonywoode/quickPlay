#include <windows.h>
#include "Common.h"
#pragma hdrstop
#include "Zip.h" 
#include "ZipErr.h"

// ZipUp.c Copyright (C) 1990-1996 Mark Adler, Richard B. Wales, Jean-loup
//   Gailly, Kai Uwe Rommel, Onno van der Linden and Igor Mandrichenko. This
//   version modified by Chris Vleghert and Eric Engler for BCB/Delphi Zip.
//   distributed under LGPL license ** see license.txt for details RP -
//   Corrected for relative paths 10 Jul 2002 1.73 12 July 2003 RP Extra Data
#include <ctype.h>

#include <share.h>

// Use the raw functions for MSDOS to save on buffer space. (This sort of
//   stuff belongs in fileio.c, but oh well.)
// include "ZipUp.h"
// Local functions
static int suffixes( char *, char * /* , struct ZGlobals *pG */ );

// Return the percentage compression from n to m using only integer
//   operations. n :: Is the original size. m :: Is the new size.
int percent( ulg n, ulg m )
{
  if ( n > 0xFFFFFFL )
  {
    // If n >= 16M
    n += 0x80;
    n >>= 8; // then divide n and m by 256
    m += 0x80;
    m >>= 8;
  }

  return n > m ? ( int )( 1+( 200 *( n - m ) / n )) / 2: 0;
}

// Return true if a ends in any of the suffixes in the list s. a :: Name to
//   check suffix of. s :: List of suffixes separated by : or ;
static int suffixes( char *a, char *s )
{
  int m; // true if suffix matches so far
  char *p; // pointer into special
  char *q; // pointer into name a
  m = 1;
  q = a + lstrlen( a ) - 1;
  for ( p = s + lstrlen( s ) - 1; p >= s; p-- )
  {
    if ( *p == (char)':' ||  *p == (char)';' )
      if ( m )
        return 1;
      else
      {
        m = 1;
        q = a + lstrlen( a ) - 1;
      }
    else
    {
      m = m && q >= a && case_map( *p ) == case_map( *q );
      q--;
    }
  }

  return m;
}

// Note: a zip "entry" includes a local header (which includes the file
//   name), an encryption header if encrypting, the compressed data and
//   possibly an extended local header.
// Compress the file z->name into the zip entry described by *z and write it
//   to the file *y. Encrypt if requested. Return an error code in the ZEN_
//   class. Also, update tempzn by the number of bytes written. z :: Zip entry
//   to compress. y :: Output file.
int zipup( struct zlist *z, HANDLE y, struct ZGlobals *pG )
{
  ztimbuf f_utim; // UNIX GMT timestamps, filled by
  ///* filetime()
  ulg tim; // Time returned by filetime()
  ulg a = 0L; // Attributes returned by filetime()
  char *b; // Malloc'ed file buffer
//  extent
  int k = 0; // Result of zread
  int l = 0; // True if this file is a symbolic
  ///* link
  int m; // Method for this entry
  ulg o, p; // Offsets in zip file
  //  long          fsize = -3/*L*/;            // Size returned by filetime
  unsigned long fsize =  ZFT_SIZE; // Size returned by filetime
  int r; // Temporary variable
  ulg s = 0L; // Size of compressed data
  int isdir; // Set for a directory name
  int set_type = 0; // Set if file type (ascii/binary)
  ///* unknown
  unsigned char *tempextra; // to hold pointer returned by user
  long hi;
  unsigned long tunslong;     
#ifdef CRYPT
  ulg f_crc;// = 0;
  __int64 fsz;// = 0;
  bool haveCRC;// = false;
#endif

  z->nam = lstrlen( z->zname );
  isdir = z->zname[z->nam - 1] == (char)'\\'; // SLASH
#ifdef USE_STRM_INPUT
  if ( pG->UseInStream )
  {
    // This replaces the filetime function
    a = (( ulg )( S_IFREG | S_IREAD ) << 16 ) | ( ulg )pG->StrFileAttr;
    fsize = pG->InStreamSize;
    tim = f_utim.actime = f_utim.modtime = pG->StrFileDate;
  }
  else
#endif
    if (( tim = zfiletime( z->name, &a, &fsize, &f_utim, pG )) == 0
         || (fsize == ZFT_SIZE ))
    {
      if (fsize ==  ZFT_SIZE )
        Notify( PF, ZEN_SIZE03 | IWARNING, "%s is too big ",
                GetFullPath( pG, z->name ));
      return ZEN_OPEN02;
    }

  // fsize is set to -1 if the input file is a device, -2 for a volume label
  if ( fsize == ZFT_LABEL )
  {
    isdir = 1;
    fsize = 0;
  }
  else
    if ( isdir != (( a &MSDOS_DIR_ATTR ) != 0 ))
    {
      // don't overwrite a directory with a file and vice-versa
      return ZEN_MISS01;
    }

  z->att = ( ush )UNKNOWN; // will be changed later
  z->atx = 0; // may be changed by set_extra_field()

  // Free the old extra fields which are probably obsolete
  pG->key = z->passw; // 1.73 restore global password
  pG->window_size = 0L;

  // Select method based on the suffix and the global method
//  m = pG->method;
//  if ( m == BEST )
    m = DEFLATE;  // default method
  pG->level = z->options.level;
  if (!pG->level
       || (!z->options.noext     // check per file override
       && pG->special && suffixes( z->name, pG->special)))
    m = STORE;
                     
  _CB_.MsgP2 = z->comment;
  _CB_.MsgP = z->zname;
  User_CB(PF, zacComment);
  if (_CB_.ActionCode == -1)  // have valid result?
  {
    // User changed the comment
    FREEANDNIL(z->comment);
    z->com = _CB_.Arg1;
    if (z->com)
    {
      if ((z->comment = (char*)MALLOC(z->com + 1)) == NULL)
        return (ziperr(ZEN_MEM37, pG));
      strncpy(z->comment, _CB_.Msg, z->com);// + 1);
      z->comment[z->com] = 0;   // mark end
    }
//    altered++;
  }
  // CHANGE 1.73 RAEL changed RPETERS Code added to generate and handle
  //   action code 14 file extra data Extra data needs to be delivered
  //   formatted according to PKZIP appnote.txt
  _CB_.Arg1 = z->ext;           // size
  _CB_.MsgP2 = z->extra;        // old data
  _CB_.Arg2 = z->options.level;
  _CB_.MsgP = GetFullPath(pG, z->name);
  if (User_CB(PF, zacData))
    return ZEN_ABORT04;
  // free any old data - probably obsolete
  if ( z->ext )
    FREE( z->extra );
  if ( z->cext && z->extra != z->cextra )
    FREE( z->cextra );
  z->ext = z->cext = 0;       
  if ((_CB_.ActionCode & 0xffffff0e) == 0xffffff0e)    // changed level
  {
      unsigned lvl = (_CB_.ActionCode & 0xf0) >> 4;
      if (lvl <= 9) {
          z->options.level = lvl;
          z->options.noext = 1;
          m = lvl ? DEFLATE : STORE;
          pG->level = lvl;
      }
  }
//  if (_CB_.ActionCode == -1)    // changed
  if ((_CB_.ActionCode & 0xffffff0f) == 0xffffff0f)    // changed data
  {
    // user changed extrafield data
    if ( _CB_.Arg1 > 512 )
      tempextra = ( unsigned char* )_CB_.MsgP2;
    // pointer to data
    else
      tempextra = ( unsigned char* )_CB_.Msg;
    if ( !tempextra )
      _CB_.Arg1 = 0;
    z->ext = _CB_.Arg1;
    // user changed extrafield data
    if ( z->ext )
    {
      if (( z->extra = ( char* )MALLOC( z->ext )) == NULL )
        // extra field in
        ///local header
      {
        Close_Handle( &pG->hInfile );
        return ZEN_MEM41;
      }

      memcpy( z->extra, tempextra, z->ext ); // copy data
      z->cext = z->ext;
      z->cextra = z->extra;
    }
  }

  if ( isdir )
  {
    // directory
    pG->hInfile = INVALID_HANDLE_VALUE;
    m = STORE;
    fsize = 0;
  }
  else
  {
    // Callback: action, error code, filesize, filename
//    User(PF, zacItem, 0, z->len /* fsize */, z->name);
    _CB_.Written.i64 = pG->BytesWritten;
    _CB_.FileSize.i64 = z->len;
    _CB_.MsgP = z->name;
    User_CB(PF, zacItem);

    if ( pG->Frame.Abort_Flag )
      return ZEN_ABORT05;
    // Here's the open of the input file if applicable
    // This time it will stay open for a little while.
    if (
#ifdef USE_STRM_INPUT
      !pG->UseInStream &&
#endif
//	  ( pG->hInfile = CreateFile( GetFullPath( pG, z->name ), GENERIC_READ,
////                                  FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE |
//	 FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE |
//								  FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
//                                  FILE_FLAG_SEQUENTIAL_SCAN, NULL )) == INVALID_HANDLE_VALUE )
	  ( pG->hInfile = OpenRead(PF, GetFullPath( pG, z->name ),
		 FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY |
		 FILE_ATTRIBUTE_SYSTEM | FILE_FLAG_SEQUENTIAL_SCAN)) == INVALID_HANDLE_VALUE )
    {
      int le = GetLastError();
      if ( le == ERROR_SHARING_VIOLATION )
		return ZEN_OPEN04;
      if ( le == ERROR_ACCESS_DENIED )
        return ZEN_OPEN05;
      return ZEN_OPEN03;
    }
  }
  z->tim = tim;

  pG->FileError = 0;

  if ( l || fsize == 0)
    m = STORE;
//  if ( m == BEST )
//    m = DEFLATE;

  // Do not create STORED files with extended local headers if the input
  //   size is not known, because such files could not be extracted. So if the
  //   zip file is not seekable and the input file is not on disk, obey the -0
  //   option by forcing deflation with stored block. Note however that using
  //   "zip -0" as filter is not very useful... ??? to be done.
  // Fill in header information and write local header to zip file. This
  //   header will later be re-written since compressed length and crc are not
  //   yet known.
  // (Assume ext, cext, com, and zname already filled in.)
  // (RCV Added (ush)( ... )
//  if ( !z->options.dosflag && !Extended( z->zname ))
  if ( !z->options.dosflag && !Extended( z->zname ) && (!z->com || !Extended(z->comment)))
    // mimic WinZip
    z->options.dosflag = 2;
  // if has no extended
  ///chars use MSDOS

  // Made under MSDOS by PKZIP 2.0, NTFS by PKZIP 2.2
  z->vem = ( ush )( z->options.dosflag ? 20 : OS_CODE + 22 );

  // For a FAT file system, we cheat and pretend that the file was not made
  //   on OS2, but under DOS. unzip is confused otherwise.
  // (RCV Added (ush)( ... )
  z->ver = ( ush )(( m == STORE ) ? 10 : 20 ); // Need PKUNZIP 2.0 to
  ///* extract, unless it is stored
  z->crc = 0; // to be updated later

  // Assume first that we will need an extended local header:
  z->flg = 8; // to be updated later
#ifdef CRYPT
  f_crc = 0;
  fsz = 0;
  haveCRC = false;
  if (pG->key && !pG->UseInStream)
  {
  // +++++ get CRC before we start
    DWORD byts;
    f_crc = crc32(0L, (uch*)NULL, 0);

    //    olen = len = read( pG->ifile, buf, size );
    while (ReadFile(pG->hInfile, pG->window, sizeof( pG->window ), &byts, NULL) &&
            byts != (DWORD)EOF)
    {
      if (!byts)
        break;
      fsz += (int)byts;
      f_crc = crc32(f_crc, (uch*)pG->window, byts);
    }
  // Check input size
    if (fsz != fsize)// && !ftranslate_eol)
    {
        Notify(PF, IWARNING, " file size changed while zipping: %s", z->name);
        if (pG->Frame.Verbose < 0)
          Notify(PF, IDIAG, " i=%Lu, fsize=%Lu ", fsz, fsize);
    }
    else
    {
      z->crc = f_crc;
      haveCRC = true;
    }
    hi = 0;
    o = SetFilePointer(pG->hInfile, 0, &hi, FILE_BEGIN );
    if ( hi || ( o == INVALID_SET_FILE_POINTER && GetLastError()))
    {
      Close_Handle( &pG->hInfile );
      ziperr( ZEN_WRITE05, pG );

      if (pG->Frame.Verbose)
        Notify(PF, IDIAG, "Could not reposition %s ", z->name);

//		pG->hInfile = CreateFile(GetFullPath(pG, z->name), GENERIC_READ,
//				 FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING,
//				 FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN |
//				 FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
//                 FILE_FLAG_SEQUENTIAL_SCAN,  NULL);
		pG->hInfile = OpenRead(PF, GetFullPath(pG, z->name), 
				 FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN |
				 FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
				 FILE_FLAG_SEQUENTIAL_SCAN);
        if (pG->hInfile == INVALID_HANDLE_VALUE)
          return  ziperr(ZEN_READ10, pG);
    }
    z->flg |= 1;
  }
  else
  // ----- get CRC before we start
  if ( pG->key )
  {
    z->flg |= 1;

    // Since we do not yet know the crc here, we pretend that the crc is the
    //   modification time:
    z->crc = z->tim << 16;
  }

#endif // CRYPT
  z->lflg = z->flg;

  // (RCV Added below (ush)
  z->how = ( ush )m; // may be changed later
//  z->siz = ( ulg )( m == STORE && fsize >= 0 ? fsize : 0 );
  z->siz = ( ulg )( m == STORE && fsize < ZFT_SIZE ? fsize : 0 );
  // will be changed later
//  z->len = ( ulg )( fsize >= 0 ? fsize : 0 ); // may be changed later
  z->len = ( ulg )( fsize < (unsigned)ZFT_SIZE ? fsize : 0 ); // may be changed later
  z->dsk = 0;
  if ( z->att == ( ush )UNKNOWN )
  {
    z->att = BINARY; // set sensible value in header
    set_type = 1;
  }

  // Attributes from filetime(), flag bits from set_extra_field():
  z->atx = z->options.dosflag ? a &0xFF : a | ( z->atx &0x0000FF00 );
  z->off = (unsigned)pG->tempzn;


  // now put it in the file
  if (( r = putlocal( z, y, pG )) != ZEN_OK )
  {
    Close_Handle( &pG->hInfile );
    return r;
  }

  pG->tempzn += 4+LOCHEAD + z->nam + z->ext;

#ifdef CRYPT
  if ( pG->key )
  {
    crypthead( pG->key, z->crc, y, pG );
    z->siz += RAND_HEAD_LEN; // to be updated later
    pG->tempzn += RAND_HEAD_LEN;
  }
#endif // CRYPT

  // for error checking, ftell can fail on pipes
  hi = 0;
  o = SetFilePointer( y, 0, &hi, FILE_CURRENT );
  if ( hi || ( o == INVALID_SET_FILE_POINTER && GetLastError()))
  {
    Close_Handle( &pG->hInfile );
    ziperr( ZEN_WRITE05, pG );
  }

  /*  if ( pG->Frame.Verbose )
  {
  Notify( PF, IDIAG,  "at position %X", o);
  }*/
  // Write stored or deflated file to zip file
  pG->isize = 0L;
  pG->crc = crc32( 0L, ( uch* )NULL, 0 );

  if ( m == DEFLATE )
  {
    bi_init( y, pG );
    if ( set_type )
      z->att = ( ush )UNKNOWN;
    // will be changed in deflate()
    ct_init( &z->att, &m, pG );
    lm_init( pG->level, &z->flg, pG );
//    lm_init( pG->level, &z->flg, pG );

    // PERFORM THE DEFLATE
    s = deflate( pG );
    if ( pG->Frame.Abort_Flag )
    {
      Close_Handle( &pG->hInfile );
      return ZEN_ABORT;
    }
  }
  else
    if ( !isdir )
    {
//      if (( b = ( char* )MALLOC( CBSZ )) == NULL )
//      {
//        Close_Handle( &pG->hInfile );
//        return ZEN_MEM18;
//      }

      if ( l )
      {     
        b = (char*) &pG->window[0];
        // symbolic link processing
        k = rdsymlnk( z->name, b, CBSZ );

        // compute crc first because zfwrite will alter the buffer b points to !!
        pG->crc = crc32( pG->crc, ( uch* )b, k );
        if ( !zfwrite( b,  /*1,*/k, y, pG ))
        {
//          FREE( b );
          Close_Handle( &pG->hInfile );
          return ZEN_TEMP05;
        }

        pG->isize = k;
      }
      else
      {
        // Trace ( ( "Storing %s ", GetFullPath ( pG, z->name )) );
        if ( pG->Frame.Verbose )
          Notify( PF, IDIAG, "Storing %s ", GetFullPath( pG, z->name ));


        tunslong = 0xFFFFFFD0;  // avoid BDS 4 bug
        if (((pG->tempzn + fsize) > tunslong) ||
          pG->compressed_len > ( 0xFFFFFFD0 - ( unsigned long )fsize ))
        {
          _CB_.Written.i64 = pG->BytesWritten;
          _CB_.FileSize.i64 = fsize;
          User_CB(PF, zacProgress);    // show done
          return ZEN_SIZE02;
        }

        //      while ( (k = file_read( b, CBSZ, pG )) > 0 && k != (extent) EOF )
        while ( ( k = file_read( pG->window, sizeof( pG->window ), pG )) > 0 && k
                != EOF )
        {
          if ( pG->Frame.Abort_Flag )
          {
//            FREE( b );
            Close_Handle( &pG->hInfile );
            return ZEN_ABORT;
          }

          //        if ( !zfwrite( b, 1, k, y, pG ) )
          if ( !zfwrite( pG->window, k, y, pG ))
          {
//            FREE( b );
            Close_Handle( &pG->hInfile );
            return ZEN_TEMP06;
          }
        }
      }

//      FREE( b );
      s = pG->isize;
    }

  //  if ( pG->ifile > 0 && k == (extent) (-1) )

  if ( pG->hInfile == INVALID_HANDLE_VALUE && k == (-1))
  {
    Notify( PF, IWARNING, "could not read input file: %s", z->zname );
  }

  Close_Handle( &pG->hInfile );                   // Close the input file
  pG->tempzn += s;
  p = (unsigned)pG->tempzn; // save for future fseek()

  // +++
#ifdef CRYPT
  if (haveCRC && f_crc != pG->crc)
  {
    Notify(PF, ZEN_READ11 | IERROR | IBAD, " File CRC changed while zipping: %s", z->name);
    return ziperr(ZEN_READ11, pG);
  }
#endif
  // ---

  // Check input size
  if ( fsize < (unsigned)ZFT_SIZE && pG->isize != ( ulg )fsize && !pG->translate_eol )
  {
    // may be file error
    if ( pG->FileError)
    {
      if ( pG->FileError == ERROR_LOCK_VIOLATION )
        Notify( PF, pG->FileError | IWARNING, " File lock violation: %s", z->name);
      else if ( pG->FileError == ERROR_ACCESS_DENIED )
        Notify( PF, pG->FileError | IWARNING, " File lock violation: %s", z->name);
      else
        Notify( PF, pG->FileError | IWARNING, " File read error [%d]: %s",
           pG->FileError, z->name);
        Notify(PF, ZEN_READ12 | IERROR | IBAD, " File error while zipping: %s", z->name);
        return ZEN_READ12;
        //return ziperr(ZEN_READ12, pG);
    }
    else
    {
      Notify( PF, IWARNING, " file size changed while zipping: %s", z->name );
      if ( pG->Frame.Verbose < 0 )
        Notify( PF, IDIAG, " i=%ld, fsize=%lu ", pG->isize, fsize );
    }
  }

  // Try to rewrite the local header with correct information
  z->crc = pG->crc;
  z->siz = s;

#ifdef CRYPT
  if ( pG->key )
    z->siz += RAND_HEAD_LEN;
#endif

  z->len = pG->isize;

  hi = 0;
  if ( SetFilePointer( y, z->off, &hi, FILE_BEGIN ) == INVALID_SET_FILE_POINTER
       && GetLastError())
  {
    pG->CanSeek = 0; // 1.75 cannot seek
    if ( z->how != ( ush )m )
      ziperr( ZEN_WRITE06, pG );
    if ( m == STORE && fsize >= (unsigned)ZFT_SIZE )
      ziperr( ZEN_PARMS14, pG );
    if (( r = putextended( z, y, pG )) != ZEN_OK )
      pG->tempzn += 16L;
    z->flg = z->lflg; // if flg modified by inflate
  }
  else
  {
    unsigned bw;
    // seek ok, ftell() should work, check compressed size
    if ( p - o != s )
    {
      Notify( PF, IWARNING, " s=%lu, actual=%lu ", s, p - o );
      ziperr( ZEN_LOGIC06, pG );
    }

    pG->CanSeek = 1; // 1.75 can seek

    // (RCV Added in two lines below (ush)( ... )
    z->how = ( ush )m;
    z->ver = ( ush )(( m == STORE ) ? 10 : 20 ); // Need PKUNZIP 2.0 to
    ///* extract, unless it is stored
//    if (( z->flg &1 ) == 0 )
//      z->flg &= ~8;
#ifdef CRYPT     
    if ((z->flg & 1) == 0 || haveCRC)
      z->flg &= ~8;
#else
    if ((z->flg & 1) == 0)
      z->flg &= ~8;
#endif
    // clear the extended local header flag
    z->lflg = z->flg;
    bw = pG->BytesWritten;
    // rewrite the local header:
    if (( r = putlocal( z, y, pG )) != ZEN_OK )
      return r;
    pG->BytesWritten = bw;
    /*long*/
    hi = 0;
    if ( SetFilePointer( y, p, &hi, FILE_BEGIN ) == INVALID_SET_FILE_POINTER &&
         GetLastError())
      return ZEN_READ03;
    if (( z->flg &1 ) != 0 && !haveCRC)
    {
      // encrypted file, extended header still required
      if (( r = putextended( z, y, pG )) != ZEN_OK )
        return r;
      pG->tempzn += 16L;
    }
  }

  // Free the local extra field which is no longer needed
  if ( z->ext )
  {
    if ( z->extra != z->cextra )
      FREE( z->extra );
    z->ext = 0;
  }

  // Display statistics
  if ( pG->Frame.Verbose )
  {
    Notify( PF, 0, "%s  in=%lu,  out=%lu,  %d%%", ( m == DEFLATE ) ?
            "deflated" : "stored", pG->isize, s, percent( pG->isize, s ));
  }

  return ZEN_OK;
}

//BOOL ReadFileX(LPVOID lpBuffer, DWORD BytesToRead,
//   LPDWORD BytesRead, struct ZGlobals *pG)
//{
//  int i;
//  for (i = 0; i < 60; i++)
//  {
//      if (ReadFile(pG->hInfile, lpBuffer, BytesToRead, BytesRead, NULL))
//        return true;
//      if (pG->FileError || GetLastError() != ERROR_LOCK_VIOLATION)
//        return false;            
//      if (i < 3 && pG->Frame.Verbose < 0)
//        Notify(PF, IDIAG, "Waiting for locked file");
//      Sleep(500);//00);//000);
//      if (i > 60)
//          return false;
//  }
//  return false;
//}

// Read a new buffer from the current input file, perform end-of-line
//   translation, and update the crc and input file size. IN assertion: size >=
//   2 (for end-of-line translation)
int file_read(unsigned char *buf, unsigned size, struct ZGlobals *pG )
{
  DWORD len, olen;
  uch *b;

  if ( pG->translate_eol == 0 )
  {
#ifdef USE_STRM_INPUT
    if ( pG->UseInStream )
    {
      olen = len = size = min( pG->InStreamSize - pG->StreamPos, size );
      memcpy( buf, ( char* )pG->InStream + pG->StreamPos, size );
      pG->StreamPos += size;
    }
    else
      //      olen = len = read( pG->ifile, buf, size );
    {
      if ( !ReadFile(pG->hInfile, buf, size, &len, NULL ))
//      if ( !ReadFileX(buf, size, &len, pG))
      {
        pG->FileError = GetLastError();
        return EOF;
      }
      olen = len;
    }
#else
    //    olen = len = read( pG->ifile, buf, size );
    if ( !ReadFile( pG->hInfile, buf, size, &len, NULL ))
//    if ( !ReadFileX(buf, size, &len, pG))
      {
        pG->FileError = GetLastError();
        return EOF;
      }
    olen = len;
#endif
    //    if ( len == ( unsigned )EOF || !len )
    //      return ( int )len;
    if ( !len )
      return 0;
  }
  else
    if ( pG->translate_eol == 1 )
    {
      // Transform LF to CR/LF
      size >>= 1;
      b = buf + size;
      //    olen = size = len = read( pG->ifile, b, size ); 
      if ( !ReadFile( pG->hInfile, b, size, &len, NULL ))
//      if ( !ReadFileX(b, size, &len, pG))
      {
        pG->FileError = GetLastError();
        return EOF;
      }
      if ( !len )
        return 0;
      size = olen = len;
      //    if ( len == ( unsigned )EOF || !len )
      //      return ( int )len;
      do
      {
        if (( *buf++ =  *b++ ) == '\n' )
          // replace LF with CR/LF
          *( buf - 1 ) = '\r',  *buf++ = '\n', len++;
      }
      while ( --size != 0 );
      buf -= len;
    }
    else
    {
      // Transform CR/LF to LF and suppress final ^Z
      b = (uch *) buf;
      //    olen = size = len = read( pG->ifile, buf, size - 1 ); 
      if ( !ReadFile( pG->hInfile, buf, size - 1, &len, NULL ))
//      if ( !ReadFileX(buf, size - 1, &len, pG))
      {
        pG->FileError = GetLastError();
        return EOF;
      }
      if ( !len )
        return 0;
      size = olen = len;
      //    if ( len == ( unsigned )EOF || !len )
      //      return ( int )len;
      buf[len] = '\n'; // I should check if next
      ///* char is really a \n
      do
      {
        if (( *buf++ =  *b++ ) == '\r' &&  *b == '\n' )
          buf--, len--;
      }
      while ( --size != 0 );

      if ( !len )
      {
        //      olen = read( pG->ifile, buf, 1 );
        if ( !ReadFile( pG->hInfile, buf, 1, &olen, NULL ))
//        if ( !ReadFileX(buf, 1, &olen, pG))
          olen = 0;
        len = 1; // keep single \r if EOF
      }
      else
      {
        buf -= len;
        if ( buf[len - 1] == CTRLZ )
          len--;          // suppress final ^Z
      }
    }
                                             
  pG->crc = crc32( pG->crc, ( uch* )buf, len );
  pG->isize += ( ulg )len;
  // Callback: actioncode 2 = increment progress bar
//  User(PF, zacProgress, 0, olen, NULL);//, pG ); // Added for progress bar
  _CB_.Written.i64 = pG->BytesWritten;
  _CB_.FileSize.i64 = olen;
  User_CB(PF, zacProgress);
  return ( int )len;
}
