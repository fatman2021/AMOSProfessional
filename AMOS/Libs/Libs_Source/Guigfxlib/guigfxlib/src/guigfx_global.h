/*
 *      GuiGFX library globals
 *      © 1997 TEK neoscientists
 */

#ifndef _GUIGFX_GLOBAL_H
#define _GUIGFX_GLOBAL_H 1

#define AQuote(string) #string                                                          /* Put quotes around the whole thing */
#define AVersion(major,minor) AQuote(major ## . ## minor)       /* Concatenate the two version-strings */
#define AmVersion(major,minor) AVersion(major,minor)            /* We need to do it this way to elimate the blank spaces */

#define VERSION  20
#define REVISION  0
#define LIBVER AmVersion(VERSION,REVISION)
#define LIBNAME "guigfx.library"
#define LIBDATE "(26.04.2003)"

#ifdef __MORPHOS__
#define LIBTYPE " [MorphOS]"
#elif __amigaos4__
#define LIBTYPE " [AmigaOS4]"
#else
#define LIBTYPE
#endif

#ifdef __MORPHOS__
#define SAVE_DS
#define ASM
#define M68KREG(x)
#define LIBENT
#elif  __amigaos4__
#define SAVE_DS
#define ASM
#define M68KREG(x)
#define LIBENT
#else
#define SAVE_DS
#define ASM             __asm
#define M68KREG(x)  register __ ## x
#define LIBENT  SAVE_DS ASM
#endif

#include <exec/execbase.h>
#include <exec/resident.h>
#include <exec/initializers.h>
#include <exec/memory.h>

#include <dos/dosextens.h>

#include <proto/graphics.h>
#include <proto/utility.h>
#include <proto/exec.h>
#include <clib/macros.h>

#ifdef __MORPHOS__
#include <emul/emulinterface.h>
#include <emul/emulregs.h>
#include <public/proto/libamiga/amiga_protos.h>

#undef TurboCopyMem
#undef TurboFillMem
#define TurboCopyMem(src,dest,len) memcpy(dest,src,len)
#define TurboFillMem(mem,len,fill) memset(mem,fill,len)

#define FUNC_HOOK(ret, name, htype, hook, dtype, data, mtype, msg) \
        static ret name##_GATE(void); \
        static ret name##func(htype hook, dtype data, mtype msg); \
        struct EmulLibEntry name = { TRAP_LIB, 0, (void (*)(void))name##_GATE }; \
        static ret name##_GATE(void) { return (name##func((htype)REG_A0, (dtype)REG_A2, (mtype)REG_A1)); } \
        static ret name##func(htype hook, dtype data, mtype msg)
#define HOOKENTRY(name) (HOOKFUNC)&##name

#elif __amigaos4__

#undef TurboCopyMem
#undef TurboFillMem
#define TurboCopyMem(src,dest,len) memcpy(dest,src,len)
#define TurboFillMem(mem,len,fill) memset(mem,fill,len)

#define FUNC_HOOK(ret, name, htype, hook, dtype, data, mtype, msg) \
        ret name (htype hook, dtype data, mtype msg)
#define HOOKENTRY(name) (HOOKFUNC) name

#else

#include <clib/alib_protos.h>

#define FUNC_HOOK(ret, name, htype, hook, dtype, data, mtype, msg) \
        __asm __saveds ret name (register __a0 htype hook, register __a2 dtype data, register __a1 mtype msg)
#define HOOKENTRY(name) (HOOKFUNC) name

#endif

/*****************************************************************************/

#define RNG(b,x,t) MIN(MAX((b),(x)),(t))                /* clamp */


struct GuiGFXBase
{
        struct Library LibNode;
        struct ExecBase *ExecBase;
        BPTR LibSegment;
        struct SignalSemaphore LockSemaphore;
};


#include "guigfx_internal.h"
#include "guigfx_data.h"
#include "guigfx_libprotos.h"


#endif
