/* config.c
** Handles the processing of MRQ's configfile
**
** ©1997-2000 by Matthias.Bethke <Matthias.Bethke@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id: config.c 1.4 2000/10/15 13:29:23 msbethke Exp msbethke $
**
** $Log: config.c $
** Revision 1.4  2000/10/15 13:29:23  msbethke
** oops - forgot an argument to the warning message...
**
** Revision 1.3  2000/10/15 12:51:25  msbethke
** Additional warning in FillDefaultClass()
**
** Revision 1.2  2000/01/25 17:28:45  msbethke
** Adapted to new header names
**
** Revision 1.1  2000/01/25 17:20:15  msbethke
** Initial revision
**
**
*/

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/locale.h>
#include <proto/intuition.h>
#include <exec/memory.h>
#include <lib/mb_utils.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mrq.h"
#include "config.h"
#include "gfxfiles.h"


/* local protos */
static STRPTR AddMiscClassString(STRPTR,struct MRQConfig*,STRPTR*,STRPTR);
static STRPTR AddLocalizedString(STRPTR,LONG,struct MRQConfig*,ULONG);
static STRPTR AddMRQString(STRPTR,struct MRQConfig*,ULONG);
static void FillDefaultClass(struct MRQConfig*);
static STRPTR MkImagePath(STRPTR);



struct MRQConfig *ReadMRQConfig(STRPTR Name)
{
STRPTR err=NULL;
static struct MRQConfig Config={0};

