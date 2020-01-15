(*(* $Id: pgplib.mod,v 1.10 2002/07/15 18:50:38 schenk Exp $ *)*)

MODULE pgplib;

(* $OvflChk- $RangeChk- $StackChk- $NilChk- $ReturnChk- $CaseChk- $OddChk- *)

IMPORT
  a  := ASCII,
  c  := Conversions,
  d  := Dos,
  e  := Exec,
  ms := MHStrings,
  p  := Printf,
  rx := Rexx,
  rs := RexxSysLib,
        RVI,
  s  := Strings,
  s0 := Strings0,
  u  := Utility,
  wb := WBPath,
  S  := SYSTEM;

CONST
  tagOutFile   = u.user + 1;
  tagUserId    = u.user + 2;
  tagConOutput = u.user + 3;
  tagBinary    = u.user + 4;
  tagBreak     = u.user + 5;
  tagPassword  = u.user + 6;
  tagSign      = u.user + 7;
  tagWipeOut   = u.user + 8;

  varname = "pgppass";

VAR
  pgppath : e.STRING;

PROCEDURE DoCommand (command, conoutput : ARRAY OF CHAR; password : e.LSTRPTR) : LONGINT; (* $CopyArrays- *)
VAR
  ok     : LONGINT;
  path   : d.PathLockPtr;
  stdout : d.FileHandlePtr;
  setvar : BOOLEAN;
BEGIN
  ok := -1;
  path := wb.CloneWorkbenchPath ();
  stdout := d.Open (conoutput, d.oldFile);
  IF stdout # NIL THEN
    IF password # NIL THEN
      (* $OddChk- *)
      setvar := d.SetVar (varname, password^, -1, LONGSET {d.localOnly})
      (* $OddChk= *)
    ELSE
      setvar := FALSE
    END;
    ok := d.SystemTags (command, d.npPath,    S.VAL (LONGINT, path),
                                 d.sysInput,  S.VAL (LONGINT, stdout),
                                 d.sysOutput, S.VAL (LONGINT, NIL),
                                 u.done);
    IF setvar THEN
      IF d.DeleteVar (varname, LONGSET {d.localOnly}) THEN END
    END;
    d.OldClose (stdout)
  END;
  IF ok = -1 THEN
    wb.FreeWorkbenchPath (path)
  END;
  RETURN ok
END DoCommand;

PROCEDURE Encrypt * (regfilename {8},
                     reguserid   {9} : e.LSTRPTR;
                     regtagitems {0} : u.TagItemPtr) : LONGINT;
VAR
  filename, userid, outfile,
  signpassword, signuserid : e.LSTRPTR;
  tagitems, tag, tstate    : u.TagItemPtr;
  command, stdout          : ms.STRING;
  ok                       : LONGINT;
  ascii                    : ARRAY 4 OF CHAR;
(* $SaveRegs+ *)
BEGIN
  filename     := regfilename;
  userid       := reguserid;
  tagitems     := regtagitems;
  outfile      := NIL;
  signpassword := NIL;
  signuserid   := NIL;
  ascii        := "a";
  stdout.Set ("*");
  tstate := tagitems;
  tag := u.NextTagItem (tstate);
  WHILE tag # NIL DO
    CASE tag^.tag OF
    | tagBinary    : IF tag^.data # e.LFALSE THEN
                       ascii := ""
                     END
    | tagConOutput : IF tag^.data # NIL THEN
                       (* $OddChk- *)
                       stdout.Set (S.VAL (e.LSTRPTR, tag^.data)^)
                       (* $OddChk= *)
                     END
    | tagOutFile   : IF tag^.data # NIL THEN
                       outfile := tag^.data
                     END
    | tagWipeOut   : IF tag^.data # e.LFALSE THEN
                       s.Append (ascii, "w")
                     END
    | tagPassword  : IF tag^.data # NIL THEN
                       signpassword := tag^.data
                     END
    | tagSign      : IF tag^.data # e.LFALSE THEN
                       s.Append (ascii, "s")
                     END
    | tagUserId    : IF tag^.data # NIL THEN
                       signuserid := tag^.data
                     END
    ELSE END;
    tag := u.NextTagItem (tstate)
  END;
  ms.SPrintf (command, "pgp +batchmode -e%s \"%s\" \"%s\"", S.ADR (ascii),
                                                            filename,
                                                            userid);
  IF outfile # NIL THEN
    command.Append (" -o \"");
    (* $OddChk- *)
    command.Append (outfile^);
    (* $OddChk= *)
    command.Append ("\"")
  END;
  IF signuserid # NIL THEN
    command.Append (" -u \"");
    (* $OddChk- *)
    command.Append (signuserid^);
    (* $OddChk= *)
    command.Append ("\"")
  END;
  ok := DoCommand (command.chars^, stdout.chars^, signpassword);
  command.Dispose;
  stdout.Dispose;
  RETURN ok
