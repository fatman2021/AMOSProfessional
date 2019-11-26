
#include "lib_init.h"
#include "lib_debug.h"
#include <proto/exec.h>

#define AQuote(string) #string
#define AVersion(major,minor) AQuote(major ## . ## minor)
#define AmVersion(major,minor) AVersion(major,minor)
#define LIBVER AmVersion(LIB_VERSION,LIB_REVISION)
#define LIBTYPE " [MorphOS]"

static LONG LibNull(void)
{
	return -1;
}

static char LibVersion[] = "$VER: " LIB_NAME " " LIBVER " " LIB_DATE LIBTYPE;

static struct LibInitStruct
{
	ULONG LibSize;
	void *FuncTable;
	void *DataTable;
	void (*InitFunc)(void);

} LibInitStruct;

struct Resident RomTag = 
{
	RTC_MATCHWORD,
	&RomTag,
	&RomTag + 1,
	RTF_AUTOINIT | RTF_PPC | RTF_EXTENDED,
	LIB_VERSION,
	NT_LIBRARY,
	0,
	LIB_NAME,
	&LibVersion[6],
	&LibInitStruct,
	LIB_REVISION,
	NULL
};

ULONG __abox__ = 1;

struct ExecBase *SysBase = NULL;

/*****************************************************************************
**
**	lib function wrappers.
*/

static APTR libCreateRMHandlerA(void)
{
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return CreateRMHandlerA(tags);
}

static void libDeleteRMHandler(void)
{
	APTR rmh = (APTR)REG_A0;
	DeleteRMHandler(rmh);
}

static APTR libAllocRenderMem(void)
{
	APTR rmh = (APTR)REG_A0;
	ULONG size = (ULONG)REG_D0;
	return AllocRenderMem(rmh, size);
}

static void libFreeRenderMem(void)
{
	APTR rmh = (APTR)REG_A0;
	APTR mem = (APTR)REG_A1;
	ULONG size = (ULONG)REG_D0;
	FreeRenderMem(rmh, mem, size);
}

static APTR libAllocRenderVec(void)
{
	APTR rmh = (APTR)REG_A0;
	ULONG size = (ULONG)REG_D0;
	return AllocRenderVec(rmh, size);
}

static void libFreeRenderVec(void)
{
	APTR mem = (APTR)REG_A0;
	FreeRenderVec(mem);
}

static APTR libAllocRenderVecClear(void)
{
	APTR rmh = (APTR)REG_A0;
	ULONG size = (ULONG)REG_D0;
	return AllocRenderVecClear(rmh, size);
}

static void libTurboFillMem(void)
{
	APTR mem = (APTR)REG_A0;
	ULONG len = (ULONG)REG_D0;
	ULONG val = (ULONG)REG_D1;
	TurboFillMem(mem, len, val);
}

static void libTurboCopyMem(void)
{
	APTR src = (APTR)REG_A0;
	APTR dst = (APTR)REG_A1;
	ULONG len = (ULONG)REG_D0;
	TurboCopyMem(src, dst, len);
}

static APTR libCreateHistogramA(void)
{
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return CreateHistogramA(tags);
}

static void libDeleteHistogram(void)
{
	APTR histo = (APTR)REG_A0;
	DeleteHistogram(histo);
}

static ULONG libAddRGB(void)
{
	APTR histo = (APTR)REG_A0;
	ULONG rgb = (ULONG)REG_D0;
	ULONG count = (ULONG)REG_D1;
	return AddRGB(histo, rgb, count);
}

static ULONG libQueryHistogram(void)
{
	APTR histo = (APTR)REG_A0;
	Tag tag = (Tag)REG_D0;
	return QueryHistogram(histo, tag);
}

