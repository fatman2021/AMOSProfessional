head	1.1;
access;
symbols;
locks
	msbethke:1.1; strict;
comment	@ * @;


1.1
date	2000.01.25.17.20.40;	author msbethke;	state Exp;
branches;
next	;


desc
@C header for MRQ's config parser, also defines a lot of data structures
used throughout the program
@


1.1
log
@Initial revision
@
text
@/* config.h
** C header for MRQ's config parser, also defines a lot of data structures
** used throughout the program
**
** ©1997-1999 by Matthias.Bethke <Matthias.Bethke@@gmx.net>
** You are free to modify this source or use parts of it in your
** own programs as long as they are distributed as freeware.
*/

/* $Id:$
**
** $Log:$
**
*/


/* MRQString flags */
#define MSF_PATTERN		(1<<0)
#define MSF_NOCASE		(1<<1)
#define MSF_SUBSTRING	(1<<2)
#define MSF_FORMATTED	(1<<3)

/* MRQImage flags */
#define MIF_FILENAME		(1<<0)
#define MIF_STDIMAGE		(1<<1)
#define MIF_ANIMATION	(1<<2)
#define MIF_TRANSPARENT	(1<<3)

struct MRQImageButton
{
	APTR mib_Picture;					// guigfx picture object
	STRPTR mib_Text;					// text to match for this button
};

struct MRQImage
{
	APTR	mi_Object;				// filename pointer, guigfx object or image pointer
	ULONG mi_Flags;				// see above (MIF_*)
};

struct MRQString
{
	struct MinNode ms_Node;	// to link into string list
	STRPTR ms_String;			// the actual string to match
	ULONG ms_Flags;			// see above (MSF_*)
};

struct MRQEventClass
{
	struct MinNode mec_Node;			// to link into eventclass list
	struct MinList mec_StringList;	// list of strings for this class
	struct MRQImage mec_Image;			// image to show for this class
	STRPTR mec_RxPortName;				// ARexx port name
	STRPTR mec_RxCmdString;				// command to dispatch
};

struct MRQConfig
{
	APTR mc_MemPool;									// MemPool to use for all allocations
															// during config parse (see AVP.a!)
	struct MinList mc_ClassList;					// list of all event classes
	struct MRQImageButton mc_IButton_Yes;		// Imagebuttons
	struct MRQImageButton mc_IButton_No;		// if any
	struct MRQImageButton mc_IButton_Cancel;	// chosen
	struct MRQEventClass mc_DefClass;			// the default event class if no other matches
};

struct Arguments		// for ReadArgs() to parse the configfile
{							// see template below
	LONG NewClass;
	STRPTR *Locale;
	STRPTR String;
	LONG Pattern;
	LONG NoCase;
	LONG Substring;
	LONG Formatted;
	STRPTR Image;
 	LONG Preload;
	LONG Transparent;
	STRPTR RxPort;
	STRPTR RxCmd;
};

#define CONFIG_RDAPATTERN "\
NEWCLASS/S,\
LO=LOCALE/K/M,\
ST=STRING/K,\
PA=PATTERN/S,\
NC=CMPNOCASE/S,\
SU=SUBSTRING/S,\
FO=FORMATTED/S,\
IM=IMAGE/K,\
PL=PRELOAD/S,\
TR=TRANSPARENT/S,\
RP=REXXPORT/K,\
RC=REXXCMD/K"

/* protos */
struct MRQConfig *ReadMRQConfig(STRPTR);
void FreeMRQConfig(struct MRQConfig*);
@
