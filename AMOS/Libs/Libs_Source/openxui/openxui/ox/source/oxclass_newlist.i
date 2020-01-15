	IFND LIBRARIES_OX_CLASSES_NEWLIST_I
LIBRARIES_OX_CLASSES_NEWLIST_I	SET	1

; newlist class for open source external user interfaces
; Andreas G. Szabo

		include	p:ox.i
		include exec/types.i
		include exec/lists.i
		include exec/nodes.i

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxNLA_minwidth		; minimal pixel witdh
	XITEM	oxNLA_minheight		; minimal pixel hight
	XITEM	oxNLA_propw		; width may grow
	XITEM	oxNLA_proph		; height may grow
	XITEM	oxNLA_minlines		; minimum display lines
	XITEM	oxNLA_columns		; display columns 1 to 8

	XITEM	oxNLA_senschar		; go active when this key is pressed

	XITEM	oxNLA_dchook		; item double clicked, see oxNLSelInfo below
	XITEM	oxNLA_selhook		; mouse released over item, see ...

	XITEM	oxNLA_menulook		; alternate look f.e. for menu/popup, default FALSE
	XITEM	oxNLA_titles		; default FALSE
	XITEM	oxNLA_multiselect	; default FALSE
	XITEM	oxNLA_shiftmulti	; allow multiselect when shift is hold down, default FALSE
	XITEM	oxNLA_separators	; default TRUE
	XITEM	oxNLA_slider		; default TRUE
	XITEM	oxNLA_boldtitles	; default FALSE
	XITEM	oxNLA_maxed		; return minheight with all items visible, default FALSE
					; (usefull for menu/popup mode)

	XITEM	oxNLA_folders		; maintain recursive tree of folders

	XITEM	oxNLA_softpos

	XITEM	oxNLA_prop1		; default column sizes = equal
	XITEM	oxNLA_prop2
	XITEM	oxNLA_prop3
	XITEM	oxNLA_prop4
	XITEM	oxNLA_prop5
	XITEM	oxNLA_prop6
	XITEM	oxNLA_prop7
	XITEM	oxNLA_prop8

	XITEM	oxNLA_title1
	XITEM	oxNLA_title2
	XITEM	oxNLA_title3
	XITEM	oxNLA_title4
	XITEM	oxNLA_title5
	XITEM	oxNLA_title6
	XITEM	oxNLA_title7
	XITEM	oxNLA_title8

	XITEM	oxNLA_align		; 8 bits, each for one column if that is aligned right

	XITEM	oxNLA_item		; tagdata is *taglist with tags for new item
	XITEM	oxNLA_itemtext2

	XITEM	oxNLA_titleheight	; for GET!

; bits for oxNLA_align

RIGHT1	=	1
RIGHT2	=	2
RIGHT3	=	4
RIGHT4	= 	8
RIGHT5	= 	16
RIGHT6	=	32
RIGHT7	=	64
RIGHT8	=	128

; tags for new list item via oxNLA_item

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxNLIA_text1
	XITEM	oxNLIA_text2
	XITEM	oxNLIA_text3
	XITEM	oxNLIA_text4
	XITEM	oxNLIA_text5
	XITEM	oxNLIA_text6
	XITEM	oxNLIA_text7
	XITEM	oxNLIA_text8
	XITEM	oxNLIA_userdata
	XITEM	oxNLIA_previtem		; insert new item after this, 0 = at end, -1 at start
	XITEM	oxNLIA_selected
	XITEM	oxNLIA_off		; ghosted
	XITEM	oxNLIA_altcolor		; use alternate color for item text, e.g. for "dirs"
	XITEM	oxNLIA_pri		; e.g. for "dirs first"
	XITEM	oxNLIA_separator	; this item is just a horinzontal separating line
	XITEM	oxNLIA_id		; unique user ID for this item, delivered to hooks in struct oxNLSelInfo

	XITEM	oxNLIA_folder		; add item to this folder
	XITEM	oxNLIA_numfold		; this item is a folder and the next numfold items are in this folder,
					; subfolders are counted as 1

; hooks get: a0 and a3 *list, a1 *oxNLSelInfo (see below), a4 *base from oxO_userbase(a3)

 STRUCTURE	oxNLSelInfo,0
	APTR	oxNLSI_list
	ULONG	oxNLSI_userdata
	APTR	oxNLSI_item
	ULONG	oxNLSI_item_userdata
	UWORD	oxNLSI_item_id		; copy of oxNLIA_id tag that was supplied at item creation time
	LABEL	oxNLSI_SIZEOF


; list methods

		ENUM	OX_METHODS_CLASS

	EITEM	oxNLM_sort				; alfabetical sort of entries , todo: sort with pri
	EITEM	oxNLM_getitemtexts			; get * to array with pointers to up to #columns texts
	EITEM	oxNLM_getitemuserdata
	EITEM	oxNLM_getnextitem
	EITEM	oxNLM_getnextselecteditem
	EITEM	oxNLM_deleteitem
	EITEM	oxNLM_item_on
	EITEM	oxNLM_item_off
	EITEM	oxNLM_selectitem
	EITEM	oxNLM_deselectitem
	EITEM	oxNLM_setitemtext
	EITEM	oxNLM_activate

	EITEM	oxNLM_unfold				; a1 folder *item to close
	EITEM	oxNLM_fold				;          ..        open


 STRUCTURE	oxNLSetItemText,0
	APTR	oxNLSIT_item
	APTR	oxNLSIT_text
	UWORD	oxNLSIT_column
	LABEL	oxNLSIT_SIZEOF

; Zak McKracken for President

	ENDC
