#ifndef DEFINES_DXTN_H
#define DEFINES_DXTN_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/dxtn/dxtn.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for dxtn
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DXTN_LIBBASE)
#    define __DXTN_LIBBASE DXTNBase
#endif

__BEGIN_DECLS


#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

#define __DXTN_CompressTex_WB(__DXTNBase, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(DXTNBase,1)\
        AROS_LC7NR(void, DXTN_CompressTex, \
                  AROS_LCA(GLint,(__arg1),D0), \
                  AROS_LCA(GLint,(__arg2),D1), \
                  AROS_LCA(GLint,(__arg3),D2), \
                  AROS_LCA(const GLubyte *,(__arg4),A0), \
                  AROS_LCA(GLenum,(__arg5),D3), \
                  AROS_LCA(GLubyte *,(__arg6),A1), \
                  AROS_LCA(GLint,(__arg7),D4), \
        struct Library *, (__DXTNBase), 5, DXTN);\
})

#define DXTN_CompressTex(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __DXTN_CompressTex_WB(__DXTN_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

#define __DXT1_Fetch2DRGBTexel_WB(__DXTNBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DXTNBase,1)\
        AROS_LC5NR(void, DXT1_Fetch2DRGBTexel, \
                  AROS_LCA(GLint,(__arg1),D0), \
                  AROS_LCA(const GLubyte *,(__arg2),A0), \
                  AROS_LCA(GLint,(__arg3),D1), \
                  AROS_LCA(GLint,(__arg4),D2), \
                  AROS_LCA(GLvoid *,(__arg5),A1), \
        struct Library *, (__DXTNBase), 6, DXTN);\
})

#define DXT1_Fetch2DRGBTexel(arg1, arg2, arg3, arg4, arg5) \
    __DXT1_Fetch2DRGBTexel_WB(__DXTN_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

#define __DXT1_Fetch2DRGBATexel_WB(__DXTNBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DXTNBase,1)\
        AROS_LC5NR(void, DXT1_Fetch2DRGBATexel, \
                  AROS_LCA(GLint,(__arg1),D0), \
                  AROS_LCA(const GLubyte *,(__arg2),A0), \
                  AROS_LCA(GLint,(__arg3),D1), \
                  AROS_LCA(GLint,(__arg4),D2), \
                  AROS_LCA(GLvoid *,(__arg5),A1), \
        struct Library *, (__DXTNBase), 7, DXTN);\
})

#define DXT1_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __DXT1_Fetch2DRGBATexel_WB(__DXTN_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

#define __DXT3_Fetch2DRGBATexel_WB(__DXTNBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DXTNBase,1)\
        AROS_LC5NR(void, DXT3_Fetch2DRGBATexel, \
                  AROS_LCA(GLint,(__arg1),D0), \
                  AROS_LCA(const GLubyte *,(__arg2),A0), \
                  AROS_LCA(GLint,(__arg3),D1), \
                  AROS_LCA(GLint,(__arg4),D2), \
                  AROS_LCA(GLvoid *,(__arg5),A1), \
        struct Library *, (__DXTNBase), 8, DXTN);\
})

#define DXT3_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __DXT3_Fetch2DRGBATexel_WB(__DXTN_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

#define __DXT5_Fetch2DRGBATexel_WB(__DXTNBase, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(DXTNBase,1)\
        AROS_LC5NR(void, DXT5_Fetch2DRGBATexel, \
                  AROS_LCA(GLint,(__arg1),D0), \
                  AROS_LCA(const GLubyte *,(__arg2),A0), \
                  AROS_LCA(GLint,(__arg3),D1), \
                  AROS_LCA(GLint,(__arg4),D2), \
                  AROS_LCA(GLvoid *,(__arg5),A1), \
        struct Library *, (__DXTNBase), 9, DXTN);\
})

#define DXT5_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __DXT5_Fetch2DRGBATexel_WB(__DXTN_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_DXTN_H*/
