#=========================================================================
#
#-------------------------------------------------------------------------
# ||      ||||  |||||| ||  || |||||| |||||| |||  || |||||| ||  || ||||||
# ||     ||  || ||  ||  ||||  ||  ||   ||   |||| ||   ||   ||  || ||
# ||     |||||| |||||    ||   ||||||   ||   || | ||   ||   |||||| ||||
# ||     ||  || ||  ||  ||    || ||    ||   || ||||   ||   ||  || ||
# |||||| ||  || |||||| ||     ||  || |||||| ||  |||   ||   ||  || ||||||
#-------------------------------------------------------------------------
#
#=========================================================================
#
#Autheur : Royer Jérémy
#          Amady Naysel
#Date : 24/12/2020
#File : Makefile

#=========================================================================
#
#					Makefile pour le jeu labyrinthe
#
#=======================================================================*/


# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS =
LIBSDIR =

# fichiers du projet
SRC = affichage.c lecture.c joueur.c labyrinthe.c
OBJ = $(SRC:.c=.o)
EXEC = run.out


# règle initiale
all: $(EXEC)

# dépendance des .h
affichage.o: affichage.h
lecture.o: affichage.h lecture.h
joueur.o: affichage.h lecture.h joueur.h
labyrinthe.o: affichage.h lecture.h
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o

.PHONY: clean mproper