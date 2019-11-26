/*
** Show the use of some date/time function
** Usage: rx dtime
**/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
prg=ProgramName("NOEXT")

call GetDate("D")
say "Time is:" d.days "days " d.minute "minute " d.tick "ticks"

say "That is in human form:" formatdate("D","%m %w %d %Y %H:%M:%S")

call ds2tv("D")
t.secs=GMTOffset()*60
call AddTime("D","T")
call tv2ds("D")
say "and in GMT" formatdate("D","%m %w %d %Y %H:%M:%S GMT")

say "Now let's wait 5 seconds (or a ctrl-c)..."
tim=CreateTimer()
ts=TimerSignal(tim)
call StartTimer(tim,5)
res=Wait(or(ts,2**12))
if and(res,ts)~=0 then say "timeout"
if and(res,2**12)~=0 then say "ctrl-c"
say "bye..."
