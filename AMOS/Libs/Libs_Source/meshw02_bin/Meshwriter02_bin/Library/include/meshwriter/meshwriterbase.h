/*
**      $VER: meshwriterbase.h 0.2 (28.3.99)
**
**      definition of MeshWriterBase
**
**      Stephan Bielmann
*/

#ifndef MESHWRITER_MESHWRITERBASE_H
#define MESHWRITER_MESHWRITERBASE_H

#ifdef   __MAXON__
#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#else
#ifndef  EXEC_LIBRARIES
#include <exec/libraries.h>
#endif /* EXEC_LIBRARIES_H */
#endif

struct MeshWriterBase
{
 struct Library         mwb_LibNode;
 SEGLISTPTR             mwb_SegList;
 struct ExecBase       *mwb_SysBase;
 struct UtilityBase    *mwb_UtilityBase;
};

#endif /* MESHWRITER_MESHWRITERBASE_H */
