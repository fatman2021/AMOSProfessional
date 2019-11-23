#ifndef DEFINES_KMS_H
#define DEFINES_KMS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/kms/kms.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for kms
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__KMS_LIBBASE)
#    define __KMS_LIBBASE KMSBase
#endif

__BEGIN_DECLS


#if !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__)

#define __OpenKeymap_WB(__KMSBase, __arg1) ({\
        AROS_LIBREQ(KMSBase,3)\
        AROS_LC1(struct KeyMapNode *, OpenKeymap, \
                  AROS_LCA(STRPTR,(__arg1),A0), \
        struct KMSLibrary *, (__KMSBase), 5, Kms);\
})

#define OpenKeymap(arg1) \
    __OpenKeymap_WB(__KMS_LIBBASE, (arg1))

#endif /* !defined(__KMS_LIBAPI__) || (3 <= __KMS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_KMS_H*/
