#ifndef DEFINES_SETPATCH_H
#define DEFINES_SETPATCH_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/setpatch/setpatch.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for setpatch
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__SETPATCH_LIBBASE)
#    define __SETPATCH_LIBBASE SetPatchBase
#endif

__BEGIN_DECLS


#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

#define __AddPatch_WB(__SetPatchBase, __arg1) ({\
        AROS_LIBREQ(SetPatchBase,41)\
        AROS_LC1(BOOL, AddPatch, \
                  AROS_LCA(struct PatchEntry *,(__arg1),A0), \
        struct Library *, (__SetPatchBase), 5, Setpatch);\
})

#define AddPatch(arg1) \
    __AddPatch_WB(__SETPATCH_LIBBASE, (arg1))

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

#define __RemPatch_WB(__SetPatchBase, __arg1) ({\
        AROS_LIBREQ(SetPatchBase,41)\
        AROS_LC1NR(VOID, RemPatch, \
                  AROS_LCA(struct PatchEntry *,(__arg1),A0), \
        struct Library *, (__SetPatchBase), 6, Setpatch);\
})

#define RemPatch(arg1) \
    __RemPatch_WB(__SETPATCH_LIBBASE, (arg1))

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

#define __FindPatch_WB(__SetPatchBase, __arg1) ({\
        AROS_LIBREQ(SetPatchBase,41)\
        AROS_LC1(struct PatchEntry *, FindPatch, \
                  AROS_LCA(CONST_STRPTR,(__arg1),A0), \
        struct Library *, (__SetPatchBase), 7, Setpatch);\
})

#define FindPatch(arg1) \
    __FindPatch_WB(__SETPATCH_LIBBASE, (arg1))

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_SETPATCH_H*/
