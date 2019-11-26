#ifndef PRAGMAS_WBSTART_PRAGMAS_H
#define PRAGMAS_WBSTART_PRAGMAS_H

/*
 * wbstart_pragmas.h  V2.2
 *
 * Inline library calls for wbstart.library functions
 *
 * (c) 1991-1996 Stefan Becker
 */

#pragma libcall WBStartBase WBStartTagList 24 801
#ifdef __SASC_60
#pragma tagcall WBStartBase WBStartTags 24 801
#endif

#endif /* PRAGMAS_WBSTART_PRAGMAS_H */