END Encrypt;

PROCEDURE Decrypt * (regfilename {8},
                     regpassword {9} : e.LSTRPTR;
                     regtagitems {0} : u.TagItemPtr) : LONGINT;
VAR
  filename, password, outfile : e.LSTRPTR;
  tagitems, tag, tstate       : u.TagItemPtr;
  ok                          : LONGINT;
  command, stdout             : ms.STRING;
(* $SaveRegs+ *)
BEGIN
  filename := regfilename;
  password := regpassword;
  tagitems := regtagitems;
  outfile  := NIL;
  ok       := -1;
  stdout.Set ("*");
  tstate := tagitems;
  tag := u.NextTagItem (tstate);
  WHILE tag # NIL DO
    CASE tag^.tag OF
    | tagConOutput : IF tag^.data # NIL THEN
                       (* $OddChk- *)
                       stdout.Set (S.VAL (e.LSTRPTR, tag^.data)^)
                       (* $OddChk= *)
                     END
    | tagOutFile   : IF tag^.data # NIL THEN
                       outfile := tag^.data
                     END
    ELSE END;
    tag := u.NextTagItem (tstate)
  END;
  ms.SPrintf (command, "pgp +batchmode \"%s\"", filename);
  IF outfile # NIL THEN
    command.Append (" -o \"");
    (* $OddChk- *)
    command.Append (outfile^);
    (* $OddChk= *)
    command.Append ("\"")
  END;
  ok := DoCommand (command.chars^, stdout.chars^, password);
  command.Dispose;
  stdout.Dispose;
  RETURN ok
END Decrypt;

PROCEDURE Sign * (regfilename {8},
                  regpassword {9} : e.LSTRPTR;
                  regtagitems {0} : u.TagItemPtr) : LONGINT;
VAR
  filename, password, outfile, userid : e.LSTRPTR;
  tagitems, tag, tstate               : u.TagItemPtr;
  ok                                  : LONGINT;
  command, stdout                     : ms.STRING;
  ascii                               : CHAR;
(* $SaveRegs+ *)
BEGIN
  filename := regfilename;
  password := regpassword;
  tagitems := regtagitems;
  outfile  := NIL;
  userid   := NIL;
  ascii    := "a";
  ok       := -1;
  stdout.Set ("*");
  tstate := tagitems;
  tag := u.NextTagItem (tstate);
  WHILE tag # NIL DO
    CASE tag^.tag OF
    | tagBreak     : IF tag^.data # e.LFALSE THEN
                       ascii := "b"
                     END
    | tagConOutput : IF tag^.data # NIL THEN
                       (* $OddChk- *)
                       stdout.Set (S.VAL (e.LSTRPTR, tag^.data)^)
                       (* $OddChk= *)
                     END
    | tagOutFile   : IF tag^.data # NIL THEN
                       outfile := tag^.data
                     END
    | tagUserId    : IF tag^.data # NIL THEN
                       userid := tag^.data
                     END
    ELSE END;
    tag := u.NextTagItem (tstate)
  END;
  ms.SPrintf (command, "pgp +batchmode -s%lc \"%s\"", ORD (ascii), filename);
  IF outfile # NIL THEN
    command.Append (" -o \"");
    (* $OddChk- *)
    command.Append (outfile^);
    (* $OddChk= *)
    command.Append ("\"")
  END;
  IF userid # NIL THEN
    command.Append (" -u \"");
    (* $OddChk- *)
    command.Append (userid^);
    (* $OddChk= *)
    command.Append ("\"")
  END;
  ok := DoCommand (command.chars^, stdout.chars^, password);
  command.Dispose;
  stdout.Dispose;
  RETURN ok
