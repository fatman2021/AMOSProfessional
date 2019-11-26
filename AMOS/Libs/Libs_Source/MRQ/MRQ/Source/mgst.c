/* mgst.c
** Generates the SAS/C GST file for faster MRQ compilation
*/

#include <proto/rexxsyslib.h>
#include <proto/commodities.h>
#include <proto/datatypes.h>
#include <proto/wbstart.h>
#include <proto/guigfx.h>
#include <proto/utility.h>
#include <proto/locale.h>
#include <proto/cybergraphics.h>
#include <cybergraphics/cybergraphics.h>
#include <guigfx/guigfx.h>
#include <dos/dosextens.h>
#include <datatypes/pictureclass.h>
#include <datatypes/PictureClassExt.h>
#include <libraries/reqtools.h>
#include <clib/debug_protos.h>
#include <libraries/reqtools.h>
#include <exec/memory.h>
#include <exec/alerts.h>
#include <dos/dostags.h>
#include <lib/mb_utils.h>
#include <MUI/Guigfx_mcc.h>
#include <MUI/TransferAnim_mcc.h>
#include <dos.h>

#include <stdarg.h>
#include <ctype.h>
#include <math.h>


#include "mrq.h"
#include "config.h"
#include "gfxfiles.h"
#include "mui_macros.h"
#include "muistuff.h"
#include "Requesters.h"
#include "MRQasm.h"
#include "mrqwindowclass_private.h"
