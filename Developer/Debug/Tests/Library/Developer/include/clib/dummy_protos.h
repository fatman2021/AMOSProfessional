#ifndef CLIB_DUMMY_PROTOS_H
#define CLIB_DUMMY_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/dummy.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)
AROS_LP2(ULONG, add,
         AROS_LPA(ULONG, a, D0),
         AROS_LPA(ULONG, b, D1),
         LIBBASETYPEPTR, DummyBase, 5, Dummy
);

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)
AROS_LP2(ULONG, asl,
         AROS_LPA(ULONG, a, D0),
         AROS_LPA(ULONG, b, D1),
         LIBBASETYPEPTR, DummyBase, 6, Dummy
);

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

#if !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__)
#ifndef printx
LONG printx(LONG args, ...);
#endif

#endif /* !defined(__DUMMY_LIBAPI__) || (1 <= __DUMMY_LIBAPI__) */

__END_DECLS

#endif /* CLIB_DUMMY_PROTOS_H */
