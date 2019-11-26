#ifndef  REGEX_PROTOS_H
#define  REGEX_PROTOS_H

#ifndef  LIBRARIES_REGEX_H
#include <libraries/regex.h>
#endif

int regcomp ( regex_t * , const char * , int );
size_t regerror ( int , const regex_t * , char * , size_t );
int regexec ( regex_t * , char * , size_t , regmatch_t * , int );
void regfree ( regex_t * );

#endif	 /* REGEX_PROTOS_H */
