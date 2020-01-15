/*
 *  $VER: init.c $Revision$ (02-Mar-2005)
 *
 *  This file is part of guigfx.
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
#include <exec/interfaces.h>
#include <exec/libraries.h>
#include <exec/emulation.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <stdarg.h>
#include <interfaces/guigfx.h>

#include <proto/dos.h>

#include "guigfx_global.h"

#define VSTRING LIBNAME " " LIBVER " " LIBDATE LIBTYPE "\r\n"

static const char __attribute__((used)) LibVersion[] = "\0$VER: " LIBNAME " " LIBVER " " LIBDATE LIBTYPE;

struct GuiGFXBase *GuiGFXBase = NULL;


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
    struct GuiGFXBase *libBase = (struct GuiGFXBase *)Self->Data.LibBase;

    ObtainSemaphore(&GuiGFXBase->LockSemaphore);

    if(++libBase->LibNode.lib_OpenCnt == 1)
    {
            if(!GGFX_Init())
            {
                    GGFX_Exit();

                    libBase->LibNode.lib_OpenCnt--;

                    libBase = NULL;
            }
    }

    ReleaseSemaphore(&GuiGFXBase->LockSemaphore);

    return (struct Library *)libBase;

}

/* Close the library */
APTR libClose(struct LibraryManagerInterface *Self)
{
    struct GuiGFXBase *libBase = (struct GuiGFXBase *)Self->Data.LibBase;
    /* Make sure to undo what open did */

    ObtainSemaphore(&libBase->LockSemaphore);

    if (libBase->LibNode.lib_OpenCnt > 0)
    {
            if (!(--libBase->LibNode.lib_OpenCnt))
                    GGFX_Exit();
    }

    ReleaseSemaphore(&libBase->LockSemaphore);

    return 0;
}

/* Expunge the library */
APTR libExpunge(struct LibraryManagerInterface *Self)
{
    /* If your library cannot be expunged, return 0 */
    APTR result = (APTR)0;
    struct GuiGFXBase *libBase = (struct GuiGFXBase *)Self->Data.LibBase;
    if (libBase->LibNode.lib_OpenCnt == 0)
    {
        result = (APTR)libBase->LibSegment;
        /* Undo what the init code did */

        Remove((struct Node *)libBase);
        DeleteLibrary((struct Library *)libBase);

        GuiGFXBase = NULL;
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
    struct GuiGFXBase *libBase = (struct GuiGFXBase *)LibraryBase;

    IExec = (struct ExecIFace *)exec;

    GuiGFXBase = libBase;

    libBase->LibNode.lib_Node.ln_Type = NT_LIBRARY;
    libBase->LibNode.lib_Node.ln_Pri  = 0;
    libBase->LibNode.lib_Node.ln_Name = "guigfx.library";
    libBase->LibNode.lib_Flags        = LIBF_SUMUSED|LIBF_CHANGED;
    libBase->LibNode.lib_Version      = VERSION;
    libBase->LibNode.lib_Revision     = REVISION;
    libBase->LibNode.lib_IdString     = VSTRING;

    libBase->LibSegment = (BPTR)seglist;

    InitSemaphore(&GuiGFXBase->LockSemaphore);

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

ULONG _GuiGFX_Obtain(struct GuiGFXIFace *Self)
{
    return (ULONG)0;
}

ULONG _GuiGFX_Release(struct GuiGFXIFace *Self)
{
    return (ULONG)0;
}

APTR VARARGS68K _GuiGFX_MakePicture(struct GuiGFXIFace *Self,
       APTR array,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->MakePictureA(
        array,
        width,
        height,
        tags);

}

APTR VARARGS68K _GuiGFX_MakePictureA(struct GuiGFXIFace *Self,
       APTR array,
       UWORD width,
       UWORD height,
       struct TagItem * tags)
{

    return MakePictureA(array, width, height, tags);
}

APTR VARARGS68K _GuiGFX_LoadPicture(struct GuiGFXIFace *Self,
       STRPTR filename,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, filename);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->LoadPictureA(
        filename,
        tags);

}

APTR VARARGS68K _GuiGFX_LoadPictureA(struct GuiGFXIFace *Self,
       STRPTR filename,
       struct TagItem * tags)
{
    return LoadPictureA(filename, tags);
}


APTR VARARGS68K _GuiGFX_ReadPicture(struct GuiGFXIFace *Self,
       struct RastPort * a0arg,
       struct ColorMap * colormap,
       UWORD x,
       UWORD y,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ReadPictureA(
        a0arg,
        colormap,
        x,
        y,
        width,
        height,
        tags);

}

APTR VARARGS68K _GuiGFX_ReadPictureA(struct GuiGFXIFace *Self,
       struct RastPort * a0arg,
       struct ColorMap * colormap,
       UWORD x,
       UWORD y,
       UWORD width,
       UWORD height,
       struct TagItem * tags)
{
    return ReadPictureA(a0arg, colormap, x, y, width, height, tags);
}

APTR VARARGS68K _GuiGFX_ClonePicture(struct GuiGFXIFace *Self,
       APTR pic,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pic);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ClonePictureA(
        pic,
        tags);

}

