CF = -c -msmall-code -m68020 -fbaserel
 
drawmodes: drawmodes.o startup.o
	gcc -o drawmodes -nostartfiles -noixemul -msmall-code -fbaserel startup.o drawmodes.o

drawmodes.o: drawmodes.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

