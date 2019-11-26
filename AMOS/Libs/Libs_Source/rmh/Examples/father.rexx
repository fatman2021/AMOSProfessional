/*
** MacroNotify
** Father Macro:
** Runs 10 children macros, waits 10 seconds and exists
**
**/

signal on halt
signal on break_c

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

call MacroEnv("env")

name=pragma("ID")
mns=MacroNotifyCreate(name)
if mns=0 then do
    call info "Can't create MacroNotify"
    exit
end

tim=CreateTimer()
ts=TimerSignal(tim)
ctrL_c=2**12
mask=or(mns,ts,ctrl_c)

call StartTimer(tim,10)

m=0
do forever

    if m<9 then do
        call RxsCall("child" name m)
        m=m+1
    end

    recv=Wait(mask)

    if and(recv,ctrl_c)>0 then do
        call info "interrupted"
        exit
    end

    if and(recv,ts)>0 then do
        call info "timeout"
        exit
    end

    if and(recv,mns)>0 then call HandleMacroNotify
end
/* never reached */

HandleMacroNotify:
    do forever
        ev=MacroNotifyGetEvent(name)
        if ev="" then return
        parse var ev ev id more
        select
            when ev="STARTED" then call info "Macro" id "started"
            when ev="ENDED" then call info "Macro" id "exited"
            otherwise nop
        end
    end
    /* never reached */

info:
parse arg msg
    say env.prg":" msg
    return

break_c:
halt:
    call info "interrupted"
    exit