APTR VARARGS68K _GuiGFX_ClonePictureA(struct GuiGFXIFace *Self,
       APTR pic,
       struct TagItem * tags)
{
    return ClonePictureA(pic, tags);
}

void VARARGS68K _GuiGFX_DeletePicture(struct GuiGFXIFace *Self,
       APTR pic)
{
    DeletePicture(pic);
}

BOOL VARARGS68K _GuiGFX_UpdatePicture(struct GuiGFXIFace *Self,
       APTR pic)
{
    return UpdatePicture(pic);
}

APTR VARARGS68K _GuiGFX_AddPicture(struct GuiGFXIFace *Self,
       APTR psm,
       APTR pic,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pic);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddPictureA(
        psm,
        pic,
        tags);

}

APTR VARARGS68K _GuiGFX_AddPictureA(struct GuiGFXIFace *Self,
       APTR psm,
       APTR pic,
       struct TagItem * tags)
{
    return AddPictureA(psm, pic, tags);
}

APTR VARARGS68K _GuiGFX_AddPalette(struct GuiGFXIFace *Self,
       APTR psm,
       APTR palette,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, palette);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddPaletteA(
        psm,
        palette,
        tags);

}

APTR VARARGS68K _GuiGFX_AddPaletteA(struct GuiGFXIFace *Self,
       APTR psm,
       APTR palette,
       struct TagItem * tags)
{
    return AddPaletteA(psm, palette, tags);
}

APTR VARARGS68K _GuiGFX_AddPixelArray(struct GuiGFXIFace *Self,
       APTR psm,
       APTR array,
       UWORD width,
       UWORD height,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, height);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->AddPixelArrayA(
        psm,
        array,
        width,
        height,
        tags);

}

APTR VARARGS68K _GuiGFX_AddPixelArrayA(struct GuiGFXIFace *Self,
       APTR psm,
       APTR array,
       UWORD width,
       UWORD height,
       struct TagItem * tags)
{
    return AddPixelArrayA(psm, array, width, height, tags);
}

void VARARGS68K _GuiGFX_RemColorHandle(struct GuiGFXIFace *Self,
       APTR colorhandle)
{
    RemColorHandle(colorhandle);
}

APTR VARARGS68K _GuiGFX_CreatePenShareMap(struct GuiGFXIFace *Self,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, Self);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreatePenShareMapA(
        tags);

}

APTR VARARGS68K _GuiGFX_CreatePenShareMapA(struct GuiGFXIFace *Self,
       struct TagItem * tags)
{
    return CreatePenShareMapA(tags);
}

void VARARGS68K _GuiGFX_DeletePenShareMap(struct GuiGFXIFace *Self,
       APTR psm)
{
    DeletePenShareMap(psm);
}

APTR VARARGS68K _GuiGFX_ObtainDrawHandle(struct GuiGFXIFace *Self,
       APTR psm,
       struct RastPort * a1arg,
       struct ColorMap * cm,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, cm);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->ObtainDrawHandleA(
        psm,
        a1arg,
        cm,
        tags);

}

APTR VARARGS68K _GuiGFX_ObtainDrawHandleA(struct GuiGFXIFace *Self,
       APTR psm,
       struct RastPort * a1arg,
       struct ColorMap * cm,
       struct TagItem * tags)
{
    return ObtainDrawHandleA(psm, a1arg, cm, tags);
}

void VARARGS68K _GuiGFX_ReleaseDrawHandle(struct GuiGFXIFace *Self,
       APTR drawhandle)
{
    ReleaseDrawHandle(drawhandle);
}

BOOL VARARGS68K _GuiGFX_DrawPicture(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR pic,
       UWORD x,
       UWORD y,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, y);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->DrawPictureA(
        drawhandle,
        pic,
        x,
        y,
        tags);

}

