#ifndef _REGVAR_H
#define _REGVAR_H


/*
** a macro to define register parameters
*/
#ifdef __GNUC__

#define REGFUNC
#define REG( _reg, _var ) _var __asm(#_reg)

#elif __STORM__

#define REGFUNC
#define REG( _reg, _var ) register __##_reg _var

#elif __MAXON__

#define REGFUNC
#define REG( _reg, _var ) register __##_reg _var

#elif __SASC

#define REGFUNC __asm
#define REG( _reg, _var ) register __##_reg _var

#endif


#endif  /* _REGVAR_H */
