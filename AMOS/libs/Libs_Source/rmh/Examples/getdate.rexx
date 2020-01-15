/* GetDate() example */

l="rmh.library";if ~show("L",l) then;if ~addlib(l,0,-30) then exit

inetDate="%m %w %d %Y %H:%M:%S"
GMTInetDate=inetDate "GMT"

if GetDate("D","GMT") then do
    say "GMT date:   " translateDate(formatdate("D",GMTInetDate))
    call GetDate("D") then do
    say "Locale date:" translateDate(formatdate("D",inetDate))
end
else do
    say "Can't find ENV:TZ"
    say "Locale date:" translateDate(formatdate("D",inetDate))
end
exit
/***************************************************************************/
translateDate: procedure
    d.0="Sun";d.1="Mon";d.2="Tue";d.3="Wed";d.4="Thu";d.5="Fri";d.6="Sat"
    m.1="Jan";m.2="Feb";m.3="Mar";m.4="Apr";m.5="May";m.6="Jun";m.7="Jul";m.8="Aug";m.9="Sep";m.10="Oct";m.11="Nov";m.12="Dec"
    parse arg i j rest
    i=i%1
    return d.j"," m.i || rest
/***************************************************************************/
