#ifndef INLINE_EFI_H
#define INLINE_EFI_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/efi/efi.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for efi
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EFI_LIBBASE)
#    define __EFI_LIBBASE EFIBase
#endif


#if !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__)

static inline void * __inline_Efi_EFI_FindConfigTable(const uuid_t * __arg1, APTR __EFIBase)
{
    AROS_LIBREQ(EFIBase, 1)
    return AROS_LC1(void *, EFI_FindConfigTable,
        AROS_LCA(const uuid_t *,(__arg1),A0),
        struct EFIBase *, (__EFIBase), 1, Efi    );
}

#define EFI_FindConfigTable(arg1) \
    __inline_Efi_EFI_FindConfigTable((arg1), __EFI_LIBBASE)

#endif /* !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__) */

#endif /* INLINE_EFI_H*/
