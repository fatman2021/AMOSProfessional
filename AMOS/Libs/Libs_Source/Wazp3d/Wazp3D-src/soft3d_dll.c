/* Wazp3D - Alain THELLIER - Paris - FRANCE 							*/
/* Adaptation to AROS from Matthias Rustler							*/
/* Code clean-up and library enhancements from Gunther Nikl					*/
/* LICENSE: GNU General Public License (GNU GPL) for this file				*/

/* This file contain the DLL header & PC code that CANT be merged with soft3dnn.c	*/

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
/*=================================================================*/
BOOL LibDebug=TRUE;			/* Enable Library Debugger (global)		*/
int consoleopen=0;			/* Window's log stuffs				*/
FILE *debugfile;
void *stdinput;
void *stdoutput;
#define WRITE_LOG_BUF_SIZE 10000
/*=================================================================*/
/*
 Procedure:	  LibMain ID:1
 Purpose:		 Dll entry point.Called when a dll is loaded or
					 unloaded by a process, and when new threads are
					 created or destroyed.
 Input:			hDllInst: Instance handle of the dll
					 fdwReason: event: attach/detach
					 lpvReserved: not used
 Output:		  The return value is used only when the fdwReason is
					 DLL_PROCESS_ATTACH. True means that the dll has
					 sucesfully loaded, False means that the dll is unable
					 to initialize and should be unloaded immediately.
 Errors:
*/
/*=================================================================*/
BOOL WINAPI __declspec(dllexport) LibMain(HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved)
{
	 switch (fdwReason)
	 {
		  case DLL_PROCESS_ATTACH:
				// The DLL is being loaded for the first time by a given process.
				// Perform per-process initialization here.  If the initialization
				// is successful, return TRUE; if unsuccessful, return FALSE.


				break;
		  case DLL_PROCESS_DETACH:
				// The DLL is being unloaded by a given process.  Do any
				// per-process clean up here, such as undoing what was done in
				// DLL_PROCESS_ATTACH.  The return value is ignored.


				break;
		  case DLL_THREAD_ATTACH:
				// A thread is being created in a process that has already loaded
				// this DLL.  Perform any per-thread initialization here.  The
				// return value is ignored.

				break;
		  case DLL_THREAD_DETACH:
				// A thread is exiting cleanly in a process that has already
				// loaded this DLL.  Perform any per-thread clean up here.  The
				// return value is ignored.

				break;
	 }
	 return TRUE;
}
/*=================================================================*/
void LibAlert(unsigned char *text)
{
	MessageBox(NULL,text,"Message :",MB_OK);
}
/*=================================================================*/
void	Libsavefile(unsigned char *filename,void *pt,unsigned long int size)
{
FILE *fp;

	fp=fopen(filename,"wb");
	size=fwrite(pt,size,1,fp);
	fclose(fp);
}
/*=================================================================*/
void	Libloadfile(unsigned char *filename,void *pt,unsigned long int  size)
{
FILE *fp;

	fp = fopen(filename,"rb");
	if(fp == NULL) return;
	fread(pt,size,1,fp);
	fclose(fp);
}
/*=================================================================*/
void   Libprintf(const unsigned char *string, ...)
{
DWORD numwritten;
char buffer[WRITE_LOG_BUF_SIZE];
va_list parms;

	if(!LibDebug ) return;
	va_start (parms, string);
	_vsnprintf( buffer, WRITE_LOG_BUF_SIZE-1, string, parms );
	if(!consoleopen)
	{
		AllocConsole();
		stdinput=GetStdHandle(STD_INPUT_HANDLE);
		stdoutput=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleMode(stdinput,ENABLE_PROCESSED_INPUT|ENABLE_LINE_INPUT|ENABLE_ECHO_INPUT|ENABLE_PROCESSED_OUTPUT);
		consoleopen = 1;
	 }
	WriteConsole(stdoutput,buffer,strlen(buffer),&numwritten,0);

	if(!debugfile)
		debugfile = fopen("soft3debug.txt", "wt" );

	if( debugfile)
	{
	fprintf( debugfile, buffer );
	fflush (debugfile);
	}
	va_end (parms);
}
/*=================================================================*/
void   Libsprintf(unsigned char *buffer,const unsigned char *string, ...)
{
va_list parms;

	va_start (parms, string);
	_vsnprintf( buffer, 1000, string, parms );
}
/*=================================================================*/
void  *Libmalloc(unsigned long int size )
{
	return(malloc(size));
}
/*=================================================================*/
void   Libfree(void *p)
{
	free(p);
}
/*=================================================================*/
void  Libmemcpy(void *s1,void *s2,unsigned long int  n)
{
	memcpy(s1,s2,n);
}
/*=================================================================*/
void Libstrcat(unsigned char *s1,const unsigned char *s2)
{
	strcat(s1,s2);
}
/*=================================================================*/
void Libstrcpy(unsigned char *s1,const unsigned char *s2)
{
	strcpy(s1,s2);
}
/*=================================================================*/
unsigned long int  Libstrlen(const unsigned char *string)
{
	return(strlen(string));
}
/*=================================================================*/
double  Libexp(double x)
{
	return(exp(x));
}
/*=================================================================*/
float Libfloor(float x)
{
	return(floor(x));
}
/*=================================================================*/

