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



void get_excl();


int choice;

//Définis les structure Vols et Passager

typedef struct Passager Passager;
typedef struct Vols Vols;

//Définit les valeurs de la structure Vols
struct Vols{
    int numero;
    char* compagnie;
    char* destination;

    int num_comptoir;
    int debut_enregistrement;
    int fin_enregistrement;

    int salle_embarquement;
    int debut_embarquement;
    int fin_embarquement;

    int heure_decollage;
    char* etat_vol;
    char* liste_passager;

};

//Définit les valeurs de la structure Passager
struct Passager {
    char* nom;
    char* prenom;

    char* date_naissance;

    int num_siege;
    int prix;
};
