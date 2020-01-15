/*****************************************************************************

    mhimdev.library - MHI driver for mpeg.device
    Copyright (C) 2001  Michael Henke

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/


#include <proto/exec.h>
#include <proto/dos.h>
#include <exec/memory.h>
#include <exec/interrupts.h>
#include <utility/tagitem.h>
#include <libraries/mhi.h>
#include <devices/melodympeg.h>
#include <clib/alib_protos.h>
#include "mhimdev.h"




struct mhimdevHandle
{
    UBYTE               mdevunit, mdevname[256], mhistatus;
    struct MsgPort      *mdevport;
    struct IOMPEGReq    *mdevreq;
    struct List         list_unused, list_getempty;
    struct Task         *mhitask;
    ULONG               mhisignal;
    struct Interrupt    mdevsoftint;
    LONG                requests_pending;
    ULONG               mhivolume, mhipanning;
    struct IOMPEGReq    *PlayReq;
    struct ExecBase *   SysBase ;
};


static void myDoIO(struct ExecBase *SysBase, struct IOMPEGReq *mdevreq, UWORD command);
static void REGFUNC softint_server(REG( a1, struct mhimdevHandle *h));


APTR REGFUNC
i_MHIAllocDecoder(REG( a0, struct Task *task), REG( d0, ULONG mhisignal), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h;
    struct ExecBase *SysBase ;
    
    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIAllocDecoder()\n");
#endif
    if(task==NULL) return(NULL);
    h=(struct mhimdevHandle*)AllocVec(sizeof(struct mhimdevHandle),MEMF_PUBLIC|MEMF_CLEAR);
    if(h==NULL) return(NULL);
    h->SysBase=SysBase;
    h->mhitask=task;
    h->mhisignal=mhisignal;
    h->mhistatus=MHIF_STOPPED;
    h->mhivolume=100;
    h->mhipanning=50;
    NewList(&h->list_unused);
    NewList(&h->list_getempty);
    {
        struct DosLibrary *DOSBase;
        UBYTE *varbuf;
        LONG  varlen, args[2]={0,0};
        struct RDArgs *rdargs, *rdargs2;
        struct TagItem tagdone={TAG_DONE,0};
        if((DOSBase=(struct DosLibrary*)OpenLibrary("dos.library",37)))
        {
            if((varbuf=AllocVec(1024,MEMF_PUBLIC|MEMF_CLEAR)))
            {
                if((varlen=GetVar("MHIMDEV",varbuf,1024,LV_VAR))>0)
                {
#ifdef DEBUG
KPutStr("MHIMDEV varbuf=\"");
KPutStr(varbuf);
KPutStr("\"\n");
#endif
                    if((rdargs=AllocDosObject(DOS_RDARGS,&tagdone)))
                    {
                        rdargs->RDA_Source.CS_Buffer=varbuf;
                        rdargs->RDA_Source.CS_Length=varlen;
                        rdargs->RDA_Source.CS_CurChr=0;
                        rdargs->RDA_Flags=RDAF_NOPROMPT;
                        rdargs->RDA_DAList=0;
                        rdargs2=ReadArgs("DEVICE,UNIT/N",args,rdargs);
                        if(args[0]) CopyMem((APTR)args[0],h->mdevname,sizeof(h->mdevname)-1);
                        if(args[1]) h->mdevunit=(*(LONG*)args[1]);
                        FreeArgs(rdargs2);
                        FreeDosObject(DOS_RDARGS,rdargs);
                    }
                }
                FreeVec(varbuf);
            }
            CloseLibrary((struct Library*)DOSBase);
        }
    }
#ifdef DEBUG
KPutStr("MHIMDEV var:  DEVICE=");
KPutStr(h->mdevname);
KPutStr("  UNIT=");
KPutChar((LONG)('0'+h->mdevunit));
#endif
    if((h->mdevport=CreateMsgPort()))
    {
        h->mdevsoftint.is_Data=(APTR)h;
        h->mdevsoftint.is_Code=(void(*)(void))softint_server;
        h->mdevport->mp_SoftInt= &h->mdevsoftint;
        h->mdevport->mp_Flags=PA_SOFTINT;
        if((h->mdevreq=(struct IOMPEGReq*)CreateIORequest(h->mdevport,sizeof(struct IOMPEGReq))))
        {
          h->PlayReq = (struct IOMPEGReq * )AllocMem( sizeof( struct IOMPEGReq ), MEMF_PUBLIC ) ;
          if( NULL != h->PlayReq )
          {
            if(OpenDevice(h->mdevname,(ULONG)h->mdevunit,(struct IORequest*)h->mdevreq,0)==0)
            {
                CopyMem( h->mdevreq, h->PlayReq, sizeof( struct IOMPEGReq ) ) ;
                h->PlayReq->iomr_Req.io_Command = MPEGCMD_PLAY ;
                h->PlayReq->iomr_Req.io_Flags = 0 ;
                h->PlayReq->iomr_StreamType = MPEGSTREAM_AUDIO ;
                myDoIO( SysBase, h->mdevreq,CMD_RESET);
#ifdef DEBUG
KPutStr("  __open ok__\n");
#endif
                return(h);
            }
            FreeMem( h->PlayReq, sizeof( struct IOMPEGReq ) ) ;
          }
          DeleteIORequest(h->mdevreq);
        }
        DeleteMsgPort(h->mdevport);
    }
    FreeVec(h);
#ifdef DEBUG
KPutStr("  **open failed**\n");
#endif
    return(NULL);
}





void REGFUNC
i_MHIFreeDecoder(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct IOMPEGReq *req;
    struct ExecBase *SysBase ;
  
    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIFreeDecoder()\n");
#endif
    if(handle==NULL) return;
    i_MHIStop(handle, MHIMDEVBase );
    while((req=(struct IOMPEGReq*)RemHead(&h->list_unused)))
        FreeMem(req,sizeof(struct IOMPEGReq));
    CloseDevice((struct IORequest*)h->mdevreq);
    FreeMem( h->PlayReq, sizeof( struct IOMPEGReq ) ) ;
    DeleteIORequest(h->mdevreq);
    DeleteMsgPort(h->mdevport);
    FreeVec(h);
}





BOOL REGFUNC
i_MHIQueueBuffer(REG( a3, APTR handle), REG( a0, APTR buffer), REG( d0, ULONG size), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct IOMPEGReq *req;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIQueueBuffer()\n");
#endif
    if((handle==NULL) || (buffer==NULL) || (size==0)) return(FALSE);
    if(!(req=(struct IOMPEGReq*)RemHead(&h->list_unused)))
    {
        UWORD i;
        for(i=0;i<32;i++)
        {
            req=(struct IOMPEGReq*)AllocMem(sizeof(struct IOMPEGReq),MEMF_PUBLIC);
            if(req) AddTail(&h->list_unused,(struct Node*)req);
        }
        if(!(req=(struct IOMPEGReq*)RemHead(&h->list_unused)))
            return(FALSE);
    }
    CopyMem(h->mdevreq,req,sizeof(struct IOMPEGReq));
    req->iomr_Req.io_Command=CMD_WRITE;
    req->iomr_Req.io_Data=buffer;
    req->iomr_Req.io_Length=size;
    req->iomr_Req.io_Flags=0;
    req->iomr_StreamType=MPEGSTREAM_AUDIO;
    req->iomr_MPEGFlags=0;
    h->requests_pending++;
    SendIO((struct IORequest*)req);
    return(TRUE);
}





APTR REGFUNC
i_MHIGetEmpty(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct IOMPEGReq *req;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIGetEmpty()\n");
#endif
    if(handle==NULL) return(NULL);
    Disable();
    req=(struct IOMPEGReq*)RemHead(&h->list_getempty);
    Enable();
    if(req==NULL) return(NULL);
    AddTail(&h->list_unused,(struct Node*)req);
    return(req->iomr_Req.io_Data);
}





UBYTE REGFUNC
i_MHIGetStatus(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIGetStatus()\n");
#endif
    if(handle==NULL) return(MHIF_STOPPED);
    if((h->requests_pending<=0) && (h->mhistatus==MHIF_PLAYING))
        return(MHIF_OUT_OF_DATA);
    else
        return(h->mhistatus);
}





void REGFUNC
i_MHIPlay(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIPlay()\n");
#endif
    if(handle==NULL) return;
    SendIO( ( struct IORequest * )h->PlayReq ) ;
    h->mhistatus=MHIF_PLAYING;
}





void REGFUNC
i_MHIStop(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct IOMPEGReq *req;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIStop()\n");
#endif
    if(handle==NULL) return;
    if( MHIF_STOPPED != h->mhistatus )
    {  /* only abort if the play request is in use */
      AbortIO( ( struct IORequest * )h->PlayReq ) ;
      WaitIO( ( struct IORequest * )h->PlayReq ) ;
    }
    Disable();
    h->mdevport->mp_Flags=PA_IGNORE;
    Enable();
    while((req=(struct IOMPEGReq*)RemHead(&h->list_getempty)))
        AddTail(&h->list_unused,(struct Node*)req);
    myDoIO( SysBase, h->mdevreq,CMD_FLUSH);
    while((req=(struct IOMPEGReq*)GetMsg(h->mdevport)))
        if(req!=h->mdevreq) AddTail(&h->list_unused,(struct Node*)req);
    h->requests_pending=0;
    h->mdevport->mp_Flags=PA_SOFTINT;
    h->mhistatus=MHIF_STOPPED;
}





