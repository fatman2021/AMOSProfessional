#ifndef CLIB_PTPLAY_PROTOS_H
#define CLIB_PTPLAY_PROTOS_H

/*
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

APTR	PtInit		(UBYTE *buf, LONG bufsize, LONG freq, ULONG modtype);
VOID	PtRender		(APTR mod, BYTE *destbuf1, BYTE *destbuf2, LONG bufmodulo, LONG numsmp, LONG scale, LONG depth, LONG channels);
ULONG	PtTest		(CONST_STRPTR filename, UBYTE *buf, LONG bufsize);
VOID	PtCleanup	(APTR mod);
VOID	PtSetAttrs	(APTR mod, struct TagItem *taglist);
ULONG	PtGetAttr	(APTR mod, ULONG tagitem, ULONG *StoragePtr);
ULONG	PtSeek		(APTR mod, ULONG time);

#endif /* CLIB_PTPLAY_PROTOS_H */
