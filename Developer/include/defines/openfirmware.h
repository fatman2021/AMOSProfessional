#ifndef DEFINES_OPENFIRMWARE_H
#define DEFINES_OPENFIRMWARE_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/openfirmware/openfirmware.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for openfirmware
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__OPENFIRMWARE_LIBBASE)
#    define __OPENFIRMWARE_LIBBASE OpenFirmwareBase
#endif

__BEGIN_DECLS


#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_OpenKey_WB(__OpenFirmwareBase, __arg1) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC1(void *, OF_OpenKey, \
                  AROS_LCA(char *,(__arg1),A0), \
        APTR , (__OpenFirmwareBase), 1, Openfirmware);\
})

#define OF_OpenKey(arg1) \
    __OF_OpenKey_WB(__OPENFIRMWARE_LIBBASE, (arg1))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_CloseKey_WB(__OpenFirmwareBase, __arg1) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC1NR(void, OF_CloseKey, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__OpenFirmwareBase), 2, Openfirmware);\
})

#define OF_CloseKey(arg1) \
    __OF_CloseKey_WB(__OPENFIRMWARE_LIBBASE, (arg1))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_GetChild_WB(__OpenFirmwareBase, __arg1, __arg2) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC2(void *, OF_GetChild, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
        APTR , (__OpenFirmwareBase), 3, Openfirmware);\
})

#define OF_GetChild(arg1, arg2) \
    __OF_GetChild_WB(__OPENFIRMWARE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_FindProperty_WB(__OpenFirmwareBase, __arg1, __arg2) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC2(void *, OF_FindProperty, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(char *,(__arg2),A1), \
        APTR , (__OpenFirmwareBase), 4, Openfirmware);\
})

#define OF_FindProperty(arg1, arg2) \
    __OF_FindProperty_WB(__OPENFIRMWARE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_GetProperty_WB(__OpenFirmwareBase, __arg1, __arg2) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC2(void *, OF_GetProperty, \
                  AROS_LCA(void *,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
        APTR , (__OpenFirmwareBase), 5, Openfirmware);\
})

#define OF_GetProperty(arg1, arg2) \
    __OF_GetProperty_WB(__OPENFIRMWARE_LIBBASE, (arg1), (arg2))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_GetPropLen_WB(__OpenFirmwareBase, __arg1) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC1(uint32_t, OF_GetPropLen, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__OpenFirmwareBase), 6, Openfirmware);\
})

#define OF_GetPropLen(arg1) \
    __OF_GetPropLen_WB(__OPENFIRMWARE_LIBBASE, (arg1))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_GetPropValue_WB(__OpenFirmwareBase, __arg1) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC1(void *, OF_GetPropValue, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__OpenFirmwareBase), 7, Openfirmware);\
})

#define OF_GetPropValue(arg1) \
    __OF_GetPropValue_WB(__OPENFIRMWARE_LIBBASE, (arg1))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

#if !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__)

#define __OF_GetPropName_WB(__OpenFirmwareBase, __arg1) ({\
        AROS_LIBREQ(OpenFirmwareBase,0)\
        AROS_LC1(char *, OF_GetPropName, \
                  AROS_LCA(void *,(__arg1),A0), \
        APTR , (__OpenFirmwareBase), 8, Openfirmware);\
})

#define OF_GetPropName(arg1) \
    __OF_GetPropName_WB(__OPENFIRMWARE_LIBBASE, (arg1))

#endif /* !defined(__OPENFIRMWARE_LIBAPI__) || (0 <= __OPENFIRMWARE_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_OPENFIRMWARE_H*/
