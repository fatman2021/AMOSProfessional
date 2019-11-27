#ifndef CLIB_SETPATCH_PROTOS_H
#define CLIB_SETPATCH_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/arch/m68k-amiga/setpatch/setpatch.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <exec/nodes.h>

struct PatchEntry {
    struct MinNode  pe_Node;
    CONST_STRPTR    pe_Name;        /* Name of the patch */
    UWORD           pe_Version;     /* Patch version */
    UWORD           pe_Revision;    /* Patch revision */
};

__BEGIN_DECLS


#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)
AROS_LP1(BOOL, AddPatch,
         AROS_LPA(struct PatchEntry *, pe, A0),
         LIBBASETYPEPTR, SetPatchBase, 5, Setpatch
);

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)
AROS_LP1(VOID, RemPatch,
         AROS_LPA(struct PatchEntry *, pe, A0),
         LIBBASETYPEPTR, SetPatchBase, 6, Setpatch
);

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

#if !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__)
AROS_LP1(struct PatchEntry *, FindPatch,
         AROS_LPA(CONST_STRPTR, name, A0),
         LIBBASETYPEPTR, SetPatchBase, 7, Setpatch
);

#endif /* !defined(__SETPATCH_LIBAPI__) || (41 <= __SETPATCH_LIBAPI__) */

__END_DECLS

#endif /* CLIB_SETPATCH_PROTOS_H */
