
#include "lib_init.h"
#include "lib_debug.h"
#include <proto/exec.h>

#define AQuote(string) #string
#define AVersion(major,minor) AQuote(major ## . ## minor)
#define AmVersion(major,minor) AVersion(major,minor)
#define LIBVER AmVersion(LIB_VERSION,LIB_REVISION)
#define LIBTYPE " [68k, beta]"

#ifdef __SASC
	#define LIBENT			__asm
	#define REG(reg,arg)	register __ ## reg arg
#endif

#ifdef __GNUC__
	#define LIBENT
	#define REG(reg,arg)	arg __asm( #reg )
#endif

static LONG LibNull(void)
{
	return -1;
}

static const char LibVersion[] = "$VER: " LIB_NAME " " LIBVER " " LIB_DATE LIBTYPE;

static const struct LibInitStruct
{
	ULONG LibSize;
	const void *FuncTable;
	void *DataTable;
	void (*InitFunc)(void);

} LibInitStruct;

static const struct Resident RomTag =
{
	RTC_MATCHWORD,
	(struct Resident *) &RomTag,
	(APTR) (&RomTag + 1),
	RTF_AUTOINIT,
	LIB_VERSION,
	NT_LIBRARY,
	0,
	LIB_NAME,
	(char *) &LibVersion[6],
	(APTR) &LibInitStruct
};

struct ExecBase *SysBase = NULL;

/*****************************************************************************
**
**	lib function wrappers.
*/

static LIBENT APTR libCreateRMHandlerA(
	REG(a1, struct TagItem *tags))
{
	return CreateRMHandlerA(tags);
}

static LIBENT void libDeleteRMHandler(
	REG(a0, APTR rmh))
{
	DeleteRMHandler(rmh);
}

static LIBENT APTR libAllocRenderMem(
	REG(a0, APTR rmh), 
	REG(d0, ULONG size))
{
	return AllocRenderMem(rmh, size);
}

static LIBENT void libFreeRenderMem(
	REG(a0, APTR rmh), 
	REG(a1, APTR mem), 
	REG(d0, ULONG size))
{
	FreeRenderMem(rmh, mem, size);
}

static LIBENT APTR libAllocRenderVec(
	REG(a0, APTR rmh),
	REG(d0, ULONG size))
{
	return AllocRenderVec(rmh, size);
}

static LIBENT void libFreeRenderVec(
	REG(a0, APTR mem))
{
	FreeRenderVec(mem);
}

static LIBENT APTR libAllocRenderVecClear(
	REG(a0, APTR rmh), 
	REG(d0, ULONG size))
{
	return AllocRenderVecClear(rmh, size);
}

static LIBENT void libTurboFillMem(
	REG(a0, APTR mem), 
	REG(d0, ULONG len),
	REG(d1, ULONG val))
{
	TurboFillMem(mem, len, val);
}

static LIBENT void libTurboCopyMem(
	REG(a0, APTR src), 
	REG(a1, APTR dst),
	REG(d0, ULONG len))
{
	TurboCopyMem(src, dst, len);
}

static LIBENT APTR libCreateHistogramA(
	REG(a1, struct TagItem *tags))
{
	return CreateHistogramA(tags);
}

static LIBENT void libDeleteHistogram(
	REG(a0, APTR histo))
{
	DeleteHistogram(histo);
}

static LIBENT ULONG libAddRGB(
	REG(a0, APTR histo),
	REG(d0, ULONG rgb),
	REG(d1, ULONG count))
{
	return AddRGB(histo, rgb, count);
}

static LIBENT ULONG libQueryHistogram(
	REG(a0, APTR histo),
	REG(d0, Tag tag))
{
	return QueryHistogram(histo, tag);
}

static LIBENT ULONG libAddRGBImageA(
	REG(a0, APTR histo),
	REG(a1, ULONG *rgb),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, struct TagItem *tags))
{
	return AddRGBImageA(histo, rgb, width, height, tags);
}

static LIBENT RNDPAL *libCreatePaletteA(
	REG(a1, struct TagItem *tags))
{
	return CreatePaletteA(tags);
}

