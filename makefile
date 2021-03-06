CC = gcc
CCFLAGS = -g -Wall
LIBS = -lX11 -lXext -lm
OBJ = algo.o boite.o debug.o objets.o interfaceC.o interface.o interfaceG.o ez-draw.o
OBJ2 = Ofiles/algo.o Ofiles/boite.o Ofiles/debug.o Ofiles/objets.o Ofiles/interfaceC.o Ofiles/interface.o Ofiles/interfaceG.o Ofiles/ez-draw.o
PATHSRC = src/
PATHHEADER = headers/
DEPINT = Interface/
DEPGEN = Generator/
OUTO = -o Ofiles/$*.o

vpath
vpath %.h headers
vpath %.h headers/Interface 
vpath %.h headers/Generator

vpath %.c src
vpath %.c src/Interface 
vpath %.c src/Generator 

vpath %.o Ofiles

all: makedir xX_projet_Xx generator

xX_projet_Xx : main.c $(OBJ)
	$(CC) $(CCFLAGS) -o xX_projet_Xx $(PATHSRC)main.c $(OBJ2) $(LIBS)

generator : generator.c
	$(CC) $(CCFLAGS) -o generator $(PATHSRC)$(DEPGEN)generator.c 

algo.o : algo.c algo.h boite.h objets.h interfaceC.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)algo.c $(OUTO) $(LIBS)

boite.o : boite.c boite.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)boite.c $(OUTO) $(LIBS)

objets.o : objets.c objets.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)objets.c $(OUTO) $(LIBS)

interface.o : interface.c interface.h interfaceC.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)$(DEPINT)interface.c $(OUTO) $(LIBS)

interfaceC.o : interfaceC.c interfaceC.h debug.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)$(DEPINT)interfaceC.c $(OUTO) $(LIBS)

interfaceG.o : interfaceG.c interfaceG.h debug.h ez-draw.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)$(DEPINT)interfaceG.c $(OUTO) $(LIBS)

ez-draw.o : ez-draw.c ez-draw.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)$(DEPINT)ez-draw.c $(OUTO) $(LIBS)

debug.o : debug.c debug.h
	$(CC) $(CCFLAGS) -c $(PATHSRC)$(DEPINT)debug.c $(OUTO) $(LIBS)

makedir :
	- mkdir Ofiles
clean :
	- rm xX_projet_Xx generator
	- rm -f -r Ofiles/






