/*
** Sort Example 2: how to sort dates.
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

a.0="5/7/2003"
a.1="25/2/2003"
a.2="30/9/2003"
a.3="27/6/2003"

call sort("a",0,3,"","
    parse arg a,b;
    call parsedate(a,'%d/%m/%Y','d1');
    call parsedate(b,'%d/%m/%Y','d2');
    return CompareDates(d2,d1)")

do i=0 to 3
    say i":" a.i
end