static LIBENT void libDeletePalette(
	REG(a0, RNDPAL *palette))
{
	DeletePalette(palette);
}

static LIBENT void libImportPaletteA(
	REG(a0, RNDPAL *palette),
	REG(a1, APTR coltab),
	REG(d0, UWORD numcol),
	REG(a2, struct TagItem *tags))
{
	ImportPaletteA(palette, coltab, numcol, tags);
}

static LIBENT void libExportPaletteA(
	REG(a0, RNDPAL *palette),
	REG(a1, APTR coltab),
	REG(a2, struct TagItem *tags))
{
	ExportPaletteA(palette, coltab, tags);
}

static LIBENT void libFlushPalette(
	REG(a0, RNDPAL *palette))
{
	FlushPalette(palette);
}

static LIBENT ULONG libAddChunkyImageA(
	REG(a0, RNDHISTO *histogram),
	REG(a1, UBYTE *chunky),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, RNDPAL *palette),
	REG(a3, struct TagItem *tags))
{
	return AddChunkyImageA(histogram, chunky, width, height, palette, tags);
}

static LIBENT ULONG libExtractPaletteA(
	REG(a0, RNDHISTO *histogram),
	REG(a1, RNDPAL *palette),
	REG(d0, UWORD numcol),
	REG(a2, struct TagItem *tags))
{
	return ExtractPaletteA(histogram, palette, numcol, tags);
}

static LIBENT struct RNDHistoEntry **libCreateHistogramPointerArray(
	REG(a0, RNDHISTO *histogram))
{
	return CreateHistogramPointerArray(histogram);
}

static LIBENT ULONG libCountRGB(
	REG(a0, RNDHISTO *histogram),
	REG(d0, ULONG rgb))
{
	return CountRGB(histogram, rgb);
}

static LIBENT LONG libBestPen(
	REG(a0, RNDPAL *palette),
	REG(d0, ULONG rgb))
{
	return BestPen(palette, rgb);
}

static LIBENT RNDMAP *libCreateMapEngineA(
	REG(a0, RNDPAL *palette),
	REG(a1, struct TagItem *tags))
{
	return CreateMapEngineA(palette, tags);
}

static LIBENT void libDeleteMapEngine(
	REG(a0, RNDMAP *mapengine))
{
	DeleteMapEngine(mapengine);
}

static LIBENT ULONG libMapRGBArrayA(
	REG(a0, RNDMAP *engine),
	REG(a1, ULONG *rgb),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, UBYTE *chunky),
	REG(a3, struct TagItem *tags))
{
	return MapRGBArrayA(engine, rgb, width, height, chunky, tags);
}

static LIBENT ULONG libMapChunkyArrayA(
	REG(a0, RNDMAP *engine),
	REG(a1, UBYTE *src),
	REG(a2, RNDPAL *palette),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a3, UBYTE *dest),
	REG(a4, struct TagItem *tags))
{
	return MapChunkyArrayA(engine, src, palette, width, height, dest, tags);
}

static LIBENT ULONG libCountHistogram(
	REG(a0, RNDHISTO *histo))
{
	return CountHistogram(histo);
}

static LIBENT ULONG libAddHistogramA(
	REG(a0, RNDHISTO *dst),
	REG(a1, RNDHISTO *src),
	REG(a2, struct TagItem *tags))
{
	return AddHistogramA(dst, src, tags);
}

static LIBENT ULONG libChunky2RGBA(
	REG(a0, UBYTE *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, ULONG *dst),
	REG(a2, RNDPAL *pal),
	REG(a3, struct TagItem *tags))
{
	return Chunky2RGBA(src, width, height, dst, pal, tags);
}

static LIBENT LONG libRGBArrayDiversityA(
	REG(a0, ULONG *rgb),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, struct TagItem *tags))
{
	return RGBArrayDiversityA(rgb, width, height, tags);
}

