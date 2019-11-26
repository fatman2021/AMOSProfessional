/*
 *  $VER: init.c $Revision$ (03-Mar-2005)
 *
 *  This file is part of render.
 *
 *  (C) Copyright 2005 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id$
 *
 * $Log$
 *
 *
 */


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <graphics/gfx.h>
#include <utility/hooks.h>
#include <utility/tagitem.h>
#include <interfaces/render.h>
#include <stdarg.h>

#include "lib_init.h"
#include "lib_debug.h"

#define AQuote(string) #string
#define AVersion(major,minor) AQuote(major ## . ## minor)
#define AmVersion(major,minor) AVersion(major,minor)
#define LIBVER AmVersion(LIB_VERSION,LIB_REVISION)
#define LIBTYPE " [AmigaOS4]"

#define VSTRING LIB_NAME " " LIBVER " " LIB_DATE LIBTYPE "\r\n"

static const char __attribute__((used)) LibVersion[] = "\0$VER: " LIB_NAME " " LIBVER " " LIB_DATE LIBTYPE;

struct ExecIFace *IExec = NULL;

/*
 * The system (and compiler) rely on a symbol named _start which marks
 * the beginning of execution of an ELF file. To prevent others from 
 * executing this library, and to keep the compiler/linker happy, we
 * define an empty _start symbol here.
 *
 * On the classic system (pre-AmigaOS4) this was usually done by
 * moveq #0,d0
 * rts
 *
 */
void _start(void)
{
    /* If you feel like it, open DOS and print something to the user */
}


/* Open the library */
struct Library *libOpen(struct LibraryManagerInterface *Self, ULONG version)
{
    struct RenderBase *libBase = (struct RenderBase *)Self->Data.LibBase;
    struct Library *result = (struct Library *) libBase;

    ObtainSemaphore(&libBase->LockSemaphore);
    if (++libBase->LibNode.lib_OpenCnt == 1)
    {
        if (!Library_Init(libBase))
        {
                Library_Exit(libBase);
                libBase->LibNode.lib_OpenCnt--;
                result = NULL;
        }
    }

    ReleaseSemaphore(&libBase->LockSemaphore);
    return result;
}


/* Close the library */
APTR libClose(struct LibraryManagerInterface *Self)
{
    struct RenderBase *libBase = (struct RenderBase *)Self->Data.LibBase;
    /* Make sure to undo what open did */

    ObtainSemaphore(&libBase->LockSemaphore);
    if (libBase->LibNode.lib_OpenCnt > 0)
    {
        if (--libBase->LibNode.lib_OpenCnt == 0)
        {
            Library_Exit(libBase);
        }
    }
    ReleaseSemaphore(&libBase->LockSemaphore);

    return 0;
}


/* Expunge the library */
APTR libExpunge(struct LibraryManagerInterface *Self)
{
    /* If your library cannot be expunged, return 0 */
    APTR result = (APTR)0;
    struct RenderBase *libBase = (struct RenderBase *)Self->Data.LibBase;
    if (libBase->LibNode.lib_OpenCnt == 0)
    {
        result = (APTR)libBase->LibSegment;
        /* Undo what the init code did */

        Remove((struct Node *)libBase);
        DeleteLibrary((struct Library *)libBase);
    }
    else
    {
        result = (APTR)0;
        libBase->LibNode.lib_Flags |= LIBF_DELEXP;
    }
    return result;
}


/* The ROMTAG Init Function */
struct Library *libInit(struct Library *LibraryBase, APTR seglist, struct Interface *exec)
{
    struct RenderBase *libBase = (struct RenderBase *)LibraryBase;

    IExec = (struct ExecIFace *)exec;

    libBase->LibNode.lib_Node.ln_Type = NT_LIBRARY;
    libBase->LibNode.lib_Node.ln_Pri  = 0;
    libBase->LibNode.lib_Node.ln_Name = "render.library";
    libBase->LibNode.lib_Flags        = LIBF_SUMUSED|LIBF_CHANGED;
    libBase->LibNode.lib_Version      = LIB_VERSION;
    libBase->LibNode.lib_Revision     = LIB_REVISION;
    libBase->LibNode.lib_IdString     = VSTRING;

