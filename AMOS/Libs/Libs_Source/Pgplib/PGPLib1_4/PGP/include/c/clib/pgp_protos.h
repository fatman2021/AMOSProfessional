#ifndef  CLIB_PGP_PROTOS_H
#define  CLIB_PGP_PROTOS_H

/*
**  clib/pgp_protos.h
**
**  $VER: pgp_protos.h 1.1 (10.1.98)
**
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif


LONG PGPEncrypt      (STRPTR filename,STRPTR userid,struct TagItem *tags);
LONG PGPEncryptTags  (STRPTR filename,STRPTR userid,ULONG tag1item,...);

LONG PGPDecrypt      (STRPTR filename,STRPTR password,struct TagItem *tags);
LONG PGPDecryptTags  (STRPTR filename,STRPTR password,ULONG tag1item,...);

LONG PGPFault        (LONG code,STRPTR header,STRPTR buffer,LONG len);

LONG PGPSign         (STRPTR filename,STRPTR password,struct TagItem *tags);
LONG PGPSignTags     (STRPTR filename,STRPTR password,ULONG tag1item,...);

#endif   /* CLIB_PGP_PROTOS_H */
