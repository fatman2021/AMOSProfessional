/* Small demo, sending drawing command to AMOS */

address 'AMOS-DRAW'
Say 'Sending stuff to AMOS'

/* Jerk around a bit with the Plot-command */
y=10
do x=100 to 400 by 5
   Draw x y
   end

do y=12 to 102 by 2
   draw x y
   end

do x=400 to 100 by -5
   draw x y
   end
do y=102 to 12 by -2
   draw x y
   end
do t=0 to 45 by 1
   x=x+3
   y=y+1
	DRAW x y
   end
do t=0 to 45 by 1
   x=x+3
   y=y-1
	DRAW x y
   end

Say "All done!"
exit 0
