/*
**      $VER: compiler.h 37.12 (29.6.97)
**
**      Compiler independent register (and SAS/C extensions) handling
**
**      (C) Copyright 1997 Andreas R. Kleinert
**      All Rights Reserved.
*/

/* 
	This is compiler.h to compile example.library with VBCC 0.5
*/

#define AND &&
#define OR ||

#ifdef VBCC
  #define d0 "d0"
  #define d1 "d1"
  #define d2 "d2"
  #define d3 "d3"
  #define d4 "d4"
  #define d5 "d5"
  #define d6 "d6"
  #define d7 "d7"
  #define a0 "a0"
  #define a1 "a1"
  #define a2 "a2"
  #define a3 "a3"
  #define a4 "a4"
  #define a5 "a5"
  #define a6 "a6"
  #define a7 "a7"
#endif

#ifdef VBCC
  #define REG(register) __reg(register)
/* VBCC ignore this switch */
  #define __aligned
  #define __asm
  #define __regargs
  #define __saveds
  #define __stdargs
#endif
