#ifndef DEFINES_USBCLASS_H
#define DEFINES_USBCLASS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/usb/classes/usbclass.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for usbclass
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__USBCLASS_LIBBASE)
#    define __USBCLASS_LIBBASE UsbClsBase
#endif

__BEGIN_DECLS


#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

#define __usbGetAttrsA_WB(__UsbClsBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(UsbClsBase,1)\
        AROS_LC3(LONG, usbGetAttrsA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__UsbClsBase), 5, Usbclass);\
})

#define usbGetAttrsA(arg1, arg2, arg3) \
    __usbGetAttrsA_WB(__USBCLASS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbGetAttrs(arg1, arg2, ...) \
({ \
    const IPTR usbGetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbGetAttrsA((arg1), (arg2), (struct TagItem *)(usbGetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

#define __usbSetAttrsA_WB(__UsbClsBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(UsbClsBase,1)\
        AROS_LC3(LONG, usbSetAttrsA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(APTR,(__arg2),A0), \
                  AROS_LCA(struct TagItem *,(__arg3),A1), \
        struct Library *, (__UsbClsBase), 6, Usbclass);\
})

#define usbSetAttrsA(arg1, arg2, arg3) \
    __usbSetAttrsA_WB(__USBCLASS_LIBBASE, (arg1), (arg2), (arg3))

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbSetAttrs(arg1, arg2, ...) \
({ \
    const IPTR usbSetAttrsA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbSetAttrsA((arg1), (arg2), (struct TagItem *)(usbSetAttrsA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

#if !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__)

#define __usbDoMethodA_WB(__UsbClsBase, __arg1, __arg2) ({\
        AROS_LIBREQ(UsbClsBase,1)\
        AROS_LC2(SIPTR, usbDoMethodA, \
                  AROS_LCA(ULONG,(__arg1),D0), \
                  AROS_LCA(IPTR *,(__arg2),A1), \
        struct Library *, (__UsbClsBase), 7, Usbclass);\
})

#define usbDoMethodA(arg1, arg2) \
    __usbDoMethodA_WB(__USBCLASS_LIBBASE, (arg1), (arg2))

#if !defined(NO_INLINE_STDARG) && !defined(USBCLASS_NO_INLINE_STDARG)
#define usbDoMethod(arg1, ...) \
({ \
    const IPTR usbDoMethodA_args[] = { AROS_PP_VARIADIC_CAST2IPTR(__VA_ARGS__) };\
    usbDoMethodA((arg1), (IPTR *)(usbDoMethodA_args)); \
})
#endif /* !NO_INLINE_STDARG */

#endif /* !defined(__USBCLASS_LIBAPI__) || (1 <= __USBCLASS_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_USBCLASS_H*/
