#include <windows.h>
#include "Common.h"
#pragma hdrstop

/* Common.c * Copyright (C) 1997 Mike White, Eric W. Engler and Russell Peters
* Permission is granted to any individual or institution to use, copy, or
* redistribute this software so long as all of the original files are included,
* that it is not sold for profit, and that this copyright notice is retained.
* This version modified by Chris Vleghert BCB/Delphi Zip.
** distributed under LGPL license
** see license.txt for details
1.79 14 September 2005
*/

#include <stdio.h>
#include "version.h"
#include "cpyrght.h"
//#include "time.h"
#include "enter.h"

extern HINSTANCE ModuleInst;

bool MakeLog( Frames * pf, const char * nl, const char * fzn );
void GiveTime( Frames * pf );
bool QueryINI(Frames * pf, bool IsZip);

/* =====================================================
* Entry point to abort operation started with C
*/
long WINAPI DZ_Abort( void * C )
{
  return Set_Oper_Abort((OperKeys)C);
}

long WINAPI DZ_Version( void )
{
  return DELZIPVERS; // see version.h
}

long WINAPI DZ_PrivVersion( void )
{
  return DELZIPPRIVVERS;
}

static char* PathBuf = 0;
const char* WINAPI DZ_Path( void )  //(char *buf, int len)
{
  if (PathBuf)
    return PathBuf;
  if ((PathBuf = (char *) MALLOC( MAX_PATH + 2)) == NULL)
    return NULL;

  if (!GetModuleFileName(ModuleInst, PathBuf, MAX_PATH))
  {
    FREE( PathBuf );
    PathBuf = NULL;
  }
  return PathBuf;
}
/*
// ziperr() is the preferred error msg function!!!
void msgbox( char * msg, struct ZGlobals * pG )
{
  // Did user pass us a window handle?
  if ( pG->Frame.global_handle )
  { // RCV changed: was exit if no handle;
    lstrcpy( pG->ewetmp, "Msg From ZIP DLL: " );
    lstrcat( pG->ewetmp, msg );
    MessageBox( pG->Frame.global_handle, pG->ewetmp, "Msg From ZIP DLL", MB_OK );
  }
}
*/

void ShowNotifyBox(Frames *fp, const char *msg )
{
  HWND wHandle;
  char tmp[52];

  wHandle = fp->global_handle;

  /* Did the user pass us a good window handle? if not, we can't pop-up a box. */
  if ( !wHandle )
    wHandle = GetDesktopWindow(); // v1.6021
  /* bring up a dialog box */
  snprintf(tmp, 50, "DelZip179 %s message", fp->OpTyp != UNZOPER ?"ZIP":"UNZIP");
  tmp[51] = 0;
  if (MessageBox(wHandle, msg, tmp, MB_OKCANCEL | MB_ICONEXCLAMATION) == IDCANCEL)
	fp->Abort_Flag |= GA_CANCEL;  // abort
}

static const char *errs[5] =
  { "Warning: ", "Error: ", "trace: ", "Trace: ", "Debug: "
  };

int __cdecl
Notify(Frames *fp, int err, const char *format, ... )
{
  va_list argptr;
//  char    buf[514 + 8];
  char    *buffer = fp->InfoBuf;
  int     blen = 512;
  int     typ, bad = 0;
  if ( !fp )
    return -1;  // should not happen
  fp->InfoBuf[0] = 0;
  if (err > 0)
  {
      bad = err & IBAD;
	  typ = err >> 24;
	  if (bad)
	    typ &= 0x7;

	  if (typ > 5)
		typ = 0;
	  err = err & 0xFFFF;

	  if (typ)
	  {
		lstrcpy( buffer, errs[--typ] );
		blen = lstrlen( buffer );
		buffer = buffer + blen;
		blen = 512 - blen;
	  }
  }

  va_start( argptr, format );
  vsnprintf( buffer, blen, format, argptr );
  fp->InfoBuf[512] = 0;
  if (fp->LogName && *(fp->LogName))
	LogString(fp, err, fp->InfoBuf);
  if (bad && fp->Verbose < -10)
  {
	  fp->Verbose++;
	  ShowNotifyBox(fp, fp->InfoBuf);
  }

  // warning message, or info message only
//  User(fp, zacMessage, err, 0, fp->InfoBuf );
  va_end( argptr );
  fp->CallBackData.Arg1 = err;    // error
  fp->CallBackData.MsgP = fp->InfoBuf;
  User_CB(fp, zacMessage);

  return 0;
}

