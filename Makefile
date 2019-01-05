but : SNAKE

OFILES = MenuP.o \
	 Options.o \
	 Score.o \
	 MiseEnPlace.o \
	 Jeu.o \
	 Main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

MenuP.o : MenuP.h Score.h
Options.o : Options.h
Score.o : Score.h
MiseEnPlace.o : MiseEnPlace.h
Jeu.o : Jeu.h Score.h MiseEnPlace.h
Main.o : MenuP.h Options.h MiseEnPlace.h Jeu.h Score.h

SNAKE : $(OFILES)
	$(CC) $(CFLAGS) -o SNAKE $(OFILES) -lgraph

clean :
	-rm -f $(OFILES) SNAKE

.PHONY : but clean
