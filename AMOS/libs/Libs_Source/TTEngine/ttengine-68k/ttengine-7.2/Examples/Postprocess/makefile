CF = -c -msmall-code -m68020 -fbaserel
 
postprocess: postprocess.o startup.o
	gcc -o postprocess -nostartfiles -noixemul -msmall-code -fbaserel startup.o postprocess.o

postprocess.o: postprocess.c
	gcc $(CF) $<

startup.o: startup.c
	gcc $(CF) -fwritable-strings $<

