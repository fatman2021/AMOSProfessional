#ifndef INLINE_KMS_H
#define INLINE_KMS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/kms/kms.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for kms
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__KMS_LIBBASE)
#    define __KMS_LIBBASE KMSBase
#endif


#if !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__)

static inline struct KeyMapNode * __inline_Kms_OpenKeymap(STRPTR __arg1, APTR __KMSBase)
{
    AROS_LIBREQ(KMSBase, 3)
    return AROS_LC1(struct KeyMapNode *, OpenKeymap,
        AROS_LCA(STRPTR,(__arg1),A0),
        struct KMSLibrary *, (__KMSBase), 5, Kms    );
}

#define OpenKeymap(arg1) \
    __inline_Kms_OpenKeymap((arg1), __KMS_LIBBASE)

#endif /* !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__) */

#endif /* INLINE_KMS_H*/