    libBase->LibSegment = (BPTR)seglist;

    InitSemaphore(&libBase->LockSemaphore);

    return (struct Library *)libBase;
}

/* ------------------- Manager Interface ------------------------ */
/* These are generic. Replace if you need more fancy stuff */
static LONG _manager_Obtain(struct LibraryManagerInterface *Self)
{
    return Self->Data.RefCount++;
}

static ULONG _manager_Release(struct LibraryManagerInterface *Self)
{
    return Self->Data.RefCount--;
}

/* Manager interface vectors */
static void *lib_manager_vectors[] =
{
    (void *)_manager_Obtain,
    (void *)_manager_Release,
    (void *)0,
    (void *)0,
    (void *)libOpen,
    (void *)libClose,
    (void *)libExpunge,
    (void *)0,
    (void *)-1,
};

/* "__library" interface tag list */
static struct TagItem lib_managerTags[] =
{
    {MIT_Name,             (ULONG)"__library"},
    {MIT_VectorTable,      (ULONG)lib_manager_vectors},
    {MIT_Version,          1},
    {TAG_DONE,             0}
};

/* ------------------- Library Interface(s) ------------------------ */

ULONG VARARGS68K _Render_Obtain(struct RenderIFace *Self)
{
    return (ULONG)0;
}

ULONG VARARGS68K _Render_Release(struct RenderIFace *Self)
{
    return (ULONG)0;
}

void VARARGS68K _Render_TurboFillMem(struct RenderIFace *Self,
       APTR dst,
       ULONG len,
       ULONG val)
{
    TurboFillMem(dst, len, val);
}

void VARARGS68K _Render_TurboCopyMem(struct RenderIFace *Self,
       APTR src,
       APTR dst,
       ULONG len)
{
    TurboCopyMem(src, dst, len);
}

APTR VARARGS68K _Render_CreateRMHandler(struct RenderIFace *Self,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, Self);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreateRMHandlerA(
        tags);
}

APTR VARARGS68K _Render_CreateRMHandlerA(struct RenderIFace *Self,
       struct TagItem * taglist)
{
    return CreateRMHandlerA(taglist);
}

void VARARGS68K _Render_DeleteRMHandler(struct RenderIFace *Self,
       APTR rmh)
{
    DeleteRMHandler(rmh);
}

APTR VARARGS68K _Render_AllocRenderMem(struct RenderIFace *Self,
       APTR rendermemhandler,
       ULONG size)
{
    return AllocRenderMem(rendermemhandler, size);
}

void VARARGS68K _Render_FreeRenderMem(struct RenderIFace *Self,
       APTR rendermemhandler,
       APTR mem,
       ULONG size)
{
    FreeRenderMem(rendermemhandler, mem, size);
}

APTR VARARGS68K _Render_AllocRenderVec(struct RenderIFace *Self,
       APTR rendermemhandler,
       ULONG size)
{
    return AllocRenderVec(rendermemhandler, size);
}

void VARARGS68K _Render_FreeRenderVec(struct RenderIFace *Self,
       APTR mem)
{
    FreeRenderVec(mem);
}

APTR VARARGS68K _Render_CreateHistogram(struct RenderIFace *Self,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, Self);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreateHistogramA(
        tags);

}

APTR VARARGS68K _Render_CreateHistogramA(struct RenderIFace *Self,
       struct TagItem * taglist)
{
    return CreateHistogramA(taglist);
}

void VARARGS68K _Render_DeleteHistogram(struct RenderIFace *Self,
       APTR histogram)
{
    DeleteHistogram(histogram);
}

ULONG VARARGS68K _Render_QueryHistogram(struct RenderIFace *Self,
       APTR histogram,
       Tag d0arg)
{
    return QueryHistogram(histogram, d0arg);
}

ULONG VARARGS68K _Render_AddRGB(struct RenderIFace *Self,
       APTR histogram,
       ULONG RGB,
       ULONG count)
{
    return AddRGB(histogram, RGB, count);
}

