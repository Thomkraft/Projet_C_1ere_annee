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
        int m = (l + r - 1) / 2;

        // Trie la première et la deuxième moitié
        tri_fusion(tab, l, m);
        printf("1 c good ");
        tri_fusion(tab, m + 1, r);
        printf("2 c good ");
        printf("l : %d  m : %d  r : %d ", l,m,r);

        // Fusionne les moitiés triées
        interclassement(tab, l, m, r);
        printf("interclassement ok ");
    }
}

// Fonction de fusion pour le tri fusion (modifiée pour les structures Vols)
void interclassement(struct Vols* tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l;
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
        int m = (l + r - 1) / 2;

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


void interclassement_prix(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
{
    int i = 0, j = 0, k = 0;

    // TODO enzo nom explicites et propres
    const int sizetab = nombre_passagersA + nombre_passagersB;
    // TODO enzo to test
    struct Passager tab_final[sizetab];
    //struct Passager *tab_final = (struct Passager *)malloc(sizetab * sizeof(struct Passager));

    while (i < nombre_passagersA && j < nombre_passagersB)
    {
        // TODO enzo tri du plus tot au plus tard et du plus cher au moins cher
       if ((tableau_passagersA[i].prix > tableau_passagersB[j].prix)
            || (tableau_passagersA[i].prix == tableau_passagersB[j].prix && tableau_passagersA[i].nom >= tableau_passagersB[j].nom))

        //if (tableau_passagersA[i].prix_billet >= tableau_passagersB[j].prix_billet)

        {
            tab_final[k] = tableau_passagersA[i];
            i++;
        }
        else
        {
            tab_final[k] = tableau_passagersB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_passagersA)
    {
        tab_final[k] = tableau_passagersA[i];
        i++;
        k++;
    }

    while (j < nombre_passagersB)
    {
        tab_final[k] = tableau_passagersB[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
        tableau_passagersA[i] = tab_final[i];
    }

    //free(tab_final);
}


void tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
{
    if (nombre_passagers > 1)
    {
        const int nombre_passagersA = nombre_passagers / 2;
        const int nombre_passagersB = nombre_passagers - nombre_passagersA;

        tri_prix(tableau_passagers, nombre_passagersA);
        tri_prix(tableau_passagers + nombre_passagersA, nombre_passagersB);

        interclassement_prix(tableau_passagers, nombre_passagersA, tableau_passagers + nombre_passagersA, nombre_passagersB);
    }
}
