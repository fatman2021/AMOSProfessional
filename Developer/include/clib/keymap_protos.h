#ifndef CLIB_KEYMAP_PROTOS_H
#define CLIB_KEYMAP_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/rom/keymap/keymap.conf'. Edits will be lost. ***
    Copyright © 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <devices/keymap.h>
#include <devices/inputevent.h>

__BEGIN_DECLS


#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)
AROS_LP1(void, SetKeyMapDefault,
         AROS_LPA(struct KeyMap *, keyMap, A0),
         LIBBASETYPEPTR, KeymapBase, 5, Keymap
);

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)
AROS_LP0(struct KeyMap *, AskKeyMapDefault,
         LIBBASETYPEPTR, KeymapBase, 6, Keymap
);

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)
AROS_LP4(WORD, MapRawKey,
         AROS_LPA(struct InputEvent *, event, A0),
         AROS_LPA(STRPTR, buffer, A1),
         AROS_LPA(LONG, length, D1),
         AROS_LPA(struct KeyMap *, keyMap, A2),
         LIBBASETYPEPTR, KeymapBase, 7, Keymap
);

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

#if !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__)
AROS_LP5(LONG, MapANSI,
         AROS_LPA(STRPTR, string, A0),
         AROS_LPA(LONG, count, D0),
         AROS_LPA(STRPTR, buffer, A1),
         AROS_LPA(LONG, length, D1),
         AROS_LPA(struct KeyMap *, keyMap, A2),
         LIBBASETYPEPTR, KeymapBase, 8, Keymap
);

#endif /* !defined(__KEYMAP_LIBAPI__) || (36 <= __KEYMAP_LIBAPI__) */

__END_DECLS

#endif /* CLIB_KEYMAP_PROTOS_H */
