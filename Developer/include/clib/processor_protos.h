#ifndef CLIB_PROCESSOR_PROTOS_H
#define CLIB_PROCESSOR_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/processor/processor.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>


#include <utility/tagitem.h>


__BEGIN_DECLS


#if !defined(__PROCESSOR_LIBAPI__) || (2 <= __PROCESSOR_LIBAPI__)
AROS_LP1(VOID, GetCPUInfo,
         AROS_LPA(struct TagItem *, tagList, A0),
         LIBBASETYPEPTR, ProcessorBase, 1, Processor
);

#endif /* !defined(__PROCESSOR_LIBAPI__) || (2 <= __PROCESSOR_LIBAPI__) */

__END_DECLS

#endif /* CLIB_PROCESSOR_PROTOS_H */
