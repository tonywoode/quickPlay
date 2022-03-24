/* ---------------------------------------------------------------------------
 * globals.h
 *  This file has been reconstructed using
 *  ZGlobals.h from UnzipDll version 1.60 and
 *  declarations of variables from ZipDll version 1.50
 *  Xavier Mor-Mur  (2001/10/25)
 *  ** distributed under LGPL license ** see license.txt for details
1.73.2.6 21 September 2003 added Callback_Exception
 * ---------------------------------------------------------------------------
 */

#ifndef __globals_h
#define __globals_h

//#include "enter.h"
#include "common.h"
//#include <sys\stat.h>

#ifndef HASH_BITS
  #define HASH_BITS 15    // Number of bits used to hash strings
#endif
#define HASH_SIZE ( unsigned )( 1 << HASH_BITS )
#define HASH_MASK ( HASH_SIZE - 1 )
#define WMASK     ( WSIZE - 1 )

// HASH_SIZE and WSIZE must be powers of two
#define NIL 0

// Tail of hash chains
typedef ush Pos;
typedef size_t extent;
typedef struct ct_data
{
  union
  {
    ush freq; // frequency count
    ush code; // bit string
  } fc;
  union
  {
    ush dad; // father node in Huffman tree
    ush len; // length of bit string
  } dl;
}ct_data;

typedef struct tree_desc
{
  ct_data *dyn_tree; // the dynamic tree
  ct_data *static_tree; // corresponding static tree or NULL
  int *extra_bits; // extra bits for each code or NULL
  int extra_base; // base index for extra_bits
  int elems; // max number of elements in the tree
  int max_length; // max bit length for the codes
  int max_code; // largest code with non zero frequency
}tree_desc;

#define Freq          fc.freq
#define Code          fc.code
#define Dad           dl.dad
#define Len           dl.len

#define ADD           1
#define MAX_BITS      15  // All codes must not exceed MAX_BITS bits
#define MAX_BL_BITS   7   // Bit length codes must not exceed MAX_BL_BITS bits
#define LENGTH_CODES  29
// number of length codes, not counting the special END_BLOCK code
#define LITERALS      256 // number of literal bytes 0..255
#define END_BLOCK     256 // end of block literal code
#define L_CODES       ( LITERALS + 1 + LENGTH_CODES )
// number of Literal or Length codes, including the END_BLOCK code
#define D_CODES       30                  // number of distance codes
#define BL_CODES      19
// number of codes used to transfer the bit lengths
#define HEAP_SIZE     ( 2 * L_CODES + 1 ) // maximum heap size
#define Max( a, b )   ( a >= b ? a : b )
#define REP_3_6       16
#define REPZ_3_10     17
#define REPZ_11_138   18

#ifdef DEBUGx
    #define send_code( c, tree, g )            \
{                                            \
if ( Frame.Verbose < 0 )                         \
    Notify( PF, IDIAG, "\ncd %3d ", c ); \
    send_bits( tree[c].Code, tree[c].Len, g ); \
}

#else // !DEBUG
    #define send_code( c, tree, g )            \
{                                            \
send_bits( tree[c].Code, tree[c].Len, g ); \
}

// Send a code of the given tree. c and tree must not have side effects
#endif
#define STORED_BLOCK  0
#define STATIC_TREES  1
#define DYN_TREES     2

#ifndef LIT_BUFSIZE
  #define LIT_BUFSIZE 0x8000
#endif
#define DIST_BUFSIZE  LIT_BUFSIZE