ULONG VARARGS68K _Render_AddRGBImage(struct RenderIFace *Self,
       APTR histogram,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddRGBImageA(
        histogram,
        rgb,
        width,
        height,
        tags);

}

ULONG VARARGS68K _Render_AddRGBImageA(struct RenderIFace *Self,
       APTR histogram,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       struct TagItem * taglist)
{
    return AddRGBImageA(histogram, rgb, width, height, taglist);
}

ULONG VARARGS68K _Render_AddChunkyImage(struct RenderIFace *Self,
       APTR histogram,
       UBYTE * chunky,
       UWORD width,
       UWORD height,
       APTR palette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, palette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddChunkyImageA(
        histogram,
        chunky,
        width,
        height,
        palette,
        tags);

}

ULONG VARARGS68K _Render_AddChunkyImageA(struct RenderIFace *Self,
       APTR histogram,
       UBYTE * chunky,
       UWORD width,
       UWORD height,
       APTR palette,
       struct TagItem * taglist)
{
    return AddChunkyImageA(histogram, chunky, width, height, palette, taglist);
}

ULONG VARARGS68K _Render_ExtractPalette(struct RenderIFace *Self,
       APTR histogram,
       ULONG * palette,
       UWORD numcolors,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, numcolors);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ExtractPaletteA(
        histogram,
        palette,
        numcolors,
        tags);

}

ULONG VARARGS68K _Render_ExtractPaletteA(struct RenderIFace *Self,
       APTR histogram,
       ULONG * palette,
       UWORD numcolors,
       struct TagItem * taglist)
{
    return ExtractPaletteA(histogram, palette, numcolors, taglist);
}

ULONG VARARGS68K _Render_Render(struct RenderIFace *Self,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       UBYTE * chunky,
       APTR palette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, palette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->RenderA(
        rgb,
        width,
        height,
        chunky,
        palette,
        tags);

}

ULONG VARARGS68K _Render_RenderA(struct RenderIFace *Self,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       UBYTE * chunky,
       APTR palette,
       struct TagItem * taglist)
{
    return RenderA(rgb, width, height, chunky, palette, taglist);
}

void VARARGS68K _Render_Planar2Chunky(struct RenderIFace *Self,
       PLANEPTR * planetab,
       UWORD bytewidth,
       UWORD height,
       UWORD depth,
       UWORD bytesperrow,
       UBYTE * chunky,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, chunky);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->Planar2ChunkyA(
        planetab,
        bytewidth,
        height,
        depth,
        bytesperrow,
        chunky,
        tags);

}

void VARARGS68K _Render_Planar2ChunkyA(struct RenderIFace *Self,
       PLANEPTR * planetab,
       UWORD bytewidth,
       UWORD height,
       UWORD depth,
       UWORD bytesperrow,
       UBYTE * chunky,
       struct TagItem * taglist)
{
    Planar2ChunkyA(planetab, bytewidth, height, depth, bytesperrow, chunky, taglist);
}

ULONG VARARGS68K _Render_Chunky2RGB(struct RenderIFace *Self,
       UBYTE * chunky,
       UWORD width,
       UWORD height,
       ULONG * rgb,
       APTR palette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, palette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->Chunky2RGBA(
        chunky,
        width,
        height,
        rgb,
        palette,
        tags);

}

ULONG VARARGS68K _Render_Chunky2RGBA(struct RenderIFace *Self,
       UBYTE * chunky,
       UWORD width,
       UWORD height,
       ULONG * rgb,
       APTR palette,
       struct TagItem * taglist)
{
    return Chunky2RGBA(chunky, width, height, rgb, palette, taglist);
}

void VARARGS68K _Render_Chunky2BitMap(struct RenderIFace *Self,
       UBYTE * chunky,
       UWORD sx,
       UWORD sy,
       UWORD width,
       UWORD height,
       struct BitMap * bitmap,
       UWORD dx,
       UWORD dy,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dy);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->Chunky2BitMapA(
        chunky,
        sx,
        sy,
        width,
        height,
        bitmap,
        dx,
        dy,
        tags);

}

