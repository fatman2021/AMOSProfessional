CC_OPTS = -O2 -fomit-frame-pointer -noixemul -nostartfiles $(CFLAGS)
CPP_OPTS = -I./mad -DHAVE_CONFIG_H -DNDEBUG $(FPM)
MAD_OPTS = -Wall -O -fforce-mem -fforce-addr -fthread-jumps -fcse-follow-jumps -fcse-skip-blocks -fexpensive-optimizations -fregmove -fstrength-reduce -fschedule-insns2 -fmove-all-movables -fbranch-count-reg $(CFLAGS)
RM = rm -f
MV = mv -f

PROGNAME = mpega.library

LIB_SRC = library_init.c
LIB_OBJ = $(LIB_SRC:.c=.o)

PUP_SRC = support_pup.c
PUP_OBJ = $(PUP_SRC:.c=.o)

STARTUP_SRC = startup_pup.c
STARTUP_OBJ = $(STARTUP_SRC:.c=.o)

WRAP_SRC = support.c wrap_mpega.c
WRAP_OBJ = $(WRAP_SRC:.c=.o)

MAD_SRC = mad/filter.c mad/resample.c mad/tag.c mad/crc.c mad/fixed.c mad/bit.c mad/timer.c mad/stream.c mad/frame.c mad/synth.c mad/layer12.c mad/layer3.c mad/huffman.c
MAD_OBJ = $(MAD_SRC:.c=.o)

%.o: %.c 
	$(CC) $(CPP_OPTS) $(CC_OPTS) -c $< -o $@

all: $(PROGNAME)_PPC $(PROGNAME)_040 #$(PROGNAME)_OS4

mad_build: $(MAD_OBJ)

mad.stmp:
	$(MAKE) mad_build "CC_OPTS = \$$(MAD_OPTS)"

$(PROGNAME): $(LIB_OBJ) $(WRAP_OBJ) mad.stmp
	$(CC) -o $@ $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ) $(ADD_OBJ) $(CC_OPTS)

$(PROGNAME)_ELF: $(LIB_OBJ) $(WRAP_OBJ) mad.stmp
#	ppc-morphos-ld -r -o $(PROGNAME) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ)
	$(CC) $(CC_OPTS) -o $(PROGNAME) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ)

elfobject.o: $(STARTUP_OBJ) $(WRAP_OBJ)
	ppc-morphos-ld -r -fl libnix -o elfobject.elf $(STARTUP_OBJ) $(WRAP_OBJ) $(MAD_OBJ) -lc
	ppc-morphos-strip --strip-unneeded --keep-symbol __LibFuncTable --remove-section .comment elfobject.elf
	Data2Object elfobject.elf elfobject.o SECTION elf SYMBOL __ElfObject

$(PROGNAME)_PUP: $(LIB_OBJ) $(PUP_OBJ)
	$(CC) -o $(PROGNAME) $(LIB_OBJ) $(PUP_OBJ) elfobject.o $(CC_OPTS)

$(PROGNAME)_040:
	$(MAKE) $(PROGNAME) "CC = m68k-amigaos-gcc" "CFLAGS = -m68040" "FPM = -DFPM_DEFAULT -DOPT_SPEED -DOPT_SSO" "ADD_OBJ = -lm040"
#	$(MAKE) $(PROGNAME) "CC = m68k-amigaos-gcc" "CFLAGS = -m68040" "FPM = -DFPM_M68K -DOPT_SPEED -DOPT_SSO"
	m68k-amigaos-strip --strip-unneeded --remove-section .comment $(PROGNAME)
	-$(MV) $(PROGNAME) $(PROGNAME).040
	-$(RM) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ)

$(PROGNAME)_PPC:
	$(MAKE) $(PROGNAME)_ELF "CC = ppc-morphos-gcc" "CFLAGS = -mcpu=603e -mmultiple" "FPM = -DFPM_PPC -DOPT_ACCURACY -DBUILD_MORPHOS"
	ppc-morphos-strip --strip-unneeded --remove-section .comment $(PROGNAME)
	-$(MV) $(PROGNAME) $(PROGNAME).elf
	-$(RM) $(LIB_OBJ) $(WRAP_OBJ)
	$(MAKE) elfobject.o "CC = ppc-morphos-gcc" "CFLAGS = -mcpu=603e -mmultiple -I/GCCInclude -I/PPCInclude -I/Include" "FPM = -DFPM_PPC -DOPT_ACCURACY -DBUILD_POWERUP"
	$(MAKE) $(PROGNAME)_PUP "CC = m68k-amigaos-gcc" "CFLAGS = -m68040" "FPM = -DBUILD_POWERUP"
	m68k-amigaos-strip --strip-unneeded --remove-section .comment $(PROGNAME)
	-$(MV) $(PROGNAME) $(PROGNAME).pup
	-$(RM) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ) $(PUP_OBJ) $(STARTUP_OBJ) elfobject.elf elfobject.o

mpega_68k_os4.o: mpega_68k_os4.S
	ppc-amigaos-gcc -Wa,-mregnames $< -o $@ -c -I/V/src/kickstart/exec_sg/include

$(PROGNAME)_OS4: mpega_68k_os4.o
	$(MAKE) $(PROGNAME) "CC = ppc-amigaos-gcc" "CFLAGS = -D__USE_INLINE__ -D__USE_BASETYPE__ -mcpu=604e -mmultiple" "FPM = -DFPM_PPC -DOPT_ACCURACY -DBUILD_OS4 -I/V/include" "ADD_OBJ = mpega_68k_os4.o -lmoto"
	ppc-amigaos-strip --strip-all --remove-section .comment $(PROGNAME)
	-$(MV) $(PROGNAME) $(PROGNAME).os4
	-$(RM) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ)

clean:
	-$(RM) $(LIB_OBJ) $(WRAP_OBJ) $(MAD_OBJ) $(PUP_OBJ) $(STARTUP_OBJ) elfobject.elf elfobject.o mpega_68k_os4.o