void REGFUNC
i_MHIPause(REG( a3, APTR handle), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIPause()\n");
#endif
    if(handle==NULL) return;
    if(h->mhistatus==MHIF_PLAYING)
    {
        h->mdevreq->iomr_Arg1=1;
        h->mhistatus=MHIF_PAUSED;
    }
    else if(h->mhistatus==MHIF_PAUSED)
    {
        h->mdevreq->iomr_Arg1=0;
        h->mhistatus=MHIF_PLAYING;
    }
    else return;
    myDoIO( SysBase, h->mdevreq,MPEGCMD_PAUSE);
}





ULONG REGFUNC
i_MHIQuery(REG( d1, ULONG query), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHIQuery()\n");
#endif
    switch(query)
    {
    case MHIQ_DECODER_NAME:
        return((ULONG)"MHI driver for mpeg.device");
    case MHIQ_DECODER_VERSION:
        return((ULONG)IDSTRING);
    case MHIQ_AUTHOR:
        return((ULONG)"Michael Henke");
    case MHIQ_IS_HARDWARE:
        return(MHIF_TRUE);
    case MHIQ_LAYER1:
    case MHIQ_LAYER2:
    case MHIQ_LAYER3:
        /* mpeg.device is able to tell us but we can't access it from here */
        /* we would need an initialised mhimdevHandle for this... */
        return(MHIF_SUPPORTED);
    case MHIQ_MPEG1:
    case MHIQ_MPEG2:
    case MHIQ_MPEG25:
    case MHIQ_VARIABLE_BITRATE:
    case MHIQ_JOINT_STEREO:  /* AB: was MHIQ_JOINT_STERIO */
        /* mpeg.device can't tell us these things but we are optimistic */
        return(MHIF_SUPPORTED);
    case MHIQ_VOLUME_CONTROL:
    case MHIQ_PANNING_CONTROL:
        /* these are standard features of mpeg.device */
        return(MHIF_SUPPORTED);
    default:
        /* everything else is either MHIF_FALSE or MHIF_UNSUPPORTED ;-) */
        return(MHIF_UNSUPPORTED);
    }
}





