/*
Show how to use ReadArgs()
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
prg=ProgramName("NOEXT")

/* this is the template of AmigaDOS list command" */
template = "DIR/M,P=PAT/K,KEYS/S,DATES/S,NODATES/S,TO/K,SUB/K,SINCE/K,UPTO/K,QUICK/S,BLOCK/S,NOHEAD/S,FILES/S,DIRS/S,LFORMAT/K,ALL/S"

if ~RMHReadArgs(template) then do
    call PrintFault(IoErr(),prg)
    exit
end

if parm.0.mult>0 then
    do i=0 to parm.0.mult-1
        say "DIR" i":" parm.0.value.i
    end

if parm.1.flag then say "PAT:" parm.1.value
if parm.2.flag then say "KEYS"
if parm.3.flag then say "DATES"
if parm.4.flag then say "NODATES"
if parm.5.flag then say "TO:" parm.5.value
if parm.6.flag then say "SUB:" parm.6.value
if parm.7.flag then say "SINCE:" parm.7.value
if parm.8.flag then say "UPTO:" parm.8.value
if parm.9.flag then say "QUICK"
if parm.10.flag then say "BLOCK"
if parm.11.flag then say "NOHEAD"
if parm.12.flag then say "FILES"
if parm.13.flag then say "DIRS"
if parm.14.flag then say "LFORMAT:" parm.14.value
if parm.15.flag then say "ALL"
