#ifndef _INCLUDE_PRAGMA_REGEX_LIB_H
#define _INCLUDE_PRAGMA_REGEX_LIB_H

#ifndef CLIB_REGEX_PROTOS_H
#include <clib/regex.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma amicall(RegexBase,0x024,regcomp(a0,a1,d0))
#pragma amicall(RegexBase,0x02A,regerror(a1,d2,d0,d1))
#pragma amicall(RegexBase,0x030,regexec(a1,d0,d1,d2,d3))
#pragma amicall(RegexBase,0x036,regfree(a0))

#ifdef __cplusplus
}
#endif


#endif  /*  _INCLUDE_PRAGMA_REGEX_LIB_H  */