static ULONG libAddRGBImageA(void)
{
	APTR histo = (APTR)REG_A0;
	ULONG *rgb = (ULONG *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	return AddRGBImageA(histo, rgb, width, height, tags);
}

static RNDPAL *libCreatePaletteA(void)
{
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return CreatePaletteA(tags);
}

static void libDeletePalette(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	DeletePalette(palette);
}

static void libImportPaletteA(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	APTR coltab = (APTR)REG_A1;
	UWORD numcol = (UWORD)REG_D0;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	ImportPaletteA(palette, coltab, numcol, tags);
}

static void libExportPaletteA(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	APTR coltab = (APTR)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	ExportPaletteA(palette, coltab, tags);
}

static void libFlushPalette(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	FlushPalette(palette);
}

static ULONG libAddChunkyImageA(void)
{
	RNDHISTO *histogram = (RNDHISTO *)REG_A0;
	UBYTE *chunky = (UBYTE *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	RNDPAL *palette = (RNDPAL *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	return AddChunkyImageA(histogram, chunky, width, height, palette, tags);
}

static ULONG libExtractPaletteA(void)
{
	RNDHISTO *histogram = (RNDHISTO *)REG_A0;
	RNDPAL *palette = (RNDPAL *)REG_A1;
	UWORD numcol = (UWORD)REG_D0;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	return ExtractPaletteA(histogram, palette, numcol, tags);
}

static struct RNDHistoEntry **libCreateHistogramPointerArray(void)
{
	RNDHISTO *histogram = (RNDHISTO *)REG_A0;
	return CreateHistogramPointerArray(histogram);
}

static ULONG libCountRGB(void)
{
	RNDHISTO *histogram = (RNDHISTO *)REG_A0;
	ULONG rgb = (ULONG)REG_D0;
	return CountRGB(histogram, rgb);
}

static LONG libBestPen(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	ULONG rgb = (ULONG)REG_D0;
	return BestPen(palette, rgb);
}

static RNDMAP *libCreateMapEngineA(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return CreateMapEngineA(palette, tags);
}

static void libDeleteMapEngine(void)
{
	RNDMAP *mapengine = (RNDMAP *)REG_A0;
	DeleteMapEngine(mapengine);
}

static ULONG libMapRGBArrayA(void)
{
	RNDMAP *engine = (RNDMAP *)REG_A0;
	ULONG *rgb = (ULONG *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *chunky = (UBYTE *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	return MapRGBArrayA(engine, rgb, width, height, chunky, tags);
}

static ULONG libMapChunkyArrayA(void)
{
	RNDMAP *engine = (RNDMAP *)REG_A0;
	UBYTE *src = (UBYTE *)REG_A1;
	RNDPAL *palette = (RNDPAL *)REG_A2;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *dest = (UBYTE *)REG_A3;
	struct TagItem *tags = (struct TagItem *)REG_A4;
	return MapChunkyArrayA(engine, src, palette, width, height, dest, tags);
}

static ULONG libCountHistogram(void)
{
	RNDHISTO *histo = (RNDHISTO *)REG_A0;
	return CountHistogram(histo);
}

static ULONG libAddHistogramA(void)
{
	RNDHISTO *dst = (RNDHISTO *)REG_A0;
	RNDHISTO *src = (RNDHISTO *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	return AddHistogramA(dst, src, tags);
}

static ULONG libChunky2RGBA(void)
{
	UBYTE *src = (UBYTE *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG *dst = (ULONG *)REG_A1;
	RNDPAL *pal = (RNDPAL *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	return Chunky2RGBA(src, width, height, dst, pal, tags);
}

static LONG libRGBArrayDiversityA(void)
{
	ULONG *rgb = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return RGBArrayDiversityA(rgb, width, height, tags);
}

static LONG libChunkyArrayDiversityA(void)
{
	UBYTE *chunky = (UBYTE *)REG_A0;
	RNDPAL *palette = (RNDPAL *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	return ChunkyArrayDiversityA(chunky, palette, width, height, tags);
}

static void libInsertAlphaChannelA(void)
{
	UBYTE *chunky = (UBYTE *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG *rgb = (ULONG *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	InsertAlphaChannelA(chunky, width, height, rgb, tags);
}

static void libExtractAlphaChannelA(void)
{
	ULONG *rgb = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *chunky = (UBYTE *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	ExtractAlphaChannelA(rgb, width, height, chunky, tags);
}

static void libApplyAlphaChannelA(void)
{
	ULONG *src = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG *dst = (ULONG *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	ApplyAlphaChannelA(src, width, height, dst, tags);
}

static void libMixRGBArrayA(void)
{
	ULONG *src = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG *dst = (ULONG *)REG_A1;
	UWORD ratio = (UWORD)REG_D2;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	MixRGBArrayA(src, width, height, dst, ratio, tags);
}

static void libCreateAlphaArrayA(void)
{
	ULONG *rgb = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	struct TagItem *tags = (struct TagItem *)REG_A1;
	CreateAlphaArrayA(rgb, width, height, tags);
}

static void libMixAlphaChannelA(void)
{
	ULONG *rgb1 = (ULONG *)REG_A0;
	ULONG *rgb2 = (ULONG *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG *dest = (ULONG *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	MixAlphaChannelA(rgb1, rgb2, width, height, dest, tags);
}

static void libTintRGBArrayA(void)
{
	ULONG *src = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	ULONG rgb = (ULONG)REG_D2;
	UWORD ratio = (UWORD)REG_D3;
	ULONG *dest = (ULONG *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	TintRGBArrayA(src, width, height, rgb, ratio, dest, tags);
}

static ULONG libSortPaletteA(void)
{
	RNDPAL *palette = (RNDPAL *)REG_A0;
	ULONG mode = (ULONG)REG_D0;
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return SortPaletteA(palette, mode, tags);
}

static ULONG libRenderA(void)
{
	ULONG *src = (ULONG *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *dst = (UBYTE *)REG_A1;
	RNDPAL *palette = (RNDPAL *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	return RenderA(src, width, height, dst, palette, tags);
}


static void libPlanar2ChunkyA(void)
{
	UWORD **planetab = (UWORD **)REG_A0;
	UWORD bytewidth = (UWORD)REG_D0;
	UWORD rows = (UWORD)REG_D1;
	UWORD depth = (UWORD)REG_D2;
	UWORD bytesperrow = (UWORD)REG_D3;
	UBYTE *dst = (UBYTE *)REG_A1;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	Planar2ChunkyA(planetab, bytewidth, rows, depth, bytesperrow, dst, tags);
}

static void libChunky2BitMapA(void)
{
	UBYTE *src = (UBYTE *)REG_A0;
	UWORD sx = (UWORD)REG_D0;
	UWORD sy = (UWORD)REG_D1;
	UWORD width = (UWORD)REG_D2;
	UWORD height = (UWORD)REG_D3;
	struct BitMap *bm = (struct BitMap *)REG_A1;
	UWORD dx = (UWORD)REG_D4;
	UWORD dy = (UWORD)REG_D5;
	struct TagItem *tags = (struct TagItem *)REG_A2;
	Chunky2BitMapA(src, sx, sy, width, height, bm, dx, dy, tags);
}

static ULONG libGetPaletteAttrs(void)
{
	RNDPAL *pal = (RNDPAL *)REG_A0;
	ULONG args = (ULONG)REG_D0;
	return GetPaletteAttrs(pal, args);
}

static void libRemapArrayA(void)
{
	UBYTE *src = (UBYTE *)REG_A0;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *dst = (UBYTE *)REG_A1;
	UBYTE *pentab = (UBYTE *)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	RemapArrayA(src, width, height, dst, pentab, tags);
}

static ULONG libConvertChunkyA(void)
{
	UBYTE *src = (UBYTE *)REG_A0;
	RNDPAL *srcpal = (RNDPAL *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	UBYTE *dst = (UBYTE *)REG_A2;
	RNDPAL *dstpal = (RNDPAL *)REG_A3;
	struct TagItem *tags = (struct TagItem *)REG_A4;
	return ConvertChunkyA(src, srcpal, width, height, dst, dstpal, tags);
}

static void libCreatePenTableA(void)
{
	UBYTE *src = (UBYTE *)REG_A0;
	RNDPAL *srcpal = (RNDPAL *)REG_A1;
	UWORD width = (UWORD)REG_D0;
	UWORD height = (UWORD)REG_D1;
	RNDPAL *newpal = (RNDPAL *)REG_A2;
	UBYTE *pentab = (UBYTE *)REG_A3;
	struct TagItem *tags = (struct TagItem *)REG_A4;
	CreatePenTableA(src, srcpal, width, height, newpal, pentab, tags);
}

static RNDSCALE *libCreateScaleEngineA(void)
{
	UWORD sw = (UWORD)REG_D0;
	UWORD sh = (UWORD)REG_D1;
	UWORD dw = (UWORD)REG_D2;
	UWORD dh = (UWORD)REG_D3;
	struct TagItem *tags = (struct TagItem *)REG_A1;
	return CreateScaleEngineA(sw, sh, dw, dh, tags);
}

static void libDeleteScaleEngine(void)
{
	RNDSCALE *sce = (RNDSCALE *)REG_A0;
	DeleteScaleEngine(sce);
}

static ULONG libScaleA(void)
{
	RNDSCALE *sce = (RNDSCALE *)REG_A0;
	APTR src = (APTR)REG_A1;
	APTR dst = (APTR)REG_A2;
	struct TagItem *tags = (struct TagItem *)REG_A3;
	return ScaleA(sce, src, dst, tags);
}

static UWORD libScaleOrdinate(void)
{
	UWORD start = (UWORD)REG_D0;
	UWORD dest = (UWORD)REG_D1;
	UWORD ordinate = (UWORD)REG_D2;
	return ScaleOrdinate(start, dest, ordinate);
}



/*****************************************************************************
**
**	lib setup
*/

#define SysBase LibBase->ExecBase

static LIB_BASE_T *LibOpen(void)
{
	LIB_BASE_T *LibBase = (LIB_BASE_T *) REG_A6;
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

static BPTR LIBExpunge(LIB_BASE_T *LibBase)
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

static BPTR LibExpunge(void)
{
	LIB_BASE_T *LibBase = (LIB_BASE_T *) REG_A6;
	return LIBExpunge(LibBase);
}

static BPTR LibClose(void)
{
	LIB_BASE_T *LibBase = (LIB_BASE_T *) REG_A6;
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
		return LIBExpunge(LibBase);
	}
	return NULL;
}

#undef SysBase

static LIB_BASE_T *LibInit(LIB_BASE_T *LibBase, BPTR Segment, struct ExecBase *ExecBase)
{
	SysBase = ExecBase;

	LibBase->LibSegment = Segment;
	LibBase->ExecBase = ExecBase;
	InitSemaphore(&LibBase->LockSemaphore);
	return LibBase;
}

static ULONG LibVectors[] =
{
	FUNCARRAY_32BIT_NATIVE,
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

static struct LibInitStruct LibInitStruct =
{
	sizeof(LIB_BASE_T),
	LibVectors,
	NULL,
	(void (*)(void)) &LibInit
};


