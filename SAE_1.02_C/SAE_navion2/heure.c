/**
 * \file heure.c
 * \brief
 * \author Guillaume F
 * \version 1.0
 * \date 30/12/23
*/

#include "main.h"

/**
 * \fn Fonction saisi_heure()
 * \brief Changer l'heure au format hhmm
 *
 * \author Guillaume F
*/

int saisi_heure(int h) {
    int heure, choice;
    char buffer[256];

    do {
        // Affiche les differents choix possibles
        printf("**********************************************\n");
        printf("* Choisissez votre option De recherche       *\n");
        printf("**********************************************\n");
        printf("* L'heure actuelle est de %d               *\n", h);
        printf("* 0. quitter (Retour au choix principal)     *\n");
        printf("* 1. changer l'heure actuelle                *\n");
        printf("**********************************************\n");

        printf("\nVeuillez, s'il vous plait, saisir votre choix : ");


        // Lecture de la ligne d'entree
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Gestion d'une erreur de saisie
            choice = -1;  // Reinitialise choice si une valeur est non valide
        } else {
            // Convertit la saisie en un entier
            if (sscanf(buffer, " %d", &choice) != 1) {
                // Gestion d'une erreur de conversion
                choice = -1;  // Reinitialise choice si une valeur est non valide
            }
        }

        switch (choice) {
            case 0:
                // Retourne l'heure actuelle si l'utilisateur choisit de quitter
                return h;
                break;
            case 1:
                // Utilisez la variable locale 'heure' pour stocker la nouvelle heure
                do {
                    printf("Veuillez saisir l'heure au format hhmm : ");
                    if (scanf("%d", &heure) != 1 || heure < 0 || heure > 2359 || heure % 100 >= 60) {

                        printf("Erreur : Saisie invalide. Veuillez reessayer.\n");
                        while (getchar() != '\n');
                    }
                    else {
                        // La saisie est valide, met a jour l'heure et sortie de la boucle
                        break;
                    }
                } while (heure != 1 || heure < 0 || heure > 2359 || heure % 100 >= 60);
                // Retourne la nouvelle heure a la fin de la saisie
                return heure;
            default:
                printf("Choix invalide ! Veuillez ressayer.\n");
        }



    } while (choice != 0 || choice !=1 );  // Continue la boucle principale si le choix n'est pas 0
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

