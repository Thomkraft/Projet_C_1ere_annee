/**
 * \file structure.c
 * \brief fichier pour r�cuperer les donn�e de l'excel
 * \author Thomas K
 * \version 1.0
 * \date 30/11/23
*/

#include "main.h"

/**
 * \fn fonction proc�dur : void get_excel()
 * \brief recupere les valeurs du fichier .csv et les met dans un tableau de structure
 *
 * \author Thomas k
*/



//d�claration de la fonction proc�dure
void get_excl(struct Vols tabVols[],int* nb_vols) {

    //d�finition des diff�rentes variables et pointeur
    char* nom_fichier="./data_vols.csv";
    FILE* pointeur_de_fichier = NULL;
    char * charactere_lu;


    int nb_ligne = 0;
    int i;

    char contenue[NB_ELEMENT];

    //D�finition deu tableau de structure tabVols

    char liste_passager_all[400][500];

    //int ligne d�finis a -1 pour sauter la 1ere ligne du tableau et rester a l'indice 0 pour les 1ere valeurs
    int lignes = 0;
    int collonnes = 0;

    //ouverture du chier data_vols.csv
    pointeur_de_fichier = fopen(nom_fichier, "r");

    //V�rification si erreur lors de l'ouverture du fichier
    if (pointeur_de_fichier == NULL) {
        printf("\nL'ouverture du fichier en lecture du fichier %s a echoue. \n",nom_fichier);
    } else {

        //Saute la 1ere ligne du fichier pour eviter de remplir notre structure avec les nom des collonnes
        if (fgets(contenue,sizeof(contenue),pointeur_de_fichier) == NULL) {
            printf("Erreur lors de l'ouverture du fichier");
        } else {

            //Boucle pour lire chaque ligne une par une
            while (fgets(contenue,sizeof(contenue),pointeur_de_fichier) != NULL){

                //condition pour sauter la 1ere ligne du fichier

                //S�pare la ligne par les ',' et les diff�rents passagers par '"'
                sscanf(contenue,"%d,%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],\"%[^\"]",
                //remplie les information du vol a la ligne X
                &tabVols[lignes].numero,
                tabVols[lignes].compagnie,
                tabVols[lignes].destination,
                &tabVols[lignes].num_comptoir,
                &tabVols[lignes].debut_enregistrement,
                &tabVols[lignes].fin_enregistrement,
                &tabVols[lignes].salle_embarquement,
                &tabVols[lignes].debut_embarquement,
                &tabVols[lignes].fin_embarquement,
                &tabVols[lignes].heure_decollage,
                tabVols[lignes].etat_vol,

                //remplie la liste des passagers pour la ligne X
                &liste_passager_all[lignes]

                );

                //R�cupere la liste des passagers de la ligne X et la coupe par les ';'
                //Pour obtenir les informations de chaque passager s�parement
                char *passagerToken = strtok(liste_passager_all[lignes],";");

                //Permet de compter le nombre de passager pour le vol
                tabVols[lignes].nombre_passagers = 0;

                //Boucle pour remplir la structure passager du vol X
                while (passagerToken != NULL) {

                    //Coupe les informations d'un passager
                    sscanf(passagerToken, "%[^,],%[^,],%[^,],%d,%s",

                    //stock dans la structure passager les information du passager Y pour le vol X
                    //Car il y a plusieur passager pour le vol X
                    //grace a cela plusieurs passager peuvent avoir l'indice 0 ou 1 ect car ils d�pendent �galement su num�ro du vol
                    tabVols[lignes].Passager_vols[tabVols[lignes].nombre_passagers].nom,
                    tabVols[lignes].Passager_vols[tabVols[lignes].nombre_passagers].prenom,
                    tabVols[lignes].Passager_vols[tabVols[lignes].nombre_passagers].date_naissance,
                    &tabVols[lignes].Passager_vols[tabVols[lignes].nombre_passagers].num_siege,
                    &tabVols[lignes].Passager_vols[tabVols[lignes].nombre_passagers].prix);

                    //augmente de 1 le nombre de passager du vol X
                    tabVols[lignes].nombre_passagers++;

                    //passe au passager suivant
                    passagerToken = strtok(NULL, ";");
                }



                //passe a la ligne suivante
                lignes++;
                (*nb_vols)++;

            //recommence la boucle
            }
        }

        //ferme le fichier
        fclose(pointeur_de_fichier);
    }

}
