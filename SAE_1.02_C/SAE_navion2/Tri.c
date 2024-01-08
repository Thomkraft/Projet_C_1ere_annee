/**
 * \file Tri.c
 * \brief
 * \author Guillaume F
 * \version 1.0
 * \date 03/01/24
*/

#include "main.h"

/**
 * \fn Fonction procdure tri_fusion, interclassement()
 * \brief tri les vols par ordre de décollage
 *
 * \author Guillaume F
*/
// Fonction principale du tri fusion qui trie tab[l..r] en utilisant la fonction interclassement
void tri_fusion(struct Vols* tab[], int l, int r) {
    if (l < r) {
        // identifie le milieu du tableau
        int m = l + (r - l) / 2;

        // Trie la première et la deuxième moitié
        tri_fusion(tab, l, m);
        tri_fusion(tab, m + 1, r);

        // Fusionne les moitiés triées
        interclassement(tab, l, m, r);
    }
}

// Fonction de fusion pour le tri fusion (modifiée pour les structures Vols)
void interclassement(struct Vols* tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crée des tableaux temporaires
    struct Vols* L[n1];
    struct Vols* R[n2];

    // Copie les données dans les tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++)
        L[i] = tab[l + i];
    for (j = 0; j < n2; j++)
        R[j] = tab[m + 1 + j];

    // Fusionne les tableaux temporaires dans tab[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i]->heure_decollage <= R[j]->heure_decollage) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie les éléments restants de L[], s'il y en a
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    // Copie les éléments restants de R[], s'il y en a
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

/**
 * \fn Fonction procdure tri_fusion, interclassement() pour type Passager
 * \brief tri les passager par age
 *
 * \author Aurelien P
*/


void tri_fusionv2(struct Passager* tab[], int l, int r) {
    if (l < r) {
        // identifie le milieu du tableau
        int m = l + (r - l) / 2;

        // Trie la première et la deuxième moitié
        tri_fusionv2(tab, l, m);
        tri_fusionv2(tab, m + 1, r);

        // Fusionne les moitiés triées
        interclassementv2(tab, l, m, r);
    }
}

// Fonction de fusion pour le tri fusion (modifiée pour les structures Vols)
void interclassementv2(struct Passager* tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crée des tableaux temporaires
    struct Passager* L[n1];
    struct Passager* R[n2];

    // Copie les données dans les tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++)
        L[i] = tab[l + i];
    for (j = 0; j < n2; j++)
        R[j] = tab[m + 1 + j];

    // Fusionne les tableaux temporaires dans tab[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i]->date_naissance <= R[j]->date_naissance) {
            tab[k] = L[i];
            i++;
        } else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie les éléments restants de L[], s'il y en a
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    // Copie les éléments restants de R[], s'il y en a
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

