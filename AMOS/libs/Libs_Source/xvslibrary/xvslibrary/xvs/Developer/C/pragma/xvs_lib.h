#ifndef _INCLUDE_PRAGMA_XVS_LIB_H
#define _INCLUDE_PRAGMA_XVS_LIB_H

#ifndef CLIB_XVS_PROTOS_H
#include <clib/xvs_protos.h>
#endif

#if defined(AZTEC_C) || defined(__MAXON__) || defined(__STORM__)
#pragma amicall(xvsBase,0x01e,xvsSelfTest())
#pragma amicall(xvsBase,0x024,xvsCreateVirusList(d0))
#pragma amicall(xvsBase,0x02a,xvsFreeVirusList(a1))
#pragma amicall(xvsBase,0x030,xvsAllocObject(d0))
#pragma amicall(xvsBase,0x036,xvsFreeObject(a1))
#pragma amicall(xvsBase,0x03c,xvsObjectType(a1))
#pragma amicall(xvsBase,0x042,xvsCheckBootblock(a0))
#pragma amicall(xvsBase,0x048,xvsInstallBootblock(a0,d0,d1))
#pragma amicall(xvsBase,0x04e,xvsSumBootblock(a0,d0))
#pragma amicall(xvsBase,0x054,xvsCheckSector(a0))
#pragma amicall(xvsBase,0x05a,xvsRepairSector(a0))
#pragma amicall(xvsBase,0x060,xvsCheckFile(a0))
#pragma amicall(xvsBase,0x066,xvsRepairFile(a0))
#pragma amicall(xvsBase,0x06c,xvsSurveyMemory(a0))
#endif
#if defined(_DCC) || defined(__SASC)
#pragma  libcall xvsBase xvsSelfTest            01e 00
#pragma  libcall xvsBase xvsCreateVirusList     024 001
#pragma  libcall xvsBase xvsFreeVirusList       02a 901
#pragma  libcall xvsBase xvsAllocObject         030 001
#pragma  libcall xvsBase xvsFreeObject          036 901
#pragma  libcall xvsBase xvsObjectType          03c 901
#pragma  libcall xvsBase xvsCheckBootblock      042 801
#pragma  libcall xvsBase xvsInstallBootblock    048 10803
#pragma  libcall xvsBase xvsSumBootblock        04e 0802
#pragma  libcall xvsBase xvsCheckSector         054 801
#pragma  libcall xvsBase xvsRepairSector        05a 801
#pragma  libcall xvsBase xvsCheckFile           060 801
#pragma  libcall xvsBase xvsRepairFile          066 801
#pragma  libcall xvsBase xvsSurveyMemory        06c 801
#endif

#endif	/*  _INCLUDE_PRAGMA_XVS_LIB_H  */
