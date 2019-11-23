#ifndef DEFINES_EFI_H
#define DEFINES_EFI_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/efi/efi.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for efi
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EFI_LIBBASE)
#    define __EFI_LIBBASE EFIBase
#endif

__BEGIN_DECLS


#if !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__)

#define __EFI_FindConfigTable_WB(__EFIBase, __arg1) ({\
        AROS_LIBREQ(EFIBase,1)\
        AROS_LC1(void *, EFI_FindConfigTable, \
                  AROS_LCA(const uuid_t *,(__arg1),A0), \
        struct EFIBase *, (__EFIBase), 1, Efi);\
})

#define EFI_FindConfigTable(arg1) \
    __EFI_FindConfigTable_WB(__EFI_LIBBASE, (arg1))

#endif /* !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_EFI_H*/
