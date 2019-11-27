#ifndef INLINE_KEYMAP_H
#define INLINE_KEYMAP_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/keymap/keymap.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for keymap
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__KEYMAP_LIBBASE)
#    define __KEYMAP_LIBBASE KeymapBase
#endif


#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)

static inline void __inline_Keymap_SetKeyMapDefault(struct KeyMap * __arg1, APTR __KeymapBase)
{
    AROS_LIBREQ(KeymapBase, 36)
    AROS_LC1NR(void, SetKeyMapDefault,
        AROS_LCA(struct KeyMap *,(__arg1),A0),
        struct Library *, (__KeymapBase), 5, Keymap    );
}

#define SetKeyMapDefault(arg1) \
    __inline_Keymap_SetKeyMapDefault((arg1), __KEYMAP_LIBBASE)

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)

static inline struct KeyMap * __inline_Keymap_AskKeyMapDefault(APTR __KeymapBase)
{
    AROS_LIBREQ(KeymapBase, 36)
    return AROS_LC0(struct KeyMap *, AskKeyMapDefault,
        struct Library *, (__KeymapBase), 6, Keymap    );
}

#define AskKeyMapDefault() \
    __inline_Keymap_AskKeyMapDefault(__KEYMAP_LIBBASE)

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)

static inline WORD __inline_Keymap_MapRawKey(struct InputEvent * __arg1, STRPTR __arg2, LONG __arg3, struct KeyMap * __arg4, APTR __KeymapBase)
{
    AROS_LIBREQ(KeymapBase, 36)
    return AROS_LC4(WORD, MapRawKey,
        AROS_LCA(struct InputEvent *,(__arg1),A0),
        AROS_LCA(STRPTR,(__arg2),A1),
        AROS_LCA(LONG,(__arg3),D1),
        AROS_LCA(struct KeyMap *,(__arg4),A2),
        struct Library *, (__KeymapBase), 7, Keymap    );
}

#define MapRawKey(arg1, arg2, arg3, arg4) \
    __inline_Keymap_MapRawKey((arg1), (arg2), (arg3), (arg4), __KEYMAP_LIBBASE)

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)

static inline LONG __inline_Keymap_MapANSI(STRPTR __arg1, LONG __arg2, STRPTR __arg3, LONG __arg4, struct KeyMap * __arg5, APTR __KeymapBase)
{
    AROS_LIBREQ(KeymapBase, 36)
    return AROS_LC5(LONG, MapANSI,
        AROS_LCA(STRPTR,(__arg1),A0),
        AROS_LCA(LONG,(__arg2),D0),
        AROS_LCA(STRPTR,(__arg3),A1),
        AROS_LCA(LONG,(__arg4),D1),
        AROS_LCA(struct KeyMap *,(__arg5),A2),
        struct Library *, (__KeymapBase), 8, Keymap    );
}

#define MapANSI(arg1, arg2, arg3, arg4, arg5) \
    __inline_Keymap_MapANSI((arg1), (arg2), (arg3), (arg4), (arg5), __KEYMAP_LIBBASE)

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#endif /* INLINE_KEYMAP_H*/