void VARARGS68K _Render_Chunky2BitMapA(struct RenderIFace *Self,
       UBYTE * chunky,
       UWORD sx,
       UWORD sy,
       UWORD width,
       UWORD height,
       struct BitMap * bitmap,
       UWORD dx,
       UWORD dy,
       struct TagItem * taglist)
{
    Chunky2BitMapA(chunky, sx, sy, width, height, bitmap, dx, dy, taglist);
}

APTR VARARGS68K _Render_CreateScaleEngine(struct RenderIFace *Self,
       UWORD sourcewidth,
       UWORD sourceheight,
       UWORD destwidth,
       UWORD destheight,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, destheight);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreateScaleEngineA(
        sourcewidth,
        sourceheight,
        destwidth,
        destheight,
        tags);

}

APTR VARARGS68K _Render_CreateScaleEngineA(struct RenderIFace *Self,
       UWORD sourcewidth,
       UWORD sourceheight,
       UWORD destwidth,
       UWORD destheight,
       struct TagItem * taglist)
{
    return CreateScaleEngineA(sourcewidth, sourceheight, destwidth, destheight, taglist);
}

void VARARGS68K _Render_DeleteScaleEngine(struct RenderIFace *Self,
       APTR engine)
{
    DeleteScaleEngine(engine);
}

ULONG VARARGS68K _Render_Scale(struct RenderIFace *Self,
       APTR engine,
       APTR source,
       APTR dest,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dest);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ScaleA(
        engine,
        source,
        dest,
        tags);

}

ULONG VARARGS68K _Render_ScaleA(struct RenderIFace *Self,
       APTR engine,
       APTR source,
       APTR dest,
       struct TagItem * taglist)
{
    return ScaleA(engine, source, dest, taglist);
}

ULONG VARARGS68K _Render_ConvertChunky(struct RenderIFace *Self,
       UBYTE * source,
       APTR oldpalette,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       APTR newpalette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, newpalette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ConvertChunkyA(
        source,
        oldpalette,
        width,
        height,
        dest,
        newpalette,
        tags);

}

ULONG VARARGS68K _Render_ConvertChunkyA(struct RenderIFace *Self,
       UBYTE * source,
       APTR oldpalette,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       APTR newpalette,
       struct TagItem * taglist)
{
    return ConvertChunkyA(source, oldpalette, width, height, dest, newpalette, taglist);
}

void VARARGS68K _Render_CreatePenTable(struct RenderIFace *Self,
       UBYTE * chunky,
       APTR oldpalette,
       UWORD width,
       UWORD height,
       APTR newpalette,
       UBYTE * convtab,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, convtab);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->CreatePenTableA(
        chunky,
        oldpalette,
        width,
        height,
        newpalette,
        convtab,
        tags);

}

void VARARGS68K _Render_CreatePenTableA(struct RenderIFace *Self,
       UBYTE * chunky,
       APTR oldpalette,
       UWORD width,
       UWORD height,
       APTR newpalette,
       UBYTE * convtab,
       struct TagItem * taglist)
{
    CreatePenTableA(chunky, oldpalette, width, height, newpalette, convtab, taglist);
}

APTR VARARGS68K _Render_CreatePalette(struct RenderIFace *Self,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, Self);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreatePaletteA(
        tags);

}

APTR VARARGS68K _Render_CreatePaletteA(struct RenderIFace *Self,
       struct TagItem * taglist)
{
    return CreatePaletteA(taglist);
}

void VARARGS68K _Render_DeletePalette(struct RenderIFace *Self,
       APTR palette)
{
    DeletePalette(palette);
}

void VARARGS68K _Render_ImportPalette(struct RenderIFace *Self,
       APTR palette,
       APTR coltab,
       UWORD numcols,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, numcols);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->ImportPaletteA(
        palette,
        coltab,
        numcols,
        tags);

}

void VARARGS68K _Render_ImportPaletteA(struct RenderIFace *Self,
       APTR palette,
       APTR coltab,
       UWORD numcols,
       struct TagItem * taglist)
{
    ImportPaletteA(palette, coltab, numcols, taglist);
}

