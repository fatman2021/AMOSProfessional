Unfortunately we are not allowed to include the frame images done by 'gelb'
and 'jobbo' in our distribution of MUI. However, these frame images work
perfectly with this MUI version. All you have to do is to get a recent
MorphOS release (i.e. from http://www.morphos-team.net/morphos-2.7.iso)
and copy the frame image directories from MorphOS/Prefs/MUIGfx/frames
over to here. After that those frame images will be ready for use.

!!! IMPORTANT NOTE FOR AMIGAOS3 USERS !!!
Bitmap frames require a picture.datatype and a PNG datatype both of which are
able to provide the full alpha channel information of a loaded image to the
application. Without suitable components all you will see will be empty frames.
However, AfAOS prodives an enhanced picture.datatype which fullfils MUI's
requirements. So please consider installing AfAOS before you open a ticket in
MUI's bugtracker about missing frame images.
