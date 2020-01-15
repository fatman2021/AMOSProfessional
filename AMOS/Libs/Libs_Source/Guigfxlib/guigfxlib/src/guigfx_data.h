#ifndef _GUIGFX_DATA_H
#define _GUIGFX_DATA_H 1

//extern struct ExecBase                *SysBase;
extern struct Library           *UtilityBase;
extern struct Library           *RenderBase;
extern struct Library           *CyberGfxBase;
extern struct Library           *DataTypesBase;
//extern struct Library         *MathTransBase;
//extern struct Library                 *TowerBase;

#ifndef __amigaos4__

extern struct GfxBase           *GfxBase;
extern struct IntuitionBase     *IntuitionBase;
extern struct DosLibrary        *DOSBase;

#else

extern struct Library           *GfxBase;
extern struct Library           *IntuitionBase;
extern struct Library           *DOSBase;

extern struct ExecIFace *IExec;
extern struct DOSIFace *IDOS;
extern struct IntuitionIFace *IIntuition;
extern struct GraphicsIFace *IGraphics;
extern struct UtilityIFace *IUtility;
extern struct RenderIFace *IRender;
extern struct CyberGfxIFace *ICyberGfx;
extern struct DataTypesIFace *IDataTypes;

#endif

extern APTR MemHandler;

extern BOOL gfx40;
extern BOOL cgfx41;

extern BOOL env_usescalepixelarray;
extern BOOL env_usewpa8;
extern int env_autoditherthreshold;

extern ULONG defaultpalette[256];

#endif
