//
// chunky_protos.h
// Prototypes for library functions

#ifndef CHUNKY_PROTOS_H
#define CHUNKY_PROTOS_H

#include <libraries/chunky.h>
#include <intuition/intuition.h>

struct ChunkyPort * CHK_InitChunky(unsigned short sx, unsigned short sy);
struct ColoursCP * CHK_InitColours(struct ChunkyPort *cp);
void CHK_FreeChunky(struct ChunkyPort *cp);
void CHK_DrawChunkyArea(struct ChunkyPort *cp, struct RastPort *rp, unsigned short x, unsigned short y, unsigned short sizex, unsigned short sizey);
void CHK_DrawChunky(struct ChunkyPort *cp, struct RastPort *rp, unsigned short x, unsigned short y);
void CHK_InsertChunky(struct ChunkyPort *cp, struct RastPort *rp, unsigned short x, unsigned short y);
struct ChunkyPort * CHK_CreateChunkyFromBitMap(struct BitMap *bm, unsigned short x, unsigned short y, unsigned short width, unsigned short height);
struct ChunkyPort * CHK_CreateChunkyFromRastPort(struct RastPort *rp, unsigned short x, unsigned short y, unsigned short width, unsigned short height);
void CHK_SetDrMd(struct ChunkyPort *cp, unsigned short flags);
void CHK_SetAPen(struct ChunkyPort *cp, unsigned char p);
void CHK_SetOPen(struct ChunkyPort *cp, unsigned char p);
void CHK_SetABOPen(struct ChunkyPort *cp, unsigned char a, unsigned char b, unsigned char o);
void CHK_Move(struct ChunkyPort *cp, unsigned short x1, unsigned short y1);
void CHK_WritePixel(struct ChunkyPort *cp, unsigned short p, unsigned short x, unsigned short y);
char CHK_ReadPixel(struct ChunkyPort *cp, unsigned short x, unsigned short y);
void CHK_Draw(struct ChunkyPort *cp, unsigned short x2, unsigned short y2);
void CHK_DrawLine(struct ChunkyPort *cp, unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);
void CHK_DrawRect(struct ChunkyPort *cp, unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);
void CHK_RectFill(struct ChunkyPort *cp, unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);
void CHK_DrawEllipse(struct ChunkyPort *cp, unsigned short cx, unsigned short cy, unsigned short rx, unsigned short ry);
void CHK_SetRast(struct ChunkyPort *cp, unsigned char p);
unsigned long CHK_SetSoftStyle(struct ChunkyPort *cp, unsigned long newStyle);
void CHK_SetFont(struct ChunkyPort *cp, struct TextFont *tf);
long CHK_TextLength(struct ChunkyPort *cp, char *text, int length);
void CHK_Text(struct ChunkyPort *cp, char *text);
void CHK_TextCentre(struct ChunkyPort *cp, char *text, unsigned short y);
void CHK_ChooseHardwareMode(unsigned long ModeID);
void CHK_DrawChunkyChunkyArea(struct ChunkyPort *destcp, struct ChunkyPort *srccp, unsigned short destx, unsigned short desty, unsigned short srcx, unsigned short srcy, unsigned short w, unsigned short h);
void CHK_DrawChunkyChunky(struct ChunkyPort *destcp, struct ChunkyPort *srccp, unsigned short x, unsigned short y);
void CHK_DrawTransparentRectangle(struct ChunkyPort *cp, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
struct ChunkyPort * CHK_GetChunkyPort(void *MemoryLocation, unsigned short UseLocationBuffers);
unsigned short CHK_PutChunkyColours(struct ChunkyPort *cp, struct ViewPort *vp);
void CHK_DrawChunkyTiled(struct ChunkyPort *cp, struct RastPort *rp, short x, short y, short w, short h);
unsigned short CHK_C2POff(void);  // OBSOLETE
void CHK_DrawChunkyWindowArea(struct ChunkyPort *cp, struct Window *win, short x, short y, unsigned short w, unsigned short h);
void CHK_DrawChunkyWindow(struct ChunkyPort *cp, struct Window *win, short x, short y);
unsigned short CHK_QueryUseOS(void);
// New in V4
struct ChunkyPort *CHK_CloneChunkyPort(struct ChunkyPort *cp);
void CHK_SetBPen(struct ChunkyPort *cp, unsigned char p);
void CHK_ClearChunky(struct ChunkyPort *cp);
struct ChunkyPort *CHK_CopyChunkyChunkyArea(struct ChunkyPort *cp, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
unsigned short CHK_FlipChunkyPort(struct ChunkyPort *cp, long Flags);
void CHK_EndScroll(struct ChunkyPort *cp);
unsigned short CHK_BeginScroll(struct ChunkyPort *cp, short x1, short y1, short x2, short y2);
unsigned short CHK_Scroll(struct ChunkyPort *cp, short x1, short y1, short x2, short y2, short dx, short dy);
/* Removed in V4.1 - e-mail oondy@bigfoot.com if you want to fix it
unsigned short CHK_Rotate(struct ChunkyPort *cp, short angle);
*/
struct ChunkyPort *CHK_Scale(struct ChunkyPort *cp, short width, short height);
unsigned short CHK_SimpleScale(struct ChunkyPort *cp, short width, short height);
unsigned short CHK_ConvertCMAP(struct ChunkyPort *cp, void *Buffer, unsigned long BufSize);
void CHK_SetRGB32(struct ChunkyPort *cp, unsigned short p, unsigned long r, unsigned long g, unsigned long b);
void CHK_SetRGB4(struct ChunkyPort *cp, unsigned short p, unsigned char r, unsigned char g, unsigned char b);
struct cp_Colour32 *CHK_GetRGB32(struct ChunkyPort *cp, unsigned short p);
unsigned short CHK_GetRGB4(struct ChunkyPort *cp, unsigned short p, struct cp_Colour4 *Result);
unsigned short CHK_LoadRGB32(struct ChunkyPort *cp, void *Colours);
#endif
