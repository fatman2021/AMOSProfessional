/*
**  $VER: ConfigFile.e 2.1 (19.2.97)
**
**  E module source for the ConfigFile.library
**
**  (C) Copyright 1996-1997 min'MAX Developer's Group
**      All Rights Reserved.
**
**  (C) Copyright 1996-1997 Marcel Karas
**      All Rights Reserved.
*/

OPT MODULE,PREPROCESS
OPT EXPORT

/***************************************************************************
**                                                                        **
** General Stuff:                                                         **
**                                                                        **
***************************************************************************/

#define CF_NAME                 'configfile.library'
CONST   CF_VERSION              = 2

/***************************************************************************
**                                                                        **
** Openmodes for Cf_Open() and Cf_OpenPS():                               **
**                                                                        **
** CF_OMODE_OLDFILE   -- An existing file is opened. Did the file not     **
**                       exists the function failed.                      **
** CF_OMODE_NEWFILE   -- A new file will be create.                       **
** CF_OMODE_READWRITE -- Opens a file, but creates it if it didn't exist. **
**                                                                        **
***************************************************************************/

CONST   CF_OMODE_OLDFILE        = $00,
        CF_OMODE_NEWFILE        = $01,
        CF_OMODE_READWRITE      = $02

/***************************************************************************
**                                                                        **
** Extra flags for Cf_Open() and Cf_OpenPS(): (V2)                        **
**                                                                        **
** CF_OFLG_READ_TOO -- Reads the file directly after the it is open.      **
**                                                                        **
***************************************************************************/

CONST   CF_OFLG_READ_TOO        = $04

/***************************************************************************
**                                                                        **
** Writemodes for Cf_Write():                                             **
**                                                                        **
** CF_WMODE_DEFAULT -- Writes the file in the format from Header->Flags.  **
** CF_WMODE_SHORT   -- Writes the file in short format.                   **
** CF_WMODE_ASCII   -- Writes the file in ascii format.                   **
**                                                                        **
***************************************************************************/

CONST   CF_WMODE_DEFAULT        = $00,
        CF_WMODE_SHORT          = $01,
        CF_WMODE_ASCII          = $02

/***************************************************************************
**                                                                        **
** Extra flags for cf_Write(): (V2)                                       **
**                                                                        **
** CF_WFLG_WRITE_ALWAYS -- Cf_Write() checks not if the CF_HFLG_CHANGED   **
**                         flag set and writes always the file.           **
**                                                                        **
***************************************************************************/

CONST   CF_WFLG_WRITE_ALWAYS    = $04

/***************************************************************************
**                                                                        **
** Error codes:                                                           **
**                                                                        **
** for cf_Open():                                                         **
**                                                                        **
** CF_OERR_UNKOWN        -- Unkown failure.                               **
** CF_OERR_OPEN_FILE     -- Couldn't open CF file.                        **
** CF_OERR_READ_FILE     -- Couldn't read CF file.                        **
** CF_OERR_NO_FORMAT     -- File is no in CF format.                      **
** CF_OERR_NO_SIZE       -- File has no size.                             **
** CF_OERR_HEADER_MEM    -- No memory for Header.                         **
**                                                                        **
** for cf_Read():                                                         **
**                                                                        **
** CF_RERR_UNKOWN        -- Unkown failure.                               **
** CF_RERR_BUFFER_MEM    -- No memory for buffer.                         **
** CF_RERR_READ_FILE     -- Couldn't read the file.                       **
** CF_RERR_FORMAT        -- File has an error in the format structure.(V2)**
** CF_RERR_UNKOWN_ITYPE  -- An unkown item type was found. (V2)           **
**                                                                        **
** for cf_Write():                                                        **
**                                                                        **
** CF_WERR_UNKOWN        -- Unkown failure.                               **
** CF_WERR_ALLOC_WBUFFER -- No memory for WriteBuffer.                    **
**                                                                        **
***************************************************************************/

CONST   CF_OERR_UNKOWN          = $00,
        CF_OERR_OPEN_FILE       = $01,
        CF_OERR_READ_FILE       = $02,
        CF_OERR_NO_FORMAT       = $03,
        CF_OERR_NO_SIZE         = $04,
        CF_OERR_HEADER_MEM      = $05,

        CF_RERR_UNKOWN          = $00,
        CF_RERR_BUFFER_MEM      = $01,
        CF_RERR_READ_FILE       = $02,

        CF_RERR_FORMAT          = $06,
        CF_RERR_UNKOWN_ITYPE    = $07,

        CF_WERR_UNKOWN          = $00,
        CF_WERR_ALLOC_WBUFFER   = $01

/***************************************************************************
**                                                                        **
** Item types:                                                            **
**                                                                        **
** CF_ITYP_STRING -- String type (in file "MyString")                     **
** CF_ITYP_NUMBER -- Number type (in file %111001,$ED45F,23642)           **
** CF_ITYP_BOOL   -- Bool type   (in file TRUE/FALSE,YES/NO,ON/OFF)       **
**                                                                        **
***************************************************************************/

CONST   CF_ITYP_STRING          = $01,
        CF_ITYP_NUMBER          = $02,
        CF_ITYP_BOOL            = $03

