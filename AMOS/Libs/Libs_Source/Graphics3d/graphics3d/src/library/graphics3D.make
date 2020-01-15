###################################################################
# makefile v. 1.13 per compilatore VBCC
#  Esegue necessario per ricompilare la libreria graphics3D.library e il
#  programma 3dlib che la usa
#  (E' necessario che i sorgenti siano tutti in RAM:) 
#
##################################################################

## mettere OPTG = si se si vuole le funzioni grafiche ottimizzate
#OPTG = no
OPTG = si

## mettere DEB = no se non si vuol includere il debug 
#DEB = si
DEB = no

## mettere M68K = no se si vuol generare la libreria solo per le cpu dalla
## 68020 in poi.
#M68K = si
M68K = no

EC = emake
CC = vc

ifeq ($(M68K),si)
	FCPU    = 68000
	GD68K   = graphics3Dm68k.o
	NCPU	= _000
else
	FCPU    = 68020
	GD68K   =
	NCPU	= _020
endif

ifeq ($(DEB),si)
	DFLAGS  = -DDEBUG -Idebuglib.h
	DEBUGSL = debuglib.o
	NDEB	= _DEB
else
	DFLAGS  =
	DEBUGSL =
	NDEB	=
endif

ifeq ($(OPTG),si)
	GDOPTG	= graphics3D2d_o.o
	DFOPTG	= -DOPTG 
	NGFX	= _CPU
else
	GDOPTG	= graphics3D2d.o
	DFOPTG	= 
	NGFX	= _BLT
endif
	
CFLAGS   = -sc -DVBCC $(DFLAGS) $(DFOPTG) -c
LDFLAGS  = -nostdlib -lamiga 
LDLIBS   = 
OUTNAME  = graphics3d$(NDEB)$(NCPU)$(NGFX).library
DSALVA   = es:my_games

OBJSL = graphics3Dsu.o graphics3Dli.o $(GD68K) graphics3Dm.o graphics3Df_i2.o graphics3Df.o \
	graphics3Df1.o graphics3Df_t.o graphics3Df_i.o graphics3Df_g.o $(GDOPTG) $(DEBUGSL) \
	graphics3Dl.o 

OBJS  = 3dlib-020.m 3dlib.h 3dlibdemo.e 3dlibh.h 3dlib.make graphics3d_lib.m

################################################

# definisco tutti i file da generare 
all : $(OUTNAME) graphics3D.lib graphics3D.m graphics3D_lib.m 3dlib conv $(GD68K) $(DEBUGSL) $(GDOPTG)

##########################################################

# genero graphics3D.library
$(OUTNAME): $(OBJSL)
	$(CC) $(LDFLAGS) -o $(OUTNAME) $(OBJSL) $(LDLIBS)

graphics3Dsu.o: graphics3Dsu.c graphics3Dc.h graphics3Dbase.h graphics3Df.h
	$(CC) -cpu=$(FCPU) -O2 $(CFLAGS) graphics3Dsu.c >err

graphics3Dli.o: graphics3Dli.c graphics3Dbase.h
	$(CC) -cpu=$(FCPU) -O2 $(CFLAGS) graphics3Dli.c >err1

graphics3Df.o: graphics3Df.c graphics3Dc.h graphics3D.h graphics3Df_proto.h graphics3d2d.h
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3Df.c >err2

graphics3Df1.o: graphics3Df1.c graphics3Dc.h graphics3D.h graphics3Df_proto.h graphics3d2d.h
	$(CC) -cpu=$(FCPU) -O=8191 -schedule $(CFLAGS) graphics3Df1.c >err2b

graphics3Dl.o: graphics3dl.c graphics3df.h graphics3d.h graphics3dc.h
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3dl.c >err12

graphics3Df_t.o: graphics3Df_t.c graphics3Dc.h graphics3D.h graphics3Df_proto.h
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3Df_t.c >err3

graphics3Df_i.o: graphics3Df_i.c graphics3Dc.h graphics3D.h graphics3d2d.h 
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3Df_i.c >err4

graphics3Df_g.o: graphics3Df_g.c graphics3Dc.h graphics3D.h graphics3d2d.h 
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3Df_g.c >err4b

