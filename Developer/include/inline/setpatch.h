#ifndef INLINE_SETPATCH_H
#define INLINE_SETPATCH_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/setpatch/setpatch.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for setpatch
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__SETPATCH_LIBBASE)
#    define __SETPATCH_LIBBASE SetPatchBase
#endif


#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

static inline BOOL __inline_Setpatch_AddPatch(struct PatchEntry * __arg1, APTR __SetPatchBase)
{
    AROS_LIBREQ(SetPatchBase, 41)
    return AROS_LC1(BOOL, AddPatch,
        AROS_LCA(struct PatchEntry *,(__arg1),A0),
        struct Library *, (__SetPatchBase), 5, Setpatch    );
}

#define AddPatch(arg1) \
    __inline_Setpatch_AddPatch((arg1), __SETPATCH_LIBBASE)

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

static inline VOID __inline_Setpatch_RemPatch(struct PatchEntry * __arg1, APTR __SetPatchBase)
{
    AROS_LIBREQ(SetPatchBase, 41)
    AROS_LC1NR(VOID, RemPatch,
        AROS_LCA(struct PatchEntry *,(__arg1),A0),
        struct Library *, (__SetPatchBase), 6, Setpatch    );
}

#define RemPatch(arg1) \
    __inline_Setpatch_RemPatch((arg1), __SETPATCH_LIBBASE)

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)

static inline struct PatchEntry * __inline_Setpatch_FindPatch(CONST_STRPTR __arg1, APTR __SetPatchBase)
{
    AROS_LIBREQ(SetPatchBase, 41)
    return AROS_LC1(struct PatchEntry *, FindPatch,
        AROS_LCA(CONST_STRPTR,(__arg1),A0),
        struct Library *, (__SetPatchBase), 7, Setpatch    );
}

#define FindPatch(arg1) \
    __inline_Setpatch_FindPatch((arg1), __SETPATCH_LIBBASE)

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#endif /* INLINE_SETPATCH_H*/
