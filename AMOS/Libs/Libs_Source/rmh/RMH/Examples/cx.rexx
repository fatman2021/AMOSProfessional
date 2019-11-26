/* */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

name   = "RMHCx"
text   = "RMHCx 1.0 <alforan@tin.it>"
descr  = "Cx in ARexx by rmh.library"
flags  = "UNIQUE NOTIFY DISKINSERTED DISKREMOVED"
hotkey = "rawkey control esc"
cx=AddCx(name,text,descr,flags,hotkey)
if cx=0 then do
    say "unique violation"
    exit
end
if cx=1 then do
    say "bad hotkey description"
    exit
end
cxs=CxSignal(cx)

do while 1
    rsig=Wait(or(cxs,2**12))
    if and(rsig,2**12)~=0 then exit
    if and(rsig,cxs)~=0 then call handle(cx)
end
exit

handle:
parse arg cx
    handle.wait=0
    num=HandleCx(cx,"HANDLE")
    do i=0 to num-1
        say pragma(id) i handle.i.class
        if handle.i.class=="KILL" then exit
    end
    return
