CF = -c -msmall-code -m68020 -fbaserel
 
txex: txex.o startup.o
	gcc -o txex -nostartfiles -noixemul -msmall-code -fbaserel startup.o txex.o

txex.o: txex.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

