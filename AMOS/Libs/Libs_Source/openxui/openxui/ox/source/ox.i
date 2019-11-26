	IFND LIBRARIES_OX_I
LIBRARIES_OX_I	SET	1

; $VER: oxmaster.library   eXternal User Interfaces
;
; -----------------------------------------------------
; m68k assembler includefile and developer informations
; -----------------------------------------------------
;
; 2003, 2009, 2010 by PseudoDOS/silva@psi5.com
;
; (C) Andreas G. Szabo all rights reserved


	IFND EXEC_TYPES_I
	include "exec/types.i"
	ENDC
	IFND EXEC_LIBRARIES_I
	include "exec/libraries.i"
	ENDC
	IFND EXEC_LISTS_I
	include "exec/lists.i"
	ENDC
	IFND EXEC_NODES_I
	include "exec/nodes.i"
	ENDC
	IFND UITLITY_TAGITEM_I
	include	"utility/tagitem.i"
	ENDC
	IFND INTUITION_INTUITION_I
	include	"intuition/intuition.i"
	ENDC

OXVERSION	= 0
LIBSVER		= 39

OXNAME		MACRO
		dc.b	"oxmaster.library",0
		ENDM

; pentable for up to 32 pens, this list for each window

 STRUCTURE	oxPenTable,0
	ULONG	oxPT_allocs	; bLackpen also used for strichel-linie des aktiven elements
	UBYTE	oxPT_backpen	; für den 4-farb modus zur erleichterung der einstellung,
	UBYTE	oxPT_blackpen	; nur diese pens werden benutzt oder allokiert (wenn 24bitwerte drin stehen)
	UBYTE	oxPT_whitepen	; und in die felder dark, shine, button = tab usw kopiert
	UBYTE	oxPT_colorpen	; wird im 4farb zu darkpen kopiert
	UBYTE	oxPT_textpen
	UBYTE	oxPT_cursorpen
	UBYTE	oxPT_darkpen
	UBYTE	oxPT_shinepen	; whitepen wird im 4farb hierher kopiert
	UBYTE	oxPT_buttonpen	; an radios and checkmarks, umrandungen immer blackpen
	UBYTE	oxPT_tabspen
	UBYTE	oxPT_patternApen
	UBYTE	oxPT_patternBpen

	UBYTE	oxPT_listpen	; pattern unter dem slider immer mit blackpen
	UBYTE	oxPT_listselpen
	UBYTE	oxPT_listtextpen
	UBYTE	oxPT_listalttextpen
	UBYTE	oxPT_listofftextpen

	UBYTE	oxPT_inputpen
	UBYTE	oxPT_inputtextpen

	UBYTE	oxPT_even
	LABEL	oxPT_SIZEOF

oxPT_COLORS	= oxPT_SIZEOF-oxPT_backpen-1

oxBACKPEN	= 0
oxBLACKPEN	= 1
oxWHITEPEN	= 2
oxCOLORPEN	= 3

 STRUCTURE	oxColorTable,0
	ULONG	oxCT_backcolor
	ULONG	oxCT_blackcolor
	ULONG	oxCT_whitecolor
	ULONG	oxCT_colorcolor
	ULONG	oxCT_textcolor
	ULONG	oxCT_cursorcolor
	ULONG	oxCT_darkcolor
	ULONG	oxCT_shinecolor
	ULONG	oxCT_buttoncolor
	ULONG	oxCT_tabscolor
	ULONG	oxCT_patternAcolor
	ULONG	oxCT_patternBcolor

	ULONG	oxCT_listcolor
	ULONG	oxCT_listselcolor
	ULONG	oxCT_listtextcolor
	ULONG	oxCT_listalttextcolor
	ULONG	oxCT_listofftextcolor

	ULONG	oxCT_inputcolor
	ULONG	oxCT_inputtextcolor
	LABEL	oxCT_SIZEOF

; image table fo opened ox system global images
; handled by window and sent down to members

 STRUCTURE	oxImageTable,0		; this is a list of *oxImageNodes, not a list of *names as in oxbase!
	APTR	oxIT_buttonbgimage	; only one image od a name for one screen is stored, also if there 
	APTR	oxIT_gaugeimage	; are more windows open on a screen with their own ImageTable
	APTR	oxIT_sliderimage	; but same name images
	APTR	oxIT_winbgimage
	APTR	oxIT_bgimage		; these images are opened from window dispatcher to fit on screen depht
	APTR	oxIT_titlesimage
	APTR	oxIT_menusimage
	APTR	oxIT_selectimage
	LABEL	oxIT_SIZEOF

