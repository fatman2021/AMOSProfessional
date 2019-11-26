/*
** Show the use of the clips functions
** Usage clips [FILTER]
** FILTER an AmigaDOS pattern
**/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
prg=ProgramName("NOEXT")

parm.0.value="#?"
if ~RMHReadArgs("FILTER") then do
    call PrintFault(IoErr(),prg)
    exit
end

f=ParsePattern(parm.0.value)
clips=show('C',,'A'x)
i=0
do j=0 while clips~=""
    parse var clips clip 'A'x clips
    if MatchPattern(f,clip) then do
        cont=GetClip(clip)
        list.i=left(clip,20)" "left(GetClip(clip),20)
        if length(cont)>20 then list.i=list.i"..."
        i=i+1
    end
end

if j=0 then do
    say "ARexx clips list is empty"
    exit
end
say "Total clips:   " j
say "Filtered clips:" i
if i>0 then do
    say "---------------"
    do n=0 to i-1
        say list.n
    end
end
