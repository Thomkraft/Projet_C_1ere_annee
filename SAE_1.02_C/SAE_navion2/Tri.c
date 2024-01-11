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
 * \brief tri les vols par ordre de d�collage
 *
 * \author Guillaume F
*/
// Fonction principale du tri fusion qui trie tab[l..r] en utilisant la fonction interclassement
void tri_fusion(struct Vols* tab[], int l, int r) {
    if (l < r) {
        // identifie le milieu du tableau
        int m = (l + r - 1) / 2;

        // Trie la premi�re et la deuxi�me moiti�
        tri_fusion(tab, l, m);
        printf("1 c good ");
        tri_fusion(tab, m + 1, r);
        printf("2 c good ");
        printf("l : %d  m : %d  r : %d ", l,m,r);

        // Fusionne les moiti�s tri�es
        interclassement(tab, l, m, r);
        printf("interclassement ok ");
    }
}

// Fonction de fusion pour le tri fusion (modifi�e pour les structures Vols)
void interclassement(struct Vols* tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l;
    int n2 = r - m;

    // Cr�e des tableaux temporaires
    struct Vols* L[n1];
    struct Vols* R[n2];

    // Copie les donn�es dans les tableaux temporaires L[] et R[]
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

    // Copie les �l�ments restants de L[], s'il y en a
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    // Copie les �l�ments restants de R[], s'il y en a
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

        // Trie la premi�re et la deuxi�me moiti�
        tri_fusionv2(tab, l, m);
        tri_fusionv2(tab, m + 1, r);

        // Fusionne les moiti�s tri�es
        interclassementv2(tab, l, m, r);
    }
}

// Fonction de fusion pour le tri fusion (modifi�e pour les structures Vols)
void interclassementv2(struct Passager* tab[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cr�e des tableaux temporaires
    struct Passager* L[n1];
    struct Passager* R[n2];

    // Copie les donn�es dans les tableaux temporaires L[] et R[]
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

    // Copie les �l�ments restants de L[], s'il y en a
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    // Copie les �l�ments restants de R[], s'il y en a
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}

void tri_selec(struct Passager tableau_passagers[],int nombre_passagers){

    int i=0;
    int j=0;
    int min = 0;
    struct Passager tmp;

    while(i < nombre_passagers-1) {
        min = i;
        j = i+1;

        while (j < nombre_passagers){
            if(tableau_passagers[j].prix < tableau_passagers[min].prix) {
                min = j;

            }
            j = j+1;
        }

        tmp = tableau_passagers[i];
        tableau_passagers[i] = tableau_passagers[min];
        tableau_passagers[min] = tmp;
        i = i+1;
        
    }

};