oxIT_IMAGES	= (oxIT_SIZEOF/4)-1

;===============================================
; oxBase basis of open ox library
;===============================================

 STRUCTURE	oxBase,LIB_SIZE

	; all here is READ ONLY

	UBYTE	oxB_configflags
	UBYTE	oxB_pad

	APTR	oxB_sysbase	; *execbase (yet mostly unused)

	APTR	oxB_intbase	; program or class may use these library pointers as long oxmaster ist open
	APTR	oxB_gfxbase	; so that no additional OpenLibrary() is needed ...
	APTR	oxB_layersbase
	APTR	oxB_dosbase
	APTR	oxB_dtbase	; datatypes.library
	APTR	oxB_wbbase
	APTR	oxB_iconbase

	STRUCT	oxB_classlist,MLH_SIZE
	STRUCT	oxB_applist,MLH_SIZE
	STRUCT	oxB_imagelist,MLH_SIZE

	APTR	oxB_config	; set to *oxEnv array by initox

	APTR	oxB_presetspath
	APTR	oxB_imagesdir
	APTR	oxB_iconsdir

	STRUCT	oxB_colortable,oxCT_SIZEOF
	STRUCT	oxB_imagetable,oxIT_SIZEOF	; list of names, is turned into list of images by window_class

	LABEL	oxB_SIZEOF

	BITDEF	oxB,4COLORMODE,1
	BITDEF	oxB,USEBGIMAGES,2
	BITDEF	oxB,LOADIMAGES,3
	BITDEF	oxB,DOUBLEBUFFER,4
	BITDEF	oxB,MORPHOS,5


;==================================================================================
; configuration: environment ARRAY structure

; OX config parameters of a class are defined by an array of the follwing structures,
; termianted by a zero long

; in a class taglist the pointer to this array is defined by oxCA_envarray


 STRUCTURE	oxEnv,0
	APTR	oxE_name		; pointer to a text, 0 here means end of array

	ULONG	oxE_default		; this can be:	a value of 0 or != 0 for a FLAG
					;		a value
					;		a pointer to a text

	ULONG	oxE_temp		; the currently edited variable is stored here
					; until "test", "save" or "use" is selected

	UBYTE	oxE_type		; defines the type of this variable, see below
					; if this is oxET_FOLDER, these fields have differnt meaning:
					;	oxE_default: 0 means folder is closed, 1 means it is open
					;	oxE_flagbit: unused
					;	oxE_offset:  is renamed as oxE_numfold and means how many of the
					;		     following intries are IN the folder
					;		     (other subfolders counted as one)

	UBYTE	oxE_flagbit		; for the FLAG types this is the bit numer of bit to set/clr at oxE_offset
	UWORD	oxE_offset		; put/get the variable at this offset in a class base structure

	APTR	oxE_desc		; pointer to a descriptive text for this var
	LABEL	oxE_SIZEOF

oxE_numfold = oxE_offset


; environment variable types for oxE_type

oxET_TEXT	= %00000000
oxET_BYTE	= %00000001
oxET_WORD	= %00000010
oxET_LONG	= %00000011
oxET_HEXBYTE	= %00000101
oxET_HEXWORD	= %00000110
oxET_HEXLONG	= %00000111
oxET_FLAGBYTE	= %00001001
oxET_FLAGWORD	= %00001010
oxET_FLAGLONG	= %00001011

oxET_reserved	= %00010000

oxET_COLOR	= %00100111
oxET_PEN	= %00110001
oxET_PATH	= %01000000
oxET_FILE	= %01010000
oxET_FONT	= %01100000
oxET_ICON	= %01110000
oxET_IMAGE	= %10000000

oxET_FOLDER	= %11111111



; sys info	sent down from window or from user-attach-objects

 STRUCTURE	oxDrawInfo,0
	UBYTE	oxDI_flags
	UBYTE	oxDI_pad
	APTR	oxDI_pentable
	APTR	oxDI_imagetable
	APTR	oxDI_window
	APTR	oxDI_rastport
	APTR	oxDI_font
	APTR	oxDI_fixedfont
	APTR	oxDI_windowobject
	LABEL	oxDI_SIZEOF

	BITDEF	oxDI,WINDOWOPEN,0

