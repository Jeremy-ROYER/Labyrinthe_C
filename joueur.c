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
Date : 28/12/2020
File : joueur.c

==========================================================================

Fichier contenant les fonctions relatives au joueur.
	- Déplacement : permet au joueur de se déplacer dans le labyrinthe.
	- Action : Permet au joueur de choisir de se déplacer ou mettre en 
			   pause le jeu ou de quitter en sauvegardant ou non.

========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "lecture.h"
#include "affichage.h"
#include "joueur.h"

/* Sauvegarde et quitte ou accède au déplacement en fonction de la touche appuyé */

/* La fonction renvoie 1 si le joueur a correctement jouer, 2 si le joueur a décidé d'arrêter sinon 0 */

int actionJoueur(char labyTab[TAILLE_X][TAILLE_Y], int joueur[2]){
	char actionChoisie;
	FILE* fichierSauvegarde;
	int positionfuture[2];

	printf("Veuillez choisir ce que vous voulez faire grâce aux touches suivante\n");
	printf("Déplacement : Z --> haut ; S --> bas ; Q --> gauche ; D --> droite\n");
	printf("Sauvegarder et Quitter : E\n");
	scanf(" %c",&actionChoisie);

	/* Le joueur souhaite se déplacer */

	if(actionChoisie == 'z' || actionChoisie == 'Z'){
		positionfuture[0] = joueur[0];
		positionfuture[1] = joueur[1]-1;

		/* Vérifie si le déplacement est autorisé */
		if(labyTab[ positionfuture[0] ][ positionfuture[1] ] == '#'){
			printf("Déplacement non autorisé, n'essayez pas de tricher !\n\n");
			return 0;
		}

		else{
			joueur[0] = positionfuture[0];
			joueur[1] = positionfuture[1];
		}
	}

	else if(actionChoisie == 's' || actionChoisie == 'S'){
		positionfuture[0] = joueur[0];
		positionfuture[1] = joueur[1]+1;

		/* Vérifie si le déplacement est autorisé */
		if(labyTab[ positionfuture[0] ][ positionfuture[1] ] == '#'){
			printf("Déplacement non autorisé, n'essayez pas de tricher !\n");
			return 0;
		}

		else{
			joueur[0] = positionfuture[0];
			joueur[1] = positionfuture[1];
		}
	}

	else if(actionChoisie == 'q' || actionChoisie == 'Q'){
		positionfuture[0] = joueur[0]-1;
		positionfuture[1] = joueur[1];

		/* Vérifie si le déplacement est autorisé */
		if(labyTab[ positionfuture[0] ][ positionfuture[1] ] == '#'){
			printf("Déplacement non autorisé, n'essayez pas de tricher !\n");
			return 0;
		}

		else{
			joueur[0] = positionfuture[0];
			joueur[1] = positionfuture[1];
		}
	}

	else if(actionChoisie == 'd' || actionChoisie == 'D'){
		positionfuture[0] = joueur[0]+1;
		positionfuture[1] = joueur[1];

		/* Vérifie si le déplacement est autorisé */
		if(labyTab[ positionfuture[0] ][ positionfuture[1] ] == '#'){
			printf("Déplacement non autorisé, n'essayez pas de tricher !\n");
			return 0;
		}

		else{
			joueur[0] = positionfuture[0];
			joueur[1] = positionfuture[1];
		}
	}

	/* Le joueur souhaite sauvegarder et quitter le jeu */
	else if(actionChoisie == 'e' || actionChoisie == 'E'){
		fichierSauvegarde = fopen("laby_sauv.txt","w");

		/* Vérifie que le fichier a bien été ouvert à l'écriture */
		if(fichierSauvegarde == NULL){
			printf("Erreur avec le fichier de Sauvegarde\n");
			return 0;
		}

		/* Ecris le tableau labyTab dans le fichier de sauvegarde */
		else{
			for (int i = 0; i < TAILLE_Y; i++){
        		for (int j = 0; j < TAILLE_X; j++){
        			if(j == joueur[0] && i == joueur[1])
        				fprintf(fichierSauvegarde, "%c", 'J');
        			else
        				fprintf(fichierSauvegarde, "%c", labyTab[j][i]);
       			}
    		}
    		return 2;
		}
	}

	else{
		printf("Veuillez choisir une des réponses proposées, cinq lettres possibles ça devrait aller.\n\n");
		return 0;
	}

	return 1;
}