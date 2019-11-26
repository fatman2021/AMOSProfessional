/* */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

icon="Ram:TestIcon"
s.SupportsSnapshot=1
s.SupportsUnSnapshot=1
s.PropagatePosition=1
ai=AddAppIcon("RMH App Icon Test",icon,'s')
as=AppIconSignal(ai)

do while 1
    rsig=Wait(or(as,2**12))
    if and(rsig,2**12)>0 then exit
    if and(rsig,as)>0 then call handleAI(ai)
end
exit

handleAI:
parse arg ai
    handle.wait=0
    num=HandleAppIcon(ai,"HANDLE")
    do i=0 to num-1
        select

            when handle.i.class="DOUBLECLICK" then say "DOUBLECLICK"

            when handle.i.class="DROP" then do
                say "DROP" handle.i.dropnum
                do j=0 to handle.i.dropnum-1
                    say handle.i.name.j handle.i.lock.j
                end
            end

            when handle.i.class="SNAPSHOT" then do
                call GetAppIconPos(ai,"p")
                res=SetIconAttrs(icon,"p")
                say "Snapshot" p.posx p.posy res
            end

            when handle.i.class="UNSNAPSHOT" then do
                p.posx="FREE"
                p.posy="FREE"
                res=SetIconAttrs(icon,"p")
                say "UnSnapshot" res
            end

            otherwise nop

        end
    end
    return
