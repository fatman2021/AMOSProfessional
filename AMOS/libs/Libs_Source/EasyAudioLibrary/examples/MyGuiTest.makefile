# ------------------------------------------------------------------ #
# $VER: MuGuiTest makefile 39.01 (12.12.1999)                        #
#                                                                    #
# gnu make makefile for easyaudio test program                       #
#                                                                    #
# (C) Copyright 1999-2000 Matthew J Fletcher - All Rights Reserved.  #
# amimjf@connectfree.co.uk - www.amimjf.connectfree.co.uk            #
# ------------------------------------------------------------------ #

CC  = gcc
CFLAGS  = -m68020 -c -fstrength-reduce
LDFLAGS = -noixemul
LDLIBS  = -lm

OBJS    = MyGuiTest.gui.o MyGuiTest.main.o MyGuiTest.asl.o

MyGuiTest: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

MyGuiTest.gui.o: MyGuiTest.gui.c
	$(CC) $(CFLAGS) MyGuiTest.gui.c

MyGuiTest.main.o: MyGuiTest.main.c
	$(CC) $(CFLAGS) MyGuiTest.main.c

MyGuiTest.asl.o: MyGuiTest.asl.c
	$(CC) $(CFLAGS) MyGuiTest.asl.c

