
#include "lib_init.h"
#include "lib_debug.h"
#include <proto/exec.h>
#include <proto/utility.h>

struct Library *UtilityBase = NULL;

#ifdef __amigaos4__
struct UtilityIFace *IUtility = NULL;
#endif

LIBAPI BOOL Library_Init(LIB_BASE_T *LibBase)
{
        UtilityBase = OpenLibrary("utility.library", 0);
        if (UtilityBase)
        {
                #ifdef __amigaos4__
                IUtility = (struct UtilityIFace *) GetInterface(UtilityBase, "main", 1, NULL);
                #endif

                return TRUE;
        }
        return FALSE;
}

LIBAPI void Library_Exit(LIB_BASE_T *LibBase)
{
        #ifdef __amigaos4__
        DropInterface((struct Interface *) IUtility);
        #endif

        CloseLibrary(UtilityBase);      
}
