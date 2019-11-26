/* GetTZ() example */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

if GetTZ("TZ") then do
    say "Timeznone:      " tz.tzstn
    say "Timezone offset:" tz.timezone
    if tz.daylight then say "Daylight:       " tz.tzdtn
end
else say "Can't find ENV:TZ"

