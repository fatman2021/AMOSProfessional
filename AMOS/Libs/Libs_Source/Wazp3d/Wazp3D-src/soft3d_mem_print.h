/* Wazp3D - Alain THELLIER - Paris - FRANCE 							*/
/* Adaptation to AROS from Matthias Rustler							*/
/* Code clean-up and library enhancements from Gunther Nikl					*/
/* LICENSE: GNU General Public License (GNU GPL) for this file				*/

/* This file  contain print/memory functions usually in Wazp3d.c				*/

struct memory3D *firstME=NULL;		/* Tracked memory-allocation			*/

#ifdef WAZP3DDEBUG
void Libprintf(void *string,...);
void Libsprintf(void *buffer,void *string,...);

/*=================================================================*/
void PrintRGBA(UBYTE *RGBA)
{
	if (!Wazp3D->DebugVal.ON) return;
	Libprintf(" RGBA %ld %ld %ld %ld\n",RGBA[0],RGBA[1],RGBA[2],RGBA[3]);
}
/*==================================================================================*/
void pf(float x)		/* emulate printf() from a float %f */
{
LONG high,low,n,size;
UBYTE name[40];

	high=(LONG)(x);
	x=(x-(float)high);
	if(x<0.0) x=-x;
	low =(LONG)(1000000.0*x);
	Libsprintf(name,"%ld.%6ld ",high,low);
	size=strlen(name)-1;
	NLOOP(size)
		if(name[n]==' ') name[n]='0'; 
	Libprintf(name);
}
/*=================================================================*/
void PrintP(struct point3D *P)
{
	if (!Wazp3D->DebugPoint.ON) return;
/*	Libprintf(" P XYZW, %ld, %ld, %ld, %ld, UV, %ld, %ld,",(WORD)P->x,(WORD)P->y,(WORD)(1000.0*P->z),(WORD)(1000.0*P->w),(WORD)(P->u),(WORD)(P->v));*/

	Libprintf(" P XYZ W UV ");
	pf(P->x);
	pf(P->y);
	pf(P->z);
	pf(P->w);
	pf(P->u);
	pf(P->v);
	if (Wazp3D->DebugVal.ON)
		PrintRGBA((UBYTE *)&P->RGBA);
	else
		Libprintf("\n");
}
/*==================================================================================*/
#endif

/*==================================================================================*/
#ifdef WAZP3DDEBUG
void PrintME(struct memory3D *ME)
{
UBYTE *wall;
	wall=ME->pt;wall=wall+ME->size;
	Libprintf("[ME %ld nextME %ld\t] pt=%ld \tsize=%ld \t<%s> \t[%ld]\n ",ME,ME->nextME,ME->pt,ME->size,ME->name,wall[0]);
}
#else
#define PrintME()
#endif
/*==================================================================================*/
LONG ListMemoryUsage(void)
{
LONG MemoryUsage=0;
#ifdef WAZP3DDEBUG
struct memory3D *ME=firstME;
LONG MEnb;

	if(Wazp3D->DebugMemList.ON)
		Libprintf("TRACKED=MEMORY=USAGE=================)\n");

	MemoryUsage=0;
	MEnb=0;
	while(ME!=NULL)			/* for all packages in list */
	{
	if(Wazp3D->DebugMemList.ON)
		{Libprintf("[%ld]",MEnb); PrintME(ME);}
	MemoryUsage=MemoryUsage+ME->size;
	MEnb++;
	ME=ME->nextME;
	}

	if(Wazp3D->DebugMemUsage.ON)
		Libprintf("[%ld] MemoryUsage = %ld bytes = %ld MB\n",MEnb,MemoryUsage,MemoryUsage/(1024*1024));
#endif
	return(MemoryUsage);
}
/*==================================================================================*/
void *MYmalloc(ULONG size,char *name)
{
struct memory3D *ME;
UBYTE *pt;

#ifdef WAZP3DDEBUG
	if(Wazp3D->DebugMemUsage.ON)
		Libprintf("Will call malloc() for %ld bytes for <%s>\n",size,name);
#endif
	pt=Libmalloc(size+4+sizeof(struct memory3D));
	if (pt==NULL)
		{REM(malloc fail !);}

	ME=(struct memory3D *)pt;
	ME->pt=&pt[sizeof(struct memory3D)];
	ME->size=size;
	Libstrcpy(ME->name,name);
	ME->nextME=firstME;
	firstME=ME;
	ME->pt[ME->size]=111;		/* wall */
	memset(ME->pt,0,ME->size);
#ifdef WAZP3DDEBUG
	ListMemoryUsage();
	if(Wazp3D->DebugMemUsage.ON)
		Libprintf("MYmalloc() OK give pt: %ld (up to %ld) for <%s> \n",ME->pt,&ME->pt[ME->size],ME->name);
#endif
	return(ME->pt);
}
/*==================================================================================*/
void MYfree(void *pt)
{
struct memory3D *ME;
struct memory3D fakeME;
struct memory3D *thisME=&fakeME;
UBYTE *Bpt=pt;

	if(pt==NULL) return;
#ifdef WAZP3DDEBUG
	if(Wazp3D->DebugMemUsage.ON)
		Libprintf("Will free() memory at %ld\n",pt);
#endif
	ME =(struct memory3D *)(Bpt - sizeof(struct memory3D) );
	thisME->nextME=firstME;
	while(thisME!=NULL)
	{
	if(thisME->nextME==ME)
		{
		if(thisME->nextME==firstME)
			firstME=ME->nextME;
		else
			thisME->nextME=ME->nextME;
#ifdef WAZP3DDEBUG
		if(Wazp3D->DebugMemUsage.ON) Libprintf("MYfree() OK for pt: %ld was <%s>\n",ME->pt,ME->name);
		Libfree(ME);
		ListMemoryUsage();
#else
		Libfree(ME);
#endif
		return;
		}
	thisME=thisME->nextME;
	}
#ifdef WAZP3DDEBUG
		if(Wazp3D->DebugMemUsage.ON) Libprintf("MYfree() ME %ld not found ==> not allocated pt: %ld  !!!!\n",ME,pt);
#endif
}
/*==================================================================================*/
