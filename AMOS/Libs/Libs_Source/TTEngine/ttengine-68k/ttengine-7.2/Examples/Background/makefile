CF = -c -msmall-code -m68020 -fbaserel
 
background: background.o startup.o
	gcc -o background -nostartfiles -noixemul -msmall-code -fbaserel startup.o background.o

background.o: background.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