static LIBENT LONG libChunkyArrayDiversityA(
	REG(a0, UBYTE *chunky),
	REG(a1, RNDPAL *palette),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, struct TagItem *tags))
{
	return ChunkyArrayDiversityA(chunky, palette, width, height, tags);
}

static LIBENT void libInsertAlphaChannelA(
	REG(a0, UBYTE *chunky),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, ULONG *rgb),
	REG(a2, struct TagItem *tags))
{
	InsertAlphaChannelA(chunky, width, height, rgb, tags);
}

static LIBENT void libExtractAlphaChannelA(
	REG(a0, ULONG *rgb),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, UBYTE *chunky),
	REG(a2, struct TagItem *tags))
{
	ExtractAlphaChannelA(rgb, width, height, chunky, tags);
}

static LIBENT void libApplyAlphaChannelA(
	REG(a0, ULONG *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, ULONG *dst),
	REG(a2, struct TagItem *tags))
{
	ApplyAlphaChannelA(src, width, height, dst, tags);
}

static LIBENT void libMixRGBArrayA(
	REG(a0, ULONG *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, ULONG *dst),
	REG(d2, UWORD ratio),
	REG(a2, struct TagItem *tags))
{
	MixRGBArrayA(src, width, height, dst, ratio, tags);
}

static LIBENT void libCreateAlphaArrayA(
	REG(a0, ULONG *rgb),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, struct TagItem *tags))
{
	CreateAlphaArrayA(rgb, width, height, tags);
}

static LIBENT void libMixAlphaChannelA(
	REG(a0, ULONG *rgb1),
	REG(a1, ULONG *rgb2),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, ULONG *dest),
	REG(a3, struct TagItem *tags))
{
	MixAlphaChannelA(rgb1, rgb2, width, height, dest, tags);
}

static LIBENT void libTintRGBArrayA(
	REG(a0, ULONG *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(d2, ULONG rgb),
	REG(d3, UWORD ratio),
	REG(a1, ULONG *dest),
	REG(a2, struct TagItem *tags))
{
	TintRGBArrayA(src, width, height, rgb, ratio, dest, tags);
}

static LIBENT ULONG libSortPaletteA(
	REG(a0, RNDPAL *palette),
	REG(d0, ULONG mode),
	REG(a1, struct TagItem *tags))
{
	return SortPaletteA(palette, mode, tags);
}

static LIBENT ULONG libRenderA(
	REG(a0, ULONG *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, UBYTE *dst),
	REG(a2, RNDPAL *palette),
	REG(a3, struct TagItem *tags))
{
	return RenderA(src, width, height, dst, palette, tags);
}


static LIBENT void libPlanar2ChunkyA(
	REG(a0, UWORD **planetab),
	REG(d0, UWORD bytewidth),
	REG(d1, UWORD rows),
	REG(d2, UWORD depth),
	REG(d3, UWORD bytesperrow),
	REG(a1, UBYTE *dst),
	REG(a2, struct TagItem *tags))
{
	Planar2ChunkyA(planetab, bytewidth, rows, depth, bytesperrow, dst, tags);
}

static LIBENT void libChunky2BitMapA(
	REG(a0, UBYTE *src),
	REG(d0, UWORD sx),
	REG(d1, UWORD sy),
	REG(d2, UWORD width),
	REG(d3, UWORD height),
	REG(a1, struct BitMap *bm),
	REG(d4, UWORD dx),
	REG(d5, UWORD dy),
	REG(a2, struct TagItem *tags))
{
	Chunky2BitMapA(src, sx, sy, width, height, bm, dx, dy, tags);
}

static LIBENT ULONG libGetPaletteAttrs(
	REG(a0, RNDPAL *pal),
	REG(d0, ULONG args))
{
	return GetPaletteAttrs(pal, args);
}

static LIBENT void libRemapArrayA(
	REG(a0, UBYTE *src),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a1, UBYTE *dst),
	REG(a2, UBYTE *pentab),
	REG(a3, struct TagItem *tags))
{
	RemapArrayA(src, width, height, dst, pentab, tags);
}

