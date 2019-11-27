#ifndef INLINE_OPENFIRMWARE_H
#define INLINE_OPENFIRMWARE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/openfirmware/openfirmware.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for openfirmware
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__OPENFIRMWARE_LIBBASE)
#    define __OPENFIRMWARE_LIBBASE OpenFirmwareBase
#endif


#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void * __inline_Openfirmware_OF_OpenKey(char * __arg1, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC1(void *, OF_OpenKey,
        AROS_LCA(char *,(__arg1),A0),
        APTR , (__OpenFirmwareBase), 1, Openfirmware    );
}

#define OF_OpenKey(arg1) \
    __inline_Openfirmware_OF_OpenKey((arg1), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void __inline_Openfirmware_OF_CloseKey(void * __arg1, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    AROS_LC1NR(void, OF_CloseKey,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__OpenFirmwareBase), 2, Openfirmware    );
}

#define OF_CloseKey(arg1) \
    __inline_Openfirmware_OF_CloseKey((arg1), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void * __inline_Openfirmware_OF_GetChild(void * __arg1, void * __arg2, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC2(void *, OF_GetChild,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        APTR , (__OpenFirmwareBase), 3, Openfirmware    );
}

#define OF_GetChild(arg1, arg2) \
    __inline_Openfirmware_OF_GetChild((arg1), (arg2), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void * __inline_Openfirmware_OF_FindProperty(void * __arg1, char * __arg2, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC2(void *, OF_FindProperty,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(char *,(__arg2),A1),
        APTR , (__OpenFirmwareBase), 4, Openfirmware    );
}

#define OF_FindProperty(arg1, arg2) \
    __inline_Openfirmware_OF_FindProperty((arg1), (arg2), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void * __inline_Openfirmware_OF_GetProperty(void * __arg1, void * __arg2, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC2(void *, OF_GetProperty,
        AROS_LCA(void *,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        APTR , (__OpenFirmwareBase), 5, Openfirmware    );
}

#define OF_GetProperty(arg1, arg2) \
    __inline_Openfirmware_OF_GetProperty((arg1), (arg2), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline uint32_t __inline_Openfirmware_OF_GetPropLen(void * __arg1, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC1(uint32_t, OF_GetPropLen,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__OpenFirmwareBase), 6, Openfirmware    );
}

#define OF_GetPropLen(arg1) \
    __inline_Openfirmware_OF_GetPropLen((arg1), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline void * __inline_Openfirmware_OF_GetPropValue(void * __arg1, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC1(void *, OF_GetPropValue,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__OpenFirmwareBase), 7, Openfirmware    );
}

#define OF_GetPropValue(arg1) \
    __inline_Openfirmware_OF_GetPropValue((arg1), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

static inline char * __inline_Openfirmware_OF_GetPropName(void * __arg1, APTR __OpenFirmwareBase)
{
    AROS_LIBREQ(OpenFirmwareBase, 0)
    return AROS_LC1(char *, OF_GetPropName,
        AROS_LCA(void *,(__arg1),A0),
        APTR , (__OpenFirmwareBase), 8, Openfirmware    );
}

#define OF_GetPropName(arg1) \
    __inline_Openfirmware_OF_GetPropName((arg1), __OPENFIRMWARE_LIBBASE)

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#endif /* INLINE_OPENFIRMWARE_H*/
