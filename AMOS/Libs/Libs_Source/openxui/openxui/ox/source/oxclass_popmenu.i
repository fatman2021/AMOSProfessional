	IFND LIBRARIES_OX_CLASSES_POPMENU_I
LIBRARIES_OX_CLASSES_POPMENU_I	SET	1

; popupmenu class for open source external user interfaces
; Andreas G. Szabo

		include	p:ox.i
		include exec/types.i

; hooks get: a0 and a3 *stringgad, a1 and a5 *oxNSSelInfo (see below), a4 *base from oxO_userbase(a3)

 STRUCTURE	oxPMSelInfo,0
	UWORD	oxPMSI_menuid		; each menu and submenu can have a unique ID
 	UWORD	oxPMSI_itemid		; each item can have a unique ID
	UWORD	oxPMSI_itemnr		; each item has a number 1 to x in each menu/submenu
	LABEL	oxPMSI_SIZEOF


; popmenu attributes

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxPMA_title
	XITEM	oxPMA_hook
	XITEM	oxPMA_id
	XITEM	oxPMA_item

		ENUM	OX_ATTRIBS_CLASS

	XITEM	oxPMIA_text
	XITEM	oxPMIA_off	; true or false
	XITEM	oxPMIA_id
	XITEM	oxPMIA_submenu	; annother list of oxPMA_ attribs where only _id and _item are allowed


; popmenu methods

		ENUM	OX_METHODS_CLASS

	EITEM	oxPMM_popup
	EITEM	oxPMM_ghostitem
	EITEM	oxPMM_unghostitem
	EITEM	oxPMM_deleteitem

; Zak McKracken for President

	ENDC