void VARARGS68K _Render_ExportPalette(struct RenderIFace *Self,
       APTR palette,
       APTR coltab,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, coltab);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->ExportPaletteA(
        palette,
        coltab,
        tags);

}

void VARARGS68K _Render_ExportPaletteA(struct RenderIFace *Self,
       APTR palette,
       APTR coltab,
       struct TagItem * taglist)
{
    ExportPaletteA(palette, coltab, taglist);
}

ULONG VARARGS68K _Render_CountRGB(struct RenderIFace *Self,
       APTR histogram,
       ULONG rgb)
{
    return CountRGB(histogram, rgb);
}

LONG VARARGS68K _Render_BestPen(struct RenderIFace *Self,
       APTR palette,
       ULONG rgb)
{
    return BestPen(palette, rgb);
}

void VARARGS68K _Render_FlushPalette(struct RenderIFace *Self,
       APTR palette)
{
    FlushPalette(palette);
}

ULONG VARARGS68K _Render_SortPalette(struct RenderIFace *Self,
       APTR palette,
       ULONG mode,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, mode);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->SortPaletteA(
        palette,
        mode,
        tags);

}

ULONG VARARGS68K _Render_SortPaletteA(struct RenderIFace *Self,
       APTR palette,
       ULONG mode,
       struct TagItem * taglist)
{
    return SortPaletteA(palette, mode, taglist);
}

ULONG VARARGS68K _Render_AddHistogram(struct RenderIFace *Self,
       APTR histogram1,
       APTR histogram2,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, histogram2);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddHistogramA(
        histogram1,
        histogram2,
        tags);

}

ULONG VARARGS68K _Render_AddHistogramA(struct RenderIFace *Self,
       APTR histogram1,
       APTR histogram2,
       struct TagItem * taglist)
{
    return AddHistogramA(histogram1, histogram2, taglist);
}

UWORD VARARGS68K _Render_ScaleOrdinate(struct RenderIFace *Self,
       UWORD source,
       UWORD dest,
       UWORD ordinate)
{
    return ScaleOrdinate(source, dest, ordinate);
}

ULONG * VARARGS68K _Render_CreateHistogramPointerArray(struct RenderIFace *Self,
       APTR histogram)
{
    return CreateHistogramPointerArray(histogram);
}

ULONG VARARGS68K _Render_CountHistogram(struct RenderIFace *Self,
       APTR histogram)
{
    return CountHistogram(histogram);
}

APTR VARARGS68K _Render_CreateMapEngine(struct RenderIFace *Self,
       APTR palette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, palette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreateMapEngineA(
        palette,
        tags);

}

APTR VARARGS68K _Render_CreateMapEngineA(struct RenderIFace *Self,
       APTR palette,
       struct TagItem * taglist)
{
    return CreateMapEngineA(palette, taglist);
}

void VARARGS68K _Render_DeleteMapEngine(struct RenderIFace *Self,
       APTR engine)
{
    DeleteMapEngine(engine);
}

ULONG VARARGS68K _Render_MapRGBArray(struct RenderIFace *Self,
       APTR engine,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       UBYTE * chunky,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, chunky);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->MapRGBArrayA(
        engine,
        rgb,
        width,
        height,
        chunky,
        tags);

}

ULONG VARARGS68K _Render_MapRGBArrayA(struct RenderIFace *Self,
       APTR engine,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       UBYTE * chunky,
       struct TagItem * taglist)
{
    return MapRGBArrayA(engine, rgb, width, height, chunky, taglist);
}

LONG VARARGS68K _Render_RGBArrayDiversity(struct RenderIFace *Self,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->RGBArrayDiversityA(
        rgb,
        width,
        height,
        tags);

}

LONG VARARGS68K _Render_RGBArrayDiversityA(struct RenderIFace *Self,
       ULONG * rgb,
       UWORD width,
       UWORD height,
       struct TagItem * taglist)
{
    return RGBArrayDiversityA(rgb, width, height, taglist);
}

LONG VARARGS68K _Render_ChunkyArrayDiversity(struct RenderIFace *Self,
       UBYTE * chunky,
       APTR palette,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ChunkyArrayDiversityA(
        chunky,
        palette,
        width,
        height,
        tags);

}

LONG VARARGS68K _Render_ChunkyArrayDiversityA(struct RenderIFace *Self,
       UBYTE * chunky,
       APTR palette,
       UWORD width,
       UWORD height,
       struct TagItem * taglist)
{
    return ChunkyArrayDiversityA(chunky, palette, width, height, taglist);
}

ULONG VARARGS68K _Render_MapChunkyArray(struct RenderIFace *Self,
       APTR engine,
       UBYTE * source,
       APTR palette,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dest);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->MapChunkyArrayA(
        engine,
        source,
        palette,
        width,
        height,
        dest,
        tags);

}

ULONG VARARGS68K _Render_MapChunkyArrayA(struct RenderIFace *Self,
       APTR engine,
       UBYTE * source,
       APTR palette,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       struct TagItem * taglist)
{
    return MapChunkyArrayA(engine, source, palette, width, height, dest, taglist);
}

void VARARGS68K _Render_InsertAlphaChannel(struct RenderIFace *Self,
       UBYTE * maskarray,
       UWORD width,
       UWORD height,
       ULONG * rgbarray,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, rgbarray);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->InsertAlphaChannelA(
        maskarray,
        width,
        height,
        rgbarray,
        tags);

}

void VARARGS68K _Render_InsertAlphaChannelA(struct RenderIFace *Self,
       UBYTE * maskarray,
       UWORD width,
       UWORD height,
       ULONG * rgbarray,
       struct TagItem * taglist)
{
    InsertAlphaChannelA(maskarray, width, height, rgbarray, taglist);
}

void VARARGS68K _Render_ExtractAlphaChannel(struct RenderIFace *Self,
       ULONG * rgbarray,
       UWORD width,
       UWORD height,
       UBYTE * chunkyarray,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, chunkyarray);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->ExtractAlphaChannelA(
        rgbarray,
        width,
        height,
        chunkyarray,
        tags);

}

void VARARGS68K _Render_ExtractAlphaChannelA(struct RenderIFace *Self,
       ULONG * rgbarray,
       UWORD width,
       UWORD height,
       UBYTE * chunkyarray,
       struct TagItem * taglist)
{
    ExtractAlphaChannelA(rgbarray, width, height, chunkyarray, taglist);
}

void VARARGS68K _Render_ApplyAlphaChannel(struct RenderIFace *Self,
       ULONG * sourcearray,
       UWORD width,
       UWORD height,
       ULONG * destarray,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, destarray);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->ApplyAlphaChannelA(
        sourcearray,
        width,
        height,
        destarray,
        tags);

}

void VARARGS68K _Render_ApplyAlphaChannelA(struct RenderIFace *Self,
       ULONG * sourcearray,
       UWORD width,
       UWORD height,
       ULONG * destarray,
       struct TagItem * taglist)
{
    ApplyAlphaChannelA(sourcearray, width, height, destarray, taglist);
}

void VARARGS68K _Render_MixRGBArray(struct RenderIFace *Self,
       ULONG * sourcearray,
       UWORD width,
       UWORD height,
       ULONG * destarray,
       UWORD ratio,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, ratio);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->MixRGBArrayA(
        sourcearray,
        width,
        height,
        destarray,
        ratio,
        tags);

}

void VARARGS68K _Render_MixRGBArrayA(struct RenderIFace *Self,
       ULONG * sourcearray,
       UWORD width,
       UWORD height,
       ULONG * destarray,
       UWORD ratio,
       struct TagItem * taglist)
{
    MixRGBArrayA(sourcearray, width, height, destarray, ratio, taglist);
}

APTR VARARGS68K _Render_AllocRenderVecClear(struct RenderIFace *Self,
       APTR rendermemhandler,
       ULONG size)
{
    return AllocRenderVecClear(rendermemhandler, size);
}

void VARARGS68K _Render_CreateAlphaArray(struct RenderIFace *Self,
       ULONG * rgbarray,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->CreateAlphaArrayA(
        rgbarray,
        width,
        height,
        tags);

}

void VARARGS68K _Render_CreateAlphaArrayA(struct RenderIFace *Self,
       ULONG * rgbarray,
       UWORD width,
       UWORD height,
       struct TagItem * taglist)
{
    CreateAlphaArrayA(rgbarray, width, height, taglist);
}

void VARARGS68K _Render_MixAlphaChannel(struct RenderIFace *Self,
       ULONG * source1,
       ULONG * source2,
       UWORD width,
       UWORD height,
       ULONG * dest,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dest);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->MixAlphaChannelA(
        source1,
        source2,
        width,
        height,
        dest,
        tags);

}

void VARARGS68K _Render_MixAlphaChannelA(struct RenderIFace *Self,
       ULONG * source1,
       ULONG * source2,
       UWORD width,
       UWORD height,
       ULONG * dest,
       struct TagItem * taglist)
{
    MixAlphaChannelA(source1, source2, width, height, dest, taglist);
}

void VARARGS68K _Render_TintRGBArray(struct RenderIFace *Self,
       ULONG * source,
       UWORD width,
       UWORD height,
       ULONG RGB,
       UWORD ratio,
       ULONG * dest,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dest);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->TintRGBArrayA(
        source,
        width,
        height,
        RGB,
        ratio,
        dest,
        tags);

}

void VARARGS68K _Render_TintRGBArrayA(struct RenderIFace *Self,
       ULONG * source,
       UWORD width,
       UWORD height,
       ULONG RGB,
       UWORD ratio,
       ULONG * dest,
       struct TagItem * taglist)
{
    TintRGBArrayA(source, width, height, RGB, ratio, dest, taglist);
}

ULONG VARARGS68K _Render_GetPaletteAttrs(struct RenderIFace *Self,
       APTR palette,
       ULONG args)
{
    return GetPaletteAttrs(palette, args);
}

void VARARGS68K _Render_RemapArray(struct RenderIFace *Self,
       UBYTE * source,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       UBYTE * pentab,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pentab);
    tags = va_getlinearva(ap, struct TagItem *);

    Self->RemapArrayA(
        source,
        width,
        height,
        dest,
        pentab,
        tags);

}

void VARARGS68K _Render_RemapArrayA(struct RenderIFace *Self,
       UBYTE * source,
       UWORD width,
       UWORD height,
       UBYTE * dest,
       UBYTE * pentab,
       struct TagItem * taglist)
{
    return RemapArrayA(source, width, height, dest, pentab, taglist);
}


static void *main_vectors[] = {
        (void *)_Render_Obtain,
        (void *)_Render_Release,
        (void *)NULL,
        (void *)NULL,
        (void *)_Render_TurboFillMem,
        (void *)_Render_TurboCopyMem,
        (void *)_Render_CreateRMHandlerA,
        (void *)_Render_CreateRMHandler,
        (void *)_Render_DeleteRMHandler,
        (void *)_Render_AllocRenderMem,
        (void *)_Render_FreeRenderMem,
        (void *)_Render_AllocRenderVec,
        (void *)_Render_FreeRenderVec,
        (void *)_Render_CreateHistogramA,
        (void *)_Render_CreateHistogram,
        (void *)_Render_DeleteHistogram,
        (void *)_Render_QueryHistogram,
        (void *)_Render_AddRGB,
        (void *)_Render_AddRGBImageA,
        (void *)_Render_AddRGBImage,
        (void *)_Render_AddChunkyImageA,
        (void *)_Render_AddChunkyImage,
        (void *)_Render_ExtractPaletteA,
        (void *)_Render_ExtractPalette,
        (void *)_Render_RenderA,
        (void *)_Render_Render,
        (void *)_Render_Planar2ChunkyA,
        (void *)_Render_Planar2Chunky,
        (void *)_Render_Chunky2RGBA,
        (void *)_Render_Chunky2RGB,
        (void *)_Render_Chunky2BitMapA,
        (void *)_Render_Chunky2BitMap,
        (void *)_Render_CreateScaleEngineA,
        (void *)_Render_CreateScaleEngine,
        (void *)_Render_DeleteScaleEngine,
        (void *)_Render_ScaleA,
        (void *)_Render_Scale,
        (void *)_Render_ConvertChunkyA,
        (void *)_Render_ConvertChunky,
        (void *)_Render_CreatePenTableA,
        (void *)_Render_CreatePenTable,
        (void *)_Render_CreatePaletteA,
        (void *)_Render_CreatePalette,
        (void *)_Render_DeletePalette,
        (void *)_Render_ImportPaletteA,
        (void *)_Render_ImportPalette,
        (void *)_Render_ExportPaletteA,
        (void *)_Render_ExportPalette,
        (void *)_Render_CountRGB,
        (void *)_Render_BestPen,
        (void *)_Render_FlushPalette,
        (void *)_Render_SortPaletteA,
        (void *)_Render_SortPalette,
        (void *)_Render_AddHistogramA,
        (void *)_Render_AddHistogram,
        (void *)_Render_ScaleOrdinate,
        (void *)_Render_CreateHistogramPointerArray,
        (void *)_Render_CountHistogram,
        (void *)_Render_CreateMapEngineA,
        (void *)_Render_CreateMapEngine,
        (void *)_Render_DeleteMapEngine,
        (void *)_Render_MapRGBArrayA,
        (void *)_Render_MapRGBArray,
        (void *)_Render_RGBArrayDiversityA,
        (void *)_Render_RGBArrayDiversity,
        (void *)_Render_ChunkyArrayDiversityA,
        (void *)_Render_ChunkyArrayDiversity,
        (void *)_Render_MapChunkyArrayA,
        (void *)_Render_MapChunkyArray,
        (void *)_Render_InsertAlphaChannelA,
        (void *)_Render_InsertAlphaChannel,
        (void *)_Render_ExtractAlphaChannelA,
        (void *)_Render_ExtractAlphaChannel,
        (void *)_Render_ApplyAlphaChannelA,
        (void *)_Render_ApplyAlphaChannel,
        (void *)_Render_MixRGBArrayA,
        (void *)_Render_MixRGBArray,
        (void *)_Render_AllocRenderVecClear,
        (void *)_Render_CreateAlphaArrayA,
        (void *)_Render_CreateAlphaArray,
        (void *)_Render_MixAlphaChannelA,
        (void *)_Render_MixAlphaChannel,
        (void *)_Render_TintRGBArrayA,
        (void *)_Render_TintRGBArray,
        (void *)_Render_GetPaletteAttrs,
        (void *)_Render_RemapArrayA,
        (void *)_Render_RemapArray,
        (void *)-1
};

extern ULONG VecTable68K;

static struct TagItem mainTags[] =
{
    {MIT_Name,              (uint32)"main"},
    {MIT_VectorTable,       (uint32)main_vectors},
    {MIT_Version,           1},
    {TAG_DONE,              0}
};

static uint32 libInterfaces[] =
{
    (uint32)lib_managerTags,
    (uint32)mainTags,
    (uint32)0
};

struct TagItem libCreateTags[] =
{
    {CLT_DataSize,         (uint32)(sizeof(struct RenderBase))},
    {CLT_InitFunc,         (uint32)libInit},
    {CLT_Interfaces,       (uint32)libInterfaces},
    {CLT_Vector68K,        (uint32)&VecTable68K},
    {TAG_DONE,             0}
};


/* ------------------- ROM Tag ------------------------ */
static struct Resident __attribute__((used)) lib_res =
{
    RTC_MATCHWORD,
    &lib_res,
    &lib_res+1,
    RTF_NATIVE|RTF_AUTOINIT, /* Add RTF_COLDSTART if you want to be resident */
    LIB_VERSION,
    NT_LIBRARY, /* Make this NT_DEVICE if needed */
    0, /* PRI, usually not needed unless you're resident */
    "render.library",
    VSTRING,
    libCreateTags
};

