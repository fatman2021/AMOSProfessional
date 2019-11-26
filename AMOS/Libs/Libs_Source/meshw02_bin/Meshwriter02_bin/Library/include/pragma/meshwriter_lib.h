#ifndef _INCLUDE_PRAGMA_MESHWRITER_LIB_H
#define _INCLUDE_PRAGMA_MESHWRITER_LIB_H

#ifndef CLIB_MESHWRITER_PROTOS_H
#include <clib/meshwriter_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(MeshWriterBase,0x01E,MWLMeshNew())
#pragma amicall(MeshWriterBase,0x024,MWLMeshDelete(d1))
#pragma amicall(MeshWriterBase,0x02A,MWLMeshNameSet(d1,d2))
#pragma amicall(MeshWriterBase,0x030,MWLMeshNameGet(d1,d2))
#pragma amicall(MeshWriterBase,0x036,MWLMeshCopyrightSet(d1,d2))
#pragma amicall(MeshWriterBase,0x03C,MWLMeshCopyrightGet(d1,d2))
#pragma amicall(MeshWriterBase,0x042,MWLMeshMaterialAdd(d1,d2))
#pragma amicall(MeshWriterBase,0x048,MWLMeshMaterialNameSet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x04E,MWLMeshMaterialNameGet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x054,MWLMeshMaterialAmbientColorSet(d1,d2,a0))
#pragma amicall(MeshWriterBase,0x05A,MWLMeshMaterialAmbientColorGet(d1,d2,a0))
#pragma amicall(MeshWriterBase,0x060,MWLMeshMaterialShininessSet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x066,MWLMeshMaterialShininessGet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x06C,MWLMeshMaterialTransparencySet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x072,MWLMeshMaterialTransparencyGet(d1,d2,d3))
#pragma amicall(MeshWriterBase,0x078,MWLMeshPolygonAdd(d1,d2))
#pragma amicall(MeshWriterBase,0x07E,MWLMeshPolygonMaterialSet(d1,d2))
#pragma amicall(MeshWriterBase,0x084,MWLMeshPolygonVertexAdd(d1,a0))
#pragma amicall(MeshWriterBase,0x08A,MWLMeshTriangleAdd(d1,d2,a0,a1,a2))
#pragma amicall(MeshWriterBase,0x090,MWLMeshNumberOfMaterialsGet(d1))
#pragma amicall(MeshWriterBase,0x096,MWLMeshNumberOfPolygonsGet(d1))
#pragma amicall(MeshWriterBase,0x09C,MWLMeshNumberOfVerticesGet(d1))
#pragma amicall(MeshWriterBase,0x0A2,MWLMeshCameraLightDefaultSet(d1))
#pragma amicall(MeshWriterBase,0x0A8,MWLMeshCameraPositionSet(d1,a0))
#pragma amicall(MeshWriterBase,0x0AE,MWLMeshCameraPositionGet(d1,a0))
#pragma amicall(MeshWriterBase,0x0B4,MWLMeshCameraLookAtSet(d1,a0))
#pragma amicall(MeshWriterBase,0x0BA,MWLMeshCameraLookAtGet(d1,a0))
#pragma amicall(MeshWriterBase,0x0C0,MWLMeshLightPositionSet(d1,a0))
#pragma amicall(MeshWriterBase,0x0C6,MWLMeshLightPositionGet(d1,a0))
#pragma amicall(MeshWriterBase,0x0CC,MWLMeshLightColorSet(d1,a0))
#pragma amicall(MeshWriterBase,0x0D2,MWLMeshLightColorGet(d1,a0))
#pragma amicall(MeshWriterBase,0x0D8,MWL3DFileFormatNamesGet())
#pragma amicall(MeshWriterBase,0x0DE,MWL3DFileFormatIDGet(d1))
#pragma amicall(MeshWriterBase,0x0E4,MWL3DFileFormatExtensionGet(d1))
#pragma amicall(MeshWriterBase,0x0EA,MWL3DFileFormatNumberOfGet())
#pragma amicall(MeshWriterBase,0x0F0,MWLMeshSave3D(d1,d2,d3,a0))
#pragma amicall(MeshWriterBase,0x0F6,MWL2DFileFormatNamesGet())
#pragma amicall(MeshWriterBase,0x0FC,MWL2DFileFormatIDGet(d1))
#pragma amicall(MeshWriterBase,0x102,MWL2DFileFormatExtensionGet(d1))
#pragma amicall(MeshWriterBase,0x108,MWL2DFileFormatNumberOfGet())
#pragma amicall(MeshWriterBase,0x10E,MWLMeshSave2D(d1,d2,d3,d4,d5,a0))
#pragma amicall(MeshWriterBase,0x114,MWLDrawModeNamesGet())
#pragma amicall(MeshWriterBase,0x11A,MWLDrawModeIDGet(d1))
#pragma amicall(MeshWriterBase,0x120,MWLDrawModeNumberOfGet())
#pragma amicall(MeshWriterBase,0x126,MWLMeshVertexAdd(d1,a0,d2))
#pragma amicall(MeshWriterBase,0x12C,MWLMeshPolygonVertexAssign(d1,d2))
#pragma amicall(MeshWriterBase,0x132,MWLMeshCTMReset(d1))
#pragma amicall(MeshWriterBase,0x138,MWLMeshTranslationChange(d1,a0,d2))
#pragma amicall(MeshWriterBase,0x13E,MWLMeshTranslationGet(d1,a0))
#pragma amicall(MeshWriterBase,0x144,MWLMeshScaleChange(d1,a0,d2))
#pragma amicall(MeshWriterBase,0x14A,MWLMeshScaleGet(d1,a0))
#pragma amicall(MeshWriterBase,0x150,MWLMeshRotationChange(d1,a0,d2))
#pragma amicall(MeshWriterBase,0x156,MWLMeshRotationGet(d1,a0))
#pragma amicall(MeshWriterBase,0x15C,MWLMeshMaterialDiffuseColorSet(d1,d2,a0))
#pragma amicall(MeshWriterBase,0x162,MWLMeshMaterialDiffuseColorGet(d1,d2,a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall MeshWriterBase MWLMeshNew           01E 00
#pragma  libcall MeshWriterBase MWLMeshDelete        024 101
#pragma  libcall MeshWriterBase MWLMeshNameSet       02A 2102
#pragma  libcall MeshWriterBase MWLMeshNameGet       030 2102
#pragma  libcall MeshWriterBase MWLMeshCopyrightSet  036 2102
#pragma  libcall MeshWriterBase MWLMeshCopyrightGet  03C 2102
#pragma  libcall MeshWriterBase MWLMeshMaterialAdd   042 2102
#pragma  libcall MeshWriterBase MWLMeshMaterialNameSet 048 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialNameGet 04E 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialAmbientColorSet 054 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialAmbientColorGet 05A 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialShininessSet 060 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialShininessGet 066 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialTransparencySet 06C 32103
#pragma  libcall MeshWriterBase MWLMeshMaterialTransparencyGet 072 32103
#pragma  libcall MeshWriterBase MWLMeshPolygonAdd    078 2102
#pragma  libcall MeshWriterBase MWLMeshPolygonMaterialSet 07E 2102
#pragma  libcall MeshWriterBase MWLMeshPolygonVertexAdd 084 8102
#pragma  libcall MeshWriterBase MWLMeshTriangleAdd   08A A982105
#pragma  libcall MeshWriterBase MWLMeshNumberOfMaterialsGet 090 101
#pragma  libcall MeshWriterBase MWLMeshNumberOfPolygonsGet 096 101
#pragma  libcall MeshWriterBase MWLMeshNumberOfVerticesGet 09C 101
#pragma  libcall MeshWriterBase MWLMeshCameraLightDefaultSet 0A2 101
#pragma  libcall MeshWriterBase MWLMeshCameraPositionSet 0A8 8102
#pragma  libcall MeshWriterBase MWLMeshCameraPositionGet 0AE 8102
#pragma  libcall MeshWriterBase MWLMeshCameraLookAtSet 0B4 8102
#pragma  libcall MeshWriterBase MWLMeshCameraLookAtGet 0BA 8102
#pragma  libcall MeshWriterBase MWLMeshLightPositionSet 0C0 8102
#pragma  libcall MeshWriterBase MWLMeshLightPositionGet 0C6 8102
#pragma  libcall MeshWriterBase MWLMeshLightColorSet 0CC 8102
#pragma  libcall MeshWriterBase MWLMeshLightColorGet 0D2 8102
#pragma  libcall MeshWriterBase MWL3DFileFormatNamesGet 0D8 00
#pragma  libcall MeshWriterBase MWL3DFileFormatIDGet 0DE 101
#pragma  libcall MeshWriterBase MWL3DFileFormatExtensionGet 0E4 101
#pragma  libcall MeshWriterBase MWL3DFileFormatNumberOfGet 0EA 00
#pragma  libcall MeshWriterBase MWLMeshSave3D        0F0 832104
#pragma  libcall MeshWriterBase MWL2DFileFormatNamesGet 0F6 00
#pragma  libcall MeshWriterBase MWL2DFileFormatIDGet 0FC 101
#pragma  libcall MeshWriterBase MWL2DFileFormatExtensionGet 102 101
#pragma  libcall MeshWriterBase MWL2DFileFormatNumberOfGet 108 00
#pragma  libcall MeshWriterBase MWLMeshSave2D        10E 85432106
#pragma  libcall MeshWriterBase MWLDrawModeNamesGet  114 00
#pragma  libcall MeshWriterBase MWLDrawModeIDGet     11A 101
#pragma  libcall MeshWriterBase MWLDrawModeNumberOfGet 120 00
#pragma  libcall MeshWriterBase MWLMeshVertexAdd     126 28103
#pragma  libcall MeshWriterBase MWLMeshPolygonVertexAssign 12C 2102
#pragma  libcall MeshWriterBase MWLMeshCTMReset      132 101
#pragma  libcall MeshWriterBase MWLMeshTranslationChange 138 28103
#pragma  libcall MeshWriterBase MWLMeshTranslationGet 13E 8102
#pragma  libcall MeshWriterBase MWLMeshScaleChange   144 28103
#pragma  libcall MeshWriterBase MWLMeshScaleGet      14A 8102
#pragma  libcall MeshWriterBase MWLMeshRotationChange 150 28103
#pragma  libcall MeshWriterBase MWLMeshRotationGet   156 8102
#pragma  libcall MeshWriterBase MWLMeshMaterialDiffuseColorSet 15C 82103
#pragma  libcall MeshWriterBase MWLMeshMaterialDiffuseColorGet 162 82103
#endif
#ifdef __STORM__
#endif
#ifdef __SASC_60
#pragma  tagcall MeshWriterBase MWLMeshSave3DTags    0F0 832104
#pragma  tagcall MeshWriterBase MWLMeshSave2DTags    10E 85432106
#endif

#endif  /*  _INCLUDE_PRAGMA_MESHWRITER_LIB_H  */
