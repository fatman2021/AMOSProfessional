/*
**      $VER: meshwriter_pragmas.h 0.2 (28.3.99)
**
**      pragmas for meshwriter.library
**
**      Stephan Bielmann
*/

#ifndef PRAGMAS_MESHWRITER_H
#define PRAGMAS_MESHWRITER_H

#pragma  libcall MeshWriterBase MWLMeshNew           01e 00
#pragma  libcall MeshWriterBase MWLMeshDelete        024 101
#pragma  libcall MeshWriterBase MWLMeshNameSet       02a 2102
#pragma  libcall MeshWriterBase MWLMeshNameGet       030 2102
#pragma  libcall MeshWriterBase MWLMeshCopyrightSet  036 2102
#pragma  libcall MeshWriterBase MWLMeshCopyrightGet  03c 2102
#pragma  libcall MeshWriterBase MWLMeshMaterialAdd   042 2102
#pragma  libcall MeshWriterBase MWLMeshMaterialNameSet 048 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialNameGet 04e 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialAmbientColorSet 054 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialAmbientColorGet 05a 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialShininessSet 060 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialShininessGet 066 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialTransparencySet 06c 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialTransparencyGet 072 32103
#pragma  libcall MeshWriterBase MWLMeshPolygonAdd    078 2102
#pragma  libcall MeshWriterBase MWLMeshPolygonMaterialSet 07e 2102
#pragma  libcall MeshWriterBase MWLMeshPolygonVertexAdd 084 8102
#pragma  libcall MeshWriterBase MWLMeshTriangleAdd   08a A982105
#pragma  libcall MeshWriterBase MWLMeshNumberOfMaterialsGet 090 101
#pragma  libcall MeshWriterBase MWLMeshNumberOfPolygonsGet 096 101
#pragma  libcall MeshWriterBase MWLMeshNumberOfVerticesGet 09c 101
#pragma  libcall MeshWriterBase MWLMeshCameraLightDefaultSet 0a2 101
#pragma  libcall MeshWriterBase MWLMeshCameraPositionSet 0a8 8102
#pragma  libcall MeshWriterBase MWLMeshCameraPositionGet 0ae 8102
#pragma  libcall MeshWriterBase MWLMeshCameraLookAtSet 0b4 8102
#pragma  libcall MeshWriterBase MWLMeshCameraLookAtGet 0ba 8102
#pragma  libcall MeshWriterBase MWLMeshLightPositionSet 0c0 8102
#pragma  libcall MeshWriterBase MWLMeshLightPositionGet 0c6 8102
#pragma  libcall MeshWriterBase MWLMeshLightColorSet 0cc 8102
#pragma  libcall MeshWriterBase MWLMeshLightColorGet 0d2 8102
#pragma  libcall MeshWriterBase MWL3DFileFormatNamesGet 0D8 00
#pragma  libcall MeshWriterBase MWL3DFileFormatIDGet 0de 101
#pragma  libcall MeshWriterBase MWL3DFileFormatExtensionGet 0e4 101
#pragma  libcall MeshWriterBase MWL3DFileFormatNumberOfGet 0eA 00
#pragma  libcall MeshWriterBase MWLMeshSave3D        0f0 832104
#pragma  libcall MeshWriterBase MWL2DFileFormatNamesGet 0f6 00
#pragma  libcall MeshWriterBase MWL2DFileFormatIDGet 0Fc 101
#pragma  libcall MeshWriterBase MWL2DFileFormatExtensionGet 102 101
#pragma  libcall MeshWriterBase MWL2DFileFormatNumberOfGet 108 00
#pragma  libcall MeshWriterBase MWLMeshSave2D        10e 85432106
#pragma  libcall MeshWriterBase MWLDrawModeNamesGet  114 00
#pragma  libcall MeshWriterBase MWLDrawModeIDGet     11a 101
#pragma  libcall MeshWriterBase MWLDrawModeNumberOfGet 120 00
#pragma  libcall MeshWriterBase MWLMeshVertexAdd     126 28103
#pragma  libcall MeshWriterBase MWLMeshPolygonVertexAssign 12c 2102
#pragma  libcall MeshWriterBase MWLMeshCTMReset      132 101
#pragma  libcall MeshWriterBase MWLMeshTranslationChange 138 28103
#pragma  libcall MeshWriterBase MWLMeshTranslationGet 13e 8102
#pragma  libcall MeshWriterBase MWLMeshScaleChange   144 28103
#pragma  libcall MeshWriterBase MWLMeshScaleGet      14a 8102
#pragma  libcall MeshWriterBase MWLMeshRotationChange 150 28103
#pragma  libcall MeshWriterBase MWLMeshRotationGet   156 8102
#pragma  libcall MeshWriterBase MWLMeshMaterialDiffuseColorSet 15c 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialDiffuseColorGet 162 82103
#pragma  libcall MeshWriterBase MWLMeshSave3DTags    0f0 832104
#pragma  libcall MeshWriterBase MWLMeshSave2DTags    10e 85432106
#endif /* PRAGMAS_MESHWRITER_H */
