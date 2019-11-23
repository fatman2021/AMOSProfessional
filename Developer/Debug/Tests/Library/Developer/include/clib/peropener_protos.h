#ifndef CLIB_PEROPENER_PROTOS_H
#define CLIB_PEROPENER_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/developer/debug/test/library/peropener.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


__BEGIN_DECLS


#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
#ifndef PeropenerSetValueStack
void PeropenerSetValueStack(int);
#endif

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
#ifndef PeropenerGetValueStack
int PeropenerGetValueStack(void);
#endif

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
AROS_LP1(void, PeropenerSetValueReg,
         AROS_LPA(int, v, D0),
         LIBBASETYPEPTR, PeropenerBase, 7, Peropener
);

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
AROS_LP0(int, PeropenerGetValueReg,
         LIBBASETYPEPTR, PeropenerBase, 8, Peropener
);

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
#ifndef PeropenerNoLib
int PeropenerNoLib(void);
#endif

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

#if !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__)
#ifndef PeropenerNameChange
int PeropenerNameChange(void);
#endif

#endif /* !defined(__PEROPENER_LIBAPI__) || (2 <= __PEROPENER_LIBAPI__) */

__END_DECLS

#endif /* CLIB_PEROPENER_PROTOS_H */
