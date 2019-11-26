/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *      @(#)string.h    5.10 (Berkeley) 3/9/91
 */

#ifndef _STRING_H_
#define _STRING_H_
#include <machine/ansi.h>

#ifdef  _BSD_SIZE_T_
typedef _BSD_SIZE_T_    size_t;
#undef  _BSD_SIZE_T_
#endif

#ifndef NULL
#define NULL    0
#endif

#include <sys/cdefs.h>


__BEGIN_DECLS
void    *memchr __P((const void *, int, size_t));
int      memcmp __P((const void *, const void *, size_t));
void    *memcpy __P((void *, const void *, size_t));
void    *memmove __P((void *, const void *, size_t));
void    *memset __P((void *, int, size_t));
char    *strcat __P((char *, const char *));
char    *strchr __P((const char *, int));
int      strcmp __P((const char *, const char *));
int      strcoll __P((const char *, const char *));
char    *strcpy __P((char *, const char *));
size_t   strcspn __P((const char *, const char *));
char    *strerror __P((int));
size_t   strlen __P((const char *));
char    *strncat __P((char *, const char *, size_t));
int      strncmp __P((const char *, const char *, size_t));
char    *strncpy __P((char *, const char *, size_t));
char    *strpbrk __P((const char *, const char *));
char    *strrchr __P((const char *, int));
size_t   strspn __P((const char *, const char *));
char    *strstr __P((const char *, const char *));
char    *strtok __P((char *, const char *));
size_t   strxfrm __P((char *, const char *, size_t));




/* Nonstandard routines */
#ifndef _ANSI_SOURCE
int      bcmp __P((const void *, const void *, size_t));
void     bcopy __P((const void *, void *, size_t));
void     bzero __P((void *, size_t));
int      ffs __P((int));
char    *index __P((const char *, int));
void    *memccpy __P((void *, const void *, int, size_t));
char    *rindex __P((const char *, int));
int      strcasecmp __P((const char *, const char *));
char    *strdup __P((const char *));
void     strmode __P((int, char *));
int      strncasecmp __P((const char *, const char *, size_t));
char    *strsep __P((char **, const char *));
void     swab __P((const void *, void *, size_t));
int      stricmp __P((const char *, const char *));
int      strnicmp __P((const char *, const char *, size_t));
#ifdef __STRING_INLINE__
#define __string_decl inline
#define strlen strlen_i 
 __string_decl size_t
 strlen(const char *string)
{
  const char *s=string;

  while(*s++)
    ;
  return ~(string-s);
} 
#define strncpy strncpy_i 
__string_decl char *strncpy(char *s1,const char *s2,size_t n)
{
  if (n != 0)
  {
    char *s=s1;
    do {
      if (!(*s++ = *s2++))
      {
	while (--n != 0)
          *s++=0;
	break;
      }
    } while (--n != 0);
  }
  return s1;
}
#define strcpy strcpy_i 
__string_decl char *strcpy(char *s1,const char *s2)
{ char *s=s1;
  do
    *s++=*s2;
  while(*s2++!='\0');
  return s1;
}


#define strcmp strcmp_i 
__string_decl int strcmp(const char *s1, const char *s2)
{
  const unsigned char *p1=s1,*p2=s2;
  unsigned long r,c;

  c=0;
  do
  {
    r=*p1++;
    c=*p2++;
  } while (!(r-=c) && (unsigned char)c);
  return r;
}
#define strncmp strncmp_i 
__string_decl int strncmp(const char *s1,const char *s2,size_t n)
{
  const unsigned char *p1=s1,*p2=s2;
  unsigned long r,c;

  if((r=n))
  {
    c=0;
    do
    {
      r=*p1++;
      c=*p2++;
    } while (!(r-=c) && (unsigned char)c && --n);
  }
  return r;
}
#endif 
/* $Id: strtok_r.c,v 1.1 2003/12/03 15:22:23 chris_reid Exp $ */
 /*
  * Copyright (c) 1995, 1996, 1997 Kungliga Tekniska Högskolan
  * (Royal Institute of Technology, Stockholm, Sweden).
  * All rights reserved.
  * 
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions
  * are met:
  * 
  * 1. Redistributions of source code must retain the above copyright
  *    notice, this list of conditions and the following disclaimer.
  * 
  * 2. Redistributions in binary form must reproduce the above copyright
  *    notice, this list of conditions and the following disclaimer in the
  *    documentation and/or other materials provided with the distribution.
  * 
  * 3. Neither the name of the Institute nor the names of its contributors
  *    may be used to endorse or promote products derived from this software
  *    without specific prior written permission.
  * 
  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
  * SUCH DAMAGE.
  */
 
 
 
 #ifndef HAVE_STRTOK_R
 #ifdef  __GNUC_STDC_INLINE__  // c99 extern inline handle check.see here http://gcc.gnu.org/ml/gcc/2007-03/msg01096.html
       #define __string_decl inline
 #else
      #define __string_decl extern inline
 #endif
 __string_decl char *
 strtok_r(char *s1, const char *s2, char **lasts)
 {
  char *ret;
 
   if (s1 == NULL)
     s1 = *lasts;
   while(*s1 && strchr(s2, *s1))
     ++s1;
   if(*s1 == '\0')
    return NULL;
   ret = s1;
   while(*s1 && !strchr(s2, *s1))
     ++s1;
   if(*s1)
     *s1++ = '\0';
   *lasts = s1;
   return ret;
 }
 
 #endif /* HAVE_STRTOK_R */

#endif 
__END_DECLS

#endif /* _STRING_H_ */
