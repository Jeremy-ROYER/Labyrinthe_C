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
File : lecture.h

==========================================================================

Fichier contenant le prototype de la fonction de construction du 
labyrinthe

========================================================================*/

#ifndef __LECTURE_H__
#define __LECTURE_H__

#define TAILLE_X 20
#define TAILLE_Y 10

int construction(FILE* labyText, char labyTab[TAILLE_X][TAILLE_Y], int depart[2], int arrivee[2]);


#endif