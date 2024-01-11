/**
* \file affichage_vol.c
* \brief
* \author Guillaume F
* \version 1.0
* \date 02/01/24
*/

#include "main.h"

/**
* \fn Fonction procdure affichage_vol()
* \brief recherche les vols qui décollent dans les 3h
*
* \author Guillaume F
*/



void affichage_vol(struct Vols tabVols[], int nbvols, int heure) {
        //Déclaration des différentes variables du programme
        int i = 0;
        int j = 0;
        int k = 0;
        int retard = 0;
        int deb_emb_minutes;
        int fin_emb_minutes;
        int deb_enr_minutes;
        int fin_enr_minutes;


        // Déclaration d'un tableau de pointeurs de structures Vols
        struct Vols* tabvols_tri[100];

        for(i = 0; i < nbvols; i++) {
            // Trie les vols avec du retard, qui n'ont pas encore décollé et qui ont dépassé l'heure de décollage initial
            if (sscanf(tabVols[i].etat_vol, "Retarde (%d min)", &retard) != 0 &&
                tabVols[i].heure_decollage < heure &&
                tabVols[i].heure_decollage + retard > heure) {
                // Ajoute l'adresse du vol au tableau si la condition est satisfaite
                tabvols_tri[j] = &tabVols[i];
                j++;
            }

            // Trie des vols qui sont dans les 3h
            if (heure < tabVols[i].heure_decollage && tabVols[i].heure_decollage < heure + 300) {
                // Ajoute l'adresse du vol au tableau si la condition est satisfaite
                tabvols_tri[j] = &tabVols[i];
                j++;
            }
        }

        for(i=0; i<j-1; i++)
        {
            //Vérification si le tri est néccessaire
            if(tabvols_tri[i]->heure_decollage > tabvols_tri[i+1]->heure_decollage)
            {
            // Trie le tableau tabvols_tri en utilisant le tri fusion
            tri_insert(tabvols_tri, j);
            break;
            }
        }

        int tp_total_minute = convertisseur_minutes(heure);
        if (j != 0) {
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("| No |       Compagnie      |      Destination     | No comp | deb enr | fin enr | salle emb | deb emb | fin emb | Heur dec |       etat vols      |\n");
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for (i = 0; i != j; i++) {
                k = tabvols_tri[i] - tabVols;  // Calcule l'index original à partir du tableau tabVols
                //conversion des heures d'embarquement et d'enregistrement pour vérification
                deb_emb_minutes = convertisseur_minutes(tabVols[k].debut_embarquement);
                fin_emb_minutes = convertisseur_minutes(tabVols[k].fin_embarquement);
                deb_enr_minutes = convertisseur_minutes(tabVols[k].debut_enregistrement);
                fin_enr_minutes = convertisseur_minutes(tabVols[k].fin_enregistrement);


                       printf("| %2d | %20s | %20s |",
                       tabVols[k].numero,
                       tabVols[k].compagnie,
                       tabVols[k].destination);
                       //Vérification si on affiche les données sur l'enregistrement
                       if ((tp_total_minute >= (deb_enr_minutes - 30) && tp_total_minute <= (fin_enr_minutes + 10)))
                           {
                               printf(" %7d | %7d | %7d |",
                               tabVols[k].num_comptoir,
                               tabVols[k].debut_enregistrement,
                               tabVols[k].fin_enregistrement);
                           }
                           //Vérification si le temps pour l'affichage sur comptoire est dépassé
                           else if (tp_total_minute > (fin_emb_minutes + 10))
                           {
                               printf("    ferme|    ferme|    ferme|");
                           }
                           //affichage que le comptoire n'est pas encore défini
                           else
                           {
                                printf("    indef|    indef|    indef|");
                           }

                       //Vérification si on affiche les données sur l'embarcation
                       if ((tp_total_minute >= (deb_emb_minutes - 30) && tp_total_minute <= (fin_emb_minutes + 10)))
                           {

                               printf(" %9d | %7d | %7d |",
                               tabVols[k].salle_embarquement,
                               tabVols[k].debut_embarquement,
                               tabVols[k].fin_embarquement);
                           }
                           //Vérification si le temps pour l'affichage de l'enregistrement est dépassé
                           else if (tp_total_minute > (fin_emb_minutes + 10))
                                {
                                printf("      ferme|    ferme|    ferme|");
                                }
                            //affichage que l'embarcation n'est pas encore défini
                            else
                            {
                                printf("      indef|    indef|    indef|");
                            }

                       printf(" %8d | %20s |\n",
                       tabVols[k].heure_decollage,
                       tabVols[k].etat_vol);

                }
            }

            printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

        if (j == 0) {
            printf("\n-------------------------------------------------\n");
            printf("Il n'y a pas de vol dans les 3 prochaines heures");
            printf("\n-------------------------------------------------\n\n");
        }
}

