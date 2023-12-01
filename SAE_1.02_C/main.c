/**
 * \file main.c
 * \brief Gestion des vols commerciaux l'aéroport de Grenoble
 * \author Thomas K,Aurelien P, Guillaume F
 * \version 1.0
 * \date 30/11/23
*/

//Importation du fichier main.h qui contient toutes les déclaration de variable
#include "main.h"
#include "fonction.c"
/**
 * \fn int main()
 * \brief Fonction principale du programme
 *
 * \author Thomas K,Guillaume F
*/
int main()
{


    get_excl();


    Passager passager[3];
    /*
    passager[0].prenom = "Thomas";
    passager[1].prenom = "Aurelien";
    passager[2].prenom = "Guillaume";

    for (int i =0;i != 3;i++) {
        printf("le prenom du passager %d est : %s \n",i,passager[i].prenom);
    }


    //Boucle pour choisir l'option voulue
    do {

        //affiche les différents choix possibles
        printf("0. quitter\n");
        printf("1. Affichage Des informations sur les vols\n");
        printf("2. Recherche d'un vol\n");
        printf("3. Affichage de la liste des passagers\n");
        printf("4. Gestion des retards / annulations des vols\n");
        printf("5. Maximiser l'utilisation de la piste\n");
        printf("6. Changement de l'heure\n");

        //recupère le choix de l'utilisateur
        printf("Veuillez, s'il vous plait, saisir votre choix : ");
        scanf("%d",&choice);

        //
        switch (choice)
        {
        case 0:
            printf("\nFin du programme\n");
            return 0;
        case 1:
            printf("test");
            break;

        default:
            printf("\nerreur de valeur merci de recommencer !\n");
            choice = 1;
            break;
        }

    } while (choice != 0);

    */
    return 0;

}


void get_excl() {

//  Vols Vols[5];

    char* nom_fichier="data_vols.csv";
    FILE* pointeur_de_fichier = NULL;
    char charactere_lu;
    int erreur = 0;
    int nb_ligne = 0;

    int i = 0;
    int j=1;

    char* tab[41][12];

    char tab3[4];
    tab3[0]='a';
    tab3[1]='b';
    printf("%s",tab3);
    char* test = tab3;
    printf("%s",test);

    pointeur_de_fichier = fopen(nom_fichier, "r");

    if (pointeur_de_fichier == NULL) {
        printf("\nL'ouverture du fichier en lecture du fichier %s a echoue. \n",nom_fichier);
    } else {

        do {

            charactere_lu = fgetc(pointeur_de_fichier);

            //calcul le nb de ligne du tableau
            if(charactere_lu =='\n') {
                nb_ligne++;
            }
            if(charactere_lu == ',') {
                charactere_lu = ' ';

                /*
                i=0;
                tab[1][1]= charactere_lu;
                printf("\ntest : %s",tab[1][1]);
                */
            }
            printf("%c",charactere_lu);
            i++;
        } while (charactere_lu != EOF && !erreur);

        printf("%d",erreur);
    

/*
        for (i=0;i<nb_ligne;i++) {
            Vols[i].numero = tab[i][1];
            Vols[i].compagnie = tab[i][2];
            Vols[i].destination = tab[i][3];
        }

*/
        fclose(pointeur_de_fichier);
    }
    
}

