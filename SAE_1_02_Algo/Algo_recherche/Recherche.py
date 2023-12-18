import random

#Création des tables
tab1_10 = []
tab2_10 = []
tab3_10 = []
tab4_10 = []
tab5_10 = []
tab6_10 = []
tab7_10 = []
tab8_10 = []
tab9_10 = []
tab10_10 = []

tab1_500 = []
tab2_500 = []
tab3_500 = []
tab4_500 = []
tab5_500 = []
tab6_500 = []
tab7_500 = []
tab8_500 = []
tab9_500 = []
tab10_500 = []

tab1_5000 = []
tab2_5000 = []
tab3_5000 = []
tab4_5000 = []
tab5_5000 = []
tab6_5000 = []
tab7_5000 = []
tab8_5000 = []
tab9_5000 = []
tab10_5000 = []

tab_10 = [tab1_10,tab2_10,tab3_10,tab4_10,tab5_10,tab6_10,tab7_10,tab8_10,tab9_10,tab10_10]
tab_500 = [tab1_500,tab2_500,tab3_500,tab4_500,tab5_500,tab6_500,tab7_500,tab8_500,tab9_500,tab10_500]
tab_5000 = [tab1_5000,tab2_5000,tab3_5000,tab4_5000,tab5_5000,tab6_5000,tab7_5000,tab8_5000,tab9_5000,tab10_5000]

#Insertion des valeurs dans les tables
i=0
while i < 10:
    j=0
    while j < 10:
        tab_10[j].append(random.randint(0,100))
        j = j+1
    i = i+1

i=0

while i < 500:
    j=0
    while j < 10:
        tab_500[j].append(random.randint(0,100))
        j = j+1
    i = i+1

i=0
while i < 5000:
    j=0
    while j < 10:
        tab_5000[j].append(random.randint(0,100))
        j = j+1
    i = i+1



#Meilleur algo pour trier un tableau
#tab 10 : 261.6
#tab 500 : 383 163.6
#tab 5000 : 37 589 478.0
def tri_selection(tab):
    compteur = 0
    i = 0
    j=0
    compteur = 2+compteur
    while i < len(tab) - 1:
        min = i
        j=i+1
        compteur=5+compteur
        while j < len(tab):
            compteur+=1
            if tab[j] < tab[min]:
                min = j 
                compteur=compteur+2
            j+=1
            compteur=2+compteur

        compteur=1+compteur
        tmp = tab[i]
        tab[i] = tab[min]
        tab[min] = tmp
        i = i + 1
        compteur =5+compteur

    compteur=1+compteur
    return compteur


#Algo pour rechercher un nom de compagnie ou la destination
#Recherche par dichotomie
#tab 10 : 21
#tab 500 : 63.6
#tab 5000 : 83.8
def recherche_dicho(tab:[int],e:int):
    compteur=0

    deb=0
    fin=len(tab)-1
    ind= -1

    compteur = 4 + compteur

    while deb < fin:
        millieu = (fin + deb) //2

        compteur = 4 + compteur

        if tab[millieu] < e:

            deb = millieu + 1
            compteur = 3 + compteur

        elif tab[millieu] > e:

            fin = millieu - 1
            compteur = 4 + compteur

        else:

            ind = millieu
            compteur = 3 + compteur
            return compteur
        
    compteur = 1 + compteur

    return compteur

#Recherche dicho récursive
#tab 10 :33.8
#tab 500 : 79.0
#tab 5000 : 100.2
def recherche_dicho_rec(tab,e):
    compteur = 0
    n=len(tab)
    millieu = n//2
    ind = 0

    compteur = compteur + 4

    if n == 0:
        ind = ind - 1

        compteur = compteur + 3
    else:
        compteur = compteur + 1

        if tab[millieu] == e:

            ind = millieu
            compteur = compteur + 2

        elif tab[millieu] > e:

            ind ,compteur_rec = recherche_dicho_rec(tab[:millieu],e)
            compteur = compteur + 3 + compteur_rec

        else:

            ind, compteur_rec = recherche_dicho_rec(tab[millieu+1:],e)
            compteur = compteur + 2 + compteur_rec

            if ind != -1:

                ind = ind + millieu + 1
                compteur = compteur + 4

            compteur = compteur + 1
    return ind,compteur



#Tri par recherche pour trouver l'indice de la premiere ocurence
#ou tri linéaire
#tab 10 : 55.0
#tab 500 : 571.0
#tab 5000 : 1 182.4
def recherche_prem_occ(tab:[int],e:int):
    compteur = 0
    n=len(tab)
    ind=0
    i=0
    compteur = compteur + 3
    while i < n and tab[ind] != e:

        ind = ind + 1
        i = i + 1
        compteur = compteur + 6

    compteur = compteur + 1
    return compteur


#Nombre d'occurence d'un term
#tab 10 : 42.0
#tab 500 : 2011.2
#tab 5000 : 20 098.2
def nbocc(tab:[int],e:int):
    compteur = 0
    i=0
    nb=0
    compteur = compteur + 2
    while i < len(tab):
        compteur = compteur + 1
        if e==tab[i]:
            nb = nb + 1
            compteur = compteur + 2
        i=i+1
        compteur = compteur + 3
    return compteur

#Nombre d'occurence de maniere récursive 
#tab 10 : 23.2
#tab 500 : 1011.6
#tab 5000 : renvoie une erreur car trop de répétition de récurrence
def nbocc_rec(tab:[int],e:int,i:int = 0,occ:int=0,compteur:int = 2):
    compteur = compteur + 1
    if i == len(tab):
        return occ,compteur
    compteur = compteur + 1
    if tab[i] == e:
        occ = occ + 1
        compteur = compteur + 2

    return nbocc_rec(tab,e,i+1,occ,compteur)

calcul = 0
i=0

while i < 10:
    occ, value = nbocc_rec(tab_10[i],50)
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 10 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    occ, value = nbocc_rec(tab_500[i],50)
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 500 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    occ, value = nbocc_rec(tab_5000[i],50)
    calcul = calcul + value
    i = i+1
    
print(f"La moyenne d'operation elementaire pour les tableaux a 5000 est de : {calcul/10}")