static LIBENT ULONG libConvertChunkyA(
	REG(a0, UBYTE *src),
	REG(a1, RNDPAL *srcpal),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, UBYTE *dst),
	REG(a3, RNDPAL *dstpal),
	REG(a4, struct TagItem *tags))
{
	return ConvertChunkyA(src, srcpal, width, height, dst, dstpal, tags);
}

static LIBENT void libCreatePenTableA(
	REG(a0, UBYTE *src),
	REG(a1, RNDPAL *srcpal),
	REG(d0, UWORD width),
	REG(d1, UWORD height),
	REG(a2, RNDPAL *newpal),
	REG(a3, UBYTE *pentab),
	REG(a4, struct TagItem *tags))
{
	CreatePenTableA(src, srcpal, width, height, newpal, pentab, tags);
}

static LIBENT RNDSCALE *libCreateScaleEngineA(
	REG(d0, UWORD sw),
	REG(d1, UWORD sh),
	REG(d2, UWORD dw),
	REG(d3, UWORD dh),
	REG(a1, struct TagItem *tags))
{
	return CreateScaleEngineA(sw, sh, dw, dh, tags);
}

static LIBENT void libDeleteScaleEngine(
	REG(a0, RNDSCALE *sce))
{
	DeleteScaleEngine(sce);
}

static LIBENT ULONG libScaleA(
	REG(a0, RNDSCALE *sce),
	REG(a1, APTR src),
	REG(a2, APTR dst),
	REG(a3, struct TagItem *tags))
{
	return ScaleA(sce, src, dst, tags);
}

static LIBENT UWORD libScaleOrdinate(
	REG(d0, UWORD start),
	REG(d1, UWORD dest),
	REG(d2, UWORD ordinate))
{
	return ScaleOrdinate(start, dest, ordinate);
}


/*****************************************************************************
**
**	lib setup
*/

#define SysBase LibBase->ExecBase

static LIBENT BPTR LibExpunge(
	REG(a6, LIB_BASE_T *LibBase))
{
	if (LibBase->LibNode.lib_OpenCnt == 0 && LibBase->LibSegment)
	{
		BPTR TempSegment = LibBase->LibSegment;
		Remove((struct Node *) LibBase);
		FreeMem((APTR)((ULONG)(LibBase) - (ULONG)(LibBase->LibNode.lib_NegSize)),
			LibBase->LibNode.lib_NegSize + LibBase->LibNode.lib_PosSize);
		return TempSegment;
	}
	LibBase->LibNode.lib_Flags |= LIBF_DELEXP;
	return NULL;
}

static LIBENT LIB_BASE_T *LibOpen(
	REG(a6, LIB_BASE_T *LibBase))
{
	LIB_BASE_T *result = LibBase;
	ObtainSemaphore(&LibBase->LockSemaphore);
	LibBase->LibNode.lib_Flags &= ~LIBF_DELEXP;
	if (++LibBase->LibNode.lib_OpenCnt == 1)
	{
		if (!Library_Init(LibBase))
		{
			Library_Exit(LibBase);
			LibBase->LibNode.lib_OpenCnt--;
			result = NULL;
		}
	}
	ReleaseSemaphore(&LibBase->LockSemaphore);
	return result;
}

static LIBENT BPTR LibClose(
	REG(a6, LIB_BASE_T *LibBase))
{
	ObtainSemaphore(&LibBase->LockSemaphore);
	if (LibBase->LibNode.lib_OpenCnt > 0)
	{
		if (--LibBase->LibNode.lib_OpenCnt == 0)
		{
			Library_Exit(LibBase);
		}
	}
	ReleaseSemaphore(&LibBase->LockSemaphore);
	if (LibBase->LibNode.lib_OpenCnt == 0 && (LibBase->LibNode.lib_Flags & LIBF_DELEXP))
	{
		return LibExpunge(LibBase);
	}
	return NULL;
}

#undef SysBase

