/*
** MacroEnv() example
**/

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

call MacroEnv("env")

/*
** We accepts the following argoments:
** - shell template "CONFIG/K,PORT/K/N,START/S,QUIET/S,NOGUI/S"
** - Workbench tooltypes: CONFIG, PORT, START, QUIET, NOGUI
**/

if env.wb? then do
    c=FindVar("CONFIG")
    p=FindVar("PORT")
    s=(FindVar("START")~="")
    q=(FindVar("QUIET")~="")
    n=(FindVar("NOGUI")~="")
end
else do
    if ~RMHReadArgs("CONFIG/K,PORT/K/N,START/S,QUIET/S,NOGUI/S") then do
        call PrintFault()
        exit
    end
    if parm.0.flag then c=parm.0.value; else c=""
    if parm.1.flag then p=parm.1.value; else p=""
    s=parm.2.flag
    q=parm.3.flag
    n=parm.4.flag
end

if c="" then c="[none]"
if p="" then p="[none]"

nl="0a"x

if env.wb? then do
call EasyRequest("
Config"  c || nl ||"
Port  "  p || nl ||"
Start "  s || nl ||"
Quiet "  q || nl ||"
NoGui "  n,env.prg)
end
else do
    say env.prg": Config"  c
    say env.prg": Port  "  p
    say env.prg": Start "  s
    say env.prg": Quiet "  q
    say env.prg": NoGui "  n
end
