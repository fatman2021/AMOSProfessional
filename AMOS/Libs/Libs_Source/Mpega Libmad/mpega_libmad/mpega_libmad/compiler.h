#ifndef COMPILER_H
#define COMPILER_H

#ifdef __amigaos4__
#define REG(reg,arg) arg
#define ASM
#define LIBPPC
#define LIB
#else
#ifdef __GNUC__
#ifdef __MORPHOS__
#include <emul/emulinterface.h>
#include <emul/emulregs.h>
#include <ppcinline/exec.h>
#define LIBPPC
#elif defined(__STORMGCC__)
#define REG(reg,arg) arg __asm(#reg)
#define LIB __saveds
#define ASM
#ifdef __PPC__
#define LIBPPC __saveds
#else
#define LIBPPC
#endif
#else
#define REG(reg,arg) arg __asm(#reg)
#define LIB __saveds
#define ASM
#define LIBPPC
#endif
#else
#define REG(reg,arg) register __ ## reg arg
#define LIB __saveds __asm
#define ASM __asm
#define LIBPPC
#endif
#endif

#endif