BOOL VARARGS68K _GuiGFX_DrawPictureA(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR pic,
       UWORD x,
       UWORD y,
       struct TagItem * tags)
{
    return DrawPictureA(drawhandle, pic, x, y, tags);
}

BOOL VARARGS68K _GuiGFX_MapPalette(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR palette,
       UBYTE * pentab,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pentab);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->MapPaletteA(
        drawhandle,
        palette,
        pentab,
        tags);

}

BOOL VARARGS68K _GuiGFX_MapPaletteA(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR palette,
       UBYTE * pentab,
       struct TagItem * tags)
{
    return MapPaletteA(drawhandle, palette, pentab, tags);
}

LONG VARARGS68K _GuiGFX_MapPen(struct GuiGFXIFace *Self,
       APTR drawhandle,
       ULONG rgb,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, rgb);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->MapPenA(
        drawhandle,
        rgb,
        tags);

}

LONG VARARGS68K _GuiGFX_MapPenA(struct GuiGFXIFace *Self,
       APTR drawhandle,
       ULONG rgb,
       struct TagItem * tags)
{
    return MapPenA(drawhandle, rgb, tags);
}

struct BitMap *  VARARGS68K _GuiGFX_CreatePictureBitMap(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR pic,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pic);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreatePictureBitMapA(
        drawhandle,
        pic,
        tags);

}

struct BitMap * VARARGS68K _GuiGFX_CreatePictureBitMapA(struct GuiGFXIFace *Self,
       APTR drawhandle,
       APTR pic,
       struct TagItem * tags)
{
    return CreatePictureBitMapA(drawhandle, pic, tags);
}

ULONG VARARGS68K _GuiGFX_DoPictureMethod(struct GuiGFXIFace *Self,
       APTR pic,
       ULONG method,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, method);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->DoPictureMethodA(
        pic,
        method,
        tags);

}

ULONG VARARGS68K _GuiGFX_DoPictureMethodA(struct GuiGFXIFace *Self,
       APTR pic,
       ULONG method,
       ULONG * arguments)
{
    return DoPictureMethodA(pic, method, arguments);
}

ULONG VARARGS68K _GuiGFX_GetPictureAttrs(struct GuiGFXIFace *Self,
       APTR pic,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, pic);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->GetPictureAttrsA(
        pic,
        tags);

}

ULONG VARARGS68K _GuiGFX_GetPictureAttrsA(struct GuiGFXIFace *Self,
       APTR pic,
       struct TagItem * tags)
{
    return GetPictureAttrsA(pic, tags);
}

ULONG VARARGS68K _GuiGFX_LockPicture(struct GuiGFXIFace *Self,
       APTR pic,
       ULONG mode,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, mode);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->LockPictureA(
        pic,
        mode,
        tags);

}

ULONG VARARGS68K _GuiGFX_LockPictureA(struct GuiGFXIFace *Self,
       APTR pic,
       ULONG mode,
       ULONG * args)
{
    return LockPictureA(pic, mode, args);
}

void VARARGS68K _GuiGFX_UnLockPicture(struct GuiGFXIFace *Self,
       APTR pic,
       ULONG mode)
{
    UnLockPicture(pic, mode);
}

BOOL VARARGS68K _GuiGFX_IsPicture(struct GuiGFXIFace *Self,
       char * filename,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, filename);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->IsPictureA(
        filename,
        tags);

}

BOOL VARARGS68K _GuiGFX_IsPictureA(struct GuiGFXIFace *Self,
       char * filename,
       struct TagItem * tags)
{
    return IsPictureA(filename, tags);
}

APTR VARARGS68K _GuiGFX_CreateDirectDrawHandle(struct GuiGFXIFace *Self,
       APTR drawhandle,
       UWORD sw,
       UWORD sh,
       UWORD dw,
       UWORD dh,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, dh);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreateDirectDrawHandleA(
        drawhandle,
        sw,
        sh,
        dw,
        dh,
        tags);

}

APTR VARARGS68K _GuiGFX_CreateDirectDrawHandleA(struct GuiGFXIFace *Self,
       APTR drawhandle,
       UWORD sw,
       UWORD sh,
       UWORD dw,
       UWORD dh,
       struct TagItem * tags)
{
    return CreateDirectDrawHandleA(drawhandle, sw, sh, dw, dh, tags);
}

void VARARGS68K _GuiGFX_DeleteDirectDrawHandle(struct GuiGFXIFace *Self,
       APTR ddh)
{
    DeleteDirectDrawHandle(ddh);
}

