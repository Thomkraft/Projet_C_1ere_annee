/**
 * \file affichage_passager.c
 * \brief
 * \author Aurelien P, Thomas K
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
    int nb_dernier_vol;
    int i=0;
    int j = 0;
    int n=0;
    int nb_affiche = 0;
    int annee,jour,mois;

    int est_trie=0;

    int buffer[256];
    int lignes = -1;

    //recherche du numéro de vol le plus élevé
    nb_dernier_vol = max(tabVols, nbvols);

    //demande du numero de salle d'embarquement
    do{
        printf("Entrer le numero du vol : ");

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
    }while(vol_choisi < 0 || vol_choisi > nb_dernier_vol);

    //cherche la ligne du vol avec le numéro de vol choisi
    for(i=0;i<nbvols;i++){
        if(tabVols[i].numero == vol_choisi){
            lignes = i;
        }
    }

    //nombre de passager dans la variable j
    j = tabVols[lignes].nombre_passagers;
    // Lecture de la ligne d'entr�e

    //affichage
    printf("|------------|------------|------------|------------|\n");
    printf("|    Nom     |    Prenom  |     Prix   |    Prix    |\n");
    printf("|------------|------------|------------|------------|\n");

    if(est_trie == 0){
        for (i=0;i<nbvols;i++){
            tri_prix_et_nom(&tabVols[i].Passager_vols,tabVols[i].nombre_passagers);
        }
    }

    //regarde les vols 1 par 1 jusqu'a tomber sur le vol qui a le numéro de vols
    for(n=0;n<nbvols;n++){
        if (vol_choisi == tabVols[n].numero){
            for (i=0;i<j;i++){

                sscanf(tabVols[n].Passager_vols[i].date_naissance,"%d/%d/%d", &jour,&mois,&annee);

            //affichage des moins de 12 ans
                if(annee > 2012 && tabVols[n].Passager_vols[i].prix !=0){
                    nb_affiche++;
                    printf("| %10s | %10s | %10d | %7dans |\n",tabVols[n].Passager_vols[i].nom,tabVols[n].Passager_vols[i].prenom,tabVols[n].Passager_vols[i].prix,2024-annee);
                }
            }
        }
    }
    printf("|------------|------------|------------|------------|\n");

    for(n=0;n<nbvols;n++){
        if (vol_choisi == tabVols[n].numero){
            for (i=0;i<j;i++){

                sscanf(tabVols[n].Passager_vols[i].date_naissance,"%d/%d/%d", &jour,&mois,&annee);

            // affichage des autres passager
                if(annee < 2012 && tabVols[n].Passager_vols[i].prix !=0){
                    nb_affiche++;
                    printf("| %10s | %10s | %10d | %7dans |\n",tabVols[n].Passager_vols[i].nom,tabVols[n].Passager_vols[i].prenom,tabVols[n].Passager_vols[i].prix,2024-annee);
                }
            }
        }
    }

    if (nb_affiche == 0){
        printf("Il n'y a pas de passager dans ce vol !\n");
    }

    printf("-----------------------------------------------------\n");


}

//recherche du numéro du vol le plus haut
int max(struct Vols tabVols[],int nbvols)
{
    int max = tabVols[0].numero;
    int i = 0;

    for(i=0;i<nbvols;i++)
    {
        if(max < tabVols[i].numero)
        {
            max = tabVols[i].numero;
        }
    }
    return max;
}
