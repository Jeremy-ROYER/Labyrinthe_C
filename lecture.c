/*========================================================================

--------------------------------------------------------------------------
  ||      ||||  |||||| ||  || |||||| |||||| |||  || |||||| ||  || ||||||
  ||     ||  || ||  ||  ||||  ||  ||   ||   |||| ||   ||   ||  || ||
  ||     |||||| |||||    ||   ||||||   ||   || | ||   ||   |||||| ||||
  ||     ||  || ||  ||  ||    || ||    ||   || ||||   ||   ||  || ||
  |||||| ||  || |||||| ||     ||  || |||||| ||  |||   ||   ||  || ||||||
--------------------------------------------------------------------------

==========================================================================

Autheur : Royer Jérémy
          Amady Naysel
Date : 24/12/2020
File : lecture.c

==========================================================================

Fichier contenant la fonction de construction du labyrinthe à partir d'un 
fichier texte le contenant.

========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"

/* Construit le tableau de caractère contenant le labyrinthe 
	et récupère les coordonnées de départ et d'arrivée */

/* La taille du labyrinthe est défini en début de fichier */

/* La fonction retourne 1 si tout s'est bien passé */

int construction(FILE* labyText, char labyTab[TAILLE_X][TAILLE_Y], int depart[2], int arrivee[2]){

	/* Vérifie si le fichier est bien ouvert */
	if(labyText==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return 0;
	}

	else {
		/* On rempli le tableau pour construire le labyrinthe */
		for (int i=0; i<TAILLE_Y; i++){
			for(int j=0; j<TAILLE_X; j++){
				fscanf(labyText,"%c",&labyTab[j][i]);

				/* On regarde si le caractère lu n'est pas un D ou un A
					en conséquence on rempli les coordonnées des cases départ et arrivée */
				if(labyTab[j][i]=='D'){
					depart[0]=j;
					depart[1]=i;
				}
				else if(labyTab[j][i]=='A'){
					arrivee[0]=j;
					arrivee[1]=i;
				}
			}
		}
	}

	return 1;
}