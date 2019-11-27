#ifndef INLINE_UUID_H
#define INLINE_UUID_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/uuid/uuid.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for uuid
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__UUID_LIBBASE)
#    define __UUID_LIBBASE UUIDBase
#endif


#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline int __inline_UUID_UUID_Compare(const uuid_t * __arg1, const uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    return AROS_LC2(int, UUID_Compare,
        AROS_LCA(const uuid_t *,(__arg1),A0),
        AROS_LCA(const uuid_t *,(__arg2),A1),
        struct Library *, (__UUIDBase), 5, UUID    );
}

#define UUID_Compare(arg1, arg2) \
    __inline_UUID_UUID_Compare((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_GetNameSpace(uuid_namespace_t __arg1, uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_GetNameSpace,
        AROS_LCA(uuid_namespace_t,(__arg1),D0),
        AROS_LCA(uuid_t *,(__arg2),A0),
        struct Library *, (__UUIDBase), 6, UUID    );
}

#define UUID_GetNameSpace(arg1, arg2) \
    __inline_UUID_UUID_GetNameSpace((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline int __inline_UUID_UUID_Parse(const char * __arg1, uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    return AROS_LC2(int, UUID_Parse,
        AROS_LCA(const char *,(__arg1),A0),
        AROS_LCA(uuid_t *,(__arg2),A1),
        struct Library *, (__UUIDBase), 7, UUID    );
}

#define UUID_Parse(arg1, arg2) \
    __inline_UUID_UUID_Parse((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Unparse(const uuid_t * __arg1, char * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_Unparse,
        AROS_LCA(const uuid_t *,(__arg1),A0),
        AROS_LCA(char *,(__arg2),A1),
        struct Library *, (__UUIDBase), 8, UUID    );
}

#define UUID_Unparse(arg1, arg2) \
    __inline_UUID_UUID_Unparse((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Pack(const uuid_t * __arg1, uint8_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_Pack,
        AROS_LCA(const uuid_t *,(__arg1),A0),
        AROS_LCA(uint8_t *,(__arg2),A1),
        struct Library *, (__UUIDBase), 9, UUID    );
}

#define UUID_Pack(arg1, arg2) \
    __inline_UUID_UUID_Pack((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Unpack(const uint8_t * __arg1, uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_Unpack,
        AROS_LCA(const uint8_t *,(__arg1),A0),
        AROS_LCA(uuid_t *,(__arg2),A1),
        struct Library *, (__UUIDBase), 10, UUID    );
}

#define UUID_Unpack(arg1, arg2) \
    __inline_UUID_UUID_Unpack((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Clear(uuid_t * __arg1, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC1NR(void, UUID_Clear,
        AROS_LCA(uuid_t *,(__arg1),A0),
        struct Library *, (__UUIDBase), 11, UUID    );
}

#define UUID_Clear(arg1) \
    __inline_UUID_UUID_Clear((arg1), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Copy(const uuid_t * __arg1, uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_Copy,
        AROS_LCA(const uuid_t *,(__arg1),A0),
        AROS_LCA(uuid_t *,(__arg2),A1),
        struct Library *, (__UUIDBase), 12, UUID    );
}

#define UUID_Copy(arg1, arg2) \
    __inline_UUID_UUID_Copy((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#if !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__)

static inline void __inline_UUID_UUID_Generate(uuid_type_t __arg1, uuid_t * __arg2, APTR __UUIDBase)
{
    AROS_LIBREQ(UUIDBase, 1)
    AROS_LC2NR(void, UUID_Generate,
        AROS_LCA(uuid_type_t,(__arg1),D0),
        AROS_LCA(uuid_t *,(__arg2),A0),
        struct Library *, (__UUIDBase), 13, UUID    );
}

#define UUID_Generate(arg1, arg2) \
    __inline_UUID_UUID_Generate((arg1), (arg2), __UUID_LIBBASE)

#endif /* !defined(__UUID_LIBAPI__) || (1 <= __UUID_LIBAPI__) */

#endif /* INLINE_UUID_H*/