void LogString(Frames *fp, int err, const char *msg)
{
  char erm[20];
//  int i;
  DWORD br;
  HANDLE hLog = fp->hLogFile;
  if (hLog == INVALID_HANDLE_VALUE)
  {
	hLog = CreateFile( fp->LogName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL );
	if (hLog == INVALID_HANDLE_VALUE
		|| SetFilePointer(hLog, 0, NULL, FILE_END) == (unsigned)-1)
    {
      FREE(fp->LogName);
      fp->LogName = NULL;
      return;
    }
  }
  erm[0] = 0;
  if (err != -1)
    sprintf(erm, "%-6x      ", err);

  if ((err != -1 && !WriteFile( hLog, erm, 8, &br, NULL))
       || !WriteFile( hLog, msg, lstrlen(msg), &br, NULL)
       || !WriteFile( hLog, "\r\n", 2, &br, NULL))
  {
    FREE(fp->LogName);
    fp->LogName = NULL;
  }
  if (fp->hLogFile == INVALID_HANDLE_VALUE)
    CloseHandle(hLog);
}

bool QueryINI(Frames *pF, bool IsZip)
{
  HANDLE hTemp;
  unsigned ut;
  DWORD sz;
  char *p, *lp;
  int lvl, errs;
  char *nam = pF->InfoBuf;
  const char *Section = IsZip?"ZIP":"UNZIP";
  const char *DefName = IsZip?"DZz*":"DZu*";
  char *pth;
  lstrcpy(nam, DZ_Path());
  sz = lstrlen(nam);
//  sz = DllPath(nam, sizeof(pF->InfoBuf)-1);
  p = nam + sz - 4;
  if (sz<4 || lstrcmpi(p,".dll"))
      return false;
  lstrcpy(p, ".INI");
  p[5] = 0;
  pth = p + 6;
  lvl = GetPrivateProfileInt(Section, "Level", 0, nam);
  if (lvl < 1)
    return false;                                    
  errs = GetPrivateProfileInt(Section, "Errors", 0, nam);
  if (errs < 1)
	errs = 0;
  sz = GetPrivateProfileString(Section, "Path", ".", pth, 200, nam);
  p = pth + sz;
  if (sz > 0 && p[-1] != (char)'\\')
  {
    *p++ = '\\';
    *p = 0;
  }
//  sz = GetPrivateProfileString(Section, "Name", "DelZip*", p, 31, nam);
  sz = GetPrivateProfileString(Section, "Name", DefName, p, 31, nam);
  p += (sz -1);
  if (sz < 4)
    return false;
  if (lstrlen(pth) > 300)
    return false;
  if (*p == (char)'*')
  {
    SYSTEMTIME T;
    GetLocalTime( &T );
    ut = (T.wYear -2000) & 0xFF;
    ut = (ut << 4) + T.wMonth;
    ut = (ut << 5) + T.wDay;
    ut = (ut << 5) + T.wHour;
    ut = (ut << 6) + T.wMinute;
    ut = (ut << 6) + T.wSecond;
//    ut = (ut << 2) + (T.wMilliseconds / 250);
    ut = (ut << 2) + (FCount & 3);
    p[sz-1] = 0;
    wsprintf(p,"[%X%x].log", ut, T.wMilliseconds);
  }

  lp = (char *)MALLOC( lstrlen(pth)+1 );
  if (lp)
  {
    lstrcpy(lp, pth);
    hTemp = CreateFile( lp, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW,
                        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL );
    if (hTemp == INVALID_HANDLE_VALUE )
    {
      FREE( lp );
      return false;
    }
	if (lvl > 3)
	  lvl = 3;

	if (errs)
	{
		if (errs > 255)
			errs = 255; // keep sane
        pF->Verbose = -10 - errs;
	}
	else
	  pF->Verbose = ( lvl == 1 ) ? 2 : -2;
//    if ( lvl != 3 )
      pF->hLogFile = hTemp;
    pF->LogName = lp;
    LogString(pF, -1, "DelZip_Dll Error Log ");
    LogString(pF, -1, Section);
    if ( lvl == 3 )
    {
      Close_Handle(&pF->hLogFile);//&hTemp);
    }
    return true;
  }
  return false;
}

