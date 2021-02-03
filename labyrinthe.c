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
#include "joueur.h"


int main(){
    /* Déclaration nom du fichier */
    FILE* labyText;
    /* Coordonnées de la case de départ et d'arrivée */
    int depart[2];
    int arrivee[2];
    /* Coordonnées du joueur */
    int joueur[2];
    /* Initialisation tableau contenant le labyrinthe */
    char labyTab[TAILLE_X][TAILLE_Y];
    /* Difficulté du labyrinthe (renseigné par le joueur)*/
    int difficulte;
    /* Valeur du renvoie de la fonction actionJoueur */
    int resAction = 0;

    char* en_tete = "-------------------------------------------------------------------------- \n"
                    "  ||      ||||  |||||| ||  || |||||| |||||| |||  || |||||| ||  || ||||||   \n"
                    "  ||     ||  || ||  ||  ||||  ||  ||   ||   |||| ||   ||   ||  || ||       \n"
                    "  ||     |||||| |||||    ||   ||||||   ||   || | ||   ||   |||||| ||||     \n"
                    "  ||     ||  || ||  ||  ||    || ||    ||   || ||||   ||   ||  || ||       \n"
                    "  |||||| ||  || |||||| ||     ||  || |||||| ||  |||   ||   ||  || ||||||   \n"
                    "-------------------------------------------------------------------------- \n\n";


    /* Présentation du jeu */
    printf("Bienvenue dans\n\n");
    printf("%s",en_tete);
    printf("Les règles sont simples, vous devez sortir du labyrinthe.\n");
    printf("Pour se déplacer utiliser les touches Z S Q D pour respectivement Haut Bas Gauche Droite (comme beaucoup de jeu)\n");
    printf("Ce sera répété si vous avez une petite mémoire.\n");
    printf("La sortie du labyrinthe se trouve au point A \n\n");

    printf("Choisissez la difficulté : (de 1 à 5)\n");
    printf("Tapez 6 si vous aviez sauvegardé une partie en cours\n");
    scanf("%i",&difficulte);

    /* Ouverture du fichier correspondant à la difficulté */
    switch(difficulte){
        case 1 :
            printf("\nPetit joueur, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif1.txt","r");
            break;
        case 2 :
            printf("\nTu t'amélioreras plus tard, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif2.txt","r");
            break;
        case 3 :
            printf("\nCa va aller tu te fatigues pas trop, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif3.txt","r");
            break;
        case 4 :
            printf("\nCa entretien un peu ta réflexion, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif4.txt","r");
            break;
        case 5 :
            printf("\nCreuse toi un peu la tête, bonne chance !\n\n\n");
            labyText = fopen ("laby_dif5.txt","r");
            break;
        case 6 :
            printf("\nN'abandonne pas comme la dernière fois, bonne chance !\n\n\n");
            labyText = fopen ("laby_sauv.txt","r");
            break;
    }

    printf("Vous êtes représenté par la lettre J.\n");

    /* Initialisation du labyrinthe et de l'affichage */
    /* Vérifie si le labyrinthe a bien été ouvert et construit */
    if(construction(labyText,labyTab,depart,arrivee) ){

        if(difficulte != 6){
            /* Initialisation position joueur */
            joueur[0] = depart[0];
            joueur[1] = depart[1];
        }

        /* Affiche le labyrinthe */
        afficheLabyrinthe(labyTab,joueur);

        while(resAction != 2){
            resAction = actionJoueur(labyTab,joueur);

            if(resAction == 1){
                afficheLabyrinthe(labyTab,joueur);
            }

            if( joueur[0] == arrivee[0] && joueur[1] == arrivee[1] ){
                printf("Bravo, vous y êtes arrivés !\n");
                printf("J'avoue que je doutais de vous.\n");
                if(difficulte < 5)
                    printf("J'espère vous revoir bientôt sur un niveau plus difficile, c'était un peu simple là !\n");
                else if(difficulte == 6)
                    printf("La prochaine fois faites le en une seule fois, trop simple de se reposer.\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}