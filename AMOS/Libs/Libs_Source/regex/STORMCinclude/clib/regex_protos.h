#ifndef  CLIB_REGEX_PROTOS_H
#define  CLIB_REGEX_PROTOS_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef  LIBRARIES_REGEX_H
#include <libraries/regex.h>
#endif

int regcomp ( regex_t * , const char * , int );
size_t regerror ( int , const regex_t * , char * , size_t );
int regexec ( regex_t * , char * , size_t , regmatch_t * , int );
void regfree ( regex_t * );

#ifdef __cplusplus
}
#endif

#ifdef STORMPRAGMAS
#ifndef _INCLUDE_PRAGMA_REGEX_LIB_H
#include <pragma/regex_lib.h>
#endif
#endif

#endif	 /* CLIB_REGEX_PROTOS_H */
