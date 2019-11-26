/*
    Name:           notify.rexx
    Template:       FILE,CLIP=CLIPUNIT/K/N,TIMEOUT/K/N
    Description:    wait for a changes on a FILE or a CLIP with timeout
                    default for CLIP is 0
                    default for TIMEOUT is 10 seconds
*/

parm.1.value=0
parm.2.value=10

if ~RMHReadArgs("FILE,CLIP=CLIPUNIT/K/N,TIMEOUT/K/N") then do
    call PrintFault(IoErr(),ProgramName("NOEXT"))
    exit
end

if parm.1.value<0 | parm.2.value<0 | parm.2.value>100 then do
    call PrintFault(115,ProgramName("NOEXT"))
    exit
end

if ~parm.0.flag | parm.1.flag then name="CLIP"
else name=parm.0.value

if name=="CLIP" then noti=StartNotify(name,parm.1.value)
else noti=StartNotify(name)
if noti<0 then do
    call PrintFault(IoErr(),ProgramName("NOEXT"))
    exit
end
ns=NotifySignal(noti)

timer=CreateTimer()
ts=TimerSignal(timer)

call StartTimer(timer,parm.2.value)
mask=wait(or(ns,ts))
if and(mask,ns)~=0 then do
    if name=="CLIP" then do
        say "Clip unit" parm.1.value "changed"
        if ReadTextClip("C")~=0 then do
            say "Clip unit" parm.1.value "content is:"
            say c
        end
    end
    else say "File:" name "changed"
end
else if and(mask,ts)~=0 then say "Timeout"
call FreeNotify(noti)
