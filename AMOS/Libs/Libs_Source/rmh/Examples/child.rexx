/*
** MacroNotify
** Child macro
**
**/

signal on halt
signal on break_c
signal on break_d

parse arg name i

call MacroNotifyJoin(name)
joined=1

call MacroEnv("env")

say " Child" i "started"

if i//2 then upto=1E10
else upto=100
do j=0 to upto
    say "Child" i j
end

break_c:
halt:
    if joined~=1 then call MacroNotifyJoin(name)
    exit

break_d:
    exit
