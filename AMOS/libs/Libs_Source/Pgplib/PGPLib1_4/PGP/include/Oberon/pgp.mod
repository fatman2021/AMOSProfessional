MODULE pgp;

IMPORT
  e := Exec,
  u := Utility;

CONST
  name    - = "pgp.library";
  version - = 1;

  (* -------------------- tags for Encrypt, Decrypt, Sign ------------------- *)
  tagOutFile   - = u.user + 1;
  tagConOutput - = u.user + 3;

  (* ------------------------ tags for Encrypt, Sign ------------------------ *)
  tagUserId    - = u.user + 2;

  (* --------------------------- tags for Encrypt --------------------------- *)
  tagBinary    - = u.user + 4;
  tagPassword  - = u.user + 6;
  tagSign      - = u.user + 7;
  tagWipeOut   - = u.user + 8;

  (* ---------------------------- tags for Sign ----------------------------- *)
  tagBreak     - = u.user + 5;

VAR
  base - : e.LibraryPtr; (* check if # NIL before usage! *)

PROCEDURE Encrypt     * {base, -36} (filename   {8},
                                     userid     {9}    : ARRAY OF CHAR;
                                     tagItems   {0}    : ARRAY OF u.TagItem) : LONGINT;

PROCEDURE EncryptTags * {base, -36} (filename   {8},
                                     userid     {9}    : ARRAY OF CHAR;
                                     tagItems   {0} .. : u.Tag)              : LONGINT;

PROCEDURE Decrypt     * {base, -42} (filename   {8},
                                     password   {9}    : ARRAY OF CHAR;
                                     tagItems   {0}    : ARRAY OF u.TagItem) : LONGINT;

PROCEDURE DecryptTags * {base, -42} (filename   {8},
                                     password   {9}    : ARRAY OF CHAR;
                                     tagItems   {0} .. : u.Tag)              : LONGINT;

PROCEDURE Fault       * {base, -48} (code       {0}    : LONGINT;
                                     header     {8}    : ARRAY OF CHAR;
                                     VAR buffer {9}    : ARRAY OF CHAR;
                                     len        {1}    : LONGINT)            : LONGINT;

PROCEDURE Sign        * {base, -54} (filename   {8},
                                     password   {9}    : ARRAY OF CHAR;
                                     tagItems   {0}    : ARRAY OF u.TagItem) : LONGINT;

PROCEDURE SignTags    * {base, -54} (filename   {8},
                                     password   {9}    : ARRAY OF CHAR;
                                     tagItems   {0} .. : u.Tag)              : LONGINT;

(* $OvflChk- $RangeChk- $StackChk- $NilChk- $ReturnChk- $CaseChk- *)

BEGIN
  base := e.OpenLibrary (name, version)

CLOSE
  IF base # NIL THEN
    e.CloseLibrary (base)
  END
END pgp.
