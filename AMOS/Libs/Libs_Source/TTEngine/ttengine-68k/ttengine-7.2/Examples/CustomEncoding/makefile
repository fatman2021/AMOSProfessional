CF = -c -msmall-code -m68020 -fbaserel
 
custenc: custenc.o startup.o
	gcc -o custenc -nostartfiles -noixemul -msmall-code -fbaserel startup.o custenc.o

custenc.o: custenc.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

