/*
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

if ~RMHReadArgs("ASSIGN") then do
    call PrintFault()
    exit
end
if parm.0.flag then dir=parm.0.value
else dir="libs:"

if MultiAssign(dir,"multi") then
    do i=0 to multi.num-1
        say i":" multi.i
    end