void REGFUNC
i_MHISetParam(REG( a3, APTR handle), REG( d0, UWORD param), REG( d1, ULONG value), REG( a6, struct mhimdevBaseP *MHIMDEVBase ) )
{
    struct mhimdevHandle *h = (struct mhimdevHandle*) handle;
    struct MPEGAudioParams map;
    ULONG vol;
    struct ExecBase *SysBase ;

    SysBase = MHIMDEVBase->SysBase ;
#ifdef DEBUG
KPutStr("MHISetParam()\n");
#endif
    if(handle==NULL) return;
    if(param==MHIP_VOLUME) h->mhivolume=(value>100 ? 100 : value);
    else if(param==MHIP_PANNING) h->mhipanning=(value>100 ? 100 : value);
    else return;
    vol=0xffff*h->mhivolume;
    map.map_VolumeLeft =(vol*(ULONG)(h->mhipanning>50 ? 100-h->mhipanning : 50))/5000;
    map.map_VolumeRight=(vol*(ULONG)(h->mhipanning<50 ? h->mhipanning     : 50))/5000;
    map.map_StreamID=0xffff;
    h->mdevreq->iomr_Req.io_Data= &map;
    h->mdevreq->iomr_Req.io_Length=sizeof(struct MPEGAudioParams);
    myDoIO( SysBase, h->mdevreq,MPEGCMD_SETAUDIOPARAMS);
}





/*** private routines ***/

static void
myDoIO(struct ExecBase *SysBase, struct IOMPEGReq *mdevreq, UWORD command)
{
    mdevreq->iomr_Req.io_Command=command;
    mdevreq->iomr_Req.io_Flags=0;
    mdevreq->iomr_StreamType=MPEGSTREAM_AUDIO;
    DoIO((struct IORequest*)mdevreq);
}


static void REGFUNC
softint_server(REG( a1, struct mhimdevHandle *h))
{
    struct IOMPEGReq *req;
    struct ExecBase *SysBase ;
    
    SysBase = h->SysBase ;
#ifdef DEBUG
KPutStr("--softint_server\n");
#endif
    while((req=(struct IOMPEGReq*)GetMsg(h->mdevport)))
    {
        if((req!=h->mdevreq)&&(req!=h->PlayReq))
        {
            AddTail(&h->list_getempty,(struct Node*)req);
            h->requests_pending--;
        }
    }
    Signal(h->mhitask,h->mhisignal);
}

