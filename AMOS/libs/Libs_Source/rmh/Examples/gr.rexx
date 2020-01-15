/*
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
if ~open("STDERR","CONSOLE:","W") then stderr="STDOUT"

if ~RMHReadArgs("PATTERN/A,FILE/A/M,CASE/S,ALL/S") then do
    call PrintFault()
    exit
end

pa=parm.0.value
case=parm.2.flag
if case then patt=ParsePattern(pa,"CASE")
else patt=ParsePattern(pa)
if patt="" then do
    call SetIoErr(114)
    call PrintFault()
    exit
end
all=parm.3.flag

do m=0 to parm.1.mult-1
    call DirWalk(parm.1.value.m)
end
exit

DirWalk: procedure expose patt case all
parse arg file
    do f=0 to expand("A",file)-1
        file=a.f
        if a.f.type="DIR" then do
            if all then call DirWalk(AddPart(file,"#?"))
            iterate
        end
        if ~open(in,file,"R") then iterate
        match=0
        do i=0 while ~eof(in) & match=0
            l=readln(in)
            if case then match=MatchPattern(patt,l,"CASE")
            else match=MatchPattern(patt,l)
        end
        call close(in)
        if match>0 then say file
    end
    return
