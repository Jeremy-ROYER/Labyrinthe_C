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
Date : 16/12/2020
File : labyrinthe.c

========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "affichage.h"


int main(){
    /* Déclaration nom du fichier */
    FILE* labyText;
    /* Coordonnées de la case de départ et d'arrivée */
    int depart[2];
    int arrivee[2];
    /* Initialisation tableau contenant le labyrinthe */
    char labyTab[TAILLE_X][TAILLE_Y];
    /* Difficulté du labyrinthe (renseigné par le joueur)*/
    int difficulte;

    char* en_tete = "-------------------------------------------------------------------------- \n"
                    "  ||      ||||  |||||| ||  || |||||| |||||| |||  || |||||| ||  || ||||||   \n"
                    "  ||     ||  || ||  ||  ||||  ||  ||   ||   |||| ||   ||   ||  || ||       \n"
                    "  ||     |||||| |||||    ||   ||||||   ||   || | ||   ||   |||||| ||||     \n"
                    "  ||     ||  || ||  ||  ||    || ||    ||   || ||||   ||   ||  || ||       \n"
                    "  |||||| ||  || |||||| ||     ||  || |||||| ||  |||   ||   ||  || ||||||   \n"
                    "-------------------------------------------------------------------------- \n\n";


    /* Présentation du jeu */
    printf("Bienvenue dans\n");
    printf("%s",en_tete);
    printf("Les règles sont simples, vous devez sortir du labyrinthe.\n");
    printf("Pour se déplacer utiliser les touches Z S Q D pour respectivement Haut Bas Gauche Droite (comme beaucoup de jeu)\n");
    printf("La sortie du labyrinthe se trouve au point A \n\n");

    printf("Choisissez la difficulté : (de 1 à 6)\n");
    scanf("%i",&difficulte);

    /* Ouverture du fichier correspondant à la difficulté */
    switch(difficulte){
        case 1 :
            printf("\nPetit joueur, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif1.txt","r");
            break;
        case 2 :
            printf("\nTu t'amélioreras, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif2.txt","r");
            break;
        case 3 :
            printf("\nCa va aller, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif3.txt","r");
            break;
        case 4 :
            printf("\nCa entretien, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif4.txt","r");
            break;
        case 5 :
            printf("\nCreuse toi un peu le crâne, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif5.txt","r");
            break;
        case 6 :
            printf("\nTu as du cran, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif6.txt","r");
            break;
    }


    if(construction(labyText,labyTab,depart,arrivee) ){
        /* Affiche le labyrinthe */
        afficheLabyrinthe(labyTab);
    }

    return EXIT_SUCCESS;
}