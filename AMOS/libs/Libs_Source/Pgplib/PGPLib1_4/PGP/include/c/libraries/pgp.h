#ifndef  LIBRARIES_PGP_H
#define  LIBRARIES_PGP_H

/*
**  libraries/pgp.h
**
**  C definitions for pgp.library
**
**  $VER: pgp.h 1.1 (23.3.98)
**
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif



/* Name / Version */
#define PGPNAME      "pgp.library"
#define PGPVERSION   1


/* Tags */
#define PGPTAG_OutFile      (TAG_USER + 1)      /* Encrypt,Decrypt,Sign */
#define PGPTAG_UserId       (TAG_USER + 2)      /* Encrypt,Sign */
#define PGPTAG_ConOutput    (TAG_USER + 3)      /* Encrypt,Decrypt,Sign */
#define PGPTAG_Binary       (TAG_USER + 4)      /* Encrypt */
#define PGPTAG_Break        (TAG_USER + 5)      /* Sign */
#define PGPTAG_Password     (TAG_USER + 6)      /* Encrypt */
#define PGPTAG_Sign         (TAG_USER + 7)      /* Encrypt */
#define PGPTAG_WipeOut      (TAG_USER + 8)      /* Encrypt */


#endif   /* LIBRARIES_PGP_H */
