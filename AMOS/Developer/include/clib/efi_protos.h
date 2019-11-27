#ifndef CLIB_EFI_PROTOS_H
#define CLIB_EFI_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/efi/efi.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <libraries/uuid.h>
#include <resources/efi.h>

__BEGIN_DECLS


#if !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__)
AROS_LP1(void *, EFI_FindConfigTable,
         AROS_LPA(const uuid_t *, Guid, A0),
         LIBBASETYPEPTR, EFIBase, 1, Efi
);

#endif /* !defined(__EFI_LIBAPI__) || (1 <= __EFI_LIBAPI__) */

__END_DECLS

#endif /* CLIB_EFI_PROTOS_H */
