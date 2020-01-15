/*
usage of ParseConfig()
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

file=AddPart(PathPart(ProgramName("FULL")),ProgramName("NOEXT"))".conf"

lines=ParseConfig(file,"CONF")
if lines==-1 then do
    say "File '"file"' not found."
    exit
end

do i=0 to lines-1
    say left("Real line:" i,14) left("line:" conf.i.line,9) left("Option:" conf.i,25) "Value:" conf.i.value
end
