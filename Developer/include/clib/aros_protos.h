#ifndef CLIB_AROS_PROTOS_H
#define CLIB_AROS_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/aros/aros.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <utility/tagitem.h>

__BEGIN_DECLS


#if !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__)
AROS_LP1(ULONG, ArosInquireA,
         AROS_LPA(struct TagItem *, taglist, A0),
         LIBBASETYPEPTR, ArosBase, 5, Aros
);

#endif /* !defined(__AROS_LIBAPI__) || (41 <= __AROS_LIBAPI__) */

__END_DECLS

#endif /* CLIB_AROS_PROTOS_H */
