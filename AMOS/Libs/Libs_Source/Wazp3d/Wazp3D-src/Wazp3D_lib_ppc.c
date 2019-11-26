/* Wazp3D - Alain THELLIER - Paris - FRANCE 							*/
/* Adaptation to AROS from Matthias Rustler							*/
/* Code clean-up and library enhancements from Gunther Nikl					*/
/* LICENSE: GNU General Public License (GNU GPL) for this file				*/

/* This file contain the Wazp3d3D OS4/ppc library header					*/

#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <utility/tagitem.h>
#include <stdarg.h>

/*==================================================================================*/
#include <Warp3D/Warp3D.h>		/* for warpd3 structures definitions 		*/
#include <interfaces/warp3d.h>	/* for struct Warp3DIFace 		 		*/
#include "Warp3D_protos.h"		/* for classic warpd3 functions prototypes	*/
BOOL WAZP3D_Init(void *exec);		/* Open OS libraries  and do the inits		*/
void WAZP3D_Close();			/* Close OS libraries and close/free all		*/
/*==================================================================================*/
#define VERSION	53			/* We keep original Warp3D's version/name/date	*/
#define REVISION	1
#define DATE	"24.7.2008"
#define LIBNAME   "Warp3D.library"
#define VERS	"Warp3D.library 53.1"
#define VSTRING	"Warp3D.library 53.1 (24.7.2008)\r\n"
#define VERSTAG	"\0$VER: Warp3D.library 53.1 (24.7.2008)"
#define FULLNAME VERS " " DATE " OS4.1 PPC"
/*==================================================================================*/

/* Version Tag */
STATIC CONST UBYTE USED verstag[] = VERSTAG;

struct ExampleLibrary
{
	struct Library libNode;
	BPTR segList;
	/* If you need more data fields, add them here */
	struct ExecIFace *IExec;
};

/*
 * The system (and compiler) rely on a symbol named _start which marks
 * the beginning of execution of an ELF file. To prevent others from 
 * executing this library, and to keep the compiler/linker happy, we
 * define an empty _start symbol here.
 *
 * On the classic system (pre-AmigaOS 4.x) this was usually done by
 * moveq #0,d0
 * rts
 *
 */
int32 _start(void);

int32 _start(void)
{
	/* If you feel like it, open DOS and print something to the user */
	return RETURN_FAIL;
}


/* Open the library */
STATIC struct Library *libOpen(struct LibraryManagerInterface *Self, ULONG version)
{
	struct ExampleLibrary *libBase = (struct ExampleLibrary *)Self->Data.LibBase; 

	if (version > VERSION)
		return(NULL);
	/* Add any specific open code here 
	   Return 0 before incrementing OpenCnt to fail opening */
	/* Add up the open count */
	libBase->libNode.lib_OpenCnt++;
	return(&libBase->libNode);

}


/* Close the library */
STATIC APTR libClose(struct LibraryManagerInterface *Self)
{
	struct ExampleLibrary *libBase = (struct ExampleLibrary *)Self->Data.LibBase;
	/* Make sure to undo what open did */

	/* Make the close count */
	libBase->libNode.lib_OpenCnt--;

	return 0;
}


/* Expunge the library */
STATIC APTR libExpunge(struct LibraryManagerInterface *Self)
{
	/* If your library cannot be expunged, return 0 */
	APTR result = (APTR)0;
	struct ExampleLibrary *libBase = (struct ExampleLibrary *)Self->Data.LibBase;

	if (libBase->libNode.lib_OpenCnt == 0)
	{
		result = (APTR)libBase->segList;
		/* Undo what the init code did */
		WAZP3D_Close();

		libBase->IExec->Remove((struct Node *)libBase);
		libBase->IExec->DeleteLibrary(&libBase->libNode);
	}
	else
	{
		result = (APTR)0;
		libBase->libNode.lib_Flags |= LIBF_DELEXP;
	}

	return result;
}

/* The ROMTAG Init Function */
STATIC struct Library *libInit(struct Library *LibraryBase, APTR seglist, struct Interface *exec)
{
struct ExampleLibrary *libBase = (struct ExampleLibrary *)LibraryBase;

	libBase->IExec=(void*)exec;

	libBase->libNode.lib_Node.ln_Type	= NT_LIBRARY;
	libBase->libNode.lib_Node.ln_Pri	= 0;
	libBase->libNode.lib_Node.ln_Name	= LIBNAME;
	libBase->libNode.lib_Flags		= LIBF_SUMUSED|LIBF_CHANGED;
	libBase->libNode.lib_Version 	 	= VERSION;
	libBase->libNode.lib_Revision 	= REVISION;
	libBase->libNode.lib_IdString 	= VSTRING;

	libBase->segList = (BPTR)seglist;

	/* Add additional init code here if you need it. For example, to open additional Libraries*/
	if(WAZP3D_Init(exec))
	   	return (&libBase->libNode);
	else
		return NULL;
}
/* ------------------- Manager Interface ------------------------ */
/* These are generic. Replace if you need more fancy stuff */
STATIC uint32 _manager_Obtain(struct LibraryManagerInterface *Self)
{
	uint32 res;
	__asm__ __volatile__(
	"1:	lwarx	%0,0,%1\n"
	"addic	%0,%0,1\n"
	"stwcx.	%0,0,%1\n"
	"bne-	1b"
	: "=&r" (res)
	: "r" (&Self->Data.RefCount)
	: "cc", "memory");

	return res;
}

STATIC uint32 _manager_Release(struct LibraryManagerInterface *Self)
{
	uint32 res;
	__asm__ __volatile__(
	"1:	lwarx	%0,0,%1\n"
	"addic	%0,%0,-1\n"
	"stwcx.	%0,0,%1\n"
	"bne-	1b"
	: "=&r" (res)
	: "r" (&Self->Data.RefCount)
	: "cc", "memory");

	return res;
}


ULONG LibObtain(struct Warp3DIFace *Self)
{
	return Self->Data.RefCount++;
}

ULONG LibRelease(struct Warp3DIFace *Self)
{
	return Self->Data.RefCount--;
}

/*==================================================================================*/
#include "Wazp3D_68k_to_ppc.h"
#include "Wazp3D_functions_glue_ppc.h"
/*==================================================================================*/
/* Manager interface vectors */
STATIC CONST APTR lib_manager_vectors[] =
{
	_manager_Obtain,
	_manager_Release,
	NULL,
	NULL,
	libOpen,
	libClose,
	libExpunge,
	NULL,
	(APTR)-1
};

/* "__library" interface tag list */
STATIC CONST struct TagItem lib_managerTags[] =
{
	{ MIT_Name,			(Tag)"__library"		},
	{ MIT_VectorTable,	(Tag)lib_manager_vectors},
	{ MIT_Version,		1						},
	{ TAG_DONE,			0						}
};

/* ------------------- Library Interface(s) ------------------------ */
/* Uncomment this line (and see below) if your library has a 68k jump table */
/* extern APTR VecTable68K[]; */

STATIC CONST struct TagItem mainTags[] =
{
	{ MIT_Name,			(Tag)"main"			},
	{ MIT_VectorTable,	(Tag)main_vectors	},
	{ MIT_Version,		1					},
	{ TAG_DONE,			0					}
};

STATIC CONST CONST_APTR libInterfaces[] =
{
	lib_managerTags,
	mainTags,
	NULL
};

STATIC CONST struct TagItem libCreateTags[] =
{
	{ CLT_DataSize,		sizeof(struct ExampleLibrary)	},
	{ CLT_InitFunc,		(Tag)libInit			},
	{ CLT_Interfaces,	(Tag)libInterfaces		},
	/* Uncomment the following line if you have a 68k jump table */
	{ CLT_Vector68K, (Tag)VecTable68K },
	{TAG_DONE,		 0 }
};


/* ------------------- ROM Tag ------------------------ */
STATIC CONST struct Resident lib_res USED =
{
	RTC_MATCHWORD,
	(struct Resident *)&lib_res,
	(APTR)(&lib_res + 1),
	RTF_NATIVE|RTF_AUTOINIT, /* Add RTF_COLDSTART if you want to be resident */
	VERSION,
	NT_LIBRARY, /* Make this NT_DEVICE if needed */
	0, /* PRI, usually not needed unless you're resident */
	LIBNAME,
	VSTRING,
	(APTR)libCreateTags
};

