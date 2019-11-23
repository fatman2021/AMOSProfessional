#ifndef CLIB_KMS_PROTOS_H
#define CLIB_KMS_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/kms/kms.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <libraries/kms.h>

__BEGIN_DECLS


#if !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__)
AROS_LP1(struct KeyMapNode *, OpenKeymap,
         AROS_LPA(STRPTR, name, A0),
         LIBBASETYPEPTR, KMSBase, 5, Kms
);

#endif /* !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__) */

__END_DECLS

#endif /* CLIB_KMS_PROTOS_H */