/***************************************************************************
**                                                                        **
** Special item types for cf_Write():                                     **
**                                                                        **
** CF_ITYP_BOOL:                                                          **
**                                                                        **
** CF_STYP_BOOL_DEFAULT -- same as CF_STYP_BOOL_YES. (V2)                 **
** CF_STYP_BOOL_YES     -- is YES/NO.                                     **
** CF_STYP_BOOL_TRUE    -- is TRUE/FALSE.                                 **
** CF_STYP_BOOL_ON      -- is ON/OFF.                                     **
**                                                                        **
** CF_ITYP_NUMBER:                                                        **
**                                                                        **
** CF_STYP_NUM_DEFAULT  -- same as CF_STYP_NUM_DEC. (V2)                  **
** CF_STYP_NUM_DEC      -- e.g. 24414.                                    **
** CF_STYP_NUM_HEX      -- e.g. $fDe2.                                    **
** CF_STYP_NUM_BIN      -- e.g. %10111.                                   **
**                                                                        **
***************************************************************************/

CONST   CF_STYP_BOOL_DEFAULT    = $00,
        CF_STYP_BOOL_TRUE       = $01,
        CF_STYP_BOOL_YES        = $02,
        CF_STYP_BOOL_ON         = $03,

        CF_STYP_NUM_DEFAULT     = $00,
        CF_STYP_NUM_DEC         = $01,
        CF_STYP_NUM_HEX         = $02,
	CF_STYP_NUM_BIN		= $03

/***************************************************************************
**                                                                        **
** CFHeader structure is the main pointer of a CF file.                   **
**                                                                        **
** OpenMode   -- Openmode CF_OMODE_OLDFILE/NEWFILE/READWRITE.             **
** Length     -- Actual length of the CF file.                            **
** WBufLength -- Length of the writebuffer in bytes (default is 4096).    **
** Flags      -- Flags of the CF file (see below).                        **
** PuddleSize -- Size of the memory puddle (longword aligned). (V2)       **
**                                                                        **
** NOTE:                                                                  **
**                                                                        **
** OpenMode, Length and PuddleSize are read only.                         **
**                                                                        **
***************************************************************************/

OBJECT	cfheader
  openmode
  length
  wbuflength
  flags
  private[4]:ARRAY OF LONG
  puddlesize
ENDOBJECT

/***************************************************************************
**                                                                        **
** Flags from Header->Flags:                                              **
**                                                                        **
** CF_HFLG_SHORT_FILE     -- File is in short format.                     **
** CF_HFLG_ASCII_FILE     -- File is in ascii format.                     **
** CF_HFLG_CHANGED        -- File is changed (this will be set, if you    **
**                           use functions like Cf_Add/Change/Clone... on **
**                           the open file). (V2)                         **
** CF_HFLG_WRITE_BY_CLOSE -- Writes the file by use of Cf_Close(). (V2)   **
**                                                                        **
***************************************************************************/

CONST   CF_HFLG_SHORT_FILE      = $01,
        CF_HFLG_ASCII_FILE      = $02,

        CF_HFLG_CHANGED         = $04,
        CF_HFLG_WRITE_BY_CLOSE  = $08

/***************************************************************************
**                                                                        **
** Nodes of an open CF file:                                              **
**                                                                        **
** CFGroup node is in the CF file (e.g. [MyGroup]).                       **
** CFArgument node is in the CF file (e.g. MyArgument=).                  **
** CFItem node is in the CF file (e.g. "Str",$DFe3,%110,NO).              **
**                                                                        **
***************************************************************************/

OBJECT	cfgroup
  private
ENDOBJECT

OBJECT	cfargument
  private
ENDOBJECT

OBJECT	cfitem
  private
ENDOBJECT

/***************************************************************************
**                                                                        **
** Easy to use macros for Cf_NewItem().                                   **
**                                                                        **
***************************************************************************/

#define Cf_NewString(ArgNode,String)  Cf_NewItem (ArgNode, String, CF_ITYP_STRING, NULL)

#define Cf_NewNum(ArgNode,Num)        Cf_NewItem (ArgNode, Num, CF_ITYP_NUMBER,CF_STYP_NUM_DEFAULT)
#define Cf_NewNumDec(ArgNode,Num)     Cf_NewItem (ArgNode, Num, CF_ITYP_NUMBER,CF_STYP_NUM_DEC)
#define Cf_NewNumHex(ArgNode,Num)     Cf_NewItem (ArgNode, Num, CF_ITYP_NUMBER,CF_STYP_NUM_HEX)
#define Cf_NewNumBin(ArgNode,Num)     Cf_NewItem (ArgNode, Num, CF_ITYP_NUMBER,CF_STYP_NUM_BIN)

#define Cf_NewBool(ArgNode,Bool)      Cf_NewItem (ArgNode, Bool, CF_ITYP_BOOL, CF_STYP_BOOL_DEFAULT)
#define Cf_NewBoolTrue(ArgNode,Bool)  Cf_NewItem (ArgNode, Bool, CF_ITYP_BOOL, CF_STYP_BOOL_TRUE)
#define Cf_NewBoolYes(ArgNode,Bool)   Cf_NewItem (ArgNode, Bool, CF_ITYP_BOOL, CF_STYP_BOOL_YES)
#define Cf_NewBoolOn(ArgNode,Bool)    Cf_NewItem (ArgNode, Bool, CF_ITYP_BOOL, CF_STYP_BOOL_ON)

/**************************************************************************/
