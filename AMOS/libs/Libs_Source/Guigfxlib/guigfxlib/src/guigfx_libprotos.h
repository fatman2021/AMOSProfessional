
#ifndef _GUIGFX_LIBPROTOS_H
#define _GUIGFX_LIBPROTOS_H 1

/* guigfx_lib.c */

#ifndef __amigaos4__

struct Library * LIBENT LibInit(M68KREG(d0) struct Library *LibBase, M68KREG(a0) BPTR Segment, M68KREG(a6) struct ExecBase *ExecBase);

struct Library * LIBENT LibOpen(
#ifdef __MORPHOS__
        void);
#else
        M68KREG(a6) struct Library *LibBase);
#endif

#ifdef __MORPHOS__
BPTR LIBExpunge(void);
#endif
BPTR LIBENT LibExpunge(M68KREG(a6) struct Library *LibBase);

BPTR LIBENT LibClose(
#ifdef __MORPHOS__
        void);
#else
        M68KREG(a6) struct Library *LibBase);
#endif

LONG LibNull(void);

#endif  // #ifndef __amigaos4__


/* guigfx_InitExit.c */

BOOL LIBENT GGFX_Init(void);
void LIBENT GGFX_Exit(void);

/* guigfx_picturemethod */

ULONG SAVE_DS ASM DoPictureMethodA(M68KREG(a0) APTR, M68KREG(d0) ULONG, M68KREG(a1) ULONG *);


/* guigfx_picture */

PIC SAVE_DS ASM *ReadPictureA(M68KREG(a0) struct RastPort *, M68KREG(a1) struct ColorMap *, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(d2) UWORD, M68KREG(d3) UWORD, M68KREG(a2) TAGLIST);
PIC SAVE_DS ASM *MakePictureA(M68KREG(a0) APTR, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(a1) TAGLIST);
void SAVE_DS ASM DeletePicture(M68KREG(a0) PIC *);
BOOL SAVE_DS ASM UpdatePicture(M68KREG(a0) PIC *);
ULONG SAVE_DS ASM GetPictureAttrsA(M68KREG(a0) PIC *, M68KREG(a1) TAGLIST);
PIC SAVE_DS ASM *ClonePictureA(M68KREG(a0) PIC *, M68KREG(a1) TAGLIST);
ULONG SAVE_DS ASM LockPictureA(M68KREG(a0) PIC *, M68KREG(d0) ULONG, M68KREG(a1) ULONG *);
void SAVE_DS ASM UnLockPicture(M68KREG(a0) PIC *, M68KREG(d0) ULONG);


/* guigfx_picture */

BOOL ReadBitMapArrayA(struct BitMap *, PIC *, UWORD, TAGLIST);

#if defined(__MORPHOS__) || defined(__amigaos4__)
#define ReadBitMapArray(bm, pic, displayID, tags...) \
        ({unsigned long _tags[] = { tags }; ReadBitMapArrayA(bm, pic, displayID, (TAGLIST)_tags);})
#else
BOOL ReadBitMapArray(struct BitMap *, PIC *, UWORD, Tag, ...);
#endif


/* guigfx_loading */

PIC SAVE_DS ASM *LoadPictureA(M68KREG(a0) STRPTR, M68KREG(a1) TAGLIST);
BOOL SAVE_DS ASM IsPictureA(M68KREG(a0) char *file_name, M68KREG(a1) TAGLIST tags);


BOOL PrepareDrawing(PIC *pic);
//void RemapPicture(PIC *pic, UBYTE *pentab);


/* guigfx_rasthandle */

void DeleteRastHandle(RASTHANDLE *);
RASTHANDLE *CreateRastHandle(struct RastPort *rp, ULONG modeID);


/* guigfx_colorhandle */

void SAVE_DS ASM RemColorHandle(M68KREG(a0) COLORHANDLE *);
COLORHANDLE SAVE_DS ASM *AddPictureA(M68KREG(a0) PSM *, M68KREG(a1) PIC *, M68KREG(a2) TAGLIST);
COLORHANDLE SAVE_DS ASM *AddPaletteA(M68KREG(a0) PSM *, M68KREG(a1) PALETTE, M68KREG(a2) TAGLIST);
COLORHANDLE SAVE_DS ASM *AddPixelArrayA(M68KREG(a0) PSM *, M68KREG(a1) APTR, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(a2) TAGLIST);

struct SharedHistogram *CreateSharedHistogram(APTR histo);
void LinkToSharedHistogram(struct SharedHistogram *histo);
void UnLinkSharedHistogram(struct SharedHistogram *histo);


/* guigfx_pensharemap */

PSM SAVE_DS ASM *CreatePenShareMapA(M68KREG(a0) TAGLIST);
void SAVE_DS ASM DeletePenShareMap(M68KREG(a0) PSM *);


/* guigfx_drawhandle */

DRAWHANDLE SAVE_DS ASM *ObtainDrawHandleA(M68KREG(a0) PSM *, M68KREG(a1) struct RastPort *, M68KREG(a2) struct ColorMap *, M68KREG(a3) TAGLIST);
void SAVE_DS ASM ReleaseDrawHandle(M68KREG(a0) DRAWHANDLE *);


/* guigfx_draw */

ULONG GetDitherMode(DRAWHANDLE *dh, APTR array, PALETTE palette, UWORD width, UWORD height, ULONG pixelformat, UWORD totalwidth, UWORD defaultmode, BOOL autodither);

BOOL SAVE_DS ASM DrawPictureA(M68KREG(a0) DRAWHANDLE *, M68KREG(a1) PIC *, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(a2) TAGLIST);
BOOL SAVE_DS ASM MapPaletteA(M68KREG(a0) DRAWHANDLE *, M68KREG(a1) PALETTE, M68KREG(a2) UBYTE *, M68KREG(a3) TAGLIST);
LONG SAVE_DS ASM MapPenA(M68KREG(a0) DRAWHANDLE *, M68KREG(d0) ULONG, M68KREG(a1) TAGLIST);
struct BitMap SAVE_DS ASM *CreatePictureBitMapA(M68KREG(a0) DRAWHANDLE *, M68KREG(a1) PIC *, M68KREG(a2) TAGLIST);

DIRECTDRAWHANDLE SAVE_DS ASM *CreateDirectDrawHandleA(M68KREG(a0) DRAWHANDLE *, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(d2) UWORD, M68KREG(d3) UWORD, M68KREG(a1) TAGLIST);
void SAVE_DS ASM DeleteDirectDrawHandle(M68KREG(a0) DIRECTDRAWHANDLE *);
BOOL SAVE_DS ASM DirectDrawTrueColorA(M68KREG(a0) DIRECTDRAWHANDLE *, M68KREG(a1) ULONG *, M68KREG(d0) UWORD, M68KREG(d1) UWORD, M68KREG(a2) TAGLIST);


BOOL SAVE_DS ASM CreatePictureMaskA(M68KREG(a0) PIC *pic, M68KREG(a1) UBYTE *array, M68KREG(d0) UWORD arraywidth, M68KREG(a2) TAGLIST tags);


#endif
