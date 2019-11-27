#ifndef INLINE_DXTN_H
#define INLINE_DXTN_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/dxtn/dxtn.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for dxtn
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__DXTN_LIBBASE)
#    define __DXTN_LIBBASE DXTNBase
#endif


#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

static inline void __inline_DXTN_DXTN_CompressTex(GLint __arg1, GLint __arg2, GLint __arg3, const GLubyte * __arg4, GLenum __arg5, GLubyte * __arg6, GLint __arg7, APTR __DXTNBase)
{
    AROS_LIBREQ(DXTNBase, 1)
    AROS_LC7NR(void, DXTN_CompressTex,
        AROS_LCA(GLint,(__arg1),D0),
        AROS_LCA(GLint,(__arg2),D1),
        AROS_LCA(GLint,(__arg3),D2),
        AROS_LCA(const GLubyte *,(__arg4),A0),
        AROS_LCA(GLenum,(__arg5),D3),
        AROS_LCA(GLubyte *,(__arg6),A1),
        AROS_LCA(GLint,(__arg7),D4),
        struct Library *, (__DXTNBase), 5, DXTN    );
}

#define DXTN_CompressTex(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __inline_DXTN_DXTN_CompressTex((arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7), __DXTN_LIBBASE)

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

static inline void __inline_DXTN_DXT1_Fetch2DRGBTexel(GLint __arg1, const GLubyte * __arg2, GLint __arg3, GLint __arg4, GLvoid * __arg5, APTR __DXTNBase)
{
    AROS_LIBREQ(DXTNBase, 1)
    AROS_LC5NR(void, DXT1_Fetch2DRGBTexel,
        AROS_LCA(GLint,(__arg1),D0),
        AROS_LCA(const GLubyte *,(__arg2),A0),
        AROS_LCA(GLint,(__arg3),D1),
        AROS_LCA(GLint,(__arg4),D2),
        AROS_LCA(GLvoid *,(__arg5),A1),
        struct Library *, (__DXTNBase), 6, DXTN    );
}

#define DXT1_Fetch2DRGBTexel(arg1, arg2, arg3, arg4, arg5) \
    __inline_DXTN_DXT1_Fetch2DRGBTexel((arg1), (arg2), (arg3), (arg4), (arg5), __DXTN_LIBBASE)

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

static inline void __inline_DXTN_DXT1_Fetch2DRGBATexel(GLint __arg1, const GLubyte * __arg2, GLint __arg3, GLint __arg4, GLvoid * __arg5, APTR __DXTNBase)
{
    AROS_LIBREQ(DXTNBase, 1)
    AROS_LC5NR(void, DXT1_Fetch2DRGBATexel,
        AROS_LCA(GLint,(__arg1),D0),
        AROS_LCA(const GLubyte *,(__arg2),A0),
        AROS_LCA(GLint,(__arg3),D1),
        AROS_LCA(GLint,(__arg4),D2),
        AROS_LCA(GLvoid *,(__arg5),A1),
        struct Library *, (__DXTNBase), 7, DXTN    );
}

#define DXT1_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __inline_DXTN_DXT1_Fetch2DRGBATexel((arg1), (arg2), (arg3), (arg4), (arg5), __DXTN_LIBBASE)

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

static inline void __inline_DXTN_DXT3_Fetch2DRGBATexel(GLint __arg1, const GLubyte * __arg2, GLint __arg3, GLint __arg4, GLvoid * __arg5, APTR __DXTNBase)
{
    AROS_LIBREQ(DXTNBase, 1)
    AROS_LC5NR(void, DXT3_Fetch2DRGBATexel,
        AROS_LCA(GLint,(__arg1),D0),
        AROS_LCA(const GLubyte *,(__arg2),A0),
        AROS_LCA(GLint,(__arg3),D1),
        AROS_LCA(GLint,(__arg4),D2),
        AROS_LCA(GLvoid *,(__arg5),A1),
        struct Library *, (__DXTNBase), 8, DXTN    );
}

#define DXT3_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __inline_DXTN_DXT3_Fetch2DRGBATexel((arg1), (arg2), (arg3), (arg4), (arg5), __DXTN_LIBBASE)

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#if !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__)

static inline void __inline_DXTN_DXT5_Fetch2DRGBATexel(GLint __arg1, const GLubyte * __arg2, GLint __arg3, GLint __arg4, GLvoid * __arg5, APTR __DXTNBase)
{
    AROS_LIBREQ(DXTNBase, 1)
    AROS_LC5NR(void, DXT5_Fetch2DRGBATexel,
        AROS_LCA(GLint,(__arg1),D0),
        AROS_LCA(const GLubyte *,(__arg2),A0),
        AROS_LCA(GLint,(__arg3),D1),
        AROS_LCA(GLint,(__arg4),D2),
        AROS_LCA(GLvoid *,(__arg5),A1),
        struct Library *, (__DXTNBase), 9, DXTN    );
}

#define DXT5_Fetch2DRGBATexel(arg1, arg2, arg3, arg4, arg5) \
    __inline_DXTN_DXT5_Fetch2DRGBATexel((arg1), (arg2), (arg3), (arg4), (arg5), __DXTN_LIBBASE)

#endif /* !defined(__DXTN_LIBAPI__) || (1 <= __DXTN_LIBAPI__) */

#endif /* INLINE_DXTN_H*/