; imagenode	keep only one copy of every filename of an image in memory

 STRUCTURE	ImageNode,MLN_SIZE	; pointer to  this is returned from oxGetImage in d0
	APTR	oxIN_imagename		; and used to draw or free the image
	APTR	oxIN_dtobject
	APTR	oxIN_bitmap
	APTR	oxIN_bitmapheader
	APTR	oxIN_screen		; one node per screen
	UWORD	oxIN_userscount
	LABEL	oxIN_SIZEOF


; modes flags for oxBroadCast()

OXBMODE_EVERYBODY		= 0
OXBMODE_UNTILTRUE		= 1
OXBMODE_UNTILTRUE_BIT		= 0	
OXBMODE_SELF			= 2
OXBMODE_SELF_BIT		= 1
OXBMODE_STOPLEVEL		= 4
OXBMODE_STOPLEVEL_BIT		= 2	

OXBMODE_ISBROADCAST		= 16
OXBMODE_ISBROADCAST_BIT 	= 4


; You can use BeginRefresh() and EndRefresh() around drawing
; to soften it (no more gfx-flashing) by doublebuffering.
; If there was no memory for an off-bitmap ,these functions
; do nothing!

; BeginRefresh(*oxwindow, x, y, w, h, flags)
;		a0	   d0-d3	d4

					; if flags is 0 only refreshmode is initialised, no copying

	BITDEF	OXRMODE,COPY,0		; use d0-d3 and copy that front to back before drawing
	BITDEF	OXRMODE,ALL,1		; ignore d0-d3 and work on full window

; EndRefresh(*oxwindow, x, y, w, h, flags)
;                a0        d0-d3      d4

	; XURMODE _ALL applies here same as for BeginRefresh().
	; if this bit is not set, only rect d0-d3 is copied to front
	; maybe buffer the rect as given from BeginRefresh() in oxWindow?


;====================================
; names for external or user classes
; must be at even addresses
;====================================

OXCLASSNAME	MACRO
		even
\1		dc.b	"\1",0
		even
		ENDM

;====================================
; macros and bases for ox tags,
; all tags must be ODD
;====================================

XITEM	MACRO
\1	    EQU     EOFFSET
EOFFSET     SET     EOFFSET+2
	ENDM

; anything even is an address, except 0-3 are the control-tags from utility.library

OX_INTERNAL_CLASSES	= $1001

OX_MAXIDTAG		= $1fff
OX_TAGFUNCTIONS	= $2001
OX_ATTRIBS_SYSTEM	= $3001
OX_ATTRIBS_GLOBAL	= $4001
OX_ATTRIBS_CLASS	= $5001

;=======================================
; bases for ox common and class methods
;=======================================

OX_METHODS		= 0
OX_METHODS_CLASS	= $2000

;===================================
; constants for internal classes,
; used with index-table for quick
; access, must all be ODD
;===================================

		ENUM	OX_INTERNAL_CLASSES

	XITEM	OX_BUFFER
	XITEM	OX_APP
	XITEM	OX_CONNECT
	XITEM	OX_WINDOW
	XITEM	OX_BOOPSI
	XITEM	OX_FIELD
	XITEM	OX_FRAME
	XITEM	OX_TABS
	XITEM	OX_PAGES
	XITEM	OX_SPACE
	XITEM	OX_BUTTON
	XITEM	OX_RADIO
	XITEM	OX_CHECK
	XITEM	OX_STRING
	XITEM	OX_LABEL
	XITEM	OX_TITLE
	XITEM	OX_LIST
	XITEM	OX_SLIDER
	XITEM	OX_HORIZGROUP
	XITEM	OX_VERTGROUP
	XITEM	OX_ICON
	XITEM	OX_IMAGE
	XITEM	OX_WHEELGRAD

; number of classes for internal index-table

OX_NUMBER_OF_INTERNAL_CLASSES	= (EOFFSET-OX_INTERNAL_CLASSES)/2

;==========================================
; tags that mean to do something special
;==========================================

		ENUM	OX_TAGFUNCTIONS

	XITEM	OX_PUTPTR		; write *self into address specified by tag_data
	XITEM	OX_RELPTR		; write *self into base at offset specified by tag_data

	XITEM	OX_CUSTOM		; custom object creation routine, good to use with custom classes

