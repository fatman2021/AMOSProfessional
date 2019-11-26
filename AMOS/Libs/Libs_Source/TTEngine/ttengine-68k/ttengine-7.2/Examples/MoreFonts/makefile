CF = -c -msmall-code -m68020 -fbaserel
 
morefonts: morefonts.o startup.o
	gcc -s -o morefonts -nostartfiles -noixemul -msmall-code -fbaserel startup.o morefonts.o -lsmall

morefonts.o: morefonts.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

