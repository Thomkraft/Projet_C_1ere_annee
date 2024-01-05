/**
 * \file main.u
 * \brief importation des diff�rentes fonctions
 * \author Thomas K,Aurelien P, Guillaume F
 * \version 1.0
 * \date 30/11/23
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_ELEMENT 10000


//D�finis les structure Vols et Passager

typedef struct Passager Passager;
typedef struct Vols Vols;


//D�finit les valeurs de la structure Passager
struct Passager {
    char nom[30];
    char prenom[30];

    char date_naissance[30];

    int num_siege;

    char prix[10];

};

//D�finit les valeurs de la structure Vols
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

    //Structure passager dans la structure Vols pour pouvoir diff�rencier un passager d'indice 1 suivant le vol
    //30 �tant le nombre maximum de passager pouvant etre dans le vol
    Passager Passager_vols[30];

};

//Declaration des differentes fonction du programme
void get_excl(struct Vols[],int*);
void recherche_comp(struct Vols[],int,char[]);
void recherche_dest(struct Vols[],int,char[]);
void recherche_heure_dec(struct Vols[],int,int);
void recherche_panel(struct Vols[],int);
void affichage_par_vol(struct Vols[] ,int);