OX_REL		EQU	$00000001	; odd pointers are actually offsets to userbase (then masked out)

;==========================================
; attributes that are common to all classes
;==========================================

		ENUM	OX_ATTRIBS_SYSTEM

	; system attributes handled by Create()

	XITEM	OXA_FREEHOOK
	XITEM	OXA_USERDATA
	XITEM	OXA_ID

		ENUM	OX_ATTRIBS_GLOBAL

	; attributes handled by class dispatcher 

	XITEM	oxA_buffer
	XITEM	oxA_drawinfo
	XITEM	oxA_GadgetPointer	; get  / or oxBOPA_... ?
	XITEM	oxA_active
	XITEM	oxA_prev
	XITEM	oxA_next
	XITEM	oxA_receiver
	XITEM	oxA_pos
	XITEM	oxA_selected
	XITEM	oxA_propw
	XITEM	oxA_proph
	XITEM	oxA_minwidth
	XITEM	oxA_minheight
	XITEM	oxA_senschar
	XITEM	oxA_left
	XITEM	oxA_top
	XITEM	oxA_width
	XITEM	oxA_height

;==========================================
; methods that are common to all classes
;==========================================

		ENUM	OX_METHODS

	EITEM	OXM_SET	; a1 oxm_set
	EITEM	OXM_GET	; a1 oxm_get

	EITEM	OXM_ADD	; a0 dest, a1 member

	; ox objects are created and freed from central,
	; dispatchers do private work on them

	EITEM	OXM_SETDEF	; do this before tags are read to set default values

	EITEM	OXM_INIT	; a1 oxCreateInfo
	EITEM	OXM_DEINIT
	EITEM	OXM_ACTIVATE
	EITEM	OXM_INACTIVE
	EITEM	OXM_LINKPRIV	; is broadcasted to all objects from window or tabs after page change

	EITEM	OXM_NOTIFY
	EITEM	OXM_INTUIMESSAGE

	; graphical methods

	EITEM	OXM_GETLAYOUT	; a1 oxMinMax, deffont / fonttable (first is default)
	EITEM	OXM_SETLAYOUT	; ..  ..
	EITEM	OXM_setprop
	EITEM	OXM_DRAW	; draw (no sizes calculations)
	EITEM	OXM_UPDATE	; recalc AND draw
	EITEM	OXM_DROPGFXBUFFERS
	EITEM	OXM_WINDOWOPEN
	EITEM	OXM_WINDOWCLOSING

   	EITEM	OXM_RELINK	; link all interactive elements in a ring for prev/next selection via tab
	EITEM	OXM_BACK
	EITEM	OXM_FRONT

	EITEM	OXM_APPWINMESSAGE
	EITEM	OXM_REFRESH

	EITEM	OXM_NEWPENS
	EITEM	OXM_INHERIT

; message for OXM_INHERIT

 STRUCTURE	oxInherit,0
	UBYTE	oxI_fillstyle
	UBYTE	oxI_pattsize
	UBYTE	oxI_frontpen
	UBYTE	oxI_backpen
	APTR	oxI_data	; image or pattern, or nothing if fillstyle is PEN or NONE
	LABEL	oxI_SIZEOF

oxFILLSTYLE_NONE	= 0
oxFILLSTYLE_IMAGE	= 1
oxFILLSTYLE_PEN		= 2
oxFILLSTYLE_PATTERN	= 3	

; returncodes for OXM_INIT

INIT_OK		EQU	1	; object initialisation succesfull 
INIT_FAIL	EQU	-1	; error occured
INIT_UNUSED	EQU	0	; nothing done this time 


; sometimes needed returcodes for DoMethod() if no other value is returnend

METHOD_USED
METHOD_UNUSED


 STRUCTURE	oxPropInfo,0
	UWORD	oxPI_pot
	UWORD	oxPI_body
	UWORD	oxPI_max
	LABEL	oxPI_SIZEOF

; ox extended intuimessage

 STRUCTURE	oxExtMsg,im_SIZEOF
	ULONG	oxExtM_gadget
	LABEL	oxExtM_SIZEOF

; for common nextidcmp pointer (similar purpose as window gadgetlist)
; maybe idcmp method here, sent forward by class or if allmost all
; classes may sensefully handle idcmp, by special oxHandleInput
; routine, that reads common nextidcmp pointer

