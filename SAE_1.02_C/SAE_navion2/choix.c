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
 * \fn Fonction procedure Recherche_panel()
 * \brief affiche le panel de choix des différentes recherche possible
 *
 * \author Thomas k
*/

void recherche_panel(struct Vols tabVols[],int nb_vols,int heure) {

    //declaration des variables utilisées
    int choice;

    char compagnie[NB_ELEMENT];
    char destination[NB_ELEMENT];
    int heure_decollage;

    char buffer[256];

    //boucle pour afficher le message des différents choix de recherche
    do{
        //affiche les diff�rents choix possibles
        printf("**********************************************\n");
        printf("* Choisissez votre option De recherche       *\n");
        printf("**********************************************\n");
        printf("* 0. quitter (Retour au choix principal)     *\n");
        printf("* 1. Recherche par nom de compagnie          *\n");
        printf("* 2. Recherche par destination               *\n");
        printf("* 3. Recherche par heure de decollage        *\n");
        printf("**********************************************\n");

        printf("\nVeuillez, s'il vous plait, saisir votre choix : ");


        // Lecture de la ligne d'entree
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Gestion d'une erreur de saisie
            choice = -1;  // Reinitialise choice si une valeur est non valide
        } else {
            // Convertit la saisie en un entier
            if (sscanf(buffer, "%d", &choice) != 1) {
                // Gestion d'une erreur de conversion
                choice = -1;  // Reinitialise choice si une valeur est non valide
            }
        }

        printf("\n");

        //Liste les choix possible en fonction de la valeur de choice
        switch (choice)
        {
        case 0:
            printf("Retour au choix principal !\n\n");
            break;
        case 1:
            printf("Donner le nom de la compagnie que vous voulez rechercher : ");
            gets(compagnie);
            printf("\n");

            recherche_comp(tabVols,nb_vols,compagnie,heure);
            break;
        case 2:
            printf("Donner le nom de la destination que vous voulez rechercher : ");
            gets(destination);
            printf("\n");

            recherche_dest(tabVols,nb_vols,destination,heure);
            break;

        case 3:
            //verifie que lheure de décollage est bien de la bonne forme
            do{
                printf("Merci de donner l'heure de decollage du vol que vous voulez rechercher sous la forme hhmm (+- 30min) 0 pour quitter : ");

                if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                    // Gestion d'une erreur de saisie
                    printf("Erreur de saisis !\n");
                } else {
                    // Convertit la saisie en un entier
                    if (sscanf(buffer, "%d", &heure_decollage) != 1) {

                    // Gestion d'une erreur de conversion
                    printf("Erreur de saisis !\n");

                    } else {
                        //si tout est correct la fonction sexecute
                        if (heure_decollage != 0) {
                                                    
                            printf("\n");

                            recherche_heure_dec(tabVols,nb_vols,heure_decollage,heure);
                        }
                        printf("\n");
                        choice = -1;
                    }
                }
            //arret de la boucle des que choice !=3
            }while(choice == 3);


            break;

        default:
            printf("\nerreur de valeur merci de recommencer !\n\n");
            break;
        }
    //sort de la boucle daffichage et revien au premier affichage de main.c si choice = 0

    }while (choice != 0);
}



