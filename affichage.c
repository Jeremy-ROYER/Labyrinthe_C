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
File : affichage.c

==========================================================================

Fichier contenant la fonction d'affichage du labyrinthe à partir du 
tableau rempli par construction() (lecture.c).

========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "affichage.h"

/* Affiche le labyrinthe à partir du tableau passé en paramètre */

void afficheLabyrinthe(char labyTab[TAILLE_X][TAILLE_Y], int joueur[2]){
    for (int i = 0; i < TAILLE_Y; i++){
        for (int j = 0; j < TAILLE_X; j++){
            if(labyTab[j][i] == 'J'){
                joueur[0]=j;
                joueur[1]=i;
                labyTab[j][i] = ' ';
            }
                
            if(j == joueur[0] && i == joueur[1] && joueur[0] != 0 && joueur[1] != 0)
                printf("J");
            else
                printf("%c", labyTab[j][i]);
        }
    }

    printf("\n");
}