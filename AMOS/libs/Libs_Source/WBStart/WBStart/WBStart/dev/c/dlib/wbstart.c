/*
 * wbstart.c  V2.2
 *
 * VarArgs stub for WBStartTagList
 *
 * (c) 1991-1996 Stefan Becker
 */

#include <clib/wbstart_protos.h>
extern struct Library *WBStartBase;
#include <pragmas/wbstart_pragmas.h>

LONG WBStartTags(Tag tag1, ...)
{
 return(WBStartTagList((struct TagItem *) &tag1));
}