; message structures (first two currently used without offset names,
; maybe registers could be used anyway instead later)

 STRUCTURE	oxm_set,0
	ULONG	oxms_AttributeID
	ULONG	oxms_AttributeValue
	ULONG	oxms_SIZEOF

 STRUCTURE	oxm_get,0
	ULONG	oxmg_AttributeID
	ULONG	oxmg_StoragePtr
	ULONG	oxmg_SIZEOF

; autoconnection and globals support message, sent for inits from Create()

 STRUCTURE	oxCreateInfo,0 
	APTR	oxCI_lastgadget
	LABEL	oxCI_SIZEOF

 STRUCTURE	oxRelinkInfo,0
	APTR	oxRL_first
	APTR	oxRL_last
	LABEL	oxRL_SIZEOF

; ox layout info

 STRUCTURE	oxLayoutInfo,0
	UWORD	oxLI_left
	UWORD	oxLI_top
	UWORD	oxLI_width
	UWORD	oxLI_height
	UWORD	oxLI_minwidth
	UWORD	oxLI_minheight
	UWORD	oxLI_maxwidth
	UWORD	oxLI_maxheight
	UWORD	oxLI_propw
	UWORD	oxLI_proph
	LABEL	oxLI_SIZEOF


;===========================================================
; class

OXCLASSHEADER	MACRO
		moveq	#-1,d0	; enable execution telling object
		rts		; not executable
		dc.b	"XOXO"
		dc.w	OXVERSION		;this class is for this lib version (constant from ox.i)

		; the following constants and labels must be
		; defined in the class sourcecode in order
		; to use this macro there

		dc.l	0			; reserved
		dc.w	OXCLASS_VERSION		; constant in the class source
		dc.w	OXCLASS_REVISION	; constant in the class source
		dc.l	OXCLASS_NAME		; label in the class source
		dc.l	OXCLASS_TAGS		; label in the class source
		ENDM

; class tags

	ENUM	$1000

	EITEM	oxCA_objectsize
	EITEM	oxCA_dispatcher
	EITEM	oxCA_constructor
	EITEM	oxCA_verstring
	EITEM	oxCA_description
	EITEM	oxCA_author
	EITEM	oxCA_initclass
	EITEM	oxCA_deinitclass
	EITEM	oxCA_makeexample	; create func for example object(s)
	EITEM	oxCA_basesize		; class internal variables
	EITEM	oxCA_envarray		; class internal configuration data

;===========================================================

; object

 STRUCTURE	oxObject,0
	STRUCT	oxO_node,MLN_SIZE
	STRUCT	oxO_list,MLH_SIZE
	APTR	oxO_Class
	UBYTE	oxO_flags
	UBYTE	oxO_pad

	APTR	oxO_freehook		; if set called at free from FreeObject()
	APTR	oxO_returnhook
	APTR	oxO_userdata

	APTR	oxO_userbase		; set to *globals in create as got from program
					; all OX_RELPTRs are offsets to this 

	ULONG	oxO_ID			; custom field intended for search

	LABEL	oxO_SIZEOF

	BITDEF	oxO,INITIALIZED,0
	BITDEF	oxO,VISIBLE,1
	BITDEF	oxO,GHOSTED,2		; clickable?
	BITDEF	oxO,ACTIVE,3
	BITDEF	oxO,SELECTED,4


; app methods

		ENUM	OX_METHODS_CLASS

	EITEM	oxAM_QUIT
	EITEM	oxAM_RUN


; buffer tags

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxBfA_buffersize		; set		get *buffer with oxA_buffer


; app tags

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxAA_quitflag
	XITEM	oxAA_msgport
	XITEM	oxAA_flags

	BITDEF	oxA,quitreq,0

; connect class

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxCCA_target
	XITEM	oxCCA_attr
	XITEM	oxCCA_newattr


; window attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxWA_tags
	XITEM	oxWA_undermouse
	XITEM	oxWA_layout
	XITEM	oxWA_pattern
	XITEM	oxWA_pattstyle2
	XITEM	oxWA_IDCMP
	XITEM	oxWA_closehook
	XITEM	oxWA_sigtaskclose
	XITEM	oxWA_noautoclose
	XITEM	oxWA_wantedwidth
	XITEM	oxWA_wantedheight
	XITEM	oxWA_title
	XITEM	oxWA_ichbindran
	XITEM	oxWA_tickuser
	XITEM	oxWA_intuimessagehook
	XITEM	oxWA_newsizehook
	XITEM	oxWA_borderless
	XITEM	oxWA_fillbg
	XITEM	oxWA_gadgets

