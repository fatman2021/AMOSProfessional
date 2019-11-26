#ifndef MPEGA_INTERFACE_DEF_H
#define MPEGA_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE MPEGAIFace, InterfaceData_SIZE
	    FPTR IMPEGA_Obtain
	    FPTR IMPEGA_Release
	    FPTR IMPEGA_Expunge
	    FPTR IMPEGA_Clone
	    FPTR IMPEGA_MPEGA_open
	    FPTR IMPEGA_MPEGA_close
	    FPTR IMPEGA_MPEGA_decode_frame
	    FPTR IMPEGA_MPEGA_seek
	    FPTR IMPEGA_MPEGA_time
	    FPTR IMPEGA_MPEGA_find_sync
	    FPTR IMPEGA_MPEGA_scale
	LABEL MPEGAIFace_SIZE

#endif
