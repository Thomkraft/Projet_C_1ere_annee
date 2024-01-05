/**
 * \file main.c
 * \brief Gestion des vols commerciaux l'aeroport de Grenoble
 * \author Thomas K,Aurelien P, Guillaume F
 * \version 1.0
 * \date 30/11/23
*/

//Importation du fichier main.h qui contient toutes les declaration de variable
#include "main.h"



/**
 * \fn int main()
 * \brief Fonction principale du programme
 *
 * \author Thomas K,Guillaume F
*/
int main()
{

    //declaration des variable
    int nb_vols = 0;
    int choix_de_recherche;

    int choice;

    int buffer[256];


    int* pt_nb_vols = &nb_vols;
    
    //Definition du tableau de structure tabVols
    struct Vols tabVols[40];

    //Appel de la fonction procedur get_excel pour remplir le tableau de structure
    get_excl(tabVols,pt_nb_vols);


    //Boucle pour choisir l'option voulue
    do {

        //affiche les differents choix possibles
        printf("**********************************************\n");
        printf("* Choisissez votre option                    *\n");
        printf("**********************************************\n");
        printf("* 0. quitter                                 *\n");
        printf("* 1. Affichage Des informations sur les vols *\n");
        printf("* 2. Recherche d'un vol                      *\n");
        printf("* 3. Affichage de la liste des passagers     *\n");
        printf("* 4. Changement de l'heure                   *\n");
        printf("**********************************************\n");
        //printf("5. Gestion des retards / annulations des vols\n");
        //printf("6. Maximiser l'utilisation de la piste\n");

        //recupere le choix de l'utilisateur
        printf("\nVeuillez, s'il vous plait, saisir votre choix : ");

        // Lecture de la ligne d'entree
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Gestion d'une erreur de saisie
            choice = -1;  // Réinitialise choice si une valeur est non valide
        } else {
            // Convertit la saisie en un entier
            if (sscanf(buffer, "%d", &choice) != 1) {
                // Gestion d'une erreur de conversion
                choice = -1;  // R�initialise choice si une valeur est non valide
            }
        }

        //Liste les choix possible en fonction de la valeur de choice
        switch (choice)
        {
        case 0:
            printf("\nFin du programme\n\n");
            return 0;
        case 1:
            //fonction affichage
            break;
        case 2:
            printf("\n\n");

            recherche_panel(tabVols,nb_vols);
            break;
        case 3:
            //fonction d'affichge
            break;
        case 4:
            //fonction de changement d'heure
            break;

        default:
            printf("\nerreur de valeur merci de recommencer !\n\n");
            break;
        }

    //sort de la boucle si choice = 0
    } while (choice != 0);

    return 0;


}