BOOL VARARGS68K _GuiGFX_DirectDrawTrueColor(struct GuiGFXIFace *Self,
       APTR ddh,
       ULONG * array,
       UWORD x,
       UWORD y,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, y);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->DirectDrawTrueColorA(
        ddh,
        array,
        x,
        y,
        tags);

}

BOOL VARARGS68K _GuiGFX_DirectDrawTrueColorA(struct GuiGFXIFace *Self,
       APTR ddh,
       ULONG * array,
       UWORD x,
       UWORD y,
       struct TagItem * tags)
{
    return DirectDrawTrueColorA(ddh, array, x, y, tags);
}

BOOL VARARGS68K _GuiGFX_CreatePictureMask(struct GuiGFXIFace *Self,
       APTR pic,
       UBYTE * mask,
       UWORD maskwidth,
       ...)
{
    va_list ap;
    struct TagItem *tags;

    va_startlinear(ap, maskwidth);
    tags = va_getlinearva(ap, struct TagItem *);

    return Self->CreatePictureMaskA(
        pic,
        mask,
        maskwidth,
        tags);

}

BOOL VARARGS68K _GuiGFX_CreatePictureMaskA(struct GuiGFXIFace *Self,
       APTR pic,
       UBYTE * mask,
       UWORD maskwidth,
       struct TagItem * tags)
{
    return CreatePictureMaskA(pic, mask, maskwidth, tags);
}

static void *main_vectors[] = {
        (void *)_GuiGFX_Obtain,
        (void *)_GuiGFX_Release,
        (void *)NULL,
        (void *)NULL,
        (void *)_GuiGFX_MakePictureA,
        (void *)_GuiGFX_MakePicture,
        (void *)_GuiGFX_LoadPictureA,
        (void *)_GuiGFX_LoadPicture,
        (void *)_GuiGFX_ReadPictureA,
        (void *)_GuiGFX_ReadPicture,
        (void *)_GuiGFX_ClonePictureA,
        (void *)_GuiGFX_ClonePicture,
        (void *)_GuiGFX_DeletePicture,
        (void *)_GuiGFX_UpdatePicture,
        (void *)_GuiGFX_AddPictureA,
        (void *)_GuiGFX_AddPicture,
        (void *)_GuiGFX_AddPaletteA,
        (void *)_GuiGFX_AddPalette,
        (void *)_GuiGFX_AddPixelArrayA,
        (void *)_GuiGFX_AddPixelArray,
        (void *)_GuiGFX_RemColorHandle,
        (void *)_GuiGFX_CreatePenShareMapA,
        (void *)_GuiGFX_CreatePenShareMap,
        (void *)_GuiGFX_DeletePenShareMap,
        (void *)_GuiGFX_ObtainDrawHandleA,
        (void *)_GuiGFX_ObtainDrawHandle,
        (void *)_GuiGFX_ReleaseDrawHandle,
        (void *)_GuiGFX_DrawPictureA,
        (void *)_GuiGFX_DrawPicture,
        (void *)_GuiGFX_MapPaletteA,
        (void *)_GuiGFX_MapPalette,
        (void *)_GuiGFX_MapPenA,
        (void *)_GuiGFX_MapPen,
        (void *)_GuiGFX_CreatePictureBitMapA,
        (void *)_GuiGFX_CreatePictureBitMap,
        (void *)_GuiGFX_DoPictureMethodA,
        (void *)_GuiGFX_DoPictureMethod,
        (void *)_GuiGFX_GetPictureAttrsA,
        (void *)_GuiGFX_GetPictureAttrs,
        (void *)_GuiGFX_LockPictureA,
        (void *)_GuiGFX_LockPicture,
        (void *)_GuiGFX_UnLockPicture,
        (void *)_GuiGFX_IsPictureA,
        (void *)_GuiGFX_IsPicture,
        (void *)_GuiGFX_CreateDirectDrawHandleA,
        (void *)_GuiGFX_CreateDirectDrawHandle,
        (void *)_GuiGFX_DeleteDirectDrawHandle,
        (void *)_GuiGFX_DirectDrawTrueColorA,
        (void *)_GuiGFX_DirectDrawTrueColor,
        (void *)_GuiGFX_CreatePictureMaskA,
        (void *)_GuiGFX_CreatePictureMask,
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
    {CLT_DataSize,         (uint32)(sizeof(struct GuiGFXBase))},
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
    VERSION,
    NT_LIBRARY, /* Make this NT_DEVICE if needed */
    0, /* PRI, usually not needed unless you're resident */
    "guigfx.library",
    VSTRING,
    libCreateTags
};


