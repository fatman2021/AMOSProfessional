#ifndef CLIB_POSIXC_PROTOS_H
#define CLIB_POSIXC_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/compiler/posixc/posixc.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <libraries/posixc.h>
#include <stdlib.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/resource.h>
#include <sys/mount.h>
#include <sys/time.h>
#include <sys/times.h>
#include <signal.h>
#include <regex.h>
#include <sys/utsname.h>
#include <termios.h>
#include <utime.h>

#undef __assert /* We replace the aroscstddos __assert with our own */

__BEGIN_DECLS


#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_nixmain
int __posixc_nixmain(int (*main)(int argc, char *argv[]), int argc, char *argv[]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_assert
void __posixc_assert(const char *, const char *, unsigned int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef alphasort
int alphasort(const struct dirent **a, const struct dirent **b);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef closedir
int closedir(DIR *dir);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef dirfd
int dirfd(DIR *dir);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef opendir
DIR * opendir(const char *filename);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef readdir
struct dirent * readdir(DIR *dir);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef rewinddir
void rewinddir(DIR *dir);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef scandir
int scandir(const char *dir, struct dirent ***namelist, int (*select)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **));
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef seekdir
void seekdir(DIR *dir, off_t loc);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef telldir
long telldir(DIR *dir);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef creat
int creat(const char * filename, int mode);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fcntl
int fcntl(int fd, int cmd, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef open
int open(const char * filename, int flags, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef endgrent
void endgrent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getgrent
struct group * getgrent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getgrgid
struct group * getgrgid(gid_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getgrnam
struct group * getgrnam(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setgrent
void setgrent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef basename
char * basename(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef dirname
char * dirname(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef endpwent
void endpwent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpwent
struct passwd * getpwent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpwnam
struct passwd * getpwnam(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpwuid
struct passwd * getpwuid(uid_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setpwent
void setpwent(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef regcomp
int regcomp(regex_t *restrict, const char *restrict, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef regerror
size_t regerror(int, const regex_t *restrict, char *restrict, size_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef regexec
int regexec(const regex_t *restrict, const char *restrict, size_t, regmatch_t [], int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef regfree
void regfree(regex_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef siglongjmp
void siglongjmp(sigjmp_buf, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigsetjmp
int sigsetjmp(sigjmp_buf, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef kill
int kill(pid_t, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigaction
int sigaction(int, const struct sigaction *, struct sigaction *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigaddset
int sigaddset(sigset_t *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigdelset
int sigdelset(sigset_t *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigemptyset
int sigemptyset(sigset_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigfillset
int sigfillset(sigset_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigismember
int sigismember(const sigset_t *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigpending
int sigpending(sigset_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigprocmask
int sigprocmask(int, const sigset_t *, sigset_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sigsuspend
int sigsuspend(const sigset_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef clearerr
void clearerr(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fclose
int fclose(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fdopen
FILE * fdopen(int, const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef feof
int feof(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ferror
int ferror(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fflush
int fflush(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fgetc
int fgetc(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fgetpos
int fgetpos(FILE *restrict, fpos_t *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fgets
char * fgets(char *restrict, int, FILE *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fileno
int fileno(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef flockfile
void flockfile(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fopen
FILE * fopen(const char *restrict, const char *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fprintf
int fprintf(FILE *restrict, const char *restrict, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fputc
int fputc(int, FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fputs
int fputs(const char *restrict, FILE *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fread
size_t fread(void *restrict, size_t, size_t, FILE *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef freopen
FILE * freopen(const char *restrict, const char *restrict, FILE *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fscanf
int fscanf(FILE *restrict, const char *restrict, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fseek
int fseek(FILE *, long, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fseeko
int fseeko(FILE *, off_t, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fsetpos
int fsetpos(FILE *, const fpos_t *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ftell
long ftell(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ftello
off_t ftello(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef funlockfile
void funlockfile(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fwrite
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getchar
int getchar(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getc_unlocked
int getc_unlocked(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpass
char * getpass(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef gets
char * gets(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef pclose
int pclose(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef perror
void perror(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef popen
FILE * popen(const char *, const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef printf
int printf(const char *restrict, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef putchar
int putchar(int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef puts
int puts(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_remove
int __posixc_remove(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_rename
int __posixc_rename(const char *, const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef rewind
void rewind(FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef scanf
int scanf(const char *restrict, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setbuf
void setbuf(FILE *restrict, char *restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setvbuf
int setvbuf(FILE *restrict, char *restrict, int, size_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tempnam
char * tempnam(const char *, const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tmpfile
FILE * tmpfile(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tmpnam
char * tmpnam(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ungetc
int ungetc(int, FILE *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef vfprintf
int vfprintf(FILE *restrict, const char *restrict, va_list);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef vfscanf
int vfscanf(FILE *restrict, const char *restrict, va_list);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef vprintf
int vprintf(const char *restrict, va_list);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef vscanf
int vscanf(const char *restrict, va_list);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef drand48
double drand48(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef erand48
double erand48(unsigned short [3]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getenv
char * getenv(const char *name);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef initstate
char * initstate(unsigned, char *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef jrand48
long int jrand48(unsigned short [3]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef lcong48
void lcong48(unsigned short [7]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef lrand48
long int lrand48(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef mkstemp
int mkstemp(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef mktemp
char * mktemp(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef mrand48
long int mrand48(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef nrand48
long int nrand48(unsigned short [3]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef posix_memalign
int posix_memalign(void **, size_t, size_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef putenv
int putenv(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef random
long random(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef realpath
char * realpath(const char * restrict, char * restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef seed48
unsigned short int * seed48(unsigned short [3]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setenv
int setenv(const char *, const char *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setstate
char * setstate(char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef srand48
void srand48(long);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef srandom
void srandom(unsigned);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef system
int system(const char *string);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef unsetenv
void unsetenv(const char *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getloadavg
int getloadavg(double [], int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_strerror
char * __posixc_strerror(int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ioctl
int ioctl(int, int, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getrlimit
int getrlimit(int, struct rlimit *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setrlimit
int setrlimit(int, const struct rlimit *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef chmod
int chmod(const char *path, mode_t mode);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fchmod
int fchmod(int fildes, mode_t mode);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fstat
int fstat(int fd, struct stat *sb);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef lstat
int lstat(const char * restrict path, struct stat * restrict sb);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef mkdir
int mkdir(const char *path, mode_t mode);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef mknod
int mknod(const char *path, mode_t mode, dev_t dev);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef stat
int stat(const char * restrict path, struct stat * restrict sb);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef umask
mode_t umask(mode_t numask);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef gettimeofday
int gettimeofday(struct timeval * restrict, struct timezone * restrict);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef utimes
int utimes(const char *, const struct timeval [2]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef times
clock_t times(struct tms *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef uname
int uname(struct utsname *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef wait
pid_t wait(int *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef waitpid
pid_t waitpid(pid_t, int *, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef cfgetispeed
speed_t cfgetispeed(const struct termios *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef cfgetospeed
speed_t cfgetospeed(const struct termios *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef cfsetispeed
int cfsetispeed(struct termios *, speed_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef cfsetospeed
int cfsetospeed(struct termios *, speed_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tcgetattr
int tcgetattr(int, struct termios *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tcsetattr
int tcsetattr(int, int, const struct termios *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef clock_gettime
int clock_gettime(clockid_t, struct timespec *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef nanosleep
int nanosleep(const struct timespec *, struct timespec *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef strptime
char * strptime(const char *, const char *, struct tm *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef access
int access(const char *path, int mode);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef chdir
int chdir(const char *path);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef chown
int chown(const char *path, uid_t owner, gid_t group);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef close
int close(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef dup
int dup(int oldfd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef dup2
int dup2(int oldfd, int newfd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef execl
int execl(const char *path, const char *arg, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef execlp
int execlp(const char *path, const char *arg, ...);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef execv
int execv(const char *path, char *const argv[]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef execve
int execve(const char *path, char *const argv[], char *const envp[]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef execvp
int execvp(const char *path, char *const argv[]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fchdir
int fchdir(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fchown
int fchown(int fd, uid_t owner, gid_t group);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef fsync
int fsync(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ftruncate
int ftruncate(int fd, off_t length);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getcwd
char * getcwd(char *buf, size_t size);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getegid
gid_t getegid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef geteuid
uid_t geteuid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getgid
gid_t getgid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getgroups
int getgroups(int gidsetlen, gid_t *gidset);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getlogin
char * getlogin(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpgid
pid_t getpgid(pid_t);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpgrp
pid_t getpgrp(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getpid
pid_t getpid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getppid
pid_t getppid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getuid
uid_t getuid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef isatty
int isatty(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef link
int link(const char *name1, const char *name2);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef lseek
off_t lseek(int filedes, off_t offset, int whence);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef pathconf
long pathconf(const char *path, int name);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef pipe
int pipe(int filedes[2]);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef read
ssize_t read(int d, void *buf, size_t nbytes);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef readlink
ssize_t readlink(const char * restrict path, char * restrict buf, size_t bufsize);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef rmdir
int rmdir(const char *path);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setegid
int setegid(gid_t egid);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef seteuid
int seteuid(uid_t euid);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setgid
int setgid(gid_t gid);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setsid
pid_t setsid(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef setuid
int setuid(uid_t uid);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sleep
unsigned sleep(unsigned);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef swab
void swab(const void * restrict src, void * restrict dst, size_t len);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef symlink
int symlink(const char *name1, const char *name2);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sync
void sync(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef sysconf
long sysconf(int name);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef tcgetpgrp
pid_t tcgetpgrp(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef truncate
int truncate(const char *path, off_t length);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef ttyname
char * ttyname(int fd);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef write
ssize_t write(int fd, const void *buf, size_t nbytes);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef utime
int utime(const char *, const struct utimbuf *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef updatestdio
void updatestdio(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __get_default_file
int __get_default_file(int, long *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef flock
int flock(int, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef getfsstat
int getfsstat(struct statfs *, long, int);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef statfs
int statfs(const char *, struct statfs *);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_set_environptr
int __posixc_set_environptr(char ***environptr);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef __posixc_get_environptr
char *** __posixc_get_environptr(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef usleep
int usleep(useconds_t microseconds);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

#if !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__)
#ifndef vfork
pid_t vfork(void);
#endif

#endif /* !defined(__POSIXC_LIBAPI__) || (0 <= __POSIXC_LIBAPI__) */

__END_DECLS

#endif /* CLIB_POSIXC_PROTOS_H */
