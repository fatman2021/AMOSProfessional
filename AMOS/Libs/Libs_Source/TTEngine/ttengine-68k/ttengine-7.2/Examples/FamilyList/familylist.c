/* Example of using TT_ObtainFamilyList() */

#define __NOLIBBASE__
#define USE_INLINE_STDARG

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/ttengine.h>

extern struct Library *SysBase, *DOSBase;   // Defined by startup code.
struct Library *TTEngineBase;

int main(void)
{
	if (TTEngineBase = OpenLibrary("ttengine.library", 7))
	{
		STRPTR *family_list;

		PutStr("Listing all available font families:\n-------------------------------------\n");

		if (family_list = TT_ObtainFamilyListA(NULL))
		{
			STRPTR *p = family_list;

			while (*p)
			{
				Printf("%s\n", (ULONG)*p++);
			}
			TT_FreeFamilyList(family_list);
		}

		PutStr("\nListing monospaced font families:\n-------------------------------------\n");

		if (family_list = TT_ObtainFamilyList(TTRQ_FixedWidthOnly, TRUE, TAG_END))
		{
			STRPTR *p = family_list;

			while (*p)
			{
				Printf("%s\n", (ULONG)*p++);
			}
			TT_FreeFamilyList(family_list);
		}
		CloseLibrary(TTEngineBase);
	}
}
