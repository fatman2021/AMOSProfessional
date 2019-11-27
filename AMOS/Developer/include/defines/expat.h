#ifndef DEFINES_EXPAT_H
#define DEFINES_EXPAT_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/expat/lib/expat.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

/*
    Desc: Defines for expat
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

__BEGIN_DECLS


#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParserCreate_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(XML_Parser, XML_ParserCreate, \
                  AROS_LCA(const XML_Char *,(__arg1),A0), \
        struct Library *, (__ExpatBase), 5, Expat);\
})

#define XML_ParserCreate(arg1) \
    __XML_ParserCreate_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParserCreateNS_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(XML_Parser, XML_ParserCreateNS, \
                  AROS_LCA(const XML_Char *,(__arg1),A0), \
                  AROS_LCA(XML_Char,(__arg2),D0), \
        struct Library *, (__ExpatBase), 6, Expat);\
})

#define XML_ParserCreateNS(arg1, arg2) \
    __XML_ParserCreateNS_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParserCreate_MM_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3(XML_Parser, XML_ParserCreate_MM, \
                  AROS_LCA(const XML_Char *,(__arg1),A0), \
                  AROS_LCA(const XML_Memory_Handling_Suite *,(__arg2),A1), \
                  AROS_LCA(const XML_Char *,(__arg3),A2), \
        struct Library *, (__ExpatBase), 7, Expat);\
})

#define XML_ParserCreate_MM(arg1, arg2, arg3) \
    __XML_ParserCreate_MM_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ExternalEntityParserCreate_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3(XML_Parser, XML_ExternalEntityParserCreate, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(const XML_Char *,(__arg2),A1), \
                  AROS_LCA(const XML_Char *,(__arg3),A2), \
        struct Library *, (__ExpatBase), 8, Expat);\
})

#define XML_ExternalEntityParserCreate(arg1, arg2, arg3) \
    __XML_ExternalEntityParserCreate_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParserFree_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1NR(void, XML_ParserFree, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 9, Expat);\
})

#define XML_ParserFree(arg1) \
    __XML_ParserFree_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_Parse_WB(__ExpatBase, __arg1, __arg2, __arg3, __arg4) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC4(enum XML_Status, XML_Parse, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(const char *,(__arg2),A1), \
                  AROS_LCA(int,(__arg3),D0), \
                  AROS_LCA(int,(__arg4),D1), \
        struct Library *, (__ExpatBase), 10, Expat);\
})

#define XML_Parse(arg1, arg2, arg3, arg4) \
    __XML_Parse_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3), (arg4))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParseBuffer_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3(enum XML_Status, XML_ParseBuffer, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
                  AROS_LCA(int,(__arg3),D1), \
        struct Library *, (__ExpatBase), 11, Expat);\
})

#define XML_ParseBuffer(arg1, arg2, arg3) \
    __XML_ParseBuffer_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetBuffer_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(void *, XML_GetBuffer, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
        struct Library *, (__ExpatBase), 12, Expat);\
})

#define XML_GetBuffer(arg1, arg2) \
    __XML_GetBuffer_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetStartElementHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetStartElementHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartElementHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 13, Expat);\
})

#define XML_SetStartElementHandler(arg1, arg2) \
    __XML_SetStartElementHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEndElementHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetEndElementHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_EndElementHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 14, Expat);\
})

#define XML_SetEndElementHandler(arg1, arg2) \
    __XML_SetEndElementHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetElementHandler_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3NR(void, XML_SetElementHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartElementHandler,(__arg2),A1), \
                  AROS_LCA(XML_EndElementHandler,(__arg3),A2), \
        struct Library *, (__ExpatBase), 15, Expat);\
})

#define XML_SetElementHandler(arg1, arg2, arg3) \
    __XML_SetElementHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetCharacterDataHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetCharacterDataHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_CharacterDataHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 16, Expat);\
})

#define XML_SetCharacterDataHandler(arg1, arg2) \
    __XML_SetCharacterDataHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetProcessingInstructionHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetProcessingInstructionHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_ProcessingInstructionHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 17, Expat);\
})

#define XML_SetProcessingInstructionHandler(arg1, arg2) \
    __XML_SetProcessingInstructionHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetCommentHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetCommentHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_CommentHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 18, Expat);\
})

#define XML_SetCommentHandler(arg1, arg2) \
    __XML_SetCommentHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetStartCdataSectionHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetStartCdataSectionHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartCdataSectionHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 19, Expat);\
})

#define XML_SetStartCdataSectionHandler(arg1, arg2) \
    __XML_SetStartCdataSectionHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEndCdataSectionHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetEndCdataSectionHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_EndCdataSectionHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 20, Expat);\
})

#define XML_SetEndCdataSectionHandler(arg1, arg2) \
    __XML_SetEndCdataSectionHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetCdataSectionHandler_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3NR(void, XML_SetCdataSectionHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartCdataSectionHandler,(__arg2),A1), \
                  AROS_LCA(XML_EndCdataSectionHandler,(__arg3),A2), \
        struct Library *, (__ExpatBase), 21, Expat);\
})

#define XML_SetCdataSectionHandler(arg1, arg2, arg3) \
    __XML_SetCdataSectionHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetDefaultHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetDefaultHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_DefaultHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 22, Expat);\
})

#define XML_SetDefaultHandler(arg1, arg2) \
    __XML_SetDefaultHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetDefaultHandlerExpand_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetDefaultHandlerExpand, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_DefaultHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 23, Expat);\
})

#define XML_SetDefaultHandlerExpand(arg1, arg2) \
    __XML_SetDefaultHandlerExpand_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetExternalEntityRefHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetExternalEntityRefHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_ExternalEntityRefHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 24, Expat);\
})

#define XML_SetExternalEntityRefHandler(arg1, arg2) \
    __XML_SetExternalEntityRefHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetExternalEntityRefHandlerArg_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetExternalEntityRefHandlerArg, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 25, Expat);\
})

#define XML_SetExternalEntityRefHandlerArg(arg1, arg2) \
    __XML_SetExternalEntityRefHandlerArg_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetUnknownEncodingHandler_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3NR(void, XML_SetUnknownEncodingHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_UnknownEncodingHandler,(__arg2),A1), \
                  AROS_LCA(void *,(__arg3),A2), \
        struct Library *, (__ExpatBase), 26, Expat);\
})

#define XML_SetUnknownEncodingHandler(arg1, arg2, arg3) \
    __XML_SetUnknownEncodingHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetStartNamespaceDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetStartNamespaceDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartNamespaceDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 27, Expat);\
})

#define XML_SetStartNamespaceDeclHandler(arg1, arg2) \
    __XML_SetStartNamespaceDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEndNamespaceDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetEndNamespaceDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_EndNamespaceDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 28, Expat);\
})

#define XML_SetEndNamespaceDeclHandler(arg1, arg2) \
    __XML_SetEndNamespaceDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetNamespaceDeclHandler_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3NR(void, XML_SetNamespaceDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartNamespaceDeclHandler,(__arg2),A1), \
                  AROS_LCA(XML_EndNamespaceDeclHandler,(__arg3),A2), \
        struct Library *, (__ExpatBase), 29, Expat);\
})

#define XML_SetNamespaceDeclHandler(arg1, arg2, arg3) \
    __XML_SetNamespaceDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetXmlDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetXmlDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_XmlDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 30, Expat);\
})

#define XML_SetXmlDeclHandler(arg1, arg2) \
    __XML_SetXmlDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetStartDoctypeDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetStartDoctypeDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartDoctypeDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 31, Expat);\
})

#define XML_SetStartDoctypeDeclHandler(arg1, arg2) \
    __XML_SetStartDoctypeDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEndDoctypeDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetEndDoctypeDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_EndDoctypeDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 32, Expat);\
})

#define XML_SetEndDoctypeDeclHandler(arg1, arg2) \
    __XML_SetEndDoctypeDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetDoctypeDeclHandler_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3NR(void, XML_SetDoctypeDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_StartDoctypeDeclHandler,(__arg2),A1), \
                  AROS_LCA(XML_EndDoctypeDeclHandler,(__arg3),A2), \
        struct Library *, (__ExpatBase), 33, Expat);\
})

#define XML_SetDoctypeDeclHandler(arg1, arg2, arg3) \
    __XML_SetDoctypeDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetElementDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetElementDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_ElementDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 34, Expat);\
})

#define XML_SetElementDeclHandler(arg1, arg2) \
    __XML_SetElementDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetAttlistDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetAttlistDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_AttlistDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 35, Expat);\
})

#define XML_SetAttlistDeclHandler(arg1, arg2) \
    __XML_SetAttlistDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEntityDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetEntityDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_EntityDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 36, Expat);\
})

#define XML_SetEntityDeclHandler(arg1, arg2) \
    __XML_SetEntityDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetUnparsedEntityDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetUnparsedEntityDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_UnparsedEntityDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 37, Expat);\
})

#define XML_SetUnparsedEntityDeclHandler(arg1, arg2) \
    __XML_SetUnparsedEntityDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetNotationDeclHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetNotationDeclHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_NotationDeclHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 38, Expat);\
})

#define XML_SetNotationDeclHandler(arg1, arg2) \
    __XML_SetNotationDeclHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetNotStandaloneHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetNotStandaloneHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_NotStandaloneHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 39, Expat);\
})

#define XML_SetNotStandaloneHandler(arg1, arg2) \
    __XML_SetNotStandaloneHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetErrorCode_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(enum XML_Error, XML_GetErrorCode, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 40, Expat);\
})

#define XML_GetErrorCode(arg1) \
    __XML_GetErrorCode_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ErrorString_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(const XML_LChar *, XML_ErrorString, \
                  AROS_LCA(enum XML_Error,(__arg1),D0), \
        struct Library *, (__ExpatBase), 41, Expat);\
})

#define XML_ErrorString(arg1) \
    __XML_ErrorString_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetCurrentByteIndex_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(long, XML_GetCurrentByteIndex, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 42, Expat);\
})

#define XML_GetCurrentByteIndex(arg1) \
    __XML_GetCurrentByteIndex_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetCurrentLineNumber_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(XML_Size, XML_GetCurrentLineNumber, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 43, Expat);\
})

#define XML_GetCurrentLineNumber(arg1) \
    __XML_GetCurrentLineNumber_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetCurrentColumnNumber_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(XML_Size, XML_GetCurrentColumnNumber, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 44, Expat);\
})

#define XML_GetCurrentColumnNumber(arg1) \
    __XML_GetCurrentColumnNumber_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetCurrentByteCount_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(int, XML_GetCurrentByteCount, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 45, Expat);\
})

#define XML_GetCurrentByteCount(arg1) \
    __XML_GetCurrentByteCount_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetInputContext_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC3(const char *, XML_GetInputContext, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(int *,(__arg2),A1), \
                  AROS_LCA(int *,(__arg3),A2), \
        struct Library *, (__ExpatBase), 46, Expat);\
})

#define XML_GetInputContext(arg1, arg2, arg3) \
    __XML_GetInputContext_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetUserData_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetUserData, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 47, Expat);\
})

#define XML_SetUserData(arg1, arg2) \
    __XML_SetUserData_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_DefaultCurrent_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1NR(void, XML_DefaultCurrent, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 48, Expat);\
})

#define XML_DefaultCurrent(arg1) \
    __XML_DefaultCurrent_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_UseParserAsHandlerArg_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1NR(void, XML_UseParserAsHandlerArg, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 49, Expat);\
})

#define XML_UseParserAsHandlerArg(arg1) \
    __XML_UseParserAsHandlerArg_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetBase_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(enum XML_Status, XML_SetBase, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(const XML_Char *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 50, Expat);\
})

#define XML_SetBase(arg1, arg2) \
    __XML_SetBase_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetBase_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(const XML_Char *, XML_GetBase, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 51, Expat);\
})

#define XML_GetBase(arg1) \
    __XML_GetBase_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetSpecifiedAttributeCount_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(int, XML_GetSpecifiedAttributeCount, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 52, Expat);\
})

#define XML_GetSpecifiedAttributeCount(arg1) \
    __XML_GetSpecifiedAttributeCount_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetIdAttributeIndex_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC1(int, XML_GetIdAttributeIndex, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 53, Expat);\
})

#define XML_GetIdAttributeIndex(arg1) \
    __XML_GetIdAttributeIndex_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetEncoding_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(enum XML_Status, XML_SetEncoding, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(const XML_Char *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 54, Expat);\
})

#define XML_SetEncoding(arg1, arg2) \
    __XML_SetEncoding_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetParamEntityParsing_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(int, XML_SetParamEntityParsing, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(enum XML_ParamEntityParsing,(__arg2),D0), \
        struct Library *, (__ExpatBase), 55, Expat);\
})

#define XML_SetParamEntityParsing(arg1, arg2) \
    __XML_SetParamEntityParsing_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetReturnNSTriplet_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetReturnNSTriplet, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(int,(__arg2),D0), \
        struct Library *, (__ExpatBase), 56, Expat);\
})

#define XML_SetReturnNSTriplet(arg1, arg2) \
    __XML_SetReturnNSTriplet_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ExpatVersion_WB(__ExpatBase) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC0(const XML_LChar *, XML_ExpatVersion, \
        struct Library *, (__ExpatBase), 57, Expat);\
})

#define XML_ExpatVersion() \
    __XML_ExpatVersion_WB(__EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_ParserReset_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(XML_Bool, XML_ParserReset, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(const XML_Char *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 59, Expat);\
})

#define XML_ParserReset(arg1, arg2) \
    __XML_ParserReset_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_SetSkippedEntityHandler_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2NR(void, XML_SetSkippedEntityHandler, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_SkippedEntityHandler,(__arg2),A1), \
        struct Library *, (__ExpatBase), 60, Expat);\
})

#define XML_SetSkippedEntityHandler(arg1, arg2) \
    __XML_SetSkippedEntityHandler_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_UseForeignDTD_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC2(enum XML_Error, XML_UseForeignDTD, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_Bool,(__arg2),D0), \
        struct Library *, (__ExpatBase), 61, Expat);\
})

#define XML_UseForeignDTD(arg1, arg2) \
    __XML_UseForeignDTD_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__)

#define __XML_GetFeatureList_WB(__ExpatBase) ({\
        AROS_LIBREQ(ExpatBase,0)\
        AROS_LC0(const XML_Feature *, XML_GetFeatureList, \
        struct Library *, (__ExpatBase), 62, Expat);\
})

#define XML_GetFeatureList() \
    __XML_GetFeatureList_WB(__EXPAT_LIBBASE)

#endif /* !defined(__EXPAT_LIBAPI__) || (0 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_StopParser_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC2(enum XML_Status, XML_StopParser, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_Bool,(__arg2),D0), \
        struct Library *, (__ExpatBase), 63, Expat);\
})

#define XML_StopParser(arg1, arg2) \
    __XML_StopParser_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_ResumeParser_WB(__ExpatBase, __arg1) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC1(enum XML_Status, XML_ResumeParser, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
        struct Library *, (__ExpatBase), 64, Expat);\
})

#define XML_ResumeParser(arg1) \
    __XML_ResumeParser_WB(__EXPAT_LIBBASE, (arg1))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_GetParsingStatus_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC2NR(void, XML_GetParsingStatus, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_ParsingStatus *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 65, Expat);\
})

#define XML_GetParsingStatus(arg1, arg2) \
    __XML_GetParsingStatus_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_FreeContentModel_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC2NR(void, XML_FreeContentModel, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(XML_Content *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 66, Expat);\
})

#define XML_FreeContentModel(arg1, arg2) \
    __XML_FreeContentModel_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_MemMalloc_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC2(void *, XML_MemMalloc, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(size_t,(__arg2),D0), \
        struct Library *, (__ExpatBase), 67, Expat);\
})

#define XML_MemMalloc(arg1, arg2) \
    __XML_MemMalloc_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_MemRealloc_WB(__ExpatBase, __arg1, __arg2, __arg3) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC3(void *, XML_MemRealloc, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
                  AROS_LCA(size_t,(__arg3),D0), \
        struct Library *, (__ExpatBase), 68, Expat);\
})

#define XML_MemRealloc(arg1, arg2, arg3) \
    __XML_MemRealloc_WB(__EXPAT_LIBBASE, (arg1), (arg2), (arg3))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

#if !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__)

#define __XML_MemFree_WB(__ExpatBase, __arg1, __arg2) ({\
        AROS_LIBREQ(ExpatBase,2)\
        AROS_LC2NR(void, XML_MemFree, \
                  AROS_LCA(XML_Parser,(__arg1),A0), \
                  AROS_LCA(void *,(__arg2),A1), \
        struct Library *, (__ExpatBase), 69, Expat);\
})

#define XML_MemFree(arg1, arg2) \
    __XML_MemFree_WB(__EXPAT_LIBBASE, (arg1), (arg2))

#endif /* !defined(__EXPAT_LIBAPI__) || (2 <= __EXPAT_LIBAPI__) */

__END_DECLS

#endif /* DEFINES_EXPAT_H*/
