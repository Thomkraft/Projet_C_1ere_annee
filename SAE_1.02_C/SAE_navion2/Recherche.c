/**
 * \file recherche_compagnie.c
 * \brief
 * \author Thomas K
 * \version 1.0
 * \date 30/11/23
*/

#include "main.h"

/**
 * \fn Fonction procdure Recherche_comp()
 * \brief recherche les vols contenant le nom de la compagnie voulue
 *
 * \author Thomas k
*/

void recherche_comp(struct Vols tabVols[],int nbvols,char name_compagnie[]) {
    int i;
    int j = 0;

    int heure = 1600;

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        if (strcmp(tabVols[i].compagnie, name_compagnie) == 0 && tabVols[i].fin_embarquement > heure) {

            printf("| %2d | %20s | %20s | %7d | %7d | %7d | %9d | %7d | %7d | %8d | %20s |\n",
            tabVols[i].numero,
            tabVols[i].compagnie,
            tabVols[i].destination,
            tabVols[i].num_comptoir,
            tabVols[i].debut_enregistrement,
            tabVols[i].fin_enregistrement,
            tabVols[i].salle_embarquement,
            tabVols[i].debut_embarquement,
            tabVols[i].fin_embarquement,
            tabVols[i].heure_decollage,
            tabVols[i].etat_vol
            );

            j++;

        }
    }

    if (j == 0) {
        printf("Il n'y a aucun Vols avec comme nom de compagnie : %s\n",name_compagnie);
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void recherche_dest(struct Vols tabVols[],int nbvols,char name_destination[]) {
    int i;
    int j = 0;

    int heure = 1600;


    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        // && tabVvols[i].fin_emarquement > heure 
        if (strcmp(tabVols[i].destination, name_destination) == 0 && tabVols[i].fin_embarquement > heure) {

            printf("| %2d | %20s | %20s | %7d | %7d | %7d | %9d | %7d | %7d | %8d | %20s |\n",
            tabVols[i].numero,
            tabVols[i].compagnie,
            tabVols[i].destination,
            tabVols[i].num_comptoir,
            tabVols[i].debut_enregistrement,
            tabVols[i].fin_enregistrement,
            tabVols[i].salle_embarquement,
            tabVols[i].debut_embarquement,
            tabVols[i].fin_embarquement,
            tabVols[i].heure_decollage,
            tabVols[i].etat_vol
            );

            j++;

        }
    }

    if (j == 0) {
        printf("Il n'y a aucun Vols avec comme nom de destination : %s\n",name_destination);
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

void recherche_heure_dec(struct Vols tabVols[],int nbvols,int heure_decollage) {
    int i;
    int j = 0;
    
    int heure = 0;
    printf("Affichage des vols qui décollent dans +- 30min de %d\n  ",heure_decollage);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        // && tabVvols[i].heure_decollage > heure 
        // peut etre modifié pour afficher autre que lheure exact jenre +15min pour voir les prochains aussi
        if (heure_decollage-30 < tabVols[i].heure_decollage &&  tabVols[i].heure_decollage < heure_decollage+30 && tabVols[i].fin_embarquement > heure) {

            printf("| %2d | %20s | %20s | %7d | %7d | %7d | %9d | %7d | %7d | %8d | %20s |\n",
            tabVols[i].numero,
            tabVols[i].compagnie,
            tabVols[i].destination,
            tabVols[i].num_comptoir,
            tabVols[i].debut_enregistrement,
            tabVols[i].fin_enregistrement,
            tabVols[i].salle_embarquement,
            tabVols[i].debut_embarquement,
            tabVols[i].fin_embarquement,
            tabVols[i].heure_decollage,
            tabVols[i].etat_vol
            );

            j++;

        }
    }

    if (j == 0) {
        printf("Il n'y a aucun Vols avec une heure de decollage a : %d\n",heure_decollage);
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

}
//
//
//
// Afficher les vols ect uniquement ceux apres lheure ?
// Faire des fonctions pour afficher ? pour pas a le réécrire a chaque fois
//
// pr la recherche ameliorer remplir un tableau avec les argument ( 3 max ) si tab [4] est remplie alors erreur
//