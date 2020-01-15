CF = -c -msmall-code -m68020 -fbaserel
 
txfit: txfit.o startup.o
	gcc -o txfit -nostartfiles -noixemul -msmall-code -fbaserel startup.o txfit.o

txfit.o: txfit.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

