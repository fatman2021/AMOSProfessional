#ifndef DEFINES_BZ2_H
#define DEFINES_BZ2_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/external/bz2/bz2.conf'. Edits will be lost. ***
    Copyright � 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for bz2
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__BZ2_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__BZ2_NOLIBBASE__)
#    define __BZ2_LIBBASE __aros_getbase_BZ2Base()
#  else
#    define __BZ2_LIBBASE BZ2Base
#  endif
#endif

__BEGIN_DECLS


#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzlibVersion_WB(__BZ2Base) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC0(const char *, BZ2_bzlibVersion, \
        struct Library *, (__BZ2Base), 5, BZ2);\
})

#define BZ2_bzlibVersion() \
    __BZ2_bzlibVersion_WB(__BZ2_LIBBASE)

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzCompressInit_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC4(int, BZ2_bzCompressInit, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
                  AROS_LCA(int,(__arg3),D1), \
                  AROS_LCA(int,(__arg4),D2), \
        struct Library *, (__BZ2Base), 6, BZ2);\
})

#define BZ2_bzCompressInit(arg1, arg2, arg3, arg4) \
    __BZ2_bzCompressInit_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzCompress_WB(__BZ2Base, __arg1, __arg2) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC2(int, BZ2_bzCompress, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
        struct Library *, (__BZ2Base), 7, BZ2);\
})

#define BZ2_bzCompress(arg1, arg2) \
    __BZ2_bzCompress_WB(__BZ2_LIBBASE, (arg1), (arg2))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzCompressEnd_WB(__BZ2Base, __arg1) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC1(int, BZ2_bzCompressEnd, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
        struct Library *, (__BZ2Base), 8, BZ2);\
})

#define BZ2_bzCompressEnd(arg1) \
    __BZ2_bzCompressEnd_WB(__BZ2_LIBBASE, (arg1))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzDecompressInit_WB(__BZ2Base, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC3(int, BZ2_bzDecompressInit, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
                  AROS_LCA(int,(__arg3),D1), \
        struct Library *, (__BZ2Base), 9, BZ2);\
})

#define BZ2_bzDecompressInit(arg1, arg2, arg3) \
    __BZ2_bzDecompressInit_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzDecompress_WB(__BZ2Base, __arg1) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC1(int, BZ2_bzDecompress, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
        struct Library *, (__BZ2Base), 10, BZ2);\
})

#define BZ2_bzDecompress(arg1) \
    __BZ2_bzDecompress_WB(__BZ2_LIBBASE, (arg1))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzDecompressEnd_WB(__BZ2Base, __arg1) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC1(int, BZ2_bzDecompressEnd, \
                  AROS_LCA(bz_stream *,(__arg1),A0), \
        struct Library *, (__BZ2Base), 11, BZ2);\
})

#define BZ2_bzDecompressEnd(arg1) \
    __BZ2_bzDecompressEnd_WB(__BZ2_LIBBASE, (arg1))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzBuffToBuffCompress_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC7(int, BZ2_bzBuffToBuffCompress, \
                  AROS_LCA(char *,(__arg1),A0), \
                  AROS_LCA(unsigned int *,(__arg2),A1), \
                  AROS_LCA(char *,(__arg3),A2), \
                  AROS_LCA(unsigned int,(__arg4),D0), \
                  AROS_LCA(int,(__arg5),D1), \
                  AROS_LCA(int,(__arg6),D2), \
                  AROS_LCA(int,(__arg7),D3), \
        struct Library *, (__BZ2Base), 12, BZ2);\
})

#define BZ2_bzBuffToBuffCompress(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __BZ2_bzBuffToBuffCompress_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzBuffToBuffDecompress_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC6(int, BZ2_bzBuffToBuffDecompress, \
                  AROS_LCA(char *,(__arg1),A0), \
                  AROS_LCA(unsigned int *,(__arg2),A1), \
                  AROS_LCA(char *,(__arg3),A2), \
                  AROS_LCA(unsigned int,(__arg4),D0), \
                  AROS_LCA(int,(__arg5),D1), \
                  AROS_LCA(int,(__arg6),D2), \
        struct Library *, (__BZ2Base), 13, BZ2);\
})

