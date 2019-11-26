# Wedit Makefile for project soft3d
SRCDIR=e:\local\d.perso\work\wazp3d\wazp3d-src
CFLAGS=-Ie:\local\d.perso\applis\lccnew\include  -O 
CC=e:\local\d.perso\applis\lccnew\bin\lcc.exe
LINKER=e:\local\d.perso\applis\lccnew\bin\lcclnk.exe
OBJS=\
	soft3d50.obj \
	soft3d_opengl.obj \
	soft3d_dll.obj \

LIBS=OPENGL32.LIB

soft3d.dll:	$(OBJS) Makefile
	$(LINKER)  -s -dll soft3d.def -o $(SRCDIR)\lcc\soft3d.dll $(OBJS) $(LIBS)

# Build SOFT3D50.C
SOFT3D50_C=\
	$(SRCDIR)\Wazp3D.h\
	$(SRCDIR)\soft3d_amiga_defines.h\
	$(SRCDIR)\soft3d_protos.h\
	$(SRCDIR)\soft3d_opengl.h\
	$(SRCDIR)\soft3d_mem_print.h\
	$(SRCDIR)\soft3d_pc_glue.h\
	$(SRCDIR)\winuaenative.h\

soft3d50.obj: $(SOFT3D50_C) $(SRCDIR)\soft3d50.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\soft3d50.c

# Build SOFT3D_OPENGL.C
SOFT3D_OPENGL_C=\
	$(SRCDIR)\soft3d_opengl.h\

soft3d_opengl.obj: $(SOFT3D_OPENGL_C) $(SRCDIR)\soft3d_opengl.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\soft3d_opengl.c

# Build SOFT3D_DLL.C
SOFT3D_DLL_C=\

soft3d_dll.obj: $(SOFT3D_DLL_C) $(SRCDIR)\soft3d_dll.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\soft3d_dll.c

link:
	$(LINKER)  -s -dll soft3d.def -o $(SRCDIR)\lcc\soft3d.dll $(OBJS) $(LIBS)

