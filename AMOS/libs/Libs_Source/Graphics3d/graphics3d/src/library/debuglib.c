/***********************************
 ** Routin per poter eseguire il  **
 ** debug delle share library di  **
 ** Amiga.			  **
 ** Non si puo' usare all'esterno **
 ***********************************/

#include <dos/dos.h>

/**********************************
 ** accoda nel file 'logerr' la  **
 ** stringa indicata		 ** 
 **********************************/
long int write_dbg(stringa)
char *stringa;
{
long int fl,i,rt;

fl=Open("llog:LogErr",MODE_READWRITE);
if (!fl) return(0);

Seek(fl,0,OFFSET_END);

i=0;
while(stringa[i++]!=NULL) ;

rt=Write(fl,stringa,i-1);

Close(fl);

return(rt);
}
