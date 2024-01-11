/**
 * \file affichage_passager.c
 * \brief
 * \author Aurelien P, Thomas K, Guillaume F
 * \version 1.0
 * \date 02/01/24
*/

#include "main.h"

/**
 * \fn Fonction procedure affichage_passager()
 * \brief affiche les listes de passager par terminaux
 *
 * \author Aurelien P, Thomas K
*/

void affichage_passager(struct Vols tabVols[],int nbvols,int heure){
    //Declaration de mes variables
    int vol_choisi;
    int i=0;
    int j = 0;
    int n=0;
    int nb_affiche = 0;
    int annee,jour,mois;

    int buffer[256];

    //demande du numero de salle d'embarquement
    do{
        printf("Entrer le numero du vol : ");
      //  scanf("%d",&vol_choisi);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        // Gestion d'une erreur de saisie
        vol_choisi = -1;  // R�initialise choice � une valeur non valide
        } else {
            // Convertit la saisie en un entiers
            if (sscanf(buffer, "%d", &vol_choisi) != 1) {
                // Gestion d'une erreur de conversion
                vol_choisi = -1;  // R�initialise choice � une valeur non valide
            }
        }
    }while(vol_choisi < 0 || vol_choisi > nbvols);

    j = tabVols[vol_choisi-1].nombre_passagers;

    // Lecture de la ligne d'entr�e

    //printf("%d",tabVols[vol_choisi-1].nombre_passagers);
    //affichage
    printf("|------------|------------|------------|------------|\n");
    printf("|    Nom     |    Prenom  |     Prix   |    Prix    |\n");
    printf("|------------|------------|------------|------------|\n");

    //tri_selec(tabVols[vol_choisi-1].Passager_vols,tabVols[vol_choisi-1].nombre_passagers);

    for(n=0;n<nbvols;n++){
        if (vol_choisi == tabVols[n].numero){
            for (i=0;i<j;i++){

                sscanf(tabVols[n].Passager_vols[i].date_naissance,"%d/%d/%d", &jour,&mois,&annee);

                if(annee > 2012){
                    nb_affiche++;
                    printf("| %10s | %10s | %10s | %7dans |\n",tabVols[n].Passager_vols[i].nom,tabVols[n].Passager_vols[i].prenom,tabVols[n].Passager_vols[i].prix,2024-annee);
                }
            }
        }
    }
    printf("|------------|------------|------------|------------|\n");

    for(n=0;n<nbvols;n++){
        if (vol_choisi == tabVols[n].numero){
            for (i=0;i<j;i++){

                sscanf(tabVols[n].Passager_vols[i].date_naissance,"%d/%d/%d", &jour,&mois,&annee);

                if(annee < 2012){
                    nb_affiche++;
                    printf("| %10s | %10s | %10s | %7dans |\n",tabVols[n].Passager_vols[i].nom,tabVols[n].Passager_vols[i].prenom,tabVols[n].Passager_vols[i].prix,2024-annee);
                }
            }
        }
    }

    printf("-----------------------------------------------------\n");


}
