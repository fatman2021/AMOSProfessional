/*
**      $VER: meshwriter_protos.h 0.2 (28.3.99)
**
**      prototypes for meshwriter.library
**
**      (C) Copyright 1999 Stephan Bielmann
*/

#ifndef CLIB_MESHWRITER_PROTOS_H
#define CLIB_MESHWRITER_PROTOS_H

#ifndef MESHWRITER_MESHWRITER_H
#include <meshwriter/meshwriter.h>
#endif /* MESHWRITER_MESHWRITER_H */

ULONG MWLMeshNew();
ULONG MWLMeshDelete(ULONG meshhandle);
ULONG MWLMeshNameSet(ULONG meshhandle,STRPTR name);
ULONG MWLMeshNameGet(ULONG meshhandle,STRPTR *name);
ULONG MWLMeshCopyrightSet(ULONG meshhandle,STRPTR copyright);
ULONG MWLMeshCopyrightGet(ULONG meshhandle,STRPTR *copyright);
ULONG MWLMeshMaterialAdd(ULONG meshhandle,ULONG *materialhandle);
ULONG MWLMeshMaterialNameSet(ULONG meshhandle,ULONG materialhandle,STRPTR materialname);
ULONG MWLMeshMaterialNameGet(ULONG meshhandle,ULONG materialhandle,STRPTR *name);
ULONG MWLMeshMaterialAmbientColorSet(ULONG meshhandle,ULONG materialhandle,TOCLColor *color);
ULONG MWLMeshMaterialAmbientColorGet(ULONG meshhandle,ULONG materialhandle,TOCLColor *color);
ULONG MWLMeshMaterialShininessSet(ULONG meshhandle,ULONG materialhandle,TOCLFloat shininess);
ULONG MWLMeshMaterialShininessGet(ULONG meshhandle,ULONG materialhandle,TOCLFloat *shininess);
ULONG MWLMeshMaterialTransparencySet(ULONG meshhandle,ULONG materialhandle,TOCLFloat transparency);
ULONG MWLMeshMaterialTransparencyGet(ULONG meshhandle,ULONG materialhandle,TOCLFloat *transparency);
ULONG MWLMeshPolygonAdd(ULONG meshhandle,ULONG materialhandle);
ULONG MWLMeshPolygonMaterialSet(ULONG meshhandle,ULONG materialhandle);
ULONG MWLMeshPolygonVertexAdd(ULONG meshhandle,TOCLVertex *vertex);                                
ULONG MWLMeshTriangleAdd(ULONG meshhandle,ULONG materialhandle,TOCLVertex *vertex1,TOCLVertex *vertex2,TOCLVertex *vertex3);
ULONG MWLMeshNumberOfMaterialsGet(ULONG meshhandle);
ULONG MWLMeshNumberOfPolygonsGet(ULONG meshhandle);
ULONG MWLMeshNumberOfVerticesGet(ULONG meshhandle);
ULONG MWLMeshCameraLightDefaultSet(ULONG meshhandle);
ULONG MWLMeshCameraPositionSet(ULONG meshhandle,TOCLVertex *position);
ULONG MWLMeshCameraPositionGet(ULONG meshhandle,TOCLVertex *position);
ULONG MWLMeshCameraLookAtSet(ULONG meshhandle,TOCLVertex *lookat);
ULONG MWLMeshCameraLookAtGet(ULONG meshhandle,TOCLVertex *lookat);
ULONG MWLMeshLightPositionSet(ULONG meshhandle,TOCLVertex *position);
ULONG MWLMeshLightPositionGet(ULONG meshhandle,TOCLVertex *position);
ULONG MWLMeshLightColorSet(ULONG meshhandle,TOCLColor *color);
ULONG MWLMeshLightColorGet(ULONG meshhandle,TOCLColor *color);
STRPTR * MWL3DFileFormatNamesGet();
ULONG MWL3DFileFormatIDGet(STRPTR ffname);
STRPTR MWL3DFileFormatExtensionGet(ULONG ffid);
ULONG MWL3DFileFormatNumberOfGet();
ULONG MWLMeshSave3D(ULONG meshhandle,ULONG id,STRPTR filename,struct TagItem *taglist);
STRPTR * MWL2DFileFormatNamesGet();
ULONG MWL2DFileFormatIDGet(STRPTR ffname);
STRPTR MWL2DFileFormatExtensionGet(ULONG ffid);
ULONG MWL2DFileFormatNumberOfGet();
ULONG MWLMeshSave2D(ULONG meshhandle,ULONG id,STRPTR filename,ULONG viewtype,ULONG drawmode,struct TagItem *taglist);
STRPTR * MWLDrawModeNamesGet();
ULONG MWLDrawModeIDGet(STRPTR dmname);
ULONG MWLDrawModeNumberOfGet();
ULONG MWLMeshVertexAdd(ULONG meshhandle,TOCLVertex *vertex,ULONG *index);
ULONG MWLMeshPolygonVertexAssign(ULONG meshhandle,ULONG index);
ULONG MWLMeshCTMReset(ULONG meshhandle);
ULONG MWLMeshTranslationChange(ULONG meshhandle,TOCLVertex *translation,ULONG operation);
ULONG MWLMeshTranslationGet(ULONG meshhandle,TOCLVertex *translation);
ULONG MWLMeshScaleChange(ULONG meshhandle,TOCLVertex *scale,ULONG operation);
ULONG MWLMeshScaleGet(ULONG meshhandle,TOCLVertex *scale);
ULONG MWLMeshRotationChange(ULONG meshhandle,TOCLVertex *rotation,ULONG operation);
ULONG MWLMeshRotationGet(ULONG meshhandle,TOCLVertex *rotation);
ULONG MWLMeshMaterialDiffuseColorSet(ULONG meshhandle,ULONG materialhandle,TOCLColor *color);
ULONG MWLMeshMaterialDiffuseColorGet(ULONG meshhandle,ULONG materialhandle,TOCLColor *color);

#endif /* CLIB_MESHWRITER_PROTOS_H */
