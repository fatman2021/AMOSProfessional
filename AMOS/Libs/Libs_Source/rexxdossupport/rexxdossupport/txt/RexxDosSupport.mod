(*(***********************************************************************

:Program.    rexxdossupport.mod
:Contents.   access to V37+ Dos.library functions from within ARexx
:Author.     hartmtut Goebel [hG]
:Address.    Aufseßplatz 5, D-90459 Nürnberg
:Address.    UseNet: hartmut@oberon.nbg.sub.org
:Copyright.  Copyright © 1994-1997 by hartmtut Goebel
:Language.   Oberon-2
:Translator. Amiga Oberon 3.11
:Imports.    Printf (Martin Horneffer), RxLibsSupport [hG]
:Version.    $VER: rexxdossupport.mod 3.5 (6.2.97) Copyright © 1994-1997 by hartmtut Goebel

(* $StackChk- $NilChk- $RangeChk- $CaseChk- $OvflChk- $ReturnChk- $ClearVars- *)
(****** rexxdossupport.library/--history-- **********************
*
*  3.5  06 Feb 1997
*       · fixed: AddPart(9 was callable with empty arguments which
*         caused Enforcer hits (ack: Andreas Mixich)
*  3.4  20 Mar 1996
*       · fixed FilePart(): last charakter has been stripped
*         (ack: Nick Ring)
*  3.3  06 Mar 1996
*       · revised autodocs a bit
*  3.2  23 Feb 1996
*       · improofed docs about accessing local environment varibales
*       · fixed some erratas
*  3.1  16 Feb 1996
*       · new functions: AddPart(), FilePart(), PathPart()
*         (suggested many times)
*       · ReadArgs supports /T now (suggested by Magnus Holgren)
*  3.0  17 Jan 1996 [Kai Bolay]
*       · new function: AbsolutePath()
*
*  2.4  11 Oct 1995
*       · fixed memory lose in ReadArgs (ack: Alexander Stirmlinger)
*       · ReadArgs example is now complete (ack: Oliver Creighton)
*  2.3  01 Apr 1995
*       · fixed problem with synonyms: foo=bar lead to illegal
*         variable named 'FOO=BAR'. Now allways th first synonym is
*         taken as var-name.
*  2.2  18 Jul 1994
*       · Shame on me! library names must be lowercase
*       · Some more notes in documentation
*  2.1  03 Jun 1994
*       · removed curious bug in ReadArgs() (uninitialized var,
*         introduced in V2.0)
*  2.0  07 May 1994 (never released)
*       · stronger check for present args to avoid NIL-Traps
*       · new functions: Delete(), Rename(), MakeDir(),
*                        SetComment(), SetProtection()
*  1.4  01 Feb 1994
*       · only significant part of parsed pattern is copied
*         into the ARexx Argstring
*  1.3  23 Jan 1994
*       · uses module RxLibsSupport [hG]
*  1.2  18 Jan 1994
*       · finished dokumentation
*       · UnsetVar() - like shell commnad - renamed to
*         DeleteVar() - like in dos.library
*       · SetVar() no longer accepts option "Binary"
*  1.1  16 Jan 1994
*       initial release
*
*******
(****** rexxdossupport.library/--Disclaimer-- **********************
*
*Disclaimer
*----------
*
*   Permission is granted to make and distribute verbatim copies  of  this
*manual provided the copyright  notice  and  this  permission  notice  are
*preserved on all copies.
*
*COPYRIGHT
*
*   Copyright (C) 1994-1997 by hartmut Goebel
*
*   No program, document, data file or  source  code  from  this  software
*package, neither in whole nor in part, may be included or used  in  other
*software packages unless it is authorized by a  written  permission  from
*the author.
*
*
*NO WARRANTY
*
*   There is no warranty for this software package.  Although  the  author
*has tried to prevent errors, he can't guarantee that the software package
*described in this document is 100% reliable. You are therefore using this
*material at your own risk. The author cannot be made responsible for  any
*damage which is caused by using this software package.
*
*
*DISTRIBUTION
*
*   This software package is freely distributable. It may be  put  on  any
*media which is used for the distribution of free  software,  like  Public
*Domain disk collections, CDROMs, FTP servers or bulletin board systems.
*
*   In  order  to  ensure  the  integrity  of   this   software   package,
*distributors should use the original archive file  rexxdossuppor.lha.
*The author cannot be  made  responsible  if  this software  package   has
*become unusable due to modifications of  the  archive  contents   or   of
*the archive file itself.
*
*   There is no limit on the costs  of  the  distribution,  e.g.  for  the
*media, like floppy disks, streamer tapes or compact disks, or the process
*of duplicating. Such limits have been proven to be harmful to the idea of
*freely distributable software, e.g. instead of reducing the price of  the
*floppy disk below the limit, the software was  simply  removed  from  the
*master disk.
*
*   Although the author does not impose any limit on the  distribution  of
*this software package, he would like to express his personal opinions  on
*this matter:
*
*   * This software package should be made available to everyone  free  of
*     charge whenever it is possible.
*
*   * If you have acquired this software package under  normal  conditions
*     from a Public Domain dealer on a floppy disk at a price higher  than
*     5DM or US $5, then you have definitely paid too much.  Please  don't
*     support this improper profit making  any  longer  and  switch  to  a
*     cheaper source as soon as possible.
*
*
*USAGE RESTRICTIONS
*
*   No program, document, data file or  source  code  from  this  software
*package, neither in whole nor in part, may be used on any  machine  which
*is used
*
*   * for the research, development, construction, testing  or  production
*     of weapons or other military applications. This  also  includes  any
*     machine which is  used  in  the  education  for  any  of  the  above
*     mentioned purposes.
*
*   * by people who accept, support or use violence against other  people,
*     e.g. citizens from foreign countries.
*
*********)*)*)*)
(****** rexxdossupport.library/--background-- *******************
*
*                rexxdossupport.library 3.5
*                ==========================
*
*         Copyright (C) 1994-1997 by hartmut Goebel
*
*
*   After programming ARexx script for quite a while, I missed some
*   function found in dos.library --  especially access to
*   environment variables and the comfortable argument parsing. Since
*   there seamed to be no ARexx function library which implements
*   this functions, I decited to write my own. And here it is.
*
*   This are the functions handled by this library.
*   · ReadArgs()
*   · GetVar(), SetVar(), DeleteVar()
*   · ParsePattern(), MatchPattern() - even case-insensitive
*   · Fault()
*   · Delete(), Rename(), MakeDir()
*   · SetComment(), SetProtection()
*   · FilePart(), PathPart(), AddPart()
*
*   This additional functions have been added for your convinience:
*   · AbsolutePath()
*
*   Enjoy it!
*   +++hartmut
*
*********)
(****** rexxdossupport.library/--installation-- *******************
*
*   To use rexxdossupport.library, just copy is to yout LIBS:
*   directory. That's all.
*
*   The LVO for the ARexx-Dispatcher is -30.
*       NB: it's the only LVO for this library :-)
*
*   So, in every ARexx-Script you want to use rexxdossupport.library,
*   insert
*
*      call addlib("rexxdossupport.library",0,-30,2)
*
*   somewhere before the first call to one of the routines
*   implemented in this library.
*   Since ARexx does not check whether the lib can be opened but only
*   inserts the name into a list, the result value from addlib() can
*   be ignored in most cases. The value would be interesting to check
*   if the added note will require the same library version, but I
*   don't know how to find this out.
*
*********)

MODULE rexxdossupport;
(* $StackChk- $ClearVars- *)

IMPORT
  d := Dos,
  e := Exec,
  str := Strings,
  ol := OberonLib,
  pf := Printf,
  PointerArithmetics,
  rx := Rexx,
  rxs := RexxSysLib,
  rvi := RVI,
  rls := RxLibsSupport,
  y := SYSTEM;

CONST
  versionString = "$VER: rexxdossupport 3.5 (6.2.97) Copyright © 1994-1997 by hartmtut Goebel";

  progNotFound = rls.progNotFound;
  noMemory     = rls.noMemory;
  badNumArgs   = rls.badNumArgs;
  stringTooLong= rx.err10009;
  funcErr      = rx.err10012;
  invalidArg   = rx.err10018;
  nestingLevel = rx.err10043;
  invalidTemplate = rx.err10037;
  errorReturnFromFunc = rx.err10012;
  arithConvertionErr = rx.err10047;

  strTRUE  = rls.strTRUE;
  strFALSE = rls.strFALSE;

PROCEDURE ^ GetVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ SetVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ DeleteVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ MatchPattern (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ ParsePattern (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ Fault (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ ReadArgs (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
(* new for V2.0 *)
PROCEDURE ^ Delete (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ Rename (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ MakeDir (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ SetComment (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ SetProtection (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
(* new for v3.0 *)
PROCEDURE ^ AbsolutePath (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
(* new for v3.1 *)
PROCEDURE ^ FilePart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ PathPart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
PROCEDURE ^ AddPart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;

CONST
  numFunctions = 16;

TYPE
  FunctionList = ARRAY numFunctions OF rls.FunctionListEntry;

CONST
  functionList = FunctionList(
    y.ADR("GetVar"),1,3,GetVar,
    y.ADR("SetVar"),2,3,SetVar,
    y.ADR("DeleteVar"),1,2,DeleteVar,
    y.ADR("MatchPattern"),2,4,MatchPattern,
    y.ADR("ParsePattern"),1,2,ParsePattern,
    y.ADR("Fault"),1,2,Fault,
    y.ADR("ReadArgs"),2,3,ReadArgs,
    y.ADR("Delete"),1,1,Delete,
    y.ADR("Rename"),2,2,Rename,
    y.ADR("SetComment"),2,2,SetComment,
    y.ADR("SetProtection"),2,2,SetProtection,
    y.ADR("MakeDir"),1,1,MakeDir,
    y.ADR("AddPart"),2,2,AddPart,
    y.ADR("FilePart"),1,1,FilePart,
    y.ADR("PathPart"),1,1,PathPart,
    y.ADR("AbsolutePath"),1,1,AbsolutePath
  );

(* ---------------------------------------------------------------- *)

(****** rexxdossupport.library/ReadArgs ***************
*
*   NAME
*       ReadArgs -- Parse argument string using Dos/ReadArgs()
*
*   SYNOPSIS
*       okay = ReadArgs( arguments, template, [stem] )
*
*   FUNCTION
*       Parses an argument string according to a template. See
*       dos.library/ReadArgs() for details and describtion of the
*       template.
*
*       This function supports the following template options:
*
*       /S - Switch.  Resulting variable will be either true (1) or
*            false (0).
*       /T - Toggle.  (V3) Results like /S, but much more mighty,
*                     see below.
*       /N - Number.
*       /M - Multiple strings.  See below for further information.
*
*       /K - Keyword.      }
*       /A - Required.     }  handled by dos
*       /F - Rest of line. }
*
*   INPUTS
*       arguments - the string to be parsed
*       template  - dos.library/ReadArgs()-style like template
*       stem      - stem prefix for resulting variables (optional)
*
*       For /T arguments the corresponding variable (see RESULTS) is read
*       to get the default.  The variable must be either false (0) or true
*       (1).  If the variable does not exist, the default is false (0).
*
*   RESULT
*       okay  - boolean value indicating success.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*       For each item in the template which has a corresponding
*       argument, a Rexx variable will be created. The variable's
*       name is the item's name prefixed by the stem name (if given). If
*       an item name has synonyms, the first one will be taken as variable
*       name.
*
*       Items with option /M will result in a stem variable with a
*       .COUNT node containing the number of elements. If no fitting
*       arguments is passed, .COUNT will be zero.
*       The entries will be in stem nodes .0 to .n (where n is
*       .COUNT-1).
*
*   EXAMPLE
*       /* ReadArgsExample.rexx */
*       If ~show('L', 'rexxdossupport.library') then do
*         if ~addlib('rexxdossupport.library', 0, -30, 2) then do
*          say "rexxdossupport.library not available, exiting ..."
*          exit 20
*         end
*       end
*
*       parse arg args /* get the arguments w/o ARexx-Parsing */
*
*       template = "Files/M,Method/K,MinSize/K/N,Test/S,Toggle/T"
*
*       /* set defaults */
*       Method = "NUKE"; MinSize = 512;
*
*       /* no stem given: results are assigned to simple variables */
*
*       if ReadArgs(args,template) then
*         say 'Method='method ' MinSize='MinSize 'Test=' test 'Toggle='toggle
*         do i = 0 by 1 for files.count
*           say files.i
*         end
*
*       /* stem given: results are assigned to stem variable */
*       /* since the default values are set as non-stem variables,
*        * they are not overwritten by the following call even if
*        * given
*        */
*
*       drop method MinSize test /*toggle is kept! */
*
*       if ReadArgs(args,template,"args.") then
*         say 'Method ='args.method 'MinSize='args.MinSize
*         say 'Test=' args.test 'Toggle='args.toggle
*         do i = 0 by 1 for args.files.count
*           say args.files.i
*         end
*
*   NOTE
*      /T was unsupported till V 3.1
*
*   NOTE
*      Some background about /T which is not documented well:
*      /T acts very like /S but may be set to on/off using the keywords
*      'YES'/'ON' and 'NO'/'OFF'. This is usefull when parsing eg.
*      tool-types or using multible option-sources (eg. defaults taken
*      from an environment variable).
*
*                                  /S             /T
*        1st option-set          UseScreen     UseScreen=YES
*        2nd option-set        NoUseScreen     UseScreen=NO
*          --> results into   ??confusion??    UseScreen=NO
*
*   SEE ALSO
*      Fault(), dos.library/ReadArgs()
*
***********************)

PROCEDURE ReadArgs (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;

  TYPE ArgsArray = UNTRACED POINTER TO ARRAY d.maxMultiArgs+1 OF LONGINT;

  PROCEDURE CreateSTEM (msg: rx.RexxMsgPtr;
                        template: e.LSTRPTR;
                        resarray: ArgsArray;
                        stembase: e.STRPTR;
                        setDefaultsFromRexxVars: BOOLEAN): INTEGER;
  VAR
    synonym, result, rs, rb, t, wordCnt: INTEGER;
    opts, optn, optm, optt: BOOLEAN;
    longbuff: rls.ConvertLongBuffer;
    resb: ARRAY 512 OF CHAR;

    PROCEDURE SetValue (VAR value: LONGINT): INTEGER;
    VAR
      string: e.LSTRPTR;
    BEGIN
      IF optt THEN    (*$RangeChk-*)
        result := SHORT(rvi.GetRexxVar(msg,resb,string)); (*$RangeChk=*)
        IF result # rx.ok THEN RETURN result END;
        value := d.DOSFALSE;
        IF string # NIL THEN
          IF d.StrToLong(string^,value) < 0 THEN RETURN arithConvertionErr END;
          CASE value OF
          |0: (*value := d.DOSFALSE;  alredy set *)
          |1: value := d.DOSTRUE;
          ELSE RETURN arithConvertionErr
          END;
        END;
      END;
      RETURN rx.ok;
    END SetValue;

    PROCEDURE GetValue (value: LONGINT): INTEGER;
    VAR
      string: e.LSTRPTR;
    BEGIN
      IF opts OR optt THEN
        IF value = d.DOSFALSE THEN string := y.ADR(strFALSE);
                              ELSE string := y.ADR(strTRUE);  END;
      ELSIF optn THEN (* numerisch *)
        pf.OSPrintF(longbuff, "%ld", y.VAL(ArgsArray,value)[0]);
        string := y.ADR(longbuff);
      ELSE (* string *)
        string := y.VAL(e.LSTRPTR,value);
      END;                                                                (*$RangeChk-*)
      RETURN SHORT(rvi.SetRexxVar(msg,resb,string^,str.Length(string^))); (*$RangeChk=*)
    END GetValue;

    PROCEDURE CreateResultList(value: ArgsArray): INTEGER;
    VAR
      index: LONGINT;
      tt: e.STRPTR;
      result: INTEGER;
    BEGIN
      tt := y.ADR(resb[t]);
      index := 0;
      IF value # NIL THEN
        WHILE value[index] # NIL DO
          pf.OSPrintF( tt^, ".%ld", index); (* Index an den Stem-Namen anhängen *)
          result := GetValue(value[index]);
          IF result # 0 THEN RETURN result; END;
          INC(index);
        END;
      END;
      tt^ := ".COUNT"; (* Die Count-Node ausfüllen *)
      pf.OSPrintF( longbuff, "%ld", index );                                (*$RangeChk-*)
      RETURN SHORT(rvi.SetRexxVar(msg,resb,longbuff,str.Length(longbuff))); (*$RangeChk=*)
    END CreateResultList;

  BEGIN
    wordCnt := 0; result := rx.ok;
    IF stembase # NIL THEN (* Präfix einbauen *)
      COPY(stembase^,resb); rb := SHORT(str.Length(resb));
      str.Upper(resb);
    ELSE
      resb := ""; rb := 0;
    END;
    rs := 0;

    (* Liste aufbauen *)
    WHILE template[rs] # CHR(0) DO
      t := rb; optn := FALSE; optm := FALSE; opts := FALSE; optt := FALSE; synonym := -1;
      LOOP
        CASE template[rs] OF
        | CHR(0): EXIT;
        | ",": INC(rs); EXIT;
        | "=": synonym := t;
        | "/":
          INC(rs);
          CASE CAP(template[rs]) OF
          | "N": optn := TRUE;
          | "M": optm := TRUE;
          | "S": opts := TRUE;
          | "T": optt := TRUE;
          ELSE END;
        ELSE
          resb[t] := CAP(template[rs]); INC(t); (* Resultatnamen kopieren *)
        END;
        INC(rs);
      END;
      IF synonym >= 0 THEN t := synonym; END;
      resb[t] := CHR(0);
      IF opts OR optt THEN
        optm := FALSE; optn := FALSE; END;

      (* hier ist nun der Basisname der Stem-Variable in resb,
       * und t zeigt in resb auf die Stelle, an der nun ggf. die
       * Stem-Erweiterungen (.COUNT, .0 - .n) angehängt werden
       *)
      IF setDefaultsFromRexxVars THEN
        result := SetValue(resarray[wordCnt]);
      ELSIF optm THEN (* /M war im Namen, also Liste *)
        result := CreateResultList(y.VAL(ArgsArray,resarray[wordCnt]));
      ELSE (* keine Liste *)
        IF opts OR optt OR (resarray[wordCnt] # NIL) THEN
          result := GetValue(resarray[wordCnt]);
        END;
      END;
      IF result # rx.ok THEN RETURN result; END;
      INC(wordCnt);
    END;
    RETURN result;
  END CreateSTEM;

VAR
  hasOptT: BOOLEAN;

  PROCEDURE ScanArgs(template: ARRAY OF CHAR): LONGINT; (* $CopyArrays- *)
  VAR
    pos, numArgs: LONGINT;
  BEGIN
    numArgs := 1; pos := 0;
    WHILE pos < LEN(template) DO
      CASE template[pos] OF
      |0X:  RETURN numArgs;
      |",": INC(numArgs);
      |"/": IF template[pos+1] = "T" THEN hasOptT := TRUE END;
      ELSE END;
      INC(pos);
    END;
    RETURN numArgs;
  END ScanArgs;

CONST
  rdArgsDefault = d.RDArgs(NIL,0,0, 0, NIL,0,NIL,LONGSET{d.noPrompt});
  argInput = 1; argTemplate = 2; argStem = 3;
VAR
  argv: UNTRACED POINTER TO d.ArgsStruct;
  arguments, rdArgs: d.RDArgsPtr;
  i: LONGINT;
  retval: INTEGER;
  input: e.LSTRPTR;
BEGIN (* ReadArgs *)
  IF ~ rls.ArgsPresent(msg,1,2) THEN RETURN invalidArg; END;
  IF (rx.ActionArg(msg.action) < argStem) THEN msg.args[argStem] := NIL; END;
  retval := noMemory;
  i := rxs.LengthArgstring(msg.args[argInput]);
  input := rxs.CreateArgstring(msg.args[argInput]^,i+1);
  IF input # NIL THEN
    input[i] := CHR(0AH); (* LineFeed, needed for ReadArgs() *)

    hasOptT := FALSE;
    i := ScanArgs(msg.args[argTemplate]^);

    rdArgs := d.AllocDosObject(d.rdArgs,NIL);
    IF rdArgs # NIL THEN
      ol.Allocate(argv, i *SIZE(e.APTR));
      IF argv # NIL THEN
        rdArgs^ := rdArgsDefault;
        rdArgs.source.buffer := y.ADR(input^);
        rdArgs.source.length := rxs.LengthArgstring(input);

        IF hasOptT THEN
          retval := CreateSTEM(msg, msg.args[argTemplate],
                               y.VAL(ArgsArray,argv),
                               y.VAL(e.STRPTR,msg.args[argStem]),
                               TRUE);
        END;

        arguments := d.ReadArgs(msg.args[argTemplate]^,argv^,rdArgs);
        IF arguments = NIL THEN
          resultStr := rxs.CreateArgstring(strFALSE,1);
          retval := rls.SetRC(msg,d.IoErr());
        ELSE
          resultStr := rxs.CreateArgstring(strTRUE,1);
          retval := CreateSTEM(msg, msg.args[argTemplate],
                               y.VAL(ArgsArray,argv),
                               y.VAL(e.STRPTR,msg.args[argStem]),
                               FALSE);
          d.FreeArgs(arguments);
        END;
        IF resultStr = NIL THEN retval := noMemory; END;
        DISPOSE(argv);
      END;
      d.FreeDosObject(d.rdArgs,rdArgs);
    END;
    rxs.DeleteArgstring(input);
  END;
  RETURN retval;
END ReadArgs;

(* ---------------------------------------------------------------- *)

PROCEDURE CheckBinaryVar (msg: rx.RexxMsgPtr;
                          argNum: INTEGER;
                          VAR flags: LONGSET): BOOLEAN;
VAR
  isBin: BOOLEAN;
BEGIN
  IF rls.IsValidArg(msg,argNum,"B",isBin) THEN
    IF isBin THEN
      flags := flags + LONGSET{d.binaryVar,d.dontNullTerm};
    END;
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END CheckBinaryVar;

PROCEDURE CheckLocalGlobal (msg: rx.RexxMsgPtr;
                            argNum: INTEGER;
                            VAR flags: LONGSET): BOOLEAN;
BEGIN
  IF (rx.ActionArg(msg.action) >= argNum) & (msg.args[argNum] # NIL) THEN
    CASE CAP(msg.args[argNum][0]) OF
    |"G": INCL(flags,d.globalOnly);
    |"L": INCL(flags,d.localOnly);
    ELSE
      RETURN FALSE;
    END;
  END;
  RETURN TRUE;
END CheckLocalGlobal;

(****** rexxdossupport.library/GetVar *******************
*
*   NAME
*       GetVar -- Returns the value of a local or global variable
*
*   SYNOPSIS
*       string = GetVar( name, ["Local" | "Global"], ["Binary"] )
*
*   FUNCTION
*       Gets the value of a local or environment variable.  It is advised to
*       only use ASCII strings inside variables, but not required.  This stops
*       putting characters into the destination when a \n is hit, unless
*       "Binary" is specified.  (The \n is not stored in the buffer.)
*
*   INPUTS
*       name     - variable name.
*       "Global" - tries to get a global env variable.
*       "Local"  - tries to get a local variable (see note below).
*       "Binary" - don't stop at \n
*                  in this mode the string returned is not null terminated
*
*                The default is to try to get a local variable first,
*                then to try to get a global environment variable.
*
*   RESULT
*       string - contents of the variable
*
*       RC (rexx variable) - 5 when variable does not exist,
*                            0 otherwise
*
*   EXAMPLE
*       /* */
*       username = GetVar("username")
*       if RC = 5 then
*         say "Variable 'username' is not set"
*       else
*         say "Variable 'username' is" username
*
*   NOTES
*      Contents may be max. 512 char.
*
*      Since ARexx spawns a new process of each script -- even if
*      started from Shell -- option "Local" may not work as supposed.
*      But one can
*
*                       |  Callie may  |  Callie may
*        Calling order  |     read     |     write
*                       | callers vars | to callers vars
*       ----------------+--------------+-------------------
*        Shell -> Arexx |      no      |      no
*        ARexx -> Shell |     yes      |      no
*        ARexx -> Arexx |      no      |      no
*
*   BUGS
*       Due to a bug in dos.library, binary global vars will be null
*       terminated in V37, V38.
*
*   SEE ALSO
*     SetVar(), DeleteVar(), dos.library/GetVar()
*
**********************)

PROCEDURE GetVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  flags: LONGSET;
  len: LONGINT;
  res: INTEGER;
  buffer: ARRAY 512 OF CHAR;
CONST
  argName = 1; argLocGlob = 2; argBinary = 3;
BEGIN
  flags := LONGSET{};
  IF ~ CheckLocalGlobal(msg,argLocGlob,flags)
  OR ~ CheckBinaryVar(msg,argBinary,flags)
  OR (msg.args[argName] = NIL) THEN
    RETURN invalidArg;
  END;
  len := d.GetVar(msg.args[argName]^,buffer,SIZE(buffer),flags);
  IF len < 0 THEN
    RETURN rls.SetRC5(msg);
  END;
  IF (len > SIZE(buffer)-1) & (len # d.IoErr()) THEN
    RETURN stringTooLong;
  END;
  resultStr := rxs.CreateArgstring(buffer,len);
  IF resultStr = NIL THEN RETURN noMemory; END;
  RETURN rls.SetRC0(msg);
END GetVar;


(****** rexxdossupport.library/SetVar *******************
*
*   NAME
*       SetVar -- Sets a local or environment variable
*
*   SYNOPSIS@{ub}
*       success = SetVar( name, ["Local" | "Global"] )
*
*   FUNCTION
*       Sets a local or environment variable.  It is advised to only use
*       ASCII strings inside variables, but not required.
*
*   INPUTS
*       name     - variable name.
*       "Global" - tries to get a global env variable.
*       "Local"  - tries to get a local variable (see note below).
*
*               The default is to set a local environment variable.
*
*   RESULT
*       success - If non-zero, the variable was sucessfully set, FALSE
*                 indicates failure.
*
*   NOTES
*      Since ARexx spawn a new process of each script -- even if
*      started from Shell -- option "Local" may not work as supposed.
*
*   SEE ALSO
*     GetVar(), DeleteVar(), dos.library/SetVar()
*
**************************)

PROCEDURE SetVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  flags: LONGSET;
CONST
  argName = 1; argContents = 2; argLocGlob = 3;
BEGIN
  flags := LONGSET{};
  IF ~ CheckLocalGlobal(msg,argLocGlob,flags)
  OR (msg.args[argName] = NIL) THEN
    RETURN invalidArg;
  END;
  IF d.SetVar(msg.args[argName]^,msg.args[argContents]^,
              rxs.LengthArgstring(msg.args[argContents]),flags) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
  END;
  IF resultStr = NIL THEN RETURN noMemory; END;
  RETURN rx.ok;
END SetVar;


(****** rexxdossupport.library/DeleteVar *******************
*
*   NAME
*       DeleteVar -- Deletes a local or environment variable
*
*   SYNOPSIS
*       success = DeleteVar( name, [ "Local" | "Global" ] )
*
*   FUNCTION
*       Deletes a local or environment variable.
*
*   INPUTS
*       name     - variable name.  Note variable names follow
*                  filesystem syntax and semantics.
*       "Global" - tries to get a global env variable.
*       "Local"  - tries to get a local variable (see note below).
*
*                The default is to delete a local variable if found, otherwise
*                a global environment variable if found.
*
*   RESULT
*       success - If TRUE, the variable was sucessfully deleted,
*                 FALSE indicates failure.
*
*   NOTES
*      Since ARexx spawn a new process of each script -- even if
*      started from Shell -- option "Local" may not work as supposed.
*
*   SEE ALSO
*       GetVar(), SetVar(), dos.library/DeleteVar()
*
***********************)

PROCEDURE DeleteVar (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  flags: LONGSET;
CONST
  argName = 1; argLocGlob = 2;
BEGIN
  flags := LONGSET{};
  IF ~ CheckLocalGlobal(msg,argLocGlob,flags)
  OR (msg.args[argName] = NIL) THEN
    RETURN invalidArg;
  END;
  IF d.DeleteVar(msg.args[argName]^,flags) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
  END;
  IF resultStr = NIL THEN RETURN noMemory; END;
  RETURN rx.ok;
END DeleteVar;

(* ---------------------------------------------------------------- *)

(****** rexxdossupport.library/Fault *******************
*
*   NAME
*       Fault -- Returns the text associated with a DOS error code
*
*   SYNOPSIS
*       string = Fault( code, header )
*
*   FUNCTION
*       This routine obtains the error message text for the given
*       error code. The header is prepended to the text of the error
*       message, followed by a colon. By convention, error messages
*       should be no longer than 80 characters, and preferably no
*       more than 60.
*
*       The value returned by IoErr() (not available in this library)
*       is set to the code passed in. If there is no message for the
*       error code, the message will be "Error code <number>\n".
*
*       The string will be empty if the code passed in was 0.
*
*   INPUTS
*       code   - Error code
*       header - header to output before error text
*
*   RESULT
*       string - error massage as described above.
*
*       RC (rexx variable) - 5 when error message is empty
*                            0 otherwise
*
*   BUGS
*      I've been told that this function returns only an empty sting.
*      Since nobody gave me further information, I can't fix it.
*
*   SEE ALSO
*       dos.library/Fault(), dos.library/IoErr()
*
*****************************)

PROCEDURE Fault (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
CONST
  argNumber = 1; argHeader = 2;
VAR
  errCode, len: LONGINT;
  retval: INTEGER;
  buffer: ARRAY 512 OF CHAR; (* should be enough *)
BEGIN
  IF (msg.args[argNumber] = NIL) THEN RETURN invalidArg; END;
  retval := rx.ok;
  IF (rx.ActionArg(msg.action) < argHeader) THEN
    msg.args[argHeader] := NIL; END;
  len := d.StrToLong(msg.args[argNumber]^, errCode);
  IF len # str.Length(msg.args[argNumber]^) THEN
    RETURN invalidArg; END;
  (* $NilChk-   avoid trapping msg.args[argHeader]^ *)
  len := d.Fault(errCode, msg.args[argHeader]^, buffer, SIZE(buffer));
  (* $NilChk= *)
  IF len = 0 THEN
    retval := rls.SetRC5(msg);
  ELSE
    retval := rls.SetRC0(msg);
    resultStr := rxs.CreateArgstring(buffer,str.Length(buffer));
    IF resultStr = NIL THEN RETURN noMemory; END;
  END;
  RETURN retval
END Fault;

(* ---------------------------------------------------------------- *)

(****** rexxdossupport.library/MatchPattern *******************
*
*   NAME
*       MatchPattern --  Checks for a pattern match with a string
*
*   SYNOPSIS
*       match = MatchPattern(pattern, string, ["Nocase"], ["Parsed"] )
*
*   FUNCTION
*       Checks for a pattern match with a string.
*       This routine is case-sensitive by default. Use option
*       "NoCase" for case-insensitve matching.
*
*       Use option "Parsed" to indicate that pattern has already been
*       tokenized using ParsePattern(). Make sure to use or use not
*       "NoCase" for both function.
*
*   INPUTS
*       pattern  - pattern string to match
*       string   - string to match against given pattern
*       "Nocase" - match should be case-insensitve
*       "Parsed" - pattern has already been parsed using ParsePattern()
*
*   RESULT
*       match - success or failure of pattern match.
*
*   SEE ALSO
*       ParsePattern(), dos.library/MatchPattern(),
*       dos.library/MatchPatternNoCase()
*
***********************)

PROCEDURE MatchPattern (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  buffer: e.LSTRPTR;
  res, noCase, isParsed: BOOLEAN;
  bufferLen: LONGINT;
CONST
  argPattern = 1; argInput = 2; argNoCase = 3; argIsParsed = 4;
BEGIN
  IF ~ rls.IsValidArg(msg,argNoCase,"N",noCase)
  OR ~ rls.IsValidArg(msg,argIsParsed,"P",isParsed)
  OR ~ rls.ArgsPresent(msg,argPattern,argInput) THEN
    RETURN invalidArg; END;

  IF isParsed THEN
    buffer := msg.args[argPattern];
    res := TRUE;
  ELSE
    bufferLen := 2 * str.Length(msg.args[argPattern]^) +2;
    ol.Allocate(buffer,bufferLen);
    IF buffer = NIL THEN
      RETURN noMemory;
    END;
    IF noCase THEN
      res := (d.ParsePatternNoCase(msg.args[argPattern]^,buffer^,bufferLen) >= 0);
    ELSE
      res := (d.ParsePattern(msg.args[argPattern]^,buffer^,bufferLen) >= 0);
    END;
    IF ~ res THEN
      DISPOSE(buffer);
      RETURN invalidTemplate;
    END;
  END;

  IF noCase THEN res := d.MatchPatternNoCase(buffer^,msg.args[argInput]^);
            ELSE res := d.MatchPattern(buffer^,msg.args[argInput]^); END;

  IF ~ isParsed THEN DISPOSE(buffer); END;

  IF ~ res THEN
    IF d.IoErr() = 0 THEN
      resultStr := rxs.CreateArgstring(strFALSE,1);
      IF resultStr = NIL THEN RETURN noMemory; END;
      RETURN rx.ok;
    ELSE
      RETURN nestingLevel;
    END;
  ELSE
    resultStr := rxs.CreateArgstring(strTRUE,1);
    IF resultStr = NIL THEN RETURN noMemory; END;
    RETURN rx.ok;
  END;
END MatchPattern;


(****** rexxdossupport.library/ParsePattern *******************
*
*   NAME
*       ParsePattern -- Create a tokenized string for MatchPattern()
*
*   SYNOPSIS
*       token = ParsePattern( pattern, ["NoCase"] )
*
*   FUNCTION
*       Tokenizes a pattern, for use by MatchPattern().  Also indicates
*       if there are any wildcards in the pattern (i.e. whether it might match
*       more than one item).
*
*       For a description of the wildcards, see dos.library/ParsePattern().
*
*   INPUTS
*       pattern  - unparsed wildcard string to search for.
*
*   RESULT
*       token    - output string, tokenized version of input.
*
*       RC (rexx variable) - 5 when does not contain wildcards
*                            0 otherwise
*
*   BUGS
*       Since is't not clear wether the resulting token may contain
*       null charakters, the returned string is always
*       2 * Length(pattern) + 2 bytes long.
*
*   SEE ALSO
*       ParsePattern(), dos.library/ParsePattern(),
*       dos.library/ParsePatternNoCase()
*
*********************)

PROCEDURE ParsePattern (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  result: INTEGER;
  noCase: BOOLEAN;
  buffer: e.LSTRPTR;
  bufferLen: LONGINT;
CONST
  argPattern = 1; argNoCase = 2;
BEGIN
  IF ~ rls.IsValidArg(msg,argNoCase,"N",noCase)
  OR (msg.args[argPattern] = NIL) THEN
    RETURN invalidArg; END;
  bufferLen := 2 * str.Length(msg.args[argPattern]^) +2;
  ol.Allocate(buffer,bufferLen);
  IF buffer = NIL THEN
    RETURN noMemory;
  END;
  IF noCase THEN
    result := d.ParsePatternNoCase(msg.args[argPattern]^,buffer^,bufferLen)
  ELSE
    result := d.ParsePattern(msg.args[argPattern]^,buffer^,bufferLen);
  END;
  IF result < 0 THEN
    result := invalidTemplate;
  ELSE
    resultStr := rxs.CreateArgstring(buffer^,str.Length(buffer^));
    IF resultStr = NIL THEN
      result := noMemory;
    ELSIF result > 0 THEN
      result := rls.SetRC0(msg);
    ELSE
      result := rls.SetRC5(msg);
    END;
  END;
  DISPOSE(buffer);
  RETURN result;
END ParsePattern;

(* ---------------------------------------------------------------- *)

(****** rexxdossupport.library/Delete *******************
*
*   NAME
*       Delete -- Delete a file or directory (V2)
*
*   SYNOPSIS
*       success = Delete( name )
*
*   FUNCTION
*       This attempts to delete the file or directory specified by
*       'name'. If the deletion fails an error is returned and the
*       rexx variable RC is set. Note that all the files within a
*       directory must be deleted before the directory itself can be
*       deleted.
*
*   INPUTS
*       name     - name of file or directory to delete.
*
*   RESULT
*       success - If TRUE, the file was sucessfully deleted,
*                 FALSE indicates failure.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*   SEE ALSO
*       Fault(), dos.library/DeleteFile()
*
****************************)

PROCEDURE Delete (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
CONST
  argName = 1;
VAR
  retval: INTEGER;
BEGIN
  IF msg.args[argName] = NIL THEN RETURN invalidArg; END;
  retval := rx.ok;
  IF d.DeleteFile(msg.args[argName]^) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
    retval := rls.SetRC(msg,d.IoErr());
  END;
  IF resultStr = NIL THEN retval := noMemory; END;
  RETURN retval;
END Delete;

(****** rexxdossupport.library/Rename *******************
*
*   NAME
*       Rename -- Rename a directory or file (V2)
*
*   SYNOPSIS
*       success = Rename( oldName, newName )
*
*   FUNCTION
*       Rename() attempts to rename the file or directory specified
*       as 'oldName' with the name 'newName'. If the file or
*       directory 'newName' exists, Rename() fails and returns an
*       error. Both 'oldName' and the 'newName' can contain a
*       directory specification. In this case, the file will be moved
*       from one directory to another.
*
*       Note: it is impossible to Rename() a file from one volume to
*       another.
*
*   INPUTS
*       oldName - pointer to a null-terminated string
*       newName - pointer to a null-terminated string
*
*   RESULT
*       success - If TRUE, the variable was sucessfully deleted,
*                 FALSE indicates failure.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*   SEE ALSO
*       Fault(), dos.library/Rename()
*
***************************)

PROCEDURE Rename (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  retval: INTEGER;
CONST
  argFrom = 1; argTo = 2;
BEGIN
  IF ~ rls.ArgsPresent(msg,argFrom,argTo) THEN RETURN invalidArg; END;
  retval := rx.ok;
  IF d.Rename(msg.args[argFrom]^, msg.args[argTo]^) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
    retval := rls.SetRC(msg,d.IoErr());
  END;
  IF resultStr = NIL THEN retval := noMemory; END;
  RETURN retval;
END Rename;

(****** rexxdossupport.library/MakeDir *******************
*
*   NAME
*       MakeDir -- Create a new directory (V2)
*
*   SYNOPSIS
*       success = MakeDir( name )
*
*   FUNCTION
*       MakeDir creates a new directory with the specified name. If
*       it fails an error is returned and the rexx variable RC is
*       set.  Directories can only be created on devices which
*       support them, e.g. disks.
*
*   INPUTS
*       name     - name of directory to create
*
*   RESULT
*       success - If TRUE, the variable was sucessfully deleted,
*                 FALSE indicates failure.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*   SEE ALSO
*       Fault(), dos.library/CreateDir()
*
**************************)

PROCEDURE MakeDir (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  retval: INTEGER;
CONST
  argName = 1;
VAR
  dir: d.FileLockPtr;
BEGIN
  IF msg.args[argName] = NIL THEN RETURN invalidArg; END;
  retval := rx.ok;
  dir := d.CreateDir(msg.args[argName]^);
  IF dir # NIL THEN
    d.UnLock(dir);
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
    retval := rls.SetRC(msg,d.IoErr());
  END;
  IF resultStr = NIL THEN retval := noMemory; END;
  RETURN retval;
END MakeDir;

(****** rexxdossupport.library/SetComment *******************
*
*   NAME
*       SetComment -- Change a files' comment string (V2)
*
*   SYNOPSIS
*       success = SetComment( name, comment )
*
*   FUNCTION
*       SetComment() sets a comment on a file or directory. The
*       comment may be up to 80 characters in the current ROM
*       filesystem (and RAM:).  Note that not all filesystems will
*       support comments (for example, NFS usually will not), or the
*       size of comment supported may vary.
*
*   INPUTS
*       name     - name of file or directory to set comment
*       comment  - comment to be set
*
*   RESULT
*       success - If TRUE, the variable was sucessfully deleted,
*                 FALSE indicates failure.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*   SEE ALSO
*       SetProtection(), Fault(), dos.library/SetComment()
*
**************************)

PROCEDURE SetComment (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  retval: INTEGER;
CONST
  argFile = 1; argComment = 2;
BEGIN
  IF ~ rls.ArgsPresent(msg,argFile,argComment) THEN RETURN invalidArg; END;
  retval := rx.ok;
  IF d.SetComment(msg.args[argFile]^, msg.args[argComment]^) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
    retval := rls.SetRC(msg,d.IoErr());
  END;
  IF resultStr = NIL THEN retval := noMemory; END;
  RETURN retval;
END SetComment;

(****** rexxdossupport.library/SetProtection *******************
*
*   NAME
*       SetProtection -- Set protection for a file or directory (V2)
*
*   SYNOPSIS
*       success = SetProtection( name, mask )
*
*   FUNCTION
*       SetProtection() sets the protection attributes on a file or
*       directory.  See <dos/dos.h> for a listing of protection bits.
*
*       The archive bit should be cleared by the filesystem whenever
*       the file is changed.  Backup utilities will generally set the
*       bit after backing up each file.
*
*       The V36 Shell looks at the execute bit, and will refuse to
*       execute a file if it is set.
*
*       Other bits will be defined in the <dos/dos.h>include files.
*       Rather than referring to bits by number you should use the
*       definitions in <dos/dos.h>.
*
*   INPUTS
*       name     - name of file or directory to set protection
*       mask     - the protection mask required
*
*   RESULT
*       success - If TRUE, the variable was sucessfully deleted,
*                 FALSE indicates failure.
*
*       RC (rexx variable) - contains the dos error code if the
*               function was not successfull. This can can directly
*               be used as input for Fault().
*
*   SEE ALSO
*       SetComment(), Fault(), dos.library/SetProtection()
*
**************************)

PROCEDURE SetProtection (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  retval: INTEGER;
CONST
  argFile = 1; argFlags = 2;
TYPE
  LONGSETPtr = UNTRACED POINTER TO LONGSET;
BEGIN
  IF ~ rls.ArgsPresent(msg,argFile,argFlags)
  OR (rxs.LengthArgstring(msg.args[argFlags]) # 4)
    THEN RETURN invalidArg; END;
  retval := rx.ok;
  IF d.SetProtection(msg.args[argFile]^,y.VAL(LONGSETPtr,msg.args[argFile])^) THEN
    resultStr := rxs.CreateArgstring(strTRUE,1);
  ELSE
    resultStr := rxs.CreateArgstring(strFALSE,1);
    retval := rls.SetRC(msg,d.IoErr());
  END;
  IF resultStr = NIL THEN retval := noMemory; END;
  RETURN retval;
END SetProtection;


(****** rexxdossupport.library/AbsolutePath *******************
*
*   NAME
*       AbsolutePath -- Returns the fully qualified path of a file or dir (V3)
*
*   SYNOPSIS
*       path = AbsolutePath( name )
*
*   FUNCTION
*       Determines the absolute path of a file or directory.
*
*   INPUTS
*       name  - file or directory name
*
*   RESULT
*       path  - absolute path to file/dir
*
*       RC (rexx variable) - 5 when file does not exist,
*                            0 otherwise
*
*   EXAMPLE
*       /* */
*       path = AbsolutePath(":s/Startup-Sequence")
*       if RC = 5 then
*         say "File ':s/Startup-Sequence' does not exist"
*       else
*         say "':s/Startup-Sequence' is '" || path || "'"
*
*   SEE ALSO
*     dos.library/NameFromLock()
*
**********************)

PROCEDURE AbsolutePath (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  len: LONGINT;
  res: BOOLEAN;
  lock: d.FileLockPtr;
  buffer: ARRAY 512 OF CHAR;
CONST
  argName = 1;
BEGIN
  lock := d.Lock(msg.args[argName]^, d.sharedLock);
  IF lock = NIL THEN RETURN rls.SetRC5(msg) END;
  res := d.NameFromLock(lock, buffer, SIZE(buffer));
  d.UnLock(lock); lock := NIL;
  IF ~ res THEN RETURN rls.SetRC5(msg) END;
  resultStr := rxs.CreateArgstring(buffer,str.Length(buffer));
  IF resultStr = NIL THEN RETURN noMemory; END;
  RETURN rls.SetRC0(msg);
END AbsolutePath;

(****** rexxdossupport.library/AddPart *******************
*
*   NAME
*       AddPart -- Appends a file/dir to the end of a path (V3)
*
*   SYNOPSIS
*       newpath = AddPart( dirname , filename )
*
*   FUNCTION
*       This funktion adds a file, directory, or subpath name to a
*       directory path name taking into account any required
*       seperator charakters.
*
*   INPUTS
*       dirname  - the path to add a fir/directory name to.
*       filename - the filename or directory name to add.
*
*   RESULT
*       newpath  - resulting path.
*
*       RC (rexx variable) - 5 when file does not exist,
*                            0 otherwise
*
*   EXAMPLE
*       /* */
*       path = AddPart("System:s/","Startup-Sequence")
*       if RC = 0 then say path
*         /* --> System:s/Startup-Sequence */
*
*       path = AddPart("System:s/bla",":Startup-Sequence")
*       if RC = 0 then say path
*         /* --> System:Startup-Sequence */
*
*       path = AddPart("System:s/bla","/Startup-Sequence")
*       if RC = 0 then say path
*         /* --> System:s/bla//Startup-Sequence */
*
*       path = AddPart("System:s/bla","") /* fine trick :-) */
*       if RC = 0 then say path
*         /* --> System:s/bla/ */
*   BUGS
*       Neither the input dirname nor the resulting path must exceed
*       511 Bytes. If a string overflow occurrs, error 'string too
*       long' will be returned which ARexx outputs as 'string > 65535
*       charakters'.
*
*   SEE ALSO
*       dos.library/AddPart(), FilePart(), PathPart()
*
**********************)

PROCEDURE AddPart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  buffer: ARRAY 512 OF CHAR;
CONST
  argDir = 1; argFile = 2;
BEGIN
  IF ~ rls.ArgsPresent(msg,argDir,argFile) THEN RETURN invalidArg; END;
  IF str.Length(msg.args[argDir]^) >= SIZE(buffer) THEN
    RETURN stringTooLong END;
  COPY(msg.args[argDir]^, buffer);
  IF ~ d.AddPart(buffer, msg.args[argFile]^, SIZE(buffer)) THEN
    RETURN stringTooLong END;
  resultStr := rxs.CreateArgstring(buffer, str.Length(buffer));
  IF resultStr = NIL THEN RETURN noMemory; END;
  RETURN rls.SetRC0(msg);
END AddPart;

(****** rexxdossupport.library/FilePart *******************
*
*   NAME
*       FilePart -- Returns the last component of a path (V3)
*
*   SYNOPSIS
*       part = FilePart( path )
*
*   FUNCTION
*       This function returns the last component of a string path
*       specification, which will normally be the file name.  If there is
*       only one component, it returns the complete string.
*
*   INPUTS
*       path - pointer to an path string.  May be relative to the current
*              directory or the current disk.
*
*   RESULT
*       part  - resulting path part.
*
*   EXAMPLE
*       /* */
*       say FilePart("xxx:yyy/zzz/qqq")
*         /* --> qqq */
*       say FilePart("xxx:yyy")
*         /* --> yyy */
*
*   SEE ALSO
*       dos.library/FilePart(), AddPart(), PathPart()
*
**********************)

PROCEDURE FilePart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  filePart: e.LSTRPTR;
CONST
  argPath = 1;
BEGIN
  IF msg.args[argPath] = NIL THEN RETURN invalidArg; END;
  filePart := d.FilePart(msg.args[argPath]^);
  resultStr := rxs.CreateArgstring(filePart^,str.Length(filePart^));
  IF resultStr = NIL THEN RETURN noMemory END;
  RETURN rls.SetRC0(msg);
END FilePart;

(****** rexxdossupport.library/PathPart *******************
*
*   NAME
*       PathPart -- Strips the next-to-last component of a path. (V3)
*
*   SYNOPSIS
*       part = PathPart( path )
*
*   FUNCTION
*       This function strips the next-to-last component of a path
*       specification, which will normally result in the directory name.
*       If there is only one component, it returns an empty string.
*
*   INPUTS
*       path - path string.  May be relative to the current directory or
*             the current disk.
*
*   RESULT
*       part  - resulting path part.
*
*   EXAMPLE
*       /* */
*       say FilePart("xxx:yyy/zzz/qqq")
*         /* --> xxx:yyy/zzz */
*       say FilePart("xxx:yyy")
*         /* --> xxx: */
*
*   SEE ALSO
*       dos.library/PathPart(), AddPart(), FilePart()
*
**********************)

PROCEDURE PathPart (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;
VAR
  fullPath, pathPart: e.LSTRPTR;
  len: LONGINT;
CONST
  argPath = 1;
BEGIN
  IF msg.args[argPath] = NIL THEN RETURN invalidArg; END;
  fullPath := msg.args[argPath];
  pathPart := d.PathPart(fullPath^);
  len := PointerArithmetics.Subtract(pathPart,fullPath);
  resultStr := rxs.CreateArgstring(fullPath^,len);
  IF resultStr = NIL THEN RETURN noMemory END;
  RETURN rls.SetRC0(msg);
END PathPart;

(* ---------------------------------------------------------------- *)

PROCEDURE Dispatch * (msg{8}: rx.RexxMsgPtr): LONGINT; (* $SaveRegs+ *)
VAR
  resultStr: e.LSTRPTR;
  retval: LONGINT;
BEGIN
  ol.SetA5();
  retval := rls.Dispatch(msg,resultStr,functionList);
  y.SETREG(8,resultStr);
  RETURN retval;
END Dispatch;

BEGIN
  IF (rxs.base = NIL) OR (d.base.lib.version < 37) THEN HALT(20); END;

END rexxdossupport.
