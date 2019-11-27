#ifndef INLINE_EXPAT_H
#define INLINE_EXPAT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/expat/lib/expat.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Inline function(s) for expat
*/

#include <aros/libcall.h>
#include <exec/types.h>
#include <aros/symbolsets.h>
#include <aros/preprocessor/variadic/cast2iptr.hpp>

#if !defined(__EXPAT_LIBBASE)
#  if !defined(__NOLIBBASE__) && !defined(__EXPAT_NOLIBBASE__)
#    define __EXPAT_LIBBASE __aros_getbase_ExpatBase()
#  else
#    define __EXPAT_LIBBASE ExpatBase
#  endif
#endif


#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Parser __inline_Expat_XML_ParserCreate(const XML_Char * __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(XML_Parser, XML_ParserCreate,
        AROS_LCA(const XML_Char *,(__arg1),A0),
        struct Library *, (__ExpatBase), 5, Expat    );
}

#define XML_ParserCreate(arg1) \
    __inline_Expat_XML_ParserCreate((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Parser __inline_Expat_XML_ParserCreateNS(const XML_Char * __arg1, XML_Char __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(XML_Parser, XML_ParserCreateNS,
        AROS_LCA(const XML_Char *,(__arg1),A0),
        AROS_LCA(XML_Char,(__arg2),D0),
        struct Library *, (__ExpatBase), 6, Expat    );
}

#define XML_ParserCreateNS(arg1, arg2) \
    __inline_Expat_XML_ParserCreateNS((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Parser __inline_Expat_XML_ParserCreate_MM(const XML_Char * __arg1, const XML_Memory_Handling_Suite * __arg2, const XML_Char * __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC3(XML_Parser, XML_ParserCreate_MM,
        AROS_LCA(const XML_Char *,(__arg1),A0),
        AROS_LCA(const XML_Memory_Handling_Suite *,(__arg2),A1),
        AROS_LCA(const XML_Char *,(__arg3),A2),
        struct Library *, (__ExpatBase), 7, Expat    );
}

#define XML_ParserCreate_MM(arg1, arg2, arg3) \
    __inline_Expat_XML_ParserCreate_MM((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Parser __inline_Expat_XML_ExternalEntityParserCreate(XML_Parser __arg1, const XML_Char * __arg2, const XML_Char * __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC3(XML_Parser, XML_ExternalEntityParserCreate,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(const XML_Char *,(__arg2),A1),
        AROS_LCA(const XML_Char *,(__arg3),A2),
        struct Library *, (__ExpatBase), 8, Expat    );
}

#define XML_ExternalEntityParserCreate(arg1, arg2, arg3) \
    __inline_Expat_XML_ExternalEntityParserCreate((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_ParserFree(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC1NR(void, XML_ParserFree,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 9, Expat    );
}

#define XML_ParserFree(arg1) \
    __inline_Expat_XML_ParserFree((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_Parse(XML_Parser __arg1, const char * __arg2, int __arg3, int __arg4, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC4(enum XML_Status, XML_Parse,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(const char *,(__arg2),A1),
        AROS_LCA(int,(__arg3),D0),
        AROS_LCA(int,(__arg4),D1),
        struct Library *, (__ExpatBase), 10, Expat    );
}

#define XML_Parse(arg1, arg2, arg3, arg4) \
    __inline_Expat_XML_Parse((arg1), (arg2), (arg3), (arg4), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_ParseBuffer(XML_Parser __arg1, int __arg2, int __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC3(enum XML_Status, XML_ParseBuffer,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(int,(__arg2),D0),
        AROS_LCA(int,(__arg3),D1),
        struct Library *, (__ExpatBase), 11, Expat    );
}

#define XML_ParseBuffer(arg1, arg2, arg3) \
    __inline_Expat_XML_ParseBuffer((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void * __inline_Expat_XML_GetBuffer(XML_Parser __arg1, int __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(void *, XML_GetBuffer,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(int,(__arg2),D0),
        struct Library *, (__ExpatBase), 12, Expat    );
}

#define XML_GetBuffer(arg1, arg2) \
    __inline_Expat_XML_GetBuffer((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetStartElementHandler(XML_Parser __arg1, XML_StartElementHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetStartElementHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartElementHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 13, Expat    );
}

#define XML_SetStartElementHandler(arg1, arg2) \
    __inline_Expat_XML_SetStartElementHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetEndElementHandler(XML_Parser __arg1, XML_EndElementHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetEndElementHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_EndElementHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 14, Expat    );
}

#define XML_SetEndElementHandler(arg1, arg2) \
    __inline_Expat_XML_SetEndElementHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetElementHandler(XML_Parser __arg1, XML_StartElementHandler __arg2, XML_EndElementHandler __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC3NR(void, XML_SetElementHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartElementHandler,(__arg2),A1),
        AROS_LCA(XML_EndElementHandler,(__arg3),A2),
        struct Library *, (__ExpatBase), 15, Expat    );
}

#define XML_SetElementHandler(arg1, arg2, arg3) \
    __inline_Expat_XML_SetElementHandler((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetCharacterDataHandler(XML_Parser __arg1, XML_CharacterDataHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetCharacterDataHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_CharacterDataHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 16, Expat    );
}

#define XML_SetCharacterDataHandler(arg1, arg2) \
    __inline_Expat_XML_SetCharacterDataHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetProcessingInstructionHandler(XML_Parser __arg1, XML_ProcessingInstructionHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetProcessingInstructionHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_ProcessingInstructionHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 17, Expat    );
}

#define XML_SetProcessingInstructionHandler(arg1, arg2) \
    __inline_Expat_XML_SetProcessingInstructionHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetCommentHandler(XML_Parser __arg1, XML_CommentHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetCommentHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_CommentHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 18, Expat    );
}

#define XML_SetCommentHandler(arg1, arg2) \
    __inline_Expat_XML_SetCommentHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetStartCdataSectionHandler(XML_Parser __arg1, XML_StartCdataSectionHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetStartCdataSectionHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartCdataSectionHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 19, Expat    );
}

#define XML_SetStartCdataSectionHandler(arg1, arg2) \
    __inline_Expat_XML_SetStartCdataSectionHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetEndCdataSectionHandler(XML_Parser __arg1, XML_EndCdataSectionHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetEndCdataSectionHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_EndCdataSectionHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 20, Expat    );
}

#define XML_SetEndCdataSectionHandler(arg1, arg2) \
    __inline_Expat_XML_SetEndCdataSectionHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetCdataSectionHandler(XML_Parser __arg1, XML_StartCdataSectionHandler __arg2, XML_EndCdataSectionHandler __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC3NR(void, XML_SetCdataSectionHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartCdataSectionHandler,(__arg2),A1),
        AROS_LCA(XML_EndCdataSectionHandler,(__arg3),A2),
        struct Library *, (__ExpatBase), 21, Expat    );
}

#define XML_SetCdataSectionHandler(arg1, arg2, arg3) \
    __inline_Expat_XML_SetCdataSectionHandler((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetDefaultHandler(XML_Parser __arg1, XML_DefaultHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetDefaultHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_DefaultHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 22, Expat    );
}

#define XML_SetDefaultHandler(arg1, arg2) \
    __inline_Expat_XML_SetDefaultHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetDefaultHandlerExpand(XML_Parser __arg1, XML_DefaultHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetDefaultHandlerExpand,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_DefaultHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 23, Expat    );
}

#define XML_SetDefaultHandlerExpand(arg1, arg2) \
    __inline_Expat_XML_SetDefaultHandlerExpand((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetExternalEntityRefHandler(XML_Parser __arg1, XML_ExternalEntityRefHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetExternalEntityRefHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_ExternalEntityRefHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 24, Expat    );
}

#define XML_SetExternalEntityRefHandler(arg1, arg2) \
    __inline_Expat_XML_SetExternalEntityRefHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetExternalEntityRefHandlerArg(XML_Parser __arg1, void * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetExternalEntityRefHandlerArg,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        struct Library *, (__ExpatBase), 25, Expat    );
}

#define XML_SetExternalEntityRefHandlerArg(arg1, arg2) \
    __inline_Expat_XML_SetExternalEntityRefHandlerArg((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetUnknownEncodingHandler(XML_Parser __arg1, XML_UnknownEncodingHandler __arg2, void * __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC3NR(void, XML_SetUnknownEncodingHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_UnknownEncodingHandler,(__arg2),A1),
        AROS_LCA(void *,(__arg3),A2),
        struct Library *, (__ExpatBase), 26, Expat    );
}

#define XML_SetUnknownEncodingHandler(arg1, arg2, arg3) \
    __inline_Expat_XML_SetUnknownEncodingHandler((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetStartNamespaceDeclHandler(XML_Parser __arg1, XML_StartNamespaceDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetStartNamespaceDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartNamespaceDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 27, Expat    );
}

#define XML_SetStartNamespaceDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetStartNamespaceDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetEndNamespaceDeclHandler(XML_Parser __arg1, XML_EndNamespaceDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetEndNamespaceDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_EndNamespaceDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 28, Expat    );
}

#define XML_SetEndNamespaceDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetEndNamespaceDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetNamespaceDeclHandler(XML_Parser __arg1, XML_StartNamespaceDeclHandler __arg2, XML_EndNamespaceDeclHandler __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC3NR(void, XML_SetNamespaceDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartNamespaceDeclHandler,(__arg2),A1),
        AROS_LCA(XML_EndNamespaceDeclHandler,(__arg3),A2),
        struct Library *, (__ExpatBase), 29, Expat    );
}

#define XML_SetNamespaceDeclHandler(arg1, arg2, arg3) \
    __inline_Expat_XML_SetNamespaceDeclHandler((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetXmlDeclHandler(XML_Parser __arg1, XML_XmlDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetXmlDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_XmlDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 30, Expat    );
}

#define XML_SetXmlDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetXmlDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetStartDoctypeDeclHandler(XML_Parser __arg1, XML_StartDoctypeDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetStartDoctypeDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartDoctypeDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 31, Expat    );
}

#define XML_SetStartDoctypeDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetStartDoctypeDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetEndDoctypeDeclHandler(XML_Parser __arg1, XML_EndDoctypeDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetEndDoctypeDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_EndDoctypeDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 32, Expat    );
}

#define XML_SetEndDoctypeDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetEndDoctypeDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetDoctypeDeclHandler(XML_Parser __arg1, XML_StartDoctypeDeclHandler __arg2, XML_EndDoctypeDeclHandler __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC3NR(void, XML_SetDoctypeDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_StartDoctypeDeclHandler,(__arg2),A1),
        AROS_LCA(XML_EndDoctypeDeclHandler,(__arg3),A2),
        struct Library *, (__ExpatBase), 33, Expat    );
}

#define XML_SetDoctypeDeclHandler(arg1, arg2, arg3) \
    __inline_Expat_XML_SetDoctypeDeclHandler((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetElementDeclHandler(XML_Parser __arg1, XML_ElementDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetElementDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_ElementDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 34, Expat    );
}

#define XML_SetElementDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetElementDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetAttlistDeclHandler(XML_Parser __arg1, XML_AttlistDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetAttlistDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_AttlistDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 35, Expat    );
}

#define XML_SetAttlistDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetAttlistDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetEntityDeclHandler(XML_Parser __arg1, XML_EntityDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetEntityDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_EntityDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 36, Expat    );
}

#define XML_SetEntityDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetEntityDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetUnparsedEntityDeclHandler(XML_Parser __arg1, XML_UnparsedEntityDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetUnparsedEntityDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_UnparsedEntityDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 37, Expat    );
}

#define XML_SetUnparsedEntityDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetUnparsedEntityDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetNotationDeclHandler(XML_Parser __arg1, XML_NotationDeclHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetNotationDeclHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_NotationDeclHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 38, Expat    );
}

#define XML_SetNotationDeclHandler(arg1, arg2) \
    __inline_Expat_XML_SetNotationDeclHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetNotStandaloneHandler(XML_Parser __arg1, XML_NotStandaloneHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetNotStandaloneHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_NotStandaloneHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 39, Expat    );
}

