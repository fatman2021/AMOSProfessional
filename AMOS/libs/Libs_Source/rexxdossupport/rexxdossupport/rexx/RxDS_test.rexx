/* RxDS_test.rexx --- test for RexxDosSupport.library
* $Id: RxDS_test.rexx,v 1.2 1996/02/23 12:42:18 hartmut Exp $
*/

call addlib("rexxdossupport.library",0,-30, 3)

parse source . . . file .
say "Let's get the filename and path of this script" file
fp = FilePart(file);
say "FilePart:" fp
say "PathPart:" PathPart(file);
say "AbsolutePath("fp"):" AbsolutePath("RxDS_test.rexx")

say; say "some tests about AddPart()"

call TestAddPart("Oberon:bla/fasel/foo","Bang:oha!")
call TestAddPart("Oberon:bla/fasel/foo",":oha!")
call TestAddPart("Oberon:bla/fasel/foo","oha/aha!")
call TestAddPart("Oberon:bla/fasel/foo","/oha/aha!")
call TestAddPart("Oberon:bla/fasel/foo","//oha//aha!")
call TestAddPart("Oberon:LibLink/Mathe","//Mymods/txt")
/*call TestAddPart("Oberon:"Copies('a',560),"//Mymods/txt")*/

say; say "Now we play with directories"
if ~ MakeDir("ram:foo") then say fault(rc, "test");
if ~ Rename("ram:foo","ram:bar") then say fault(rc, "test");
if ~ SetComment("ram:bar","stupit comment") then say fault(rc, "test");
if ~ SetProtection("ram:bar",'00000000'x) then say fault(rc, "test");
if ~ Delete("ram:bar") then say fault(rc, "test");

say; say "Generate some error messages:"
text = fault(0,"test"); if rc = 0 then say text
text = fault(215,"test"); if rc = 0 then say text
text = fault(215); if rc = 0 then say text

say; say "The most interesting feature: ReadArgs() :-))"
server = 'default'
template = "name/A,,passwd,server/K,prio/N"
input = "hartmut foobar prio 10"

if ReadArgs(input,template) then
  say args.name '--' args.passwd '--' args.server '--' args.prio
  say name '--' passwd '--' server '--' prio
if ReadArgs(input,template,"args.") then
  say args.name '--' args.passwd '--' args.server '--' args.prio

say "here as error message has to appear:"
if ~ ReadArgs("server=default", template, "args.") then
  say Fault(rc,"test")

/*--- tests for /T ---*/
drop test
call ReadArgs("", "test/T")
say test

test = 1;
call ReadArgs("", "test/T")
say test

call ReadArgs("test=No", "test/T")
say test

call ReadArgs("test=on", "test/T")
say test

drop test
call ReadArgs("test=on", "test/T", "args.")
say args.test

/*--- test for /M ---*/
template = "name/M,test/S"
input = "ich du er sie es test"

if ReadArgs(input,template) then do
  say name.count test
  do i = 0 for name.count by 1
    say name.i
  end
end

say; Say "test pattern matching:"
pattern = "ha*mut"
string = "hartmut"

say MatchPattern(pattern,string);

string = Upper(string)
say MatchPattern(pattern,string);
say MatchPattern(pattern,string,"N");

string = "hartmut"
pattern = parsePattern(string)
say rc
pattern = ParsePattern("ha*mut")
say MatchPattern(pattern,string,,"P");
string = Upper(string)
say MatchPattern(pattern,string,,"P");
pattern = ParsePattern("har*ut","N")
say MatchPattern(pattern,string,"N","P");


say; say "last but not least: environment variables"
call MyGetVar("foobar")

/* PLEASE NOTE: local varibales do not work as exspected since ARexx
 * creates a new process for each script. Thus there is no way to
 * access the shell env-vars. Sorry!
 * But you may pass local env-vars to programms started from a skript.
 * See below for example (address command 'get foobar').
 */

SetVar("foobar", "Oh, wunderfull, this is a local environment variable", "L")
call MyGetVar("foobar")
call MyGetVar("foobar","L")
call MyGetVar("foobar","G")

/* some tests for passing local vars to a shell */
say;say "Now we try to access local vars <address command 'get foobar'> ..."
address command 'get foobar'
say "... and set local vars <address command 'get foobar ""blafasel""'>"
address command 'set foobar "blafasel"'
call MyGetVar("foobar","L")

/* TestVars.rexx
...8<--- TestVars.rexx ---
   result = GetVar("foobar","L")
   IF rc = 0 THEN say "L: foobar has value <"result">";
          else say "L: foobar not set"
   SetVar("foobar", "variable changed", "L")
...8<---
call MyGetVar("foobar","L")
*/

say DeleteVar("foobar", "L")

say; say "Presentation finished"; say "Good bye!"

exit 0

/* --- support routines --- */

TestAddPart: PROCEDURE
  dir = arg(1); file = arg(2); path = AddPart(dir,file)
  if RC = 0 then
    say dir '+' file '->' path
  else
    say dir '+' file '**failed**'
return

MyGetVar: PROCEDURE
  name = arg(1)
  if arg(2,'ommited') then do
    result = GetVar(name)
    state = ""
  end; else do
    result = GetVar(name,arg(2))
    state = arg(2)': '
  end
  IF rc = 0 THEN say state'foobar has value <"result">';
            else say state'foobar not set'
return 0
