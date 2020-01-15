/* */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
l="rexxtricks.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

parm.0.value=200
if ~ReadArgs("NUM/N,NRMHI=NORMHINDEX/S,NRMH/S,NRMHL/S,NRXT=NOREXXTRICKS/S") then do
    call PrintFault()
    exit
end

call random(65,90,time(s))

if parm.1.flag & parm.2.flag & parm.3.flag & parm.4.flag then exit

say "Initializing..."

n=parm.0.value

do i=0 to n-1
    s=""
    do for 8
        s=s||d2c(random(65,90))
    end
    a.i=s
    b.i=s
    c.i=s
    j=i+1
    d.j=s
end

if ~parm.1.flag then do
    say "RMH index sorting..."
    call time(r)
    call sort("a",0,n-1,,,"idx")
    e1=time(e)
end

if ~parm.2.flag then do
    say "RMH sorting..."
    call time(r)
    call sort("b",0,n-1)
    e2=time(e)
end

if ~parm.3.flag then do
    say "RMH locale sorting..."
    call time(r)
    call sort("c",0,n-1,"Locale")
    e3=time(e)
end

if ~parm.4.flag then do
    say "RexxTricks sorting..."
    d.0=n
    call time(r)
    call qsort("d")
    e4=time(e)
end

say
say "Comparation for" n "strings:"
if ~parm.1.flag then say " RMH index time:" e1
if ~parm.2.flag then say "       RMH time:" e2
if ~parm.3.flag then say "RMH Locale time:" e3
if ~parm.4.flag then say "RexxTricks time:" e4

/*do i=0 to n-1
    say c.i
end*/

exit
