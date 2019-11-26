        IFND    LIBRARIES_WBSTART_I
LIBRARIES_WBSTART_I     SET     1
**
**   $VER: WBStart.I V2.2
**
**   shared library include file
**
**   (c) 1991-1996 Stefan Becker
**

     IFND  UTILITY_TAGITEM_I
     INCLUDE "utility/tagitem.i"
     ENDC

WBSTART_NAME    MACRO
                dc.b    "wbstart.library",0
                ENDM

WBSTART_VERSION EQU     2

* Tags for WBStartTagList()

* Name of the program to start. It is relative to
* WBStart_DirectoryName or WBStart_DirLock.
WBStart_Name            EQU     TAG_USER+1      ; APTR

* Name of a directory. Mutually exclusive to WBStart_DirectoryLock
WBStart_DirectoryName   EQU     TAG_USER+2      ; APTR

* Lock of a directory. Mutually exclusive to WBStart_DirectoryName
WBStart_DirectoryLock   EQU     TAG_USER+3      ; BPTR

* Stack size for the new process
WBStart_Stack           EQU     TAG_USER+4      ; ULONG

* Priority for the new process
WBStart_Priority        EQU     TAG_USER+5      ; LONG

* Number of arguments in WBStart_ArgumentList
WBStart_ArgumentCount   EQU     TAG_USER+6      ; ULONG

* Array of arguments. WBStart_ArgumentCount MUST be specified also!
WBStart_ArgumentList    EQU     TAG_USER+7      ; Pointer to struct WBArg

        ENDC    ; LIBRARIES_WBSTART_I
