#ifndef INLINE_MUISCREEN_H
#define INLINE_MUISCREEN_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/muiscreen/muiscreen.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for muiscreen
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__MUISCREEN_LIBBASE)
#    define __MUISCREEN_LIBBASE MUIScreenBase
#endif


#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline struct MUI_PubScreenDesc* __inline_MUIScreen_MUIS_AllocPubScreenDesc(struct MUI_PubScreenDesc * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC1(struct MUI_PubScreenDesc*, MUIS_AllocPubScreenDesc,
        AROS_LCA(struct MUI_PubScreenDesc *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 5, MUIScreen    );
}

#define MUIS_AllocPubScreenDesc(arg1) \
    __inline_MUIScreen_MUIS_AllocPubScreenDesc((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline VOID __inline_MUIScreen_MUIS_FreePubScreenDesc(struct MUI_PubScreenDesc * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    AROS_LC1NR(VOID, MUIS_FreePubScreenDesc,
        AROS_LCA(struct MUI_PubScreenDesc *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 6, MUIScreen    );
}

#define MUIS_FreePubScreenDesc(arg1) \
    __inline_MUIScreen_MUIS_FreePubScreenDesc((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline char* __inline_MUIScreen_MUIS_OpenPubScreen(struct MUI_PubScreenDesc * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC1(char*, MUIS_OpenPubScreen,
        AROS_LCA(struct MUI_PubScreenDesc *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 7, MUIScreen    );
}

#define MUIS_OpenPubScreen(arg1) \
    __inline_MUIScreen_MUIS_OpenPubScreen((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline BOOL __inline_MUIScreen_MUIS_ClosePubScreen(char * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC1(BOOL, MUIS_ClosePubScreen,
        AROS_LCA(char *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 8, MUIScreen    );
}

#define MUIS_ClosePubScreen(arg1) \
    __inline_MUIScreen_MUIS_ClosePubScreen((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline APTR __inline_MUIScreen_MUIS_OpenPubFile(char * __arg1, ULONG __arg2, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC2(APTR, MUIS_OpenPubFile,
        AROS_LCA(char *,(__arg1),A0),
        AROS_LCA(ULONG,(__arg2),D0),
        struct Library *, (__MUIScreenBase), 9, MUIScreen    );
}

#define MUIS_OpenPubFile(arg1, arg2) \
    __inline_MUIScreen_MUIS_OpenPubFile((arg1), (arg2), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline void __inline_MUIScreen_MUIS_ClosePubFile(APTR __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    AROS_LC1NR(void, MUIS_ClosePubFile,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 10, MUIScreen    );
}

#define MUIS_ClosePubFile(arg1) \
    __inline_MUIScreen_MUIS_ClosePubFile((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline struct MUI_PubScreenDesc* __inline_MUIScreen_MUIS_ReadPubFile(APTR __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC1(struct MUI_PubScreenDesc*, MUIS_ReadPubFile,
        AROS_LCA(APTR,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 11, MUIScreen    );
}

#define MUIS_ReadPubFile(arg1) \
    __inline_MUIScreen_MUIS_ReadPubFile((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline BOOL __inline_MUIScreen_MUIS_WritePubFile(APTR __arg1, struct MUI_PubScreenDesc * __arg2, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    return AROS_LC2(BOOL, MUIS_WritePubFile,
        AROS_LCA(APTR,(__arg1),A0),
        AROS_LCA(struct MUI_PubScreenDesc *,(__arg2),A1),
        struct Library *, (__MUIScreenBase), 12, MUIScreen    );
}

#define MUIS_WritePubFile(arg1, arg2) \
    __inline_MUIScreen_MUIS_WritePubFile((arg1), (arg2), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline void __inline_MUIScreen_MUIS_AddInfoClient(struct MUIS_InfoClient * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    AROS_LC1NR(void, MUIS_AddInfoClient,
        AROS_LCA(struct MUIS_InfoClient *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 13, MUIScreen    );
}

#define MUIS_AddInfoClient(arg1) \
    __inline_MUIScreen_MUIS_AddInfoClient((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#if !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__)

static inline void __inline_MUIScreen_MUIS_RemInfoClient(struct MUIS_InfoClient * __arg1, APTR __MUIScreenBase)
{
    AROS_LIBREQ(MUIScreenBase, 1)
    AROS_LC1NR(void, MUIS_RemInfoClient,
        AROS_LCA(struct MUIS_InfoClient *,(__arg1),A0),
        struct Library *, (__MUIScreenBase), 14, MUIScreen    );
}

#define MUIS_RemInfoClient(arg1) \
    __inline_MUIScreen_MUIS_RemInfoClient((arg1), __MUISCREEN_LIBBASE)

#endif /* !defined(__MUISCREEN_LIBAPI__) || (1 <= __MUISCREEN_LIBAPI__) */

#endif /* INLINE_MUISCREEN_H*/