	prdebug("ReadMRQConfig()\n");
	if(Config.mc_MemPool = CreatePool(MEMF_ANY | MEMF_CLEAR,1024,512))
	{
	BPTR fh;


		if(ttVars.AvoidTasks)		// store AVOIDTASKS pattern preparsed
		{
		STRPTR t;
		LONG destlen;

			destlen = strlen(ttVars.AvoidTasks)*2+2;
			if(t = AllocVecPooled(Config.mc_MemPool,destlen))
			{
				if(ParsePattern(ttVars.AvoidTasks,t,destlen) == -1)
				{
					err = MRQERROR_BADPATTERN;
				} else ttVars.AvoidTasks = t;
			} else err=MRQERROR_NOMEMORY;
		}

		if(ttVars.IButtonsByText)
		{
		STRPTR s;

			if(s = AllocVecPooled(Config.mc_MemPool,strlen(ttVars.IButtonsByText)+1))
			{
				strcpy(s,ttVars.IButtonsByText);
				Config.mc_IButton_Yes.mib_Text	= strtok(s,",");
				Config.mc_IButton_No.mib_Text		= strtok(NULL,",");
				Config.mc_IButton_Cancel.mib_Text= strtok(NULL,",");
				if(Config.mc_IButton_Yes.mib_Text &&
					Config.mc_IButton_No.mib_Text	&&
					Config.mc_IButton_Cancel.mib_Text)
				{
					prdebug("ImageButton matchtexts:\n\tYes   : %s\n\tNo    : %s\n\tCancel: %s\n",
						Config.mc_IButton_Yes.mib_Text,
						Config.mc_IButton_No.mib_Text,
						Config.mc_IButton_Cancel.mib_Text);
				} else
				{
					prdebug("Specify exactly one pattern for YES, NO and CANCEL,\nseparated by commas, for IBUTTONSBYTEXT!\n");
					ttVars.IButtonsByText = NULL;
					FreeVecPooled(Config.mc_MemPool,s);
				}
			} else err = MRQERROR_NOMEMORY;
		}
		ReadImageButtons(&Config);
		FillDefaultClass(&Config);

		NewList((struct List*)(&Config.mc_ClassList));

		if(!err && (fh = Open(Name,MODE_OLDFILE)))
		{
		struct RDArgs *rda, *fargs;

			prdebug("Reading configfile\n");
			if(rda = AllocDosObjectTagList(DOS_RDARGS,NULL))
			{
			UBYTE LBuf[512];
			struct Arguments args;
			LONG line=0;
			ULONG Flags;

				while(FGets(fh,LBuf,sizeof(LBuf)) && (!err))
				{
					line++;
					memset(&args,0,sizeof(args));

					rda->RDA_Source.CS_Buffer = LBuf;
					rda->RDA_Source.CS_Length = strlen(LBuf);
					rda->RDA_Source.CS_CurChr = 0;
					rda->RDA_Buffer = NULL;
					rda->RDA_BufSiz = 0;
					rda->RDA_Flags  = RDAF_NOPROMPT;

					if(LBuf[rda->RDA_Source.CS_Length-1] != '\n')
						LBuf[rda->RDA_Source.CS_Length++] = '\n';

					if(!(fargs = ReadArgs(CONFIG_RDAPATTERN,(LONG*)(&args),rda)))
					{
						prdebug("Parse error in line %ld, continuing...\n",line);
						continue;
					}


					Flags = 0;
					if(args.Substring)	Flags |= MSF_SUBSTRING;
					if(args.Pattern)		Flags |= MSF_PATTERN;
					if(args.NoCase)		Flags |= MSF_NOCASE;
					if(args.Formatted)	Flags |= MSF_FORMATTED;
					if((Flags & MSF_SUBSTRING) && (Flags & MSF_PATTERN))
					{
						prdebug("Warning: PATTERN and SUBSTRING are mutually exclusive (line %ld)!\n",(LONG)line);
						Flags &= ~MSF_SUBSTRING;
					}


					if(args.NewClass)
					{
					struct MRQEventClass *class;

						if(class = AllocVecPooled(Config.mc_MemPool,sizeof(struct MRQEventClass)))
						{
							NewList((struct List*)(&(class->mec_StringList)));
							AddTail((struct List*)(&Config.mc_ClassList),(struct Node*)class);
						} else err = MRQERROR_NOMEMORY;
					}

					else if(args.Locale)
					{
					STRPTR LocName;
					int ArgNum;
					
						LocName = *args.Locale;

						if(args.Locale[1])
						{
						LONG StringNum;

							for(ArgNum=1; args.Locale[ArgNum] && !err ; ArgNum++)
							{
								StringNum = strtol(args.Locale[ArgNum],NULL,10);
								err = AddLocalizedString(LocName,StringNum,&Config,Flags);
							}
						} else prdebug("Dubious or missing parameter in line %ld: %s\n",line,LocName);
					}

					else if(args.String)
					{
						if(err = AddMRQString(args.String,&Config,Flags)) break;
					}

					else if(args.Image)
					{
					STRPTR tmpimgname;
					struct MRQImage *img;

						tmpimgname = MkImagePath(args.Image);
						img = &(((struct MRQEventClass*)(Config.mc_ClassList.mlh_TailPred))->mec_Image);

						if(args.Transparent)	img->mi_Flags |= MIF_TRANSPARENT;
						if(args.Animation)	img->mi_Flags |= MIF_ANIMATION;
	
						if(args.Preload)
						{
							if(PreloadImage(tmpimgname,img))
							{
								prdebug("Preloaded image '%s'\n",args.Image);
							} else err = MRQERROR_LOADIMAGE;
						} else
						{
							AddMiscClassString(tmpimgname,&Config,(STRPTR*)(&img->mi_Object),"an image");
							img->mi_Flags |= MIF_FILENAME;
						}
						FreeVec(tmpimgname);
					}

					else if(args.RxPort || args.RxCmd)
					{
						if(args.RxPort)
						{
							err = AddMiscClassString(args.RxPort,&Config,&(((struct MRQEventClass*)(Config.mc_ClassList.mlh_TailPred))->mec_RxPortName),"an ARexx port");
						}

						if(args.RxCmd && !err)
						{
							err = AddMiscClassString(args.RxCmd,&Config,&(((struct MRQEventClass*)(Config.mc_ClassList.mlh_TailPred))->mec_RxCmdString),"an ARexx command");
						}
					}
					FreeArgs(fargs);
				}
				FreeDosObject(DOS_RDARGS,rda);
			} else err = MRQERROR_NOMEMORY;
			Close(fh);
		} else err = MRQERROR_NOCONFIGFILE;
	} else err=MRQERROR_NOMEMORY;

	if(err || IsListEmpty((struct List*)(&Config.mc_ClassList)))
	{
		DeletePool(Config.mc_MemPool);
		prdebug(err ?	"Initialization error: %s!\n" :
							"Config file doesn't contain any class definitions!\n",err);
		return NULL;
	} else prdebug("Configfile read OK\n");
	return &Config;
}

void FreeMRQConfig(struct MRQConfig *cfg) 
{
	FreeImageButtons(cfg);
	FreePreloaded(cfg);
	DeletePool(cfg->mc_MemPool);
}

static STRPTR AddLocalizedString(STRPTR CatName, LONG StringNum, struct MRQConfig *cfg, ULONG Flags)
{
struct Catalog *cat;
STRPTR ret=NULL;

	if(cat = OpenCatalogA(NULL,CatName,NULL))
	{
	STRPTR s;

		if(s=GetCatalogStr(cat,StringNum,NULL))
		{
			ret = AddMRQString(s,cfg,Flags);
		} else
		{
			prdebug("Can't read string #%ld from catalog %s!\n",StringNum,CatName);
			ret = "GetCatalogStr() failed";
		}
		CloseCatalog(cat);
	}
	return ret;
}

static STRPTR AddMRQString(STRPTR s, struct MRQConfig *cfg, ULONG Flags)
{
struct MRQString *mstr;
ULONG slen;

	if(cfg->mc_ClassList.mlh_TailPred == (struct MinNode*)(&cfg->mc_ClassList))
	{
		prdebug("Can't add a string without a class!\n");
		return MRQERROR_CONFIGFORMAT;
	}

	slen = strlen(s)+2;
	if(Flags & MSF_PATTERN) slen <<= 1;

	if(mstr = AllocVecPooled(cfg->mc_MemPool,sizeof(struct MRQString)+slen))
	{
		if(Flags & MSF_PATTERN)
		{
		LONG iswild;

			if(Flags & MSF_NOCASE) iswild = ParsePatternNoCase(s,(STRPTR)(mstr+1),slen);
			else iswild = ParsePattern(s,(STRPTR)(mstr+1),slen);
			if(iswild == -1)
			{
				FreeVecPooled(cfg->mc_MemPool,mstr);
				return MRQERROR_BADPATTERN;
			}
		} else
		{
			strcpy((char*)(mstr+1),s);
		}

		mstr->ms_String = (STRPTR)(mstr+1);
		mstr->ms_Flags  = Flags;

		AddTail((struct List*)(&((struct MRQEventClass*)(cfg->mc_ClassList.mlh_TailPred))->mec_StringList),
					(struct Node*)mstr);
		return NULL;
	} else return MRQERROR_NOMEMORY;
	return FALSE;
}

static STRPTR AddMiscClassString(STRPTR s, struct MRQConfig *cfg, STRPTR *dest, STRPTR ItemDesc)
{
STRPTR ret=NULL;
	if(cfg->mc_ClassList.mlh_TailPred != (struct MinNode*)(&cfg->mc_ClassList))
	{
		if(!(*dest))
		{
			if(*dest = AllocVecPooled(cfg->mc_MemPool,strlen(s)+1))
			{
				strcpy(*dest,s);
				return NULL;
			} else ret = MRQERROR_NOMEMORY;
		}
	} else prdebug("Can't add %s without a class!\n",ItemDesc);
	return ret;
}

static STRPTR MkImagePath(STRPTR name)
{
STRPTR dest;

	if(strchr(name,':') || (!(ttVars.DefImageDir)))
	{
		if(dest = AllocVec(strlen(name)+1,MEMF_ANY))
			strcpy(dest,name);
	} else
	{
	ULONG len;

		if(dest = AllocVec(len=strlen(name)+strlen(ttVars.DefImageDir)+3,MEMF_ANY))
		{
			strcpy(dest,ttVars.DefImageDir);
			if(!AddPart(dest,name,len))
			{
				FreeVec(dest);
				dest = NULL;
			}
		}
	}
	if(dest == NULL) prdebug("MkImagePath() failed!\n");
	return dest;
}

static void FillDefaultClass(struct MRQConfig *cfg)
{
STRPTR tmpimgname, defname="MRQ_DefaultImage";

	tmpimgname = MkImagePath(defname);
	if(!PreloadImage(tmpimgname,&cfg->mc_DefClass.mec_Image))
		prdebug("Warning: can't load default image\n\t(%s)\n\tunrecognized requesters will not be promoted!\n",tmpimgname);
	FreeVec(tmpimgname);
}
