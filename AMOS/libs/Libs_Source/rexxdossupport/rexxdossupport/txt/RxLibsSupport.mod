(*(***********************************************************************

:Program.    RxLibsSupport.mod
:Contents.   support functions for rexx function libraries
:Author.     hartmtut Goebel [hG]
:Address.    Aufseßplatz 5, D-90459 Nürnberg
:Address.    UseNet: hartmut@oberon.nbg.sub.org
:Copyright.  Copyright © 1994-1996 by hartmtut Goebel
:Language.   Oberon-2
:Translator. Amiga Oberon 3.11
:Imports.    Printf (Martin Horneffer), MoreStrings [hG]
:Version.    $VER: RxLibsSupport.mod 1.2 (30.1.96) Copyright © 1994-1996 by hartmtut Goebel

(* $StackChk- $NilChk- $RangeChk- $CaseChk- $OvflChk- $ReturnChk- $ClearVars- *)
(****i* /--history-- ***************************************
*
*  1.2  30 Jan 1996
*       · switched to Martin Horneffers Printf
*
*  1.1  07 May 1994
*       · added ArgsPresent()
*
*  1.0  23 Jan 1994
*       · initial release
*
*********************************************************************)*)*)

MODULE RxLibsSupport;

IMPORT
  e := Exec,
  str := Strings,
  Printf,
  ms := MoreStrings,
  rx := Rexx,
  rxs := RexxSysLib,
  rvi := RVI,
  y := SYSTEM;

CONST
  versionString = "$VER: RxLibsSupport 1.2 (30.1.96) Copyright © 1994-1996 by hartmtut Goebel";

  strTRUE  * = "1";
  strFALSE * = "0";

  progNotFound * = rx.err10001;
  noMemory     * = rx.err10003;
  badNumArgs   * = rx.err10017;

TYPE
  ConvertLongBuffer * = ARRAY 16 OF CHAR;
  Function * = PROCEDURE (msg: rx.RexxMsgPtr; VAR resultStr: e.LSTRPTR): INTEGER;

  FunctionListEntry * = STRUCT
    name     *: e.LSTRPTR;
    minArgs  *: INTEGER;
    maxArgs  *: INTEGER;
    function *: Function;
  END;

  FunctionList = ARRAY OF FunctionListEntry;

(* ---------------------------------------------------------------- *)

PROCEDURE SetRC * (msg: rx.RexxMsgPtr; rc: LONGINT): INTEGER;
VAR
  longbuff: ConvertLongBuffer;
BEGIN
  Printf.OSPrintF(longbuff, "%ld", rc);                                    (*$RangeChk-*)
  RETURN SHORT(rvi.SetRexxVar(msg,"RC",longbuff,str.Length(longbuff))); (*$RangeChk=*)
END SetRC;

PROCEDURE SetRC5 * (msg: rx.RexxMsgPtr): INTEGER;
BEGIN                                           (*$RangeChk-*)
  RETURN SHORT(rvi.SetRexxVar(msg,"RC","5",1)); (*$RangeChk=*)
END SetRC5;

PROCEDURE SetRC0 * (msg: rx.RexxMsgPtr): INTEGER;
BEGIN                                           (*$RangeChk-*)
  RETURN SHORT(rvi.SetRexxVar(msg,"RC","0",1)); (*$RangeChk=*)
END SetRC0;

(* ---------------------------------------------------------------- *)

(* IsValidArg()
 *
 * testes whether arguments <argNum> is a valid arguments, this
 * means is either not given or the first charakter is <c>.
 * <set> will be true if the argument is given and is valid,
 * false otherwise.
 *)
PROCEDURE IsValidArg * (msg: rx.RexxMsgPtr;
                        argNum: INTEGER;
                        c: CHAR;
                        VAR set: BOOLEAN): BOOLEAN;
BEGIN
  set := FALSE;
  IF (rx.ActionArg(msg.action) < argNum) OR (msg.args[argNum] = NIL) THEN
    RETURN TRUE;
  ELSIF CAP(msg.args[argNum][0]) = c THEN
    set := TRUE;
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
END IsValidArg;


(* ArgsPresent()
 *
 * checks whether all arguments between <start> and <stop> (including both)
 * are present (non-null)
 *)

PROCEDURE ArgsPresent * (msg: rx.RexxMsgPtr; start, stop: INTEGER): BOOLEAN;
BEGIN
  WHILE start <= stop DO
    IF msg.args[start] = NIL THEN RETURN FALSE; END;
    INC(start);
  END;
  RETURN TRUE;
END ArgsPresent;

(* ---------------------------------------------------------------- *)

PROCEDURE Dispatch * (msg: rx.RexxMsgPtr;
                      VAR resultStr: e.LSTRPTR;
                      functionList: FunctionList): LONGINT;   (* $CopyArrays- *)
VAR
  func: FunctionListEntry;
  retval: LONGINT;
  i, numArgs: INTEGER;
BEGIN
  resultStr := NIL;
  IF (msg = NIL) OR (rx.ActionCode(msg.action) # rx.rxFunc) THEN
    RETURN progNotFound;
  END;
  i := 0;
  LOOP
    IF i >= LEN(functionList) THEN
      RETURN progNotFound; END;
    IF ms.NCStrCmp(functionList[i].name^,msg.args[0]^) = 0 THEN
      EXIT; END;
    INC(i);
  END;

  numArgs := (*$RangeChk-*) SHORT(rx.ActionArg(msg.action)); (*$RangeChk=*)
  IF (numArgs < functionList[i].minArgs) OR (numArgs > functionList[i].maxArgs) THEN
    RETURN badNumArgs;
  END;

  retval := functionList[i].function(msg, resultStr);
  IF (retval = rx.ok) & (resultStr = NIL) THEN
    resultStr := rxs.CreateArgstring("",0);
    IF resultStr = NIL THEN retval := noMemory; END;
  END;
  RETURN retval;
END Dispatch;

END RxLibsSupport.