#define BZ2_bzBuffToBuffDecompress(arg1, arg2, arg3, arg4, arg5, arg6) \
    __BZ2_bzBuffToBuffDecompress_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzReadOpen_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC6(BZFILE *, BZ2_bzReadOpen, \
                  AROS_LCA(int*,(__arg1),A0), \
                  AROS_LCA(FILE*,(__arg2),A1), \
                  AROS_LCA(int,(__arg3),D0), \
                  AROS_LCA(int,(__arg4),D1), \
                  AROS_LCA(void *,(__arg5),A2), \
                  AROS_LCA(int,(__arg6),D2), \
        struct Library *, (__BZ2Base), 30, BZ2);\
})

#define BZ2_bzReadOpen(arg1, arg2, arg3, arg4, arg5, arg6) \
    __BZ2_bzReadOpen_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzReadClose_WB(__BZ2Base, __arg1, __arg2) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC2NR(void, BZ2_bzReadClose, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE*,(__arg2),A1), \
        struct Library *, (__BZ2Base), 31, BZ2);\
})

#define BZ2_bzReadClose(arg1, arg2) \
    __BZ2_bzReadClose_WB(__BZ2_LIBBASE, (arg1), (arg2))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzReadGetUnused_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC4NR(void, BZ2_bzReadGetUnused, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE *,(__arg2),A1), \
                  AROS_LCA(void **,(__arg3),A2), \
                  AROS_LCA(int *,(__arg4),A3), \
        struct Library *, (__BZ2Base), 32, BZ2);\
})

#define BZ2_bzReadGetUnused(arg1, arg2, arg3, arg4) \
    __BZ2_bzReadGetUnused_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzRead_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC4(int, BZ2_bzRead, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE*,(__arg2),A1), \
                  AROS_LCA(void *,(__arg3),A2), \
                  AROS_LCA(int,(__arg4),D0), \
        struct Library *, (__BZ2Base), 33, BZ2);\
})

#define BZ2_bzRead(arg1, arg2, arg3, arg4) \
    __BZ2_bzRead_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzWriteOpen_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC5(BZFILE *, BZ2_bzWriteOpen, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(FILE *,(__arg2),A1), \
                  AROS_LCA(int,(__arg3),D0), \
                  AROS_LCA(int,(__arg4),D1), \
                  AROS_LCA(int,(__arg5),D2), \
        struct Library *, (__BZ2Base), 34, BZ2);\
})

#define BZ2_bzWriteOpen(arg1, arg2, arg3, arg4, arg5) \
    __BZ2_bzWriteOpen_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzWrite_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC4NR(void, BZ2_bzWrite, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE*,(__arg2),A1), \
                  AROS_LCA(void *,(__arg3),A2), \
                  AROS_LCA(int,(__arg4),D0), \
        struct Library *, (__BZ2Base), 35, BZ2);\
})

#define BZ2_bzWrite(arg1, arg2, arg3, arg4) \
    __BZ2_bzWrite_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzWriteClose_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC5NR(void, BZ2_bzWriteClose, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE *,(__arg2),A1), \
                  AROS_LCA(int,(__arg3),D0), \
                  AROS_LCA(unsigned int *,(__arg4),A2), \
                  AROS_LCA(unsigned int *,(__arg5),A3), \
        struct Library *, (__BZ2Base), 36, BZ2);\
})

#define BZ2_bzWriteClose(arg1, arg2, arg3, arg4, arg5) \
    __BZ2_bzWriteClose_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

#if !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__)

#define __BZ2_bzWriteClose64_WB(__BZ2Base, __arg1, __arg2, __arg3, __arg4, __arg5, __arg6, __arg7) ({\
        AROS_LIBREQ(BZ2Base,2)\
        AROS_LC7NR(void, BZ2_bzWriteClose64, \
                  AROS_LCA(int *,(__arg1),A0), \
                  AROS_LCA(BZFILE *,(__arg2),A1), \
                  AROS_LCA(int,(__arg3),D0), \
                  AROS_LCA(unsigned int *,(__arg4),A2), \
                  AROS_LCA(unsigned int *,(__arg5),A3), \
                  AROS_LCA(unsigned int *,(__arg6),A4), \
                  AROS_LCA(unsigned int *,(__arg7),D1), \
        struct Library *, (__BZ2Base), 37, BZ2);\
})

#define BZ2_bzWriteClose64(arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
    __BZ2_bzWriteClose64_WB(__BZ2_LIBBASE, (arg1), (arg2), (arg3), (arg4), (arg5), (arg6), (arg7))

#endif /* !defined(__BZ2_LIBAPI__) || (2 <= __BZ2_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_BZ2_H*/
