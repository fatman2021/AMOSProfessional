#ifndef CLIB_STDC_PROTOS_H
#define CLIB_STDC_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/compiler/stdc/stdc.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <libraries/stdc.h>
#include <setjmp.h>
#include <complex.h>
#include <fenv.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#ifdef __GNUC__
#undef cimag
#undef cimagf
#undef cimagl
#undef creal
#undef crealf
#undef creall
#endif

/* Avoid warning for redefinition of isinf()/isnan() */
#define STDC_NOLIBINLINE
#define STDC_NOLIBDEFINES


__BEGIN_DECLS


#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_gmtoffset
int __stdc_gmtoffset(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_program_startup
void __stdc_program_startup(jmp_buf exitjmp, int *errorptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_program_end
void __stdc_program_end(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_set_errorptr
int * __stdc_set_errorptr(int *errorptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_get_errorptr
int * __stdc_get_errorptr(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_set_exitjmp
void __stdc_set_exitjmp(jmp_buf exitjmp, jmp_buf previousjmp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_jmp2exit
void __stdc_jmp2exit(int normal, int returncode);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_set_fpuprivate
void * __stdc_set_fpuprivate(void *fpuprivate);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_get_fpuprivate
void * __stdc_get_fpuprivate(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_get_fe_dfl
void * __stdc_get_fe_dfl(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_get_fe_nom
void * __stdc_get_fe_nom(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_get_fe_round
int __stdc_get_fe_round(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __assert
void __assert(const char * expr, const char * file, unsigned int line);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacos
double complex cacos(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacosf
float complex cacosf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacosl
long double complex cacosl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casin
double complex casin(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casinf
float complex casinf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casinl
long double complex casinl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catan
double complex catan(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catanf
float complex catanf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catanl
long double complex catanl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccos
double complex ccos(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccosf
float complex ccosf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccosl
long double complex ccosl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csin
double complex csin(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csinf
float complex csinf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csinl
long double complex csinl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctan
double complex ctan(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctanf
float complex ctanf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctanl
long double complex ctanl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacosh
double complex cacosh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacoshf
float complex cacoshf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cacoshl
long double complex cacoshl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casinh
double complex casinh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casinhf
float complex casinhf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef casinhl
long double complex casinhl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catanh
double complex catanh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catanhf
float complex catanhf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef catanhl
long double complex catanhl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccosh
double complex ccosh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccoshf
float complex ccoshf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ccoshl
long double complex ccoshl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csinh
double complex csinh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csinhf
float complex csinhf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csinhl
long double complex csinhl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctanh
double complex ctanh(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctanhf
float complex ctanhf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctanhl
long double complex ctanhl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cexp
double complex cexp(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cexpf
float complex cexpf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cexpl
long double complex cexpl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef clog
double complex clog(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef clogf
float complex clogf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef clogl
long double complex clogl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cabs
double cabs(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cabsf
float cabsf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cabsl
long double cabsl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cpow
double complex cpow(double complex x, double complex y);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cpowf
float complex cpowf(float complex x, float complex y);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cpowl
long double complex cpowl(long double complex x, long double complex y);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csqrt
double complex csqrt(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csqrtf
float complex csqrtf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef csqrtl
long double complex csqrtl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef carg
double carg(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cargf
float cargf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cargl
long double cargl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cimag
double cimag(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cimagf
float cimagf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cimagl
long double cimagl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef conj
double complex conj(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef conjf
float complex conjf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef conjl
long double complex conjl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cproj
double complex cproj(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cprojf
float complex cprojf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cprojl
long double complex cprojl(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef creal
double creal(double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef crealf
float crealf(float complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef creall
long double creall(long double complex z);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_ioerr2errno
int __stdc_ioerr2errno(int ioerr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef feclearexcept
int feclearexcept(int excepts);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fegetexceptflag
int fegetexceptflag(fexcept_t *flagp, int excepts);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef feraiseexcept
int feraiseexcept(int excepts);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fesetexceptflag
int fesetexceptflag(const fexcept_t *flagp, int excepts);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fetestexcept
int fetestexcept(int excepts);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fegetround
int fegetround(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fesetround
int fesetround(int round);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fegetenv
int fegetenv(fenv_t *envp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef feholdexcept
int feholdexcept(fenv_t *envp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fesetenv
int fesetenv(const fenv_t *envp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef feupdateenv
int feupdateenv(const fenv_t *envp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef imaxabs
intmax_t imaxabs(intmax_t j);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef imaxdiv
imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtoimax
intmax_t strtoimax(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtoumax
uintmax_t strtoumax(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef setlocale
char * setlocale(int category, const char *locale);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef localeconv
struct lconv * localeconv(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __fpclassifyd
int __fpclassifyd(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __fpclassifyf
int __fpclassifyf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __fpclassifyl
int __fpclassifyl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isfinite
int __isfinite(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isfinitef
int __isfinitef(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isfinitel
int __isfinitel(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isinf
int __isinf(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isinff
int __isinff(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isinfl
int __isinfl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnan
int __isnan(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnanf
int __isnanf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnanl
int __isnanl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnormal
int __isnormal(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnormalf
int __isnormalf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __isnormall
int __isnormall(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __signbit
int __signbit(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __signbitf
int __signbitf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __signbitl
int __signbitl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acos
double acos(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asin
double asin(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atan
double atan(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atan2
double atan2(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cos
double cos(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sin
double sin(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tan
double tan(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acosh
double acosh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asinh
double asinh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atanh
double atanh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cosh
double cosh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sinh
double sinh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tanh
double tanh(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef exp
double exp(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef exp2
double exp2(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef expm1
double expm1(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef frexp
double frexp(double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ilogb
int ilogb(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ldexp
double ldexp(double, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log
double log(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log10
double log10(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log1p
double log1p(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log2
double log2(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef logb
double logb(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef modf
double modf(double, double *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalbn
double scalbn(double, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalbln
double scalbln(double, long);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cbrt
double cbrt(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fabs
double fabs(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef hypot
double hypot(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef pow
double pow(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sqrt
double sqrt(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erf
double erf(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erfc
double erfc(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgamma
double lgamma(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tgamma
double tgamma(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ceil
double ceil(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef floor
double floor(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nearbyint
double nearbyint(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef rint
double rint(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lrint
long lrint(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llrint
long long llrint(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef round
double round(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lround
long lround(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llround
long long llround(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef trunc
double trunc(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmod
double fmod(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remainder
double remainder(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remquo
double remquo(double, double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef copysign
double copysign(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nan
double nan(const char *tagp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nextafter
double nextafter(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nexttoward
double nexttoward(double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fdim
double fdim(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmax
double fmax(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmin
double fmin(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fma
double fma(double, double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acosf
float acosf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asinf
float asinf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atanf
float atanf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atan2f
float atan2f(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cosf
float cosf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sinf
float sinf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tanf
float tanf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acoshf
float acoshf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asinhf
float asinhf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atanhf
float atanhf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef coshf
float coshf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sinhf
float sinhf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tanhf
float tanhf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef expf
float expf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef exp2f
float exp2f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef expm1f
float expm1f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef frexpf
float frexpf(float, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ilogbf
int ilogbf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ldexpf
float ldexpf(float, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef logf
float logf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log10f
float log10f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log1pf
float log1pf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log2f
float log2f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef logbf
float logbf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef modff
float modff(float, float *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalbnf
float scalbnf(float, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalblnf
float scalblnf(float, long);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cbrtf
float cbrtf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fabsf
float fabsf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef hypotf
float hypotf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef powf
float powf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sqrtf
float sqrtf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erff
float erff(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erfcf
float erfcf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgammaf
float lgammaf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tgammaf
float tgammaf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ceilf
float ceilf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef floorf
float floorf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nearbyintf
float nearbyintf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef rintf
float rintf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lrintf
long lrintf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llrintf
long long llrintf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef roundf
float roundf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lroundf
long lroundf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llroundf
long long llroundf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef truncf
float truncf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmodf
float fmodf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remainderf
float remainderf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remquof
float remquof(float, float, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef copysignf
float copysignf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nanf
float nanf(const char *tagp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nextafterf
float nextafterf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nexttowardf
float nexttowardf(float, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fdimf
float fdimf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmaxf
float fmaxf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fminf
float fminf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmaf
float fmaf(float, float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acosl
long double acosl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asinl
long double asinl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atanl
long double atanl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atan2l
long double atan2l(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cosl
long double cosl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sinl
long double sinl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tanl
long double tanl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef acoshl
long double acoshl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asinhl
long double asinhl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atanhl
long double atanhl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef coshl
long double coshl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sinhl
long double sinhl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tanhl
long double tanhl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef expl
long double expl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef exp2l
long double exp2l(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef expm1l
long double expm1l(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef frexpl
long double frexpl(long double value, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ilogbl
int ilogbl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ldexpl
long double ldexpl(long double, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef logl
long double logl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log10l
long double log10l(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log1pl
long double log1pl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef log2l
long double log2l(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef logbl
long double logbl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef modfl
long double modfl(long double, long double *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalbnl
long double scalbnl(long double, int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalblnl
long double scalblnl(long double, long);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef cbrtl
long double cbrtl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fabsl
long double fabsl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef hypotl
long double hypotl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef powl
long double powl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sqrtl
long double sqrtl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erfl
long double erfl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef erfcl
long double erfcl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgammal
long double lgammal(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef tgammal
long double tgammal(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ceill
long double ceill(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef floorl
long double floorl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nearbyintl
long double nearbyintl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef rintl
long double rintl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lrintl
long lrintl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llrintl
long long llrintl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef roundl
long double roundl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lroundl
long lroundl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llroundl
long long llroundl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef truncl
long double truncl(long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmodl
long double fmodl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remainderl
long double remainderl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef remquol
long double remquol(long double, long double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef copysignl
long double copysignl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nanl
long double nanl(const char *tagp);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nextafterl
long double nextafterl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef nexttowardl
long double nexttowardl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fdiml
long double fdiml(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmaxl
long double fmaxl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fminl
long double fminl(long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef fmal
long double fmal(long double, long double, long double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef setjmp
int setjmp(jmp_buf env);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef longjmp
void longjmp(jmp_buf env, int val);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef signal
__sighandler_t * signal(int, __sighandler_t *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef raise
int raise(int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef snprintf
int snprintf(char * restrict s, size_t n, const char * restrict format, ...);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sprintf
int sprintf(char * restrict s, const char * restrict format, ...);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sscanf
int sscanf(const char * restrict s, const char * restrict format, ...);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef vsnprintf
int vsnprintf(char * restrict s, size_t n, const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef vsprintf
int vsprintf(char * restrict s, const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef vsscanf
int vsscanf(const char * restrict s, const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atof
double atof(const char *nptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atoi
int atoi(const char *nptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atol
long int atol(const char *nptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atoll
long long int atoll(const char *nptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtod
double strtod(const char * restrict nptr, char ** restrict endptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtof
float strtof(const char * restrict nptr, char ** restrict endptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtold
long double strtold(const char * restrict nptr, char ** restrict endptr);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtol
long int strtol(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtoll
long long int strtoll(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtoul
unsigned long int strtoul(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtoull
unsigned long long int strtoull(const char * restrict nptr, char ** restrict endptr, int base);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef rand
int rand(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef srand
void srand(unsigned int seed);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef calloc
void * calloc(size_t count, size_t size);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef free
void free(void *memory);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef malloc
void * malloc(size_t size);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef malloc_align
void * malloc_align(size_t size, size_t alignment);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef realloc
void * realloc(void *oldmem, size_t newsize);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef realloc_nocopy
void * realloc_nocopy(void *oldmem, size_t newsize);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef abort
void abort(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef atexit
int atexit(void (*func)(void));
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef on_exit
int on_exit(void (*func)(int, void *), void *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef exit
void exit(int code);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef _Exit
void _Exit(int);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef bsearch
void * bsearch(const void * key, const void * base, size_t count, size_t size, int (*comparefunction)(const void *, const void *));
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef qsort
void qsort(void * array, size_t count, size_t elementsize, int (*comparefunction)(const void * element1, const void * element2));
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef abs
int abs(int j);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef labs
long labs(long j);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef llabs
long long llabs(long long j);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef div
div_t div(int numer, int denom);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ldiv
ldiv_t ldiv(long int numer, long int denom);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lldiv
lldiv_t lldiv(long long int numer, long long int denom);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef mblen
int mblen(const char *s, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef memmove
void * memmove(void * dest, const void * src, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcpy
char * strcpy(char * restrict dest, const char * restrict src);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strncpy
char * strncpy(char * restrict dest, const char * restrict src, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcat
char * strcat(char * restrict dest, const char * restrict src);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strncat
char * strncat(char * restrict dest, const char * restrict src, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef memcmp
int memcmp(const void * s1, const void * s2, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcmp
int strcmp(const char * s1, const char * s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcoll
int strcoll(const char *s1, const char *s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strncmp
int strncmp(const char * s1, const char * s2, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strxfrm
size_t strxfrm(char * restrict s1, const char * restrict s2, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef memchr
void * memchr(const void * dest, int c, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strchr
char * strchr(const char * s, int c);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcspn
size_t strcspn(const char *s1, const char *s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strpbrk
char * strpbrk(const char * s1, const char * s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strrchr
char * strrchr(const char * s, int c);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strspn
size_t strspn(const char * s1, const char * s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strstr
char * strstr(const char * buf, const char * str);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtok
char * strtok(char * str, const char * sep);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef memset
void * memset(void * dest, int c, size_t n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __stdc_strerror
char * __stdc_strerror(int n);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strlen
size_t strlen(const char * str);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef clock
clock_t clock(void);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef difftime
double difftime(time_t, time_t);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef mktime
time_t mktime(struct tm *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef time
time_t time(time_t *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asctime
char * asctime(const struct tm *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctime
char * ctime(const time_t *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef gmtime
struct tm * gmtime(const time_t *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef localtime
struct tm * localtime(const time_t *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strftime
size_t strftime(char *, size_t, const char *, const struct tm *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef j0
double j0(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef j1
double j1(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef jn
double jn(int, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalb
double scalb(double, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef y0
double y0(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef y1
double y1(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef yn
double yn(int, double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef gamma_r
double gamma_r(double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgamma_r
double lgamma_r(double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sincos
void sincos(double, double *, double *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef significand
double significand(double);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef j0f
float j0f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef j1f
float j1f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef jnf
float jnf(int, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef scalbf
float scalbf(float, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef y0f
float y0f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef y1f
float y1f(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ynf
float ynf(int, float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef gammaf_r
float gammaf_r(float, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgammaf_r
float lgammaf_r(float, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sincosf
void sincosf(float, float *, float *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef significandf
float significandf(float);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef lgammal_r
long double lgammal_r(long double, int *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef sincosl
void sincosl(long double, long double *, long double *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __vcformat
int __vcformat(void * data, int (*outc)(int, void *), const char * format, va_list args);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef __vcscan
int __vcscan(void * data, int (*getc)(void *), int (*ungetc)(int, void *), const char * format, va_list args);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stpcpy
char * stpcpy(char *restrict, const char *restrict);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strdup
char * strdup(const char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strndup
char * strndup(const char *, size_t);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strnlen
size_t strnlen(const char *, size_t);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strtok_r
char * strtok_r(char *restrict, const char *restrict, char **restrict);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strlcpy
size_t strlcpy(char *dst, const char *src, size_t size);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strlcat
size_t strlcat(char *dst, const char *src, size_t size);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strsep
char * strsep(char **, const char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strlwr
char * strlwr(char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strupr
char * strupr(char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strrev
char * strrev(char * s);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stch_l
int stch_l(const char * in, long * lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stcd_l
int stcd_l(const char * in, long * lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stco_l
int stco_l(const char * in, long * lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stcl_d
int stcl_d(char * out, long lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stcl_h
int stcl_h(char * out, long lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stcl_o
int stcl_o(char * out, long lvalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stcu_d
int stcu_d(char * out, unsigned uivalue);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stccpy
size_t stccpy(char *str1_ptr, const char *str2_ptr, size_t max);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stpsym
char * stpsym(char *str_ptr, char *dest_ptr, int dest_size);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef stpblk
char * stpblk(const char * str);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strcasecmp
int strcasecmp(const char * s1, const char * s2);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef strncasecmp
int strncasecmp(const char *, const char *, size_t);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef asctime_r
char * asctime_r(const struct tm *, char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef ctime_r
char * ctime_r(const time_t *, char *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef gmtime_r
struct tm * gmtime_r(const time_t *, struct tm *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

#if !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__)
#ifndef localtime_r
struct tm * localtime_r(const time_t *, struct tm *);
#endif

#endif /* !defined(__STDC_LIBAPI__) || (0 <= __STDC_LIBAPI__) */

__END_DECLS

#endif /* CLIB_STDC_PROTOS_H */
