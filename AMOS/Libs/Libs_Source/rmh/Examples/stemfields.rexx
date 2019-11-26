/* StemFields() example */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
l="datatypes.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

if ~ReadArgs("FILE/A") then do
    call PrintFault()
    exit
end

if ~Exists(parm.0.value) then do
    call SetIoErr(205)
    call PrintFault()
    exit
end

call ExamineDT(parm.0.value,dtstem.,stem)

n=StemFields("dtstem","f","Short Value")
call sort("f",,,,,"ndx")

do j=0 to n-1
    i=ndx.j
    say right(" "||j,2)":" left(f.i,12) "  " f.i.value
end