END Sign;

PROCEDURE Fault * (regcode   {0} : LONGINT;
                   regheader {8},
                   regbuffer {9} : e.LSTRPTR;
                   reglen    {1} : LONGINT) : LONGINT;
TYPE
  Error = RECORD
    code   : LONGINT;
    string : e.LSTRPTR
  END;
  ErrorArray = ARRAY 25 OF Error;

CONST
  errors = ErrorArray ( 1, S.ADR ("invalid file"),
                        2, S.ADR ("file not found"),
                        3, S.ADR ("unknown file"),
                        4, S.ADR ("no batch"),
                        5, S.ADR ("bad arg"),
                        6, S.ADR ("interrupt"),
                        7, S.ADR ("out of mem"),
                       10, S.ADR ("keygen error"),
                       11, S.ADR ("key does not exist"),
                       12, S.ADR ("keyring add error"),
                       13, S.ADR ("keyring extract error"),
                       14, S.ADR ("keyring edit error"),
                       15, S.ADR ("keyring view error"),
                       16, S.ADR ("keyring remove error"),
                       17, S.ADR ("keyring check error"),
                       18, S.ADR ("key signature error"),
                       19, S.ADR ("keysig remove error"),
                       20, S.ADR ("signature error"),
                       21, S.ADR ("rsa encryption error"),
                       22, S.ADR ("encryption error"),
                       23, S.ADR ("compress error"),
                       30, S.ADR ("signature check error"),
                       31, S.ADR ("rsa decryption error"),
                       32, S.ADR ("decryption error"),
                       33, S.ADR ("decompress error"));

VAR
  code, len              : LONGINT;
  header, buffer, string : e.LSTRPTR;

  PROCEDURE GetErrorString (code : LONGINT) : e.LSTRPTR;
  VAR
    index : LONGINT;
  BEGIN
    index := 0;
    LOOP
      IF (index >= LEN (errors)) OR (errors [index].code > code) THEN
        RETURN NIL
      END;
      IF errors [index].code = code THEN
        RETURN errors [index].string
      END;
      INC (index)
    END
  END GetErrorString;

