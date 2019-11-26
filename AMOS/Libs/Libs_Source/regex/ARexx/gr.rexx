/* mini rexx grep - slow verbose version */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit
l="regex.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

if ~open("STDERR","CONSOLE:","W") then stderr="STDOUT"

prg=programname("NOEXT")
if ~RMH_ReadArgs("RE/A,FILE/A/M,ICASE/S") then do
	call writeln(stderr,fault(ioerr(),prg))
	exit
end

re=parm.0.value
if parm.2.flag then flags = flags "ICASE"
else flags = ""
flags = flags "STARTEND"
do m=0 to parm.1.mult-1
	do f=0 to expand("A",parm.1.value.m,"FILE")-1
		file=a.f
		if ~open(in,file,"R") then call writeln(stderr,prg": file '"file"' not found")
		else do
			do i=0 while ~eof(in)
				l = readln(in)
				match=rematch(re,l,flags,"P")
				if match>1 then do
					call writeln(stderr,"prg:" regerr)
					exit
				end
				else
					if match=0 then
						say "file:'"file"' line:"i "spos:"p.so "epos:"p.eo
			end
			call close(in)
		end
	end
end
