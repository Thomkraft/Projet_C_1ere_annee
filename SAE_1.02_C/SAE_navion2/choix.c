//fonction de choix des menu
//menu de base
//menu secondaire choix des recherches

/**
 * \file choix.c
 * \brief
 * \author Thomas K
 * \version 1.0
 * \date 30/11/23
*/

#include "main.h"

/**
 * \fn Fonction procédure Recherche_comp()
 * \brief recherche les vols contenant le nom de la compagnie voulue
 *
 * \author Thomas k,Guillaume F
*/

void recherche_panel(struct Vols tabVols[],int nb_vols) {
    int choice;
    int result;

    char value[NB_ELEMENT];

    char buffer[256];

    do{
        //affiche les différents choix possibles
        printf("**********************************************\n");
        printf("* Choisissez votre option De recherche       *\n");
        printf("**********************************************\n");
        printf("* 0. quitter (Retour au choix principal)     *\n");
        printf("* 1. Recherche par nom de compagnie          *\n");
        printf("* 2. Recherche par destination               *\n");
        printf("* 3. Recherche par heure de decollage        *\n");
        printf("**********************************************\n");

        printf("\nVeuillez, s'il vous plait, saisir votre choix : ");


        // Lecture de la ligne d'entrée
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Gestion d'une erreur de saisie
            choice = -1;  // Réinitialise choice à une valeur non valide
        } else {
            // Convertit la saisie en un entier
            if (sscanf(buffer, "%d", &choice) != 1) {
                // Gestion d'une erreur de conversion
                choice = -1;  // Réinitialise choice à une valeur non valide
            }
        }
        printf("\n");
        switch (choice)
        {
        case 0:
            printf("Retour au choix principal !\n\n");
            break;
        case 1:
            printf("Donner le nom de la compagnie que vous voulez rechercher : ");
           // scanf("%s",&value);
            gets(value);
            printf("\n");

            recherche_comp(tabVols,nb_vols,value);
            break;
        case 2:
            //fonction par destination
            break;
        case 3:
            //fonction par heure de decollage
            break;

        default:
            printf("\nerreur de valeur merci de recommencer !\n\n");
            break;
        }


    }while (choice != 0);
}



