#ifndef INLINE_USBCLASS_H
#define INLINE_USBCLASS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/usb/classes/usbclass.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for usbclass
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__USBCLASS_LIBBASE)
#    define __USBCLASS_LIBBASE UsbClsBase
#endif


#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

static inline LONG __inline_Usbclass_usbGetAttrsA(ULONG __arg1, APTR __arg2, struct TagItem * __arg3, APTR __UsbClsBase)
{
    AROS_LIBREQ(UsbClsBase, 1)
    return AROS_LC3(LONG, usbGetAttrsA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__UsbClsBase), 5, Usbclass    );
}

#define usbGetAttrsA(arg1, arg2, arg3) \
    __inline_Usbclass_usbGetAttrsA((arg1), (arg2), (arg3), __USBCLASS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbGetAttrs(arg1, arg2, ...) \
({ \
    const IPTR usbGetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbGetAttrsA((arg1), (arg2), (struct TagItem *)(usbGetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

static inline LONG __inline_Usbclass_usbSetAttrsA(ULONG __arg1, APTR __arg2, struct TagItem * __arg3, APTR __UsbClsBase)
{
    AROS_LIBREQ(UsbClsBase, 1)
    return AROS_LC3(LONG, usbSetAttrsA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(APTR,(__arg2),A0),
        AROS_LCA(struct TagItem *,(__arg3),A1),
        struct Library *, (__UsbClsBase), 6, Usbclass    );
}

#define usbSetAttrsA(arg1, arg2, arg3) \
    __inline_Usbclass_usbSetAttrsA((arg1), (arg2), (arg3), __USBCLASS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbSetAttrs(arg1, arg2, ...) \
({ \
    const IPTR usbSetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbSetAttrsA((arg1), (arg2), (struct TagItem *)(usbSetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

static inline SIPTR __inline_Usbclass_usbDoMethodA(ULONG __arg1, IPTR * __arg2, APTR __UsbClsBase)
{
    AROS_LIBREQ(UsbClsBase, 1)
    return AROS_LC2(SIPTR, usbDoMethodA,
        AROS_LCA(ULONG,(__arg1),D0),
        AROS_LCA(IPTR *,(__arg2),A1),
        struct Library *, (__UsbClsBase), 7, Usbclass    );
}

#define usbDoMethodA(arg1, arg2) \
    __inline_Usbclass_usbDoMethodA((arg1), (arg2), __USBCLASS_LIBBASE)

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbDoMethod(arg1, ...) \
({ \
    const IPTR usbDoMethodA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbDoMethodA((arg1), (IPTR *)(usbDoMethodA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

#endif /* INLINE_USBCLASS_H*/