(* $SaveRegs+ *)
BEGIN
  code   := regcode;
  header := regheader;
  buffer := regbuffer;
  len    := reglen;
  IF (code # 0) & (buffer # NIL) THEN
    string := GetErrorString (code);
    (* $OddChk- *)
    IF string # NIL THEN
      p.LSPrintF (buffer^, len, "%s", string)
    ELSE
      p.LSPrintF (buffer^, len, "Error %ld", code)
    END;
    IF (header # NIL) & (header^ [0] # a.nul) THEN
      s.Insert (buffer^, 0, ": ");
      s.Insert (buffer^, 0, header^)
    END;
    RETURN s.Length (buffer^)
    (* $OddChk- *)
  ELSE
    RETURN 0
  END
END Fault;

PROCEDURE ARexxQuery * (regrexxmsg {8} : rx.RexxMsgPtr) : LONGINT;
VAR
  rexxmsg      : rx.RexxMsgPtr;
  ok, code     : LONGINT;
  result       : UNTRACED POINTER TO ARRAY OF CHAR;
  resultstring : e.LSTRPTR;
  tags         : u.Tags4;

  PROCEDURE NumArgs () : LONGINT;
  BEGIN
    RETURN rexxmsg^.action MOD 16
  END NumArgs;

(* $SaveRegs+ *)
BEGIN
  rexxmsg := regrexxmsg;
  ok := rx.err10001;
  IF (rexxmsg # NIL) & RVI.CheckRexxMsg (rexxmsg)  &
     (rx.ActionCode (rexxmsg^.action) = rx.rxFunc) &
     (rexxmsg^.args [0] # NIL) THEN
    S.ALLOCATE (result, 256);
    IF result # NIL THEN
      (* -------------------------- Befehl ausführen ------------------------ *)
      (* $OddChk- *)
      IF s0.Compare (rexxmsg^.args [0]^, "PGPEncrypt", FALSE) THEN
        IF NumArgs () >= 3 THEN
          tags [0].tag  := tagOutFile;
          tags [0].data := rexxmsg^.args [3]
        ELSE
          tags [0].tag  := u.ignore
        END;
        IF NumArgs () >= 4 THEN
          tags [1].tag  := tagConOutput;
          tags [1].data := rexxmsg^.args [4]
        ELSE
          tags [1].tag  := u.ignore
        END;
        tags [2].tag  := u.done;
        p.LSPrintF (result^, LEN (result^), "%ld", Encrypt (rexxmsg^.args [1],
                                                            rexxmsg^.args [2],
                                                            S.ADR (tags)));
        ok := rx.ok
      ELSIF s0.Compare (rexxmsg^.args [0]^, "PGPDecrypt", FALSE) THEN
        IF NumArgs () >= 3 THEN
          tags [0].tag  := tagOutFile;
          tags [0].data := rexxmsg^.args [3]
        ELSE
          tags [0].tag  := u.ignore
        END;
        IF NumArgs () >= 4 THEN
          tags [1].tag  := tagConOutput;
          tags [1].data := rexxmsg^.args [4]
        ELSE
          tags [1].tag  := u.ignore
        END;
        tags [2].tag  := u.done;
        p.LSPrintF (result^, LEN (result^), "%ld", Decrypt (rexxmsg^.args [1],
                                                            rexxmsg^.args [2],
                                                            S.ADR (tags)));
        ok := rx.ok
      ELSIF s0.Compare (rexxmsg^.args [0]^, "PGPFault", FALSE) THEN
        IF c.StringToInt (rexxmsg^.args [1]^, code) THEN
          IF Fault (code, rexxmsg^.args [2], S.ADR (result^), LEN (result^)) # 0 THEN END
        END;
        ok := rx.ok
      ELSIF s0.Compare (rexxmsg^.args [0]^, "PGPSign", FALSE) THEN
        IF NumArgs () >= 3 THEN
          tags [0].tag  := tagOutFile;
          tags [0].data := rexxmsg^.args [3]
        ELSE
          tags [0].tag  := u.ignore
        END;
        IF NumArgs () >= 4 THEN
          tags [1].tag  := tagUserId;
          tags [1].data := rexxmsg^.args [4]
        ELSE
          tags [1].tag  := u.ignore
        END;
        IF NumArgs () >= 5 THEN
          tags [2].tag  := tagConOutput;
          tags [2].data := rexxmsg^.args [5]
        ELSE
          tags [2].tag  := u.ignore
        END;
        tags [3].tag  := u.done;
        p.LSPrintF (result^, LEN (result^), "%ld", Sign (rexxmsg^.args [1],
                                                         rexxmsg^.args [2],
                                                         S.ADR (tags)));
        ok := rx.ok
      END;
      (* $OddChk= *)
      IF ok = rx.ok THEN
        resultstring := rs.CreateArgstring (result^, s.Length (result^));
        IF resultstring # NIL THEN
          S.SETREG (8, resultstring)
        ELSE
          ok := rx.err10003
        END
      END;
      DISPOSE (result)
    END
  END;
  RETURN ok
END ARexxQuery;

BEGIN
  IF d.GetVar ("pgppath", pgppath, LEN (pgppath), LONGSET {d.globalOnly}) = -1 THEN
    HALT (d.fail)
  END
END pgplib.
