#ifndef CLIB_STDCIO_PROTOS_H
#define CLIB_STDCIO_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/compiler/stdc/stdcio.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <libraries/stdcio.h>

#define _STDIO_H_NOMACRO
#include <stdio.h>

__BEGIN_DECLS


#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef __stdcio_assert
void __stdcio_assert(const char *, const char *file, unsigned int line);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef remove
int remove(const char *filename);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef rename
int rename(const char *old, const char *new);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef tmpfile
FILE * tmpfile(void);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef tmpnam
char * tmpnam(char *s);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fclose
int fclose(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fflush
int fflush(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fopen
FILE * fopen(const char * restrict filename, const char * restrict mode);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef freopen
FILE * freopen(const char * restrict filename, const char * restrict mode, FILE * restrict stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef setbuf
void setbuf(FILE * restrict stream, char * restrict buf);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef setvbuf
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fprintf
int fprintf(FILE * restrict stream, const char * restrict format, ...);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fscanf
int fscanf(FILE * restrict stream, const char * restrict format, ...);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef printf
int printf(const char * restrict format, ...);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef scanf
int scanf(const char * restrict format, ...);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef vfprintf
int vfprintf(FILE * restrict stream, const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef vfscanf
int vfscanf(FILE * restrict stream, const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef vprintf
int vprintf(const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef vscanf
int vscanf(const char * restrict format, va_list arg);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fgetc
int fgetc(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fgets
char * fgets(char * restrict s, int n, FILE * restrict stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fputc
int fputc(int c, FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fputs
int fputs(const char * restrict s, FILE * restrict stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef getchar
int getchar(void);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef gets
char * gets(char *s);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef putchar
int putchar(int c);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef puts
int puts(const char *s);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef ungetc
int ungetc(int c, FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fread
size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fwrite
size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fgetpos
int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fseek
int fseek(FILE *stream, long int offset, int whence);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef fsetpos
int fsetpos(FILE *stream, const fpos_t *pos);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef ftell
long int ftell(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef rewind
void rewind(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef clearerr
void clearerr(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef feof
int feof(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef ferror
int ferror(FILE *stream);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef getenv
char * getenv(const char *name);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

#if !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__)
#ifndef system
int system(const char *string);
#endif

#endif /* !defined(__STDCIO_LIBAPI__) || (0 <= __STDCIO_LIBAPI__) */

__END_DECLS

#endif /* CLIB_STDCIO_PROTOS_H */