/*************/
/*  ZGlobals  */
/*************/
struct ZGlobals
{
  struct OpFrame Frame; // must be first element
#ifdef USE_STRM_INPUT
  bool UseInStream; // NEW Use memory stream as input.
  void *InStream; // NEW Pointer to the start of the input stream data.
  unsigned long InStreamSize; // NEW Size of the input data.
  unsigned long StreamPos; // NEW The present position in the stream
#endif
  //  FILE *zfile;                  // zipfile file handle
  HANDLE zfile; // zipfile file handle
  unsigned calls; // crypt static: ensure diff. random header each time
  ulg keys[3]; // crypt static: keys defining pseudo-random sequence
  char *key; // crypt static: decryption password or NULL
  char *user_key; // user entered key or NULL RP 1.73
  char ewemsg[2048];
  int global_error_code; // in UnzErr() in dllmain
  int files_acted_on;
  int dll_handles_errors;
  int user_notified_of_abort; // in UnzErr() in dllmain
//  HWND global_handle;
//  void *global_caller;
//  DLLCALLBK callb; // Function address for callback purposes.
  unsigned /*short*/ WantedCodePage;
#ifdef CRYPT  // If no crypt don't use
  char lpszPassword[PWLEN + 1]; // Used in PassMsg.c
  WORD cchPassword;
  bool pwork;
  int rcode;
#endif
#ifdef DEBUG
  unsigned bits_sent;
#endif;
  unsigned short bi_buf;
  int bi_valid;
  char file_outbuf[4096];
  char *in_buf;
  char *out_buf;
  unsigned in_size;
  unsigned out_size;
  unsigned in_offset;
  unsigned out_offset;
  int( *read_buf )(unsigned char *buf, unsigned size, struct ZGlobals *pG );
  ulg window_size;
  int level;
  int sliding;
  Pos head[HASH_SIZE];
  Pos prev[WSIZE];
  int nice_match;
  unsigned good_match;
  unsigned strstart;
  unsigned lookahead;
  unsigned ins_h;
  unsigned match_start;
  unsigned int max_chain_length;
  unsigned int max_lazy_match;
  unsigned int prev_length;
  long block_start;
  uch window[2L *WSIZE];
  int eofile;
//  CallBackStruct callbackdata;
  long OCDlength;
  char *OrigCurrentDir;
  char *zcomment;
  int zcomlen;
  int ArchiveFiles;
  int ResetArchiveBit;
//  int GlobalCompVersion;
  bool HowToMove;
  bool UseOutStream;
  void *OutStream;
  long OutStreamSize;
  DWORD StrFileAttr;
  DWORD StrFileDate;
  int norecursefiles;
  char *special;
  int pcount;
  struct plist *ExternalList;
  char ewetmp[4096];//513];
//  int Frame.Verbose;
  struct flist *found;
  struct zlist *zfiles;
  extent zcount;
  struct plist *patterns;
  int latest;
  char *zipfile;
  char *tempath;
  int dispose;
  char *tempzip;
  HANDLE hTempzf;
  HANDLE hInz;
  HANDLE hOutz;
  int extra_fields;
  int NoExtChk;// method;
  int adjust;
  int tempdir;
  int action;
  int dirnames;
  int key_len;
  int pathput;
  int junk_sfx;
  int dosify;
  int translate_eol;
  int noisy;
  int recurse;
  int hidden_files;
  ulg before;
  int volume_label;
  char errbuf[FNMAX + 81];
  int linkput;
  struct zlist **zsort;
  ulg zipbeg;
  __int64 tempzn;   
//  ulg tempzn;
  ulg cenbeg;
  extent fcount;
  char fnamebuf[MAX_PATH];

  char *label;
  int zipstate;
  struct stat zipstatb;
  struct flist **fnxt;
  char *wild_match_all;
  tree_desc l_desc;
  tree_desc d_desc;
  tree_desc bl_desc;
  ct_data dyn_ltree[HEAP_SIZE]; // literal and length tree
  ct_data dyn_dtree[2 *D_CODES + 1]; // distance tree
  ct_data static_ltree[L_CODES + 2];
  ct_data static_dtree[D_CODES];
  int *extra_bits;
  int extra_base;
  ct_data bl_tree[2 *BL_CODES + 1];
  CHAR lpszPrompt[20];
  ush *file_type;
  int *file_method;
  unsigned __int64 compressed_len;
  ulg input_len;
  int base_length[LENGTH_CODES];
  uch length_code[MAX_MATCH - MIN_MATCH + 1];
  int base_dist[D_CODES];
  uch dist_code[512];
  ush bl_count[MAX_BITS + 1];
  ulg opt_len;
  ulg static_len;               // bit length of current block with static trees
  unsigned last_lit;            // running index in l_buf
  unsigned last_dist;           // running index in d_buf
  unsigned last_flags;          // running index in flag_buf
  uch flags;                    // current flags not yet saved in flag_buf
  uch flag_bit;                 // current bit used in flags
  int heap[2 *L_CODES + 1];     // heap used to build the Huffman trees
  int heap_len;                 // number of elements in the heap
  int heap_max;                 // element of largest frequency
  uch depth[2 *L_CODES + 1];
  uch flag_buf[( LIT_BUFSIZE / 8 )];
#ifdef DYN_ALLOC
  uch *l_buf;
  ush *d_buf;
#else
  uch l_buf[LIT_BUFSIZE];       // buffer for literals/lengths
  ush d_buf[DIST_BUFSIZE];      // buffer for distances
#endif
  char vol[24]; // max volume label length is 12, but extra buffer for ...
  ulg label_time;
  ulg label_mode;
  time_t label_utim;
  int use_longname_ea;
  int fix;
  HANDLE hInfile;               // 1.78.5.3
  int FileError;                // 1.78.6.0
  ulg crc;
  ulg isize;
  int AllowGrow;                // new 1.73
  int Callback_Exception;       // new 1.73.2.6
  int WantedOS;                 // new 1.74
  int BatchStarted;             // new 1.73.4.2
  int CanSeek;                  // new 1.75
  unsigned int BytesWritten;    // new 176
  const char *StartCDir;        // new 178.5.0
  char *FullPath;               // 1,74
  FileData *FileArg;            // 1.74
  int doall;                    // new 178.5.0
  char *tspec;                  // new 1.79.4.4
  int OldFAT;                   // new 1.79.6.4
}; /* end of struct ZGlobals */

/***************************************************************************/ 
extern struct ZGlobals *Create_ZGlobals( ZipParms * C );
extern void Destroy_ZGlobals( struct ZGlobals *pG);
extern struct ZGlobals *Current_ZGlobals( void );

#endif /* __globals_h */