static LIBENT LIB_BASE_T *LibInit(
	REG(d0, LIB_BASE_T *LibBase),
	REG(a0, BPTR Segment),
	REG(a6, struct ExecBase *ExecBase))
{
	SysBase = ExecBase;

	if (!(SysBase->AttnFlags & AFF_68020) ||
		!(SysBase->AttnFlags & AFF_68881))
	{
		FreeMem((APTR)((ULONG)(LibBase) - (ULONG)(LibBase->LibNode.lib_NegSize)),
			LibBase->LibNode.lib_NegSize + LibBase->LibNode.lib_PosSize);
		return NULL;
	}

	LibBase->LibNode.lib_Revision = LIB_REVISION;
	LibBase->LibSegment = Segment;
	LibBase->ExecBase = SysBase;
	InitSemaphore(&LibBase->LockSemaphore);
	return LibBase;
}

static const ULONG LibVectors[] =
{
	(ULONG) LibOpen,
	(ULONG) LibClose,
	(ULONG) LibExpunge,
	(ULONG) LibNull,

/*****************************************************************************
**
**	function table
*/

	(ULONG)	libTurboFillMem,
	(ULONG)	libTurboCopyMem,
	(ULONG) libCreateRMHandlerA,
	(ULONG) libDeleteRMHandler,
	(ULONG) libAllocRenderMem,
	(ULONG) libFreeRenderMem,
	(ULONG) libAllocRenderVec,
	(ULONG) libFreeRenderVec,
	(ULONG) libCreateHistogramA,
	(ULONG) libDeleteHistogram,
	(ULONG) libQueryHistogram,
	(ULONG) libAddRGB,
	(ULONG) libAddRGBImageA,
	(ULONG) libAddChunkyImageA,
	(ULONG) libExtractPaletteA,
	(ULONG) libRenderA,
	(ULONG) libPlanar2ChunkyA,
	(ULONG) libChunky2RGBA,
	(ULONG) libChunky2BitMapA,
	(ULONG) libCreateScaleEngineA,
	(ULONG) libDeleteScaleEngine,
	(ULONG) libScaleA,
	(ULONG) libConvertChunkyA,
	(ULONG) libCreatePenTableA,
	(ULONG) libCreatePaletteA,
	(ULONG) libDeletePalette,
	(ULONG) libImportPaletteA,
	(ULONG) libExportPaletteA,
	(ULONG) libCountRGB,
	(ULONG) libBestPen,
	(ULONG) libFlushPalette,
	(ULONG) libSortPaletteA,
	(ULONG) libAddHistogramA,
	(ULONG) libScaleOrdinate,
	(ULONG) libCreateHistogramPointerArray,
	(ULONG) libCountHistogram,
	(ULONG) libCreateMapEngineA,
	(ULONG) libDeleteMapEngine,
	(ULONG) libMapRGBArrayA,
	(ULONG) libRGBArrayDiversityA,
	(ULONG) libChunkyArrayDiversityA,
	(ULONG) libMapChunkyArrayA,
	(ULONG) libInsertAlphaChannelA,
	(ULONG) libExtractAlphaChannelA,
	(ULONG) libApplyAlphaChannelA,
	(ULONG) libMixRGBArrayA,
	(ULONG) libAllocRenderVecClear,
	(ULONG) libCreateAlphaArrayA,
	(ULONG) libMixAlphaChannelA,
	(ULONG) libTintRGBArrayA,
	(ULONG)	libGetPaletteAttrs,
	(ULONG) libRemapArrayA,
	0xFFFFFFFF
};


static const struct LibInitStruct LibInitStruct =
{
	sizeof(LIB_BASE_T),
	LibVectors,
	NULL,
	(void (*)(void)) &LibInit
};


#ifdef __SASC

/* 
**	create a dummy reference to the static const data, so that
**	it doesn't get optimized away by the compiler :)
*/

APTR foo = &RomTag;

#include <math.h>
#if !defined(_FFP)
void __stdargs _CXFERR(int code) {}
#endif
double __except(int a,const char *b,double c,double e,double f) { return f; }

#endif

#if defined(__GNUC__) && defined(__HAVE_68881__)

int errno;

#endif
