/*
usage of Requester()
*/

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

volume="Volume:"

do while Requester("Want me",,"to try again?")
end

