/**
 * \file affichage_passager.c
 * \brief
 * \author Aurelien P
 * \version 1.0
 * \date 02/01/24
*/

#include "main.h"

/**
 * \fn Fonction procedure affichage_passager()
 * \brief affiche les listes de passager par terminaux
 *
 * \author Aurelien P
*/

void affichage_passager(struct Vols tabVols[],int nbvols,int heure){
    //Declaration de mes variables
    int salle_emb;
    int i,j,num_vols,nb_passa,taille;

    //demande du numero de salle d'embarquement
    do{
    printf("Entrer le numero de salle d'embarquement : ");
    scanf("%d",&salle_emb);
    }while(salle_emb < 0  && salle_emb > 6);

    //declaration d'un tableau de pointeur des vols effectuant leurs embarquements dans la salle demandé
    struct Vols* tabvols_salles[100];
    //declaration d'un tableau de pointeur des vols effectuant leurs embarquements dans la salle demandé
    struct Vols* tabvols_passa[100];

    //tri des vols en fonction de leurs salle d'embarquement
    for (i=0;i<nbvols;i++)
    {
        j=0;
        if(tabVols[i].salle_embarquement == salle_emb)
        {
            tabvols_salles[j] = &tabVols[i];
            j++;
        }
    }

    i=0;

    //tri des vols en fonction de l'heure
    tri_fusion(tabvols_salles,0,j+1);




//recherche du prochain vol à embarquer
    for(i=0;i<j;i++)
    {
        if(heure<=tabvols_salles[i]->debut_embarquement && heure>tabvols_salles[i+1]->debut_embarquement)
        {
            num_vols = tabvols_salles[i+1]->numero;
        }
    }

    i=0;
    j=0;

    for (i=0;i<nbvols;i++)
    {
        if (tabVols[i].numero = num_vols)
        {
            tabvols_passa[j] = tabVols[i].Passager_vols;
        }
    }
    taille = strlen(tabvols_passa);

    //tri des passager du vols par date de naissance
    tri_fusion(tabvols_passa,0,taille-1);


    //affichage
    printf("|----------------------------------------------------------------------------------|\n");
    printf("|Nom|Prenom|\n");
    printf("|----------------------------------------------------------------------------------|\n");

    for (i=0)
}
