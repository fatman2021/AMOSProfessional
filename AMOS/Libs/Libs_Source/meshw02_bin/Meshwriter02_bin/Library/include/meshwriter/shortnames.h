/*
**      $VER: shortnames.h 1.00 (28.03.1999)
**
**      Creation date : 28.03.1999
**
**      Description       :
**         Short function name defines.
**
**
**      Written by Stephan Bielmann
**
*/

#ifndef INCLUDE_MWL_SHORTNAMES_H
#define INCLUDE_MWL_SHORTNAMES_H

/*************************** Defines ********************************/

#define mMNew           MWLMeshNew
#define mMDel           MWLMeshDelete
#define mMNameSet       MWLMeshNameSet
#define mMNameGet       MWLMeshNameGet
#define mMCopySet       MWLMeshCopyrightSet
#define mMCopyGet       MWLMeshCopyrightGet
#define mMMatAdd        MWLMeshMaterialAdd
#define mMMatNameSet    MWLMeshMaterialNameSet
#define mMMatNameGet    MWLMeshMaterialNameGet
#define mMMatAmbColSet  MWLMeshMaterialAmbientColorSet
#define mMMatAmbColGet  MWLMeshMaterialAmbientColorGet
#define mMMatShinSet    MWLMeshMaterialShininessSet
#define mMMatShinGet    MWLMeshMaterialShininessGet
#define mMMatTranSet    MWLMeshMaterialTransparencySet
#define mMMatTranGet    MWLMeshMaterialTransparencyGet
#define mMPolAdd        MWLMeshPolygonAdd
#define mMPolMatSet     MWLMeshPolygonMaterialSet
#define mMPolVerAdd     MWLMeshPolygonVertexAdd
#define mMTriAdd        MWLMeshTriangleAdd
#define mMnofMatGet     MWLMeshNumberOfMaterialsGet
#define mMnofPolGet     MWLMeshNumberOfPolygonsGet
#define mMnofVerGet     MWLMeshNumberOfVerticesGet
#define mMCLDefSet      MWLMeshCameraLightDefaultSet
#define mMCamPosSet     MWLMeshCameraPositionSet
#define mMCamPosGet     MWLMeshCameraPositionGet
#define mMCamLkSet      MWLMeshCameraLookAtSet
#define mMCamLkGet      MWLMeshCameraLookAtGet
#define mMLigPosSet     MWLMeshLightPositionSet
#define mMLigPosGet     MWLMeshLightPositionGet
#define mMLigColSet     MWLMeshLightColorSet
#define mMLigColGet     MWLMeshLightColorGet
#define m3DNamesGet     MWL3DFileFormatNamesGet
#define m3DIDGet        MWL3DFileFormatIDGet
#define m3DExGet        MWL3DFileFormatExtensionGet
#define m3DnofGet       MWL3DFileFormatNumberOfGet
#define mMSave3D        MWLMeshSave3D
#define m2DNamesGet     MWL2DFileFormatNamesGet
#define m2DIDGet        MWL2DFileFormatIDGet
#define m2DExGet        MWL2DFileFormatExtensionGet
#define m2DnofGet       MWL2DFileFormatNumberOfGet
#define mMSave2D        MWLMeshSave2D
#define mDMNamesGet     MWLDrawModeNamesGet
#define mDMIDGet        MWLDrawModeIDGet
#define mDMGet          MWLDrawModeNumberOfGet

#define mMVerAdd        MWLMeshVertexAdd
#define mMPolVerAss     MWLMeshPolygonVertexAssign

#define mMCTMRes        MWLMeshCTMReset
#define mMTranChg       MWLMeshTranslationChange
#define mMTranGet       MWLMeshTranslationGet
#define mMScalChg       MWLMeshScaleChange
#define mMScalGet       MWLMeshScaleGet
#define mMRotChg        MWLMeshRotationChange
#define mMRotGet        MWLMeshRotationGet

#define mMMatDiffColSet MWLMeshMaterialDiffuseColorSet
#define mMMatDiffColGet MWLMeshMaterialDiffuseColorGet

#endif

/************************* End of file ******************************/