graphics3Df_i2.o: graphics3Df_i2.c graphics3Dc.h graphics3D.h 
	$(CC) -cpu=$(FCPU) -O3 $(CFLAGS) graphics3Df_i2.c >err5

graphics3D2d.o: graphics3D2d.c graphics3Dc.h graphics3D.h graphics3D2d_proto.h
	$(CC) -cpu=$(FCPU) -O=8191 -schedule $(CFLAGS) graphics3D2d.c >err6

graphics3Dm.o: graphics3Dm.s
	$(CC) -cpu=$(FCPU) $(CFLAGS) graphics3Dm.s >err11

graphics3Dm68k.o: graphics3dm68k.c
	$(CC) -O3 -sc -c graphics3Dm68k.c >err10

graphics3D2d_o.o: graphics3D2d_o.c graphics3Dc.h graphics3D.h graphics3D2d_proto.h
	$(CC) -cpu=$(FCPU) -O=8191 -schedule $(CFLAGS) graphics3d2d_o.c >err20

debuglib.o: debuglib.c
	$(CC) -O2 $(CFLAGS) debuglib.c >errd 

###########################################################

#Nota: se si aggiungono o tolgono o modificano delle funzioni, ricordarsi
#     di aggiornare anche i file graphics3D.fd, graphics3Dsu.c ,
#     graphics3D_proto.h e graphics3Df.h ricordarsi che si vuol usare 
#     alcune funzioni internamente si possono usare i registri solo se si 
#     definiscono anche nel prototipo 

###############################################################

# genero graphics3D.lib  
# (link library per usare graphics3D.library con programmi C)
graphics3D.lib: graphics3D.fd
	LibTool -o graphics3D.s graphics3D.fd
	$(CC) -c -o graphics3D.lib graphics3D.s

#####################################################################
#creo il necessario per usare e testare la libreria anche con l'Amiga_E

# genero graphics3D_lib.m (= include file per programmi in E)
graphics3D_lib.m: graphics3D.i
	cp graphics3D.i graphics3D_lib.i
	iconvert graphics3D_lib.i
	delete graphics3D_lib.i

# genero graphics3D.m (= .bmap file per programmi in E)
graphics3D.m: graphics3D.fd
	LibTool -lpo graphics3D_pragma.h graphics3D.fd
	pragma2module graphics3D_pragma
	copy graphics3D_pragma.m graphics3D.m
	delete graphics3D_pragma.m graphics3D_pragma.h 

#compilo il convertitore di formati oggetti 3d
conv : conv.e
	ec conv

#compilo il programma utilizzatore
3dlib: $(OBJS)
	$(EC) 3dlib

3dlib-020.m: 3dlib-020.c
	$(CC) -O2 -cpu=$(FCPU) -c 3dlib-020.c
	o2m 3dlib-020
	delete 3dlib-020.o

###################################################################
# se invoco make con l'opzione 'salva' allora si eseguira' questa riga
# che salvera' tutti i file essenziali per poter rieseguire questo file

salva: FORCE
	copy graphics3D.(c|h|i) graphics3Dsu.c graphics3Dli.c graphics3Df.(c|h) $(DSALVA)
	copy debuglib.(c|h) graphics3Df_i.c graphics3D2d.c graphics3D2d_proto.h $(DSALVA)
	copy graphics3Dc.h graphics3Dbase.h graphics3Df_proto.h graphics3D.fd $(DSALVA)
	copy graphics3d2d_o.c graphics3d2d_o.h graphics3d2d_o_proto.h $(DSALVA)
	copy graphics3D2d.h graphics3Df_t.c graphics3Df_i2.c $(DSALVA)
	copy graphics3dm.s graphics3Dm68k.c $(DSALVA)
	copy graphics3dl#?.(c|h) graphics3df1.c graphics3df_g.c $(DSALVA)
	copy 3dlib.h 3dlibh.h 3dlibdemo.e 3dlib.make $(DSALVA)
	copy 3dlib-020.c pved#?.(h|e|make) $(DSALVA) 
	copy graphics3D.(make|doc|notes|readme|history) $(DSALVA)
	copy dl1#? conv.e $(DSALVA)
	copy graphics3d#?.o $(DSALVA)

FORCE:
###################################################################
