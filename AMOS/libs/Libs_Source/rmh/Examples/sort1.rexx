/*
** Sort Example 1: simple sort test
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

call random(65,90,time(s))

n=500

do i=0 to n-1
    s=""
    do for 8
        s=s||d2c(random(65,90))
    end
    a.i=s
end

call time(r)

call sort("a",0,n-1)

e=time(e)

s=1
if n>9 then s=s+1
if n>99 then s=s+1
if n>999 then s=s+1
if n>999 then s=s+1

do i=0 to n-1
    say right("  "|| i,s) || ":" a.i
end

say "Sorting elapsed time:" e
