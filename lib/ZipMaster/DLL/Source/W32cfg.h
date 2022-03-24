
/* This version modified by Chris Vleghert and Eric W. Engler
 * for BCB/Delphi Zip, Jun 18, 2000.
 *
 *---------------------------------------------------------------------------
 *  Win32 specific configuration section:
 *---------------------------------------------------------------------------
 */
#ifndef __w32cfg_h
# define __w32cfg_h

# include <sys/types.h>         /* off_t, time_t, dev_t, ... */
# include <sys/stat.h>
# include <io.h>                /* read(), open(), etc. */
# include <time.h>
# include <memory.h>
# include <direct.h>            /* mkdir() */
# include <fcntl.h>
//# include <sys/utime.h>
#include <utime.h>

# if defined( FILEIO_C )
#  include <conio.h>
#  include <windows.h>
# endif

# define DATE_FORMAT   DF_MDY

#endif /* !__w32cfg_h */