#define XML_SetNotStandaloneHandler(arg1, arg2) \
    __inline_Expat_XML_SetNotStandaloneHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Error __inline_Expat_XML_GetErrorCode(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(enum XML_Error, XML_GetErrorCode,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 40, Expat    );
}

#define XML_GetErrorCode(arg1) \
    __inline_Expat_XML_GetErrorCode((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline const XML_LChar * __inline_Expat_XML_ErrorString(enum XML_Error __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(const XML_LChar *, XML_ErrorString,
        AROS_LCA(enum XML_Error,(__arg1),D0),
        struct Library *, (__ExpatBase), 41, Expat    );
}

#define XML_ErrorString(arg1) \
    __inline_Expat_XML_ErrorString((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline long __inline_Expat_XML_GetCurrentByteIndex(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(long, XML_GetCurrentByteIndex,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 42, Expat    );
}

#define XML_GetCurrentByteIndex(arg1) \
    __inline_Expat_XML_GetCurrentByteIndex((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Size __inline_Expat_XML_GetCurrentLineNumber(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(XML_Size, XML_GetCurrentLineNumber,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 43, Expat    );
}

#define XML_GetCurrentLineNumber(arg1) \
    __inline_Expat_XML_GetCurrentLineNumber((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Size __inline_Expat_XML_GetCurrentColumnNumber(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(XML_Size, XML_GetCurrentColumnNumber,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 44, Expat    );
}

#define XML_GetCurrentColumnNumber(arg1) \
    __inline_Expat_XML_GetCurrentColumnNumber((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline int __inline_Expat_XML_GetCurrentByteCount(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(int, XML_GetCurrentByteCount,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 45, Expat    );
}

#define XML_GetCurrentByteCount(arg1) \
    __inline_Expat_XML_GetCurrentByteCount((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline const char * __inline_Expat_XML_GetInputContext(XML_Parser __arg1, int * __arg2, int * __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC3(const char *, XML_GetInputContext,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(int *,(__arg2),A1),
        AROS_LCA(int *,(__arg3),A2),
        struct Library *, (__ExpatBase), 46, Expat    );
}

#define XML_GetInputContext(arg1, arg2, arg3) \
    __inline_Expat_XML_GetInputContext((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetUserData(XML_Parser __arg1, void * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetUserData,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        struct Library *, (__ExpatBase), 47, Expat    );
}

#define XML_SetUserData(arg1, arg2) \
    __inline_Expat_XML_SetUserData((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_DefaultCurrent(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC1NR(void, XML_DefaultCurrent,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 48, Expat    );
}

#define XML_DefaultCurrent(arg1) \
    __inline_Expat_XML_DefaultCurrent((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_UseParserAsHandlerArg(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC1NR(void, XML_UseParserAsHandlerArg,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 49, Expat    );
}

#define XML_UseParserAsHandlerArg(arg1) \
    __inline_Expat_XML_UseParserAsHandlerArg((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_SetBase(XML_Parser __arg1, const XML_Char * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(enum XML_Status, XML_SetBase,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(const XML_Char *,(__arg2),A1),
        struct Library *, (__ExpatBase), 50, Expat    );
}

#define XML_SetBase(arg1, arg2) \
    __inline_Expat_XML_SetBase((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline const XML_Char * __inline_Expat_XML_GetBase(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(const XML_Char *, XML_GetBase,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 51, Expat    );
}

#define XML_GetBase(arg1) \
    __inline_Expat_XML_GetBase((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline int __inline_Expat_XML_GetSpecifiedAttributeCount(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(int, XML_GetSpecifiedAttributeCount,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 52, Expat    );
}

#define XML_GetSpecifiedAttributeCount(arg1) \
    __inline_Expat_XML_GetSpecifiedAttributeCount((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline int __inline_Expat_XML_GetIdAttributeIndex(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC1(int, XML_GetIdAttributeIndex,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 53, Expat    );
}

#define XML_GetIdAttributeIndex(arg1) \
    __inline_Expat_XML_GetIdAttributeIndex((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_SetEncoding(XML_Parser __arg1, const XML_Char * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(enum XML_Status, XML_SetEncoding,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(const XML_Char *,(__arg2),A1),
        struct Library *, (__ExpatBase), 54, Expat    );
}

#define XML_SetEncoding(arg1, arg2) \
    __inline_Expat_XML_SetEncoding((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline int __inline_Expat_XML_SetParamEntityParsing(XML_Parser __arg1, enum XML_ParamEntityParsing __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(int, XML_SetParamEntityParsing,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(enum XML_ParamEntityParsing,(__arg2),D0),
        struct Library *, (__ExpatBase), 55, Expat    );
}

#define XML_SetParamEntityParsing(arg1, arg2) \
    __inline_Expat_XML_SetParamEntityParsing((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetReturnNSTriplet(XML_Parser __arg1, int __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetReturnNSTriplet,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(int,(__arg2),D0),
        struct Library *, (__ExpatBase), 56, Expat    );
}

#define XML_SetReturnNSTriplet(arg1, arg2) \
    __inline_Expat_XML_SetReturnNSTriplet((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline const XML_LChar * __inline_Expat_XML_ExpatVersion(APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC0(const XML_LChar *, XML_ExpatVersion,
        struct Library *, (__ExpatBase), 57, Expat    );
}

#define XML_ExpatVersion() \
    __inline_Expat_XML_ExpatVersion(__EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline XML_Bool __inline_Expat_XML_ParserReset(XML_Parser __arg1, const XML_Char * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(XML_Bool, XML_ParserReset,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(const XML_Char *,(__arg2),A1),
        struct Library *, (__ExpatBase), 59, Expat    );
}

#define XML_ParserReset(arg1, arg2) \
    __inline_Expat_XML_ParserReset((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_SetSkippedEntityHandler(XML_Parser __arg1, XML_SkippedEntityHandler __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    AROS_LC2NR(void, XML_SetSkippedEntityHandler,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_SkippedEntityHandler,(__arg2),A1),
        struct Library *, (__ExpatBase), 60, Expat    );
}

#define XML_SetSkippedEntityHandler(arg1, arg2) \
    __inline_Expat_XML_SetSkippedEntityHandler((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline enum XML_Error __inline_Expat_XML_UseForeignDTD(XML_Parser __arg1, XML_Bool __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC2(enum XML_Error, XML_UseForeignDTD,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_Bool,(__arg2),D0),
        struct Library *, (__ExpatBase), 61, Expat    );
}

#define XML_UseForeignDTD(arg1, arg2) \
    __inline_Expat_XML_UseForeignDTD((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

static inline const XML_Feature * __inline_Expat_XML_GetFeatureList(APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 0)
    return AROS_LC0(const XML_Feature *, XML_GetFeatureList,
        struct Library *, (__ExpatBase), 62, Expat    );
}

#define XML_GetFeatureList() \
    __inline_Expat_XML_GetFeatureList(__EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_StopParser(XML_Parser __arg1, XML_Bool __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    return AROS_LC2(enum XML_Status, XML_StopParser,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_Bool,(__arg2),D0),
        struct Library *, (__ExpatBase), 63, Expat    );
}

#define XML_StopParser(arg1, arg2) \
    __inline_Expat_XML_StopParser((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline enum XML_Status __inline_Expat_XML_ResumeParser(XML_Parser __arg1, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    return AROS_LC1(enum XML_Status, XML_ResumeParser,
        AROS_LCA(XML_Parser,(__arg1),A0),
        struct Library *, (__ExpatBase), 64, Expat    );
}

#define XML_ResumeParser(arg1) \
    __inline_Expat_XML_ResumeParser((arg1), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_GetParsingStatus(XML_Parser __arg1, XML_ParsingStatus * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    AROS_LC2NR(void, XML_GetParsingStatus,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_ParsingStatus *,(__arg2),A1),
        struct Library *, (__ExpatBase), 65, Expat    );
}

#define XML_GetParsingStatus(arg1, arg2) \
    __inline_Expat_XML_GetParsingStatus((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_FreeContentModel(XML_Parser __arg1, XML_Content * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    AROS_LC2NR(void, XML_FreeContentModel,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(XML_Content *,(__arg2),A1),
        struct Library *, (__ExpatBase), 66, Expat    );
}

#define XML_FreeContentModel(arg1, arg2) \
    __inline_Expat_XML_FreeContentModel((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline void * __inline_Expat_XML_MemMalloc(XML_Parser __arg1, size_t __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    return AROS_LC2(void *, XML_MemMalloc,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(size_t,(__arg2),D0),
        struct Library *, (__ExpatBase), 67, Expat    );
}

#define XML_MemMalloc(arg1, arg2) \
    __inline_Expat_XML_MemMalloc((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline void * __inline_Expat_XML_MemRealloc(XML_Parser __arg1, void * __arg2, size_t __arg3, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    return AROS_LC3(void *, XML_MemRealloc,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        AROS_LCA(size_t,(__arg3),D0),
        struct Library *, (__ExpatBase), 68, Expat    );
}

#define XML_MemRealloc(arg1, arg2, arg3) \
    __inline_Expat_XML_MemRealloc((arg1), (arg2), (arg3), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

static inline void __inline_Expat_XML_MemFree(XML_Parser __arg1, void * __arg2, APTR __ExpatBase)
{
    AROS_LIBREQ(ExpatBase, 2)
    AROS_LC2NR(void, XML_MemFree,
        AROS_LCA(XML_Parser,(__arg1),A0),
        AROS_LCA(void *,(__arg2),A1),
        struct Library *, (__ExpatBase), 69, Expat    );
}

#define XML_MemFree(arg1, arg2) \
    __inline_Expat_XML_MemFree((arg1), (arg2), __EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#endif /* INLINE_EXPAT_H*/
