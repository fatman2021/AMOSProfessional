#ifndef CLIB_USEREL_PROTOS_H
#define CLIB_USEREL_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/userel.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__)
AROS_LP2(ULONG, DummyAdd,
         AROS_LPA(ULONG, a, D0),
         AROS_LPA(ULONG, b, D1),
         LIBBASETYPEPTR, UserelBase, 5, Userel
);

#endif /* !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__) */

#if !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__)
#ifndef PertaskGetParentBase
APTR PertaskGetParentBase();
#endif

#endif /* !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__) */

#if !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__)
#ifndef DummyPrint4
LONG DummyPrint4(STACKLONG a, STACKLONG b, STACKLONG c, STACKLONG d);
#endif

#endif /* !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__) */

#if !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__)
#ifndef GetChildValue
int GetChildValue(void);
#endif

#endif /* !defined(__USEREL_LIBAPI__) || (1 <= __USEREL_LIBAPI__) */

__END_DECLS

#endif /* CLIB_USEREL_PROTOS_H */
