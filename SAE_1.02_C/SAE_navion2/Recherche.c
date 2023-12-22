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

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb |      etat vols       |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        if (strcmp(tabVols[i].compagnie, name_compagnie) == 0) {

            printf("| %2d | %20s | %20s | %7d | %7d | %7d | %9d | %7d | %7d | %20s |\n",
            tabVols[i].numero,
            tabVols[i].compagnie,
            tabVols[i].destination,
            tabVols[i].num_comptoir,
            tabVols[i].debut_enregistrement,
            tabVols[i].fin_enregistrement,
            tabVols[i].salle_embarquement,
            tabVols[i].debut_embarquement,
            tabVols[i].fin_embarquement,
            tabVols[i].etat_vol
            );

            j++;

        }
    }

    if (j == 0) {
        printf("Il n'y a aucun Vols avec comme nom de compagnie %s\n",name_compagnie);
    }

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}
