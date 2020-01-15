/*
usage of ProgramName()
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

say "Simple:" ProgramName()
say "NoExt: " ProgramName("NOEXT")
say "Full:  " ProgramName("FULL")
say "Path:  " PathPart(ProgramName("FULL"))
