#include "library_base.h"
#include "compiler.h"

#define AQuote(string) #string								/* Put quotes around the whole thing */
#define AVersion(major,minor) AQuote(major ## . ## minor)	/* Concatenate the two version-numbers */
#define AmVersion(major,minor) AVersion(major,minor)		/* We need to do it this way to elimate the blank spaces */

#define LIB_NAME	"mpega.library"
#define LIB_VERSION	2
#define LIB_REVISION	4
#define LIB_DATE	"(17.03.04)"

#define CLONE_VERSION	1
#define CLONE_REVISION	7

#ifndef LIBCPU
	#if defined(BUILD_POWERUP)
		#define LIBCPU " [PowerUP]"
	#elif defined(BUILD_WARPUP)
		#define LIBCPU " [WarpOS]"
	#elif defined(BUILD_MORPHOS)
		#define LIBCPU " [MorphOS]"
	#elif defined(BUILD_OS4)
		#define LIBCPU " [AmigaOS4]"
	#else
		#if defined(_M68060) || defined(mc68060)
			#if defined(_M68881) || defined(__HAVE_68881__)
				#define LIBCPU " [060/FPU]"
			#else
				#define LIBCPU " [060]"
			#endif
		#elif defined(_M68040) || defined(mc68040)
			#if defined(_M68881) || defined(__HAVE_68881__)
				#define LIBCPU " [040/FPU]"
			#else
				#define LIBCPU " [040]"
			#endif
		#elif defined(_M68030) || defined(mc68030)
			#if defined(_M68881) || defined(__HAVE_68881__)
				#define LIBCPU " [030/FPU]"
			#else
				#define LIBCPU " [030]"
			#endif
		#elif defined(_M68020) || defined(mc68020)
			#if defined(_M68881) || defined(__HAVE_68881__)
				#define LIBCPU " [020/FPU]"
			#else
				#define LIBCPU " [020]"
			#endif
		#else
			#define LIBCPU
		#endif
	#endif
#endif

#define LIB_ID LIB_NAME " " AmVersion(LIB_VERSION,LIB_REVISION) " " LIB_DATE LIBCPU " mpega.library clone v" AmVersion(CLONE_VERSION,CLONE_REVISION) " by Sigbjørn (CISC) Skjæret, using libmad 0.15.1b - Copyright (C) 2000-2004 Underbit Technologies, Inc."


#include <libraries/mpega.h>

#ifdef __MORPHOS__

struct Library *LibInit(struct PrivateBase *PrivateBase, BPTR SegList, struct ExecBase *sysbase);
struct Library *LIB_Open(void);
BPTR LIB_Close(void);
BPTR LIB_Expunge(void);

MPEGA_STREAM *LIB_MPEGA_open(void);
void LIB_MPEGA_close(void);
LONG LIB_MPEGA_decode_frame(void);
LONG LIB_MPEGA_seek(void);
LONG LIB_MPEGA_time(void);
LONG LIB_MPEGA_find_sync(void);
LONG LIB_MPEGA_scale(void);

#else

#ifdef BUILD_OS4
#define __IFACE_OR_BASE		struct Interface *Self
#else
#define __IFACE_OR_BASE		struct PrivateBase *PrivateBase
#endif

#ifdef BUILD_OS4
struct Library * ASM LibInit(REG(d0, struct PrivateBase *PrivateBase), REG(a0, BPTR SegList), REG(a6, struct ExecIFace *pIExec));
#else
struct Library * ASM LibInit(REG(d0, struct PrivateBase *PrivateBase), REG(a0, BPTR SegList), REG(a6, struct ExecBase *sysbase));
#endif

struct Library * ASM LIB_Open(REG(a6, __IFACE_OR_BASE));
BPTR ASM LIB_Close(REG(a6, __IFACE_OR_BASE));
BPTR ASM LIB_Expunge(REG(a6, __IFACE_OR_BASE));

MPEGA_STREAM * LIB LIB_MPEGA_open(REG(a6, __IFACE_OR_BASE), REG(a0, char *stream_name), REG(a1, MPEGA_CTRL *ctrl), REG(a4, APTR a4base));
void LIB LIB_MPEGA_close(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a4, APTR a4base));
LONG LIB LIB_MPEGA_decode_frame(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a1, WORD **pcm), REG(a4, APTR a4base));
LONG LIB LIB_MPEGA_seek(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(d0, ULONG ms_time_position), REG(a4, APTR a4base));
LONG LIB LIB_MPEGA_time(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(a1, ULONG *ms_time_position));
LONG LIB LIB_MPEGA_find_sync(REG(a6, __IFACE_OR_BASE), REG(a0, UBYTE *buffer), REG(d0, LONG buffer_size));
LONG LIB LIB_MPEGA_scale(REG(a6, __IFACE_OR_BASE), REG(a0, MPEGA_STREAM *mpega_stream), REG(d0, LONG scale_percent));
#endif
