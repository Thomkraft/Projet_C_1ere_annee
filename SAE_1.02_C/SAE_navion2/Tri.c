/**
 * \file Tri.c
 * \brief
 * \author Guillaume F
 * \version 1.0
 * \date 03/01/24
*/

#include "main.h"

/**
 * \fn Fonction procedure tri_insert ()
 * \brief tri les vols par ordre de d�collage
 *
 * \author Guillaume F
*/
// Fonction tri par insertion
void tri_insert(struct Vols* tab[], int n) {
    int i, j;
    struct Vols* k;

    //Parcours les éléments du tableau
    for (i = 1; i < n; i++) {
        k = tab[i];
        j = i - 1;
        //recherche du terme de l'occurence i
        while (j >= 0 && k->heure_decollage < tab[j]->heure_decollage) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }

        tab[j + 1] = k;
    }
}

/**
 * \fn Fonction procedure trix_prix_et_nom ()
 * \brief tri les passagers par leur prix de billet
 *
 * \author  Thomas k, Aurelien P
*/
//trie les passagers par ordre croissant sur le prix du billet
//si prix egale alors trie sur le nom
void tri_prix_et_nom(struct Passager *passagers, int nombre_passagers) {
    int i, j;
    struct Passager temp;

    for (i = 1; i < nombre_passagers; i++) {
        temp = passagers[i];
        j = i - 1;

        // Trie par prix et par nom en cas d'égalité de prix
        while (j >= 0 && (passagers[j].prix > temp.prix || (passagers[j].prix == temp.prix && strcmp(passagers[j].nom, temp.nom) > 0))) {
            passagers[j + 1] = passagers[j];
            j = j - 1;
        }

        passagers[j + 1] = temp;
    }
}
