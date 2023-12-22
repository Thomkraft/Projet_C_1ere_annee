/**
 * \file main.u
 * \brief importation des différentes fonctions
 * \author Thomas K,Aurelien P, Guillaume F
 * \version 1.0
 * \date 30/11/23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_ELEMENT 10000


int choice;

//Définis les structure Vols et Passager

typedef struct Passager Passager;
typedef struct Vols Vols;
typedef struct Informations Informations;



//Définit les valeurs de la structure Passager
struct Passager {
    char nom[30];
    char prenom[30];

    char date_naissance[30];

    int num_siege;

    char prix[10];

};

//Définit les valeurs de la structure Vols
struct Vols{
    int numero;
    char compagnie[30];
    char destination[30];

    int num_comptoir;
    int debut_enregistrement;
    int fin_enregistrement;

    int salle_embarquement;
    int debut_embarquement;
    int fin_embarquement;

    int heure_decollage;
    char etat_vol[30];

    int nombre_passagers;

    //Structure passager dans la structure Vols pour pouvoir différencier un passager d'indice 1 suivant le vol
    //30 étant le nombre maximum de passager pouvant etre dans le vol
    Passager Passager_vols[30];

};


void get_excl(struct Vols[],int*);
void recherche_comp(struct Vols[],int,char[]);
void recherche_panel(struct Vols[],int);
void affichage(struct Vols[],int);
void recherche_passa(struct Passager[],int,char[]);
