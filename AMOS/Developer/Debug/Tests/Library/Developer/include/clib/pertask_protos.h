#ifndef CLIB_PERTASK_PROTOS_H
#define CLIB_PERTASK_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/pertask.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)
AROS_LP0(struct Library *, GetParentBase,
         LIBBASETYPEPTR, PertaskBase, 5, Pertask
);

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)
#ifndef GetParentBase2
struct Library * GetParentBase2();
#endif

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)
#ifndef PertaskSetValue
void PertaskSetValue(int);
#endif

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

#if !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__)
#ifndef PertaskGetValue
int PertaskGetValue(void);
#endif

#endif /* !defined(__PERTASK_LIBAPI__) || (1 <= __PERTASK_LIBAPI__) */

__END_DECLS

#endif /* CLIB_PERTASK_PROTOS_H */
