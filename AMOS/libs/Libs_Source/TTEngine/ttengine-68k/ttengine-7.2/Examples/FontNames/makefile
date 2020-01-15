CF = -c -msmall-code -m68020 -fbaserel
 
names: names.o startup.o
	gcc -o names -nostartfiles -noixemul -msmall-code -fbaserel startup.o names.o

names.o: names.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

