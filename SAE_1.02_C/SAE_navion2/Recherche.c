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

void recherche_comp(struct Vols tabVols[],int nbvols,char name_compagnie[],int heure) {

    //declaration des variable interne a la focntion
    int i;
    int j = 0;

    //Affichage de la banderole 
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Boucle pour tester chaque vols
    for(i=0;i<nbvols;i++) {

        //Condition si le nom de compagnie du vol corresspond au nom de compagnie voulue alors on affiche les info du vol
        // ( Heure de fin de débarquement dois etre supérieur a l'heure actuelle )
        if (strcmp(tabVols[i].compagnie, name_compagnie) == 0 && tabVols[i].fin_embarquement > heure) {

            //affiche les infos du vol
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

            //compte le nombre de vol qui sont affichés
            j++;

        }
    }

    //si aucun vol affiché alors mettre un message derreur
    if (j == 0) {
        printf("Il n'y a aucun Vols avec comme nom de compagnie : %s\n",name_compagnie);
    }

    //ferme le carré daffichage
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}

/**
 * \fn Fonction procdure Recherche_dest()
 * \brief recherche les vols contenant la destination voulue
 *
 * \author Thomas k
*/

void recherche_dest(struct Vols tabVols[],int nbvols,char name_destination[],int heure) {

    //declaration des variable interne a la focntion
    int i;
    int j = 0;

    //Affichage de la banderole 
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        //Condition si le nom de destination du vol corresspond au nom de destination voulue alors on affiche les info du vol
        // ( Heure de fin de débarquement dois etre supérieur a l'heure actuelle )
        if (strcmp(tabVols[i].destination, name_destination) == 0 && tabVols[i].fin_embarquement > heure) {

            //affiche les infos du vol
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

            //compte le nombre de vol qui sont affichés
            j++;

        }
    }

    //si aucun vol affiché alors mettre un message derreur
    if (j == 0) {
        printf("Il n'y a aucun Vols avec comme nom de destination : %s\n",name_destination);
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
}


/**
 * \fn Fonction procdure Recherche_heure_dec()
 * \brief recherche les vols contenant l'heure (+30min) de décollage voulue 
 *
 * \author Thomas k
*/

void recherche_heure_dec(struct Vols tabVols[],int nbvols,int heure_decollage,int heure) {

    //declaration des variable interne a la focntion
    int i;
    int j = 0;

    //Affichage de la banderole 
    printf("Affichage des vols qui décollent dans +- 30min de %d\n  ",heure_decollage);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<nbvols;i++) {

        //Condition si lheure de decollage est compris +-30 de l'heure de décollage voulue alors on affiche les infos des vols
        // ( Heure de fin de débarquement dois etre supérieur a l'heure actuelle )

        if (heure_decollage-30 < tabVols[i].heure_decollage &&  tabVols[i].heure_decollage < heure_decollage+30 && tabVols[i].fin_embarquement > heure) {

            //affiche les infos du vol
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

            //compte le nombre de vol qui sont affichés
            j++;

        }
    }

    //si aucun vol affiché alors mettre un message derreur
    if (j == 0) {
        printf("Il n'y a aucun Vols avec une heure de decollage a : %d\n",heure_decollage);
    }

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");

}

//
// pr la recherche ameliorer remplir un tableau avec les argument ( 3 max ) si tab [4] est remplie alors erreur
//