/*
An example about SetRexxVar().
Opens a port called "SRV" and wait for messages on it.
Exists if a "QUIT" message is got.
Sets the var named A to the value "Hi babe!
To use, open 2 shells
- write in one rx srv
- in the other rx "shell 'SRV' Hello;say A"

the stop srv.rexx writing rx "shell 'SRV' quit"
*/

if ~openport("SRV") then exit

stop=0
do while ~stop
    call WaitPkt("SRV")
    pkt=GetPkt("SRV")
    if pkt~=Null() then do
        comm=GetArg(pkt)
        say "A received:" comm
        if upper(comm)=="QUIT" then stop=1
        call SetRexxVar(pkt,"A",'Hi babe!')
        call Reply(pkt)
    end
end
exit