; window methods

		ENUM	OX_METHODS_CLASS

	EITEM	oxWM_OPEN
	EITEM	oxWM_CLOSE
	EITEM	oxWM_NEWSIZE
	EITEM	oxWM_clrpriv	; remove object from privileged receiver without deactivating it
				; so that it can be reattached by OXM_LINKPRIV
	EITEM	oxWM_refreshgadgets

; boopsi attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxBOPA_TYPE
	XITEM	oxBOPA_TAGS
	;XITEM	oxBOPA_BoopsiObject

; boopsi methods

		ENUM	OX_METHODS_CLASS

	;EITEM	

;button attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxBA_left
	XITEM	oxBA_top
	XITEM	oxBA_width
	XITEM	oxBA_height
	XITEM	oxBA_text
	XITEM	oxBA_hprop
	XITEM	oxBA_vprop
	XITEM	oxBA_linechar
	XITEM	oxBA_senschar
	XITEM	oxBA_hook		; gets a0 * self
	XITEM	oxBA_userdata
	XITEM	oxBA_ghosted

;field attrs

		ENUM	OX_ATTRIBS_CLASS
	XITEM	oxFdA_text
	XITEM	oxFdA_hprop
	XITEM	oxFdA_vprop
	XITEM	oxFdA_minlines
	XITEM	oxFdA_minwidth
	XITEM	oxFdA_flags
	XITEM	oxFdA_fillpen
	XITEM	oxFdA_gaugepen
	XITEM	oxFdA_softval
	XITEM	oxFdA_softbody		; currently not used
	XITEM	oxFdA_percent		; for gauge-mode, negative value aligns the fill right
	XITEM	oxFdA_color
	XITEM	oxFdA_imagename	; for backfill
	XITEM	oxFdA_fixedfont	; TRUE: use fixed size font
	XITEM	oxFdA_value		; sets number mode
	XITEM	oxFdA_inherit

	; get

	XITEM	oxFdA_visiblelines

	BITDEF	oxFd,CENTER,0
	BITDEF	oxFd,WIDE,1
	BITDEF	oxFd,FILL,2
	BITDEF	oxFd,GAUGE,3		; this activates also the center flag
	BITDEF	oxFd,3DGAUGE,4		; alternative gauge style
	BITDEF	oxFd,BDLESS,5		; dont draw/substract border
	BITDEF	oxFd,LAYOUT,6		; parse text as given by byte-opcodes see below
	BITDEF	oxFd,UPDATEREDRAW,7	; redraw on UPDATEm default is FLASE

;frame attrs
		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxFrA_hprop
	XITEM	oxFrA_vprop
	XITEM	oxFrA_minx		; this is the minimum size, egal wie groß der inhalt ist
	XITEM	oxFrA_miny
	XITEM	oxFrA_spacing		; inner spacing (padding)
	XITEM	oxFrA_bottomzero	;no spacing at bottom, used for text under frame content

	XITEM	oxFrA_framestyle	; 0 none, 1 strong, 2 shadow, 3 gng, 4 bevel
	XITEM	oxFrA_fillstyle	; 0 none, 1 pattern1, 2 pattern2, 3 pen
	XITEM	oxFrA_fillpen		; if fillstyle is pen
	XITEM	oxFrA_hzalign		; horiz:  1 left, 0 middle, 2 right
	XITEM	oxFrA_vtalign		; vert:	  1 top,  0 middle, 2 bottom

	XITEM	oxFrA_pattern		; custom, see window for format
	XITEM	oxFrA_imagename

	XITEM	oxFrA_icdhook		; icon drop hook gets d1 *numargs, a1 * arglist


oxFr_NONE	= 	0
oxFr_STRONG	= 	1
oxFr_SHADOW	=	2
oxFr_GNG	=	3
oxFr_BEVEL	=	4

oxFr_PATT1	=	1
oxFr_PATT2	=	2
oxFr_PEN	=	3
oxFr_CUSTOM	=	4
oxFr_IMAGE	=	5

oxFr_LEFT	=	-1
oxFr_MIDDLE	=	0
oxFr_RIGHT	=	1
oxFr_TOP	=	-1
oxFr_BOTTOM	=	1


;tabs attrs

	ENUM	OX_ATTRIBS_CLASS

	XITEM	oxTbA_newtab
	XITEM	oxTbA_imagename	; for fill with datatypes
	

;pages attrs
		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxPgA_newmember	; pointer to nested taglists same as for CreateObj()
	XITEM 	oxPgA_member		; precreated member, e.g. horizgroup that contains any other part
					; of the member if used with GET, the last addes/created member
					; will be returned, or zero if there is no member

	XITEM	oxPgA_current		; set currently active (visible) member (need to know pointer to
					; member, get that via GET oxPgA_member)
	XITEM	oxPgA_number		; show page number, 0 = none
	XITEM	oxPgA_redraw		; immediate redraw of currently set, default 1

; list
		ENUM	OX_ATTRIBS_CLASS	

	XITEM	oxLA_minwidth
	XITEM	oxLA_minheight
	XITEM	oxLA_propw
	XITEM	oxLA_proph
	XITEM	oxLA_leftpercent
	XITEM	oxLA_flags
	XITEM	oxLA_minlines
	XITEM	oxLA_senschar
	XITEM	oxLA_dchook	; hook gets:  a0 *list,	a1 *item, a2 *list_userdata, a3 *item_userdata
	XITEM	oxLA_selhook	; ..dito..
	XITEM	oxLA_itemtext
	XITEM	oxLA_itemrtext
	XITEM	oxLA_item			; supply tags for a new list item

	BITDEF	oxL,MULTISELECT,0
	BITDEF	oxL,NOSEPARATOR,1
	BITDEF	oxL,NOSLIDER,2			; has no slider to the right
	BITDEF	oxL,RIGHT_ALIGN_LEFT,3
	BITDEF	oxL,ACTIVE,4
	BITDEF	oxL,IMMEDIATEREDRAW,5
	BITDEF	oxL,AUTODOWN,6
	BITDEF	oxL,MOUSEPRESSEDON,7

	; list item

		ENUM	OX_ATTRIBS_CLASS	

	XITEM	oxLIA_text
	XITEM	oxLIA_righttext
	XITEM	oxLIA_userdata
	XITEM	oxLIA_flags
	XITEM	oxLIA_previtem		; insert new item after this, 0 = at end, -1 at start
	XITEM	oxLIA_selected

	BITDEF	oxLI,SELECTED,0
	BITDEF	oxLI,OFF,1		; cannot select this, written on ghost color, no click report
	BITDEF	oxLI,ACTIVE,2		; via cursor, can be toggled with space
	BITDEF	oxLI,ALTCOLOR,3
	BITDEF	oxLI,UNSELECTABLE,4	; (double) clicks are still reported

		ENUM	OX_METHODS_CLASS

	EITEM	oxLM_sort
	EITEM	oxLM_newitem
	EITEM	oxLM_newitemtags
	EITEM	oxLM_getitemtext
	EITEM	oxLM_getitemrtext
	EITEM	oxLM_getitemuserdata
	EITEM	oxLM_getnextitem
	EITEM	oxLM_getnextselecteditem
	EITEM	oxLM_deleteitem
	EITEM	oxLM_clearlist
	EITEM	oxLM_itemon
	EITEM	oxLM_itemoff
	EITEM	oxLM_activateitem		; markieren, übrige gehen aus
	EITEM	oxLM_selectitem
	EITEM	oxLM_deselectitem
	EITEM	oxLM_selectall
	EITEM	oxLM_deselectall
	EITEM	oxLM_toggleall
	EITEM	oxLM_toggleitem
   ;	EITEM	oxLM_setitemtext	UNUSED  ; (a1) *item,*text ... die erste ox methode die eine
						; customisierte message verwendet

 STRUCTURE	oxOldListItem,0
	APTR	oxOLI_text
	APTR	oxOLI_rtext
	UBYTE	oxOLI_flags
	UBYTE	oxOLI_pri
	ULONG	oxOLI_userdata
	LABEL	oxOLI_SIZEOF

; flags for oxLM_newitem (via oxNewListItem structure)
;       and oxLA_item (via oxLIA_flags tag)

	BITDEF	oxOLI,SELECTED,0
	BITDEF	oxOLI,OFF,1		; cannot select this, written on ghost color, no click report
	BITDEF	oxOLI,ACTIVE,2		; via cursor, can be toggled with space
	BITDEF	oxOLI,ALTCOLOR,3
	BITDEF	oxOLI,UNSELECTABLE,4	; (double) clicks are still reported


; horiz- / vertgroup attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxGA_equal
	XITEM	oxGA_minspace
	XITEM	oxGA_spaceprop
	XITEM	oxGA_vprop
	XITEM	oxGA_hprop
	XITEM	oxGA_minwidth
	XITEM	oxGA_minheight

; string attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxSA_text
	XITEM	oxSA_maxlenght
	XITEM	oxSA_minwidth
	XITEM	oxSA_prop
	XITEM	oxSA_lenght
	XITEM	oxSA_enterobject
	XITEM	oxSA_senschar

	XITEM	oxSA_hook	; gets *self a0, *string a1, d1 value (if HEX or DEZ is set), d2 string lenght
				; called in inactive-routine from
				; enter or from other object from tab or click
	XITEM	oxSA_flags	; for hex or dez
	XITEM	oxSA_minval
	XITEM	oxSA_maxval
	XITEM	oxSA_value
	XITEM	oxSA_softval

	BITDEF	oxS,HEX,0
	BITDEF	oxS,DEZ,1
	BITDEF	oxS,EVEN,2

; string requester input

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxSRA_title
	XITEM	oxSRA_label
	XITEM	oxSRA_buttontext
	XITEM	oxSRA_defaulttext
	XITEM	oxSRA_maxlenght
	XITEM	oxSRA_labeluline
	XITEM	oxSRA_buttonuline
	XITEM	oxSRA_okhook

		ENUM	OX_METHODS_CLASS

	EITEM	oxSRM_POPUP
	EITEM	oxSRM_CLOSE

; file requester

		ENUM	OX_ATTRIBS_CLASS


		ENUM	OX_METHODS_CLASS

	EITEM	oxFRM_select

; label attributes

		ENUM	OX_ATTRIBS_CLASS	

	XITEM	oxLabA_text
	XITEM	oxLabA_linechar

; title attributes

		ENUM	OX_ATTRIBS_CLASS	

	XITEM	oxTA_text
	XITEM	oxTA_linechar

; slider

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxSlA_pot		; use only at creation time,
	XITEM	oxSlA_body		; dont think about this
	XITEM	oxSlA_max		; ..
	XITEM	oxSlA_softval
	XITEM	oxSlA_softbody
	XITEM	oxSlA_flags
	XITEM	oxSlA_minwidth
	XITEM	oxSlA_minheight
	XITEM	oxSlA_flip		; true or false
	XITEM	oxSlA_base1		; send pot as 1 to x instead of 0 to x-1

	BITDEF	oxSl,in_frame,0	; draw frame around the container
	BITDEF	oxSl,pattern,1		; draw pattern behind the knob
	BITDEF	oxSl,FLIP,2		; flip direction of knob
	BITDEF	oxSl,BASE1,3		; start at 1, not at 0
	BITDEF	oxSl,ACTIVE,5		; system private
	BITDEF	oxSl,SLIDING,6		; ...
	BITDEF	oxSl,LAYOUTSET,7	; ...

OXPROP_SOFTMAX		=	$fff	; internally used by any prop calculations

; radio button

		ENUM	OX_ATTRIBS_CLASS
	
	XITEM	oxRadA_senschar
	XITEM	oxRadA_hook
	XITEM	oxRadA_groupid

; check button

		ENUM	OX_ATTRIBS_CLASS
	
	XITEM	oxChkA_senschar
	XITEM	oxChkA_hook

; icon image

		ENUM	OX_ATTRIBS_CLASS
	
	XITEM	oxIcA_filename
	XITEM	oxIcA_diskobject
	XITEM	oxIcA_pressed

; image
		ENUM	OX_ATTRIBS_CLASS
	
	XITEM	oxImA_filename


; wheel and gradient

		ENUM	OX_ATTRIBS_CLASS
	
	XITEM	oxWGA_minsize
	XITEM	oxWGA_color	; gets max $ffffff
	XITEM	oxWGA_hook	; gets d1 color

; end of includefile here  --- Zak McKracken 4 president! ---

	ENDC


