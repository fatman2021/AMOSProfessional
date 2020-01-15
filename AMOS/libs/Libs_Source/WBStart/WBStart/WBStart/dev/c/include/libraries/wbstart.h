#ifndef LIBRARIES_WBSTART_H
#define LIBRARIES_WBSTART_H

/*
 * libraries/wbstart.h  V2.2
 *
 * shared library include file
 *
 * (c) 1991-1996 Stefan Becker
 */

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#define WBSTART_NAME    "wbstart.library"
#define WBSTART_VERSION 2

/* Tags for WBStartTagList() */

/* Name of the program to start. It is relative to                   */
/* WBStart_DirectoryName or WBStart_DirLock.                         */
#define WBStart_Name           (TAG_USER + 1)  /* const char *       */

/* Name of a directory. Mutually exclusive to WBStart_DirectoryLock  */
#define WBStart_DirectoryName  (TAG_USER + 2)  /* const char *       */

/* Lock of a directory. Mutually exclusive to WBStart_DirectoryName  */
#define WBStart_DirectoryLock  (TAG_USER + 3)  /* BPTR               */

/* Stack size for the new process                                    */
#define WBStart_Stack          (TAG_USER + 4)  /* ULONG              */

/* Priority for the new process                                      */
#define WBStart_Priority       (TAG_USER + 5)  /* LONG               */

/* Number of arguments in WBStart_ArgumentList                       */
#define WBStart_ArgumentCount  (TAG_USER + 6)  /* ULONG              */

/* Array of arguments. WBStart_ArgumentCount MUST be specified also! */
#define WBStart_ArgumentList   (TAG_USER + 7)  /* struct WBArg *     */

#endif /* LIBRARIES_WBSTART_H */
