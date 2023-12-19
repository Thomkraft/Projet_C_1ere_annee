/**
 * \file main.c
 * \brief Gestion des vols commerciaux l'aéroport de Grenoble
 * \author Thomas K,Aurelien P, Guillaume F
 * \version 1.0
 * \date 30/11/23
*/

//Importation du fichier main.h qui contient toutes les déclaration de variable
#include "main.h"
#include "structure.c"

/**
 * \fn int main()
 * \brief Fonction principale du programme
 *
 * \author Thomas K,Guillaume F
*/
int main()
{

    //déclaration des variable
    int nb_vols = 0;

    int* pt_nb_vols = &nb_vols;

    struct Vols tabVols[40];

    //Appel de la fonction procédur get_excel pour remplir le tableau de structure
    get_excl(tabVols,pt_nb_vols);
    affichage(tabVols,nb_vols);
    

    /*

    //Boucle pour choisir l'option voulue
    do {

        //affiche les différents choix possibles
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

        //recupère le choix de l'utilisateur
        printf("\nVeuillez, s'il vous plait, saisir votre choix : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            printf("\nFin du programme\n");
            return 0;
        case 1:
            printf("test\n");
            break;

        default:
            printf("\nerreur de valeur merci de recommencer !\n");
            break;
        }


    } while (choice != 0);
    */

    return 0;

}
