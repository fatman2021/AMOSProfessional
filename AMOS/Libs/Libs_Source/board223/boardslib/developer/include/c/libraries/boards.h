#ifndef LIBRARIES_BOARDS_H
#define LIBRARIES_BOARDS_H

/*
**      $VER: boards.h 2.0 (17.12.1997)
**	created by SDI
**
**      boards.library definitions
**
**      (C)1997 by Torsten Bach
**      All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#include <libraries/configvars.h>

/* Generic library informations */
#define BOARDSNAME	"boards.library"
#define BOARDSVERSION	2

/*-----------------------------------------------------------------------
 BoardInfo structure

 This structure must only be allocated by boards.library with
 AllocBoardInfo().

 The BoardInfo structure are filled with NextBoardInfo()
 It`s READ-ONLY!
*/

struct BoardInfo {
  struct ConfigDev *	ConfigDev;    /* Pointer to ConfigDev structure */
  ULONG			bi_flags;     /* BoardInfo-flags */
  STRPTR		bi_ConfigDev; /* Pointer to ConfigDev-address [10] */
  STRPTR		bi_ExAddress; /* Pointer to Expansion-address [10] */
  STRPTR		bi_ExSize;    /* Pointer to Expansion-size [10] */
  STRPTR		bi_ManuID;    /* Pointer to ManufacturerID [6] */
  STRPTR		bi_ProdID;    /* Pointer to ProductID [4] */
  STRPTR		bi_ManuName;  /* Pointer to Manufacturer [48] */
  STRPTR		bi_ProdName;  /* Pointer to Product [48] */
  STRPTR		bi_cd_flags;  /* Pointer to ConfigDev-flags [4] */
  STRPTR		bi_er_type;   /* Pointer to Expansion-type [4] */
  STRPTR		bi_er_serial; /* Pointer to SerialNumber [12] */
};

/* You can change the string format by setting the BoardInfo-flags if you
   call AllocBoardInfo() */

/* BoardInfo-flags */

#define SB_EXPANSION_SIZE_HEX	(1<<0)	/* Default = DEC (e.g. 64k ) */

#define SB_MANUFACTURERID_HEX	(1<<2)	/* Default = DEC (e.g. 2017 ) */
#define SB_PRODUCTID_HEX	(1<<3)	/* Default = DEC (e.g. 1 ) */
#define SB_SERIALNUMBER_HEX	(1<<4)	/* Default = DEC (e.g. 123456 ) */
#define SB_CONFIGDEV_FLAGS_DEC	(1<<5)	/* Default = HEX (e.g. $02 ) */
#define SB_EXPANSION_TYPE_DEC	(1<<6)	/* Default = HEX (e.g. $c1 ) */

#endif /* LIBRARIES_BOARDS_H */

