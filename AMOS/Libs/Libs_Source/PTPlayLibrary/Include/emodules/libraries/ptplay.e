-> NOREV
OPT MODULE
OPT EXPORT

/*
**  protracker 2.3a player
**  (C) 2001, 2003, 2004 Ronald Hof, Timm S. Mueller and Per Johansson
**
** Library modifications by Ilkka Lehtoranta
*/

MODULE  'utility/tagitem'

CONST PTPLAY_CIAspeed  = TAG_USER + $00  /* SG  ULONG    Default: 125          */
CONST PTPLAY_Flags = TAG_USER + $01  /* SG ULONG    Default: MODF_ALLOWFILTER  */
CONST PTPLAY_MasterVolume = TAG_USER + $02  /* SG  ULONG    Default: 256           */
CONST PTPLAY_PatternPosition = TAG_USER + $04  /* SG ULONG                      */
CONST PTPLAY_Patterns = TAG_USER + $05  /* .G ULONG    Number of patterns      */
CONST PTPLAY_SongLength = TAG_USER + $07  /* .G  ULONG   Song length in patterns    */
CONST PTPLAY_SongLoopCount = TAG_USER + $08  /* .G  ULONG    Number of loops done      */
CONST PTPLAY_SongPosition = TAG_USER + $09  /* SG ULONG    Current position        */
CONST PTPLAY_SongTitle = TAG_USER + $0A  /* .G  STRPTR  Song name            */
CONST PTPLAY_TotalTime = TAG_USER + $0B  /* .G ULONG   Song length in seconds    */

CONST PT_MOD_UNKNOWN = 0
CONST PT_MOD_PROTRACKER = 1
CONST PT_MOD_SOUNDTRACKER = 2
CONST PT_MOD_SOUNDFX = 3

/* Values for PTPLAY_Flags
 */

CONST MODF_DOSONGEND =   $0001    /* perform song-end detection */
CONST MODF_ALLOWPANNING = $0002    /* allow mod to use command $8 for panning */
CONST MODF_ALLOWFILTER = $0004    /* allow mod to set lowpass filter */
CONST MODF_SONGEND = $0008    /* songend occured */

