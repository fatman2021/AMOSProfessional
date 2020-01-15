/*
** NamedSpace & MacroNotify
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

call NamedSpaceImport(name,"var.#?")
do i=0 to 9
    say var.i
end

break_c:
halt:
    if joined~=1 then call MacroNotifyJoin(name)
    exit

break_d:
    exit
