#ifndef PROTO_WORKBOOK_H
#define PROTO_WORKBOOK_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/system/Workbook/workbook.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <exec/types.h>
#include <aros/system.h>

#include <clib/workbook_protos.h>

#ifndef __WORKBOOK_RELLIBBASE__
 #if !defined(__NOLIBBASE__) && !defined(__WORKBOOK_NOLIBBASE__)
  #if !defined(WorkbookBase)
   #ifdef __WORKBOOK_STDLIBBASE__
    extern struct Library *WorkbookBase;
   #else
    extern APTR WorkbookBase;
   #endif
  #endif
   #ifndef __aros_getbase_WorkbookBase
    #define __aros_getbase_WorkbookBase() (WorkbookBase)
   #endif
 #endif /* defined(__NOLIBBASE__) || defined(__DUMMY_NOLIBBASE__) */
#else /* __WORKBOOK_RELLIBASE__ */
 extern const IPTR __aros_rellib_offset_WorkbookBase;
 #define AROS_RELLIB_OFFSET_WORKBOOK __aros_rellib_offset_WorkbookBase
 #define AROS_RELLIB_BASE_WORKBOOK __aros_rellib_base_WorkbookBase
 #ifndef __aros_getbase_WorkbookBase
  #ifndef __aros_getoffsettable
   char *__aros_getoffsettable(void);
  #endif
  #define __aros_getbase_WorkbookBase() (*(APTR *)(__aros_getoffsettable()+__aros_rellib_offset_WorkbookBase))
 #endif
#endif

#ifndef __aros_getbase_WorkbookBase
extern APTR __aros_getbase_WorkbookBase(void);
#endif

#if !defined(NOLIBINLINE) && !defined(WORKBOOK_NOLIBINLINE) && !defined(__WORKBOOK_RELLIBBASE__)
#   include <inline/workbook.h>
#elif !defined(NOLIBDEFINES) && !defined(WORKBOOK_NOLIBDEFINES)
#   include <defines/workbook.h>
#endif

#endif /* PROTO_WORKBOOK_H */
