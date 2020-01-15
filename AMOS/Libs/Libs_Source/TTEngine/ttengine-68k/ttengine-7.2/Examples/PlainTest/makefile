CF = -c -msmall-code -m68020 -fbaserel
 
test: test.o startup.o
	gcc -o test -nostartfiles -noixemul -msmall-code -fbaserel startup.o test.o

test.o: test.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

