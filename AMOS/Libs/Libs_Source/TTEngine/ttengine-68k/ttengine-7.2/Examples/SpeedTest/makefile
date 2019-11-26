CF = -c -msmall-code -m68020 -fbaserel
 
speed: speed.o startup.o
	gcc -o speed -nostartfiles -noixemul -msmall-code -fbaserel startup.o speed.o

speed.o: speed.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

