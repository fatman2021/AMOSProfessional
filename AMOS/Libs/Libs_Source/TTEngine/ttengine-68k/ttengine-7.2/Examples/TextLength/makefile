CF = -c -msmall-code -m68020 -fbaserel
 
txlen: txlen.o startup.o
	gcc -o txlen -nostartfiles -noixemul -msmall-code -fbaserel startup.o txlen.o

txlen.o: txlen.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