unsigned LOCSIG =   0x04034b00L;
unsigned CENSIG =   0x02014b00L;
unsigned ENDSIG =   0x06054b00L;
unsigned EXTLOCSIG = 0x08074b00L;

int Init_Process(void)
{
  LOCSIG |= 0x50;
  CENSIG |= 0x50;
  ENDSIG |= 0x50;
  EXTLOCSIG |= 0x50;
  UCount = 0;
  ZCount = 0;
  Setup_upper();
  Setup_extend();
  return 0;
}

int __fastcall Close_Handle(HANDLE *h)
{
  HANDLE ht = *h;
  if (ht != INVALID_HANDLE_VALUE)
  {
    *h = INVALID_HANDLE_VALUE;
    return CloseHandle( ht );
  }
  return 0;
}
/*
void __fastcall FreeAndNil(void **p)
{
  if (p && *p)
  {
    void *t = *p;
    *p = NULL;
    free(t);
  }
}  */

void Init_Frame( Frames *pf )
{
  pf->hLogFile = INVALID_HANDLE_VALUE;
  pf->LogName = NULL;
}

void Clean_Frame( Frames *pf )
{
  Close_Handle( &pf->hLogFile );
  FREEANDNIL(pf->LogName);
}
   
int __fastcall IsPrefix(const char* fn)
{
  if (!strncmp(fn, "\\\\?\\", 4))
    return 4;
  return 0;
}

//const char *upper = 0;
//const char *extend = 0;

void
Setup_upper( void )
{              
  int i;
  unsigned char *p = (unsigned char *)upper;
  for ( i = 0; i < 256; i++ )
    *p++ = (unsigned char) i;
  CharUpperBuff( ( char * )upper + 1, 255 );
  ( char )upper[( int )'/'] = '\\'; // ignore difference
}

void
Setup_extend( void )
{       
  int i;
  unsigned char *p = (unsigned char *)extend;
  for ( i = 0; i <= 255; i++ )
    *p++ = (unsigned char)i;        
  p = (unsigned char *)extend;
  p++;
  CharToOemBuff( ( char * )p, ( char * )p, 255 );
//  p = (unsigned char *)extend;
  for ( i = 1; i < 256; i++ )
  {
    *p = (unsigned char)((*p != ( unsigned char )i) ? 1 : 0);
    p++;
  } 
}
 
void Cleanup_Process(void)
{
  free( PathBuf );
/*  if (upper)
    free((void*)upper);
  if (extend)
    free((void*)extend); */
}

HANDLE __fastcall OpenRead(Frames *fp, LPCTSTR FileName, DWORD flags)
{
  HANDLE h = CreateFile(FileName, GENERIC_READ, /*0*/FILE_SHARE_READ, NULL,
				OPEN_EXISTING, flags, NULL);
  if (h == INVALID_HANDLE_VALUE && GetLastError() == ERROR_SHARING_VIOLATION )
  {
	  h = CreateFile(FileName, GENERIC_READ, 0/*FILE_SHARE_READ*/, NULL,
				OPEN_EXISTING, flags, NULL);
	  if (h == INVALID_HANDLE_VALUE && GetLastError() == ERROR_SHARING_VIOLATION )
	  {
		h = CreateFile(FileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL, OPEN_EXISTING, flags, NULL);
	  }
  }             
  if (h == INVALID_HANDLE_VALUE && fp->Verbose < 0)
	Notify( fp, ITRACE, "open read failed; filename=%s [%d]", FileName,
			GetLastError());
  return h;
}

//#pragma option -a1
#pragma option -a8
const char  upper[256]  =
  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
  };
const char  extend[256]  =
  {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
  };
#pragma option -a.

