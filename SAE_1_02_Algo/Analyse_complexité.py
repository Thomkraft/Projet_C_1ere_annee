import random

#Création des tables
#Thomas k
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
#Thomas K
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

#On supoera que tout les algo de recherche prennent en parametre un tableau deja trié pour
#calculer uniquement la compléxité de lalgo de recherche et non recherche + trie


#algo de trie par selection
#tab 10 : 261.6
#tab 500 : 383 163.6
#tab 5000 : 37 589 478.0
#Guillaume / Aurelien
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


#Algo pour trier (selection)
#tab 10 : 218.4
#tab 500 : 373 674.0
#tab 5000 : 37 240 611.6
#Guillaume / Aurelien
def tri_insert(tab):
    compteur = 0
    n=len(tab)
    i=1
    compteur = compteur + 2
    while i<n:

        k = tab[i]
        j = i - 1
        compteur = compteur + 4
        while j >= 0 and k < tab[j]:
            
            tab[j+1] = tab[j]
            j=j-1
            compteur = compteur + 6
        compteur = compteur + 1
        tab[j+1] = k
        i = i+1
        compteur = compteur + 4
    compteur = compteur + 1
    return compteur

#Algo pour trier (a bulles)
#tab 10 : 356.8
#tab 500 : 1 055 814.7
#tab 5000 : 94 706 849.8
#Guillaume / Aurelien
def tri_a_bulles(tab):
    compteur = 0
    n=len(tab)-1
    compteur = compteur + 2

    while n>0:
        i=0
        compteur = compteur + 2
        while i<n:
            compteur = compteur + 1
            if tab[i]>tab[i+1]:
                tmp=tab[i]
                tab[i]=tab[i+1]
                tab[i+1]=tmp
                compteur = compteur + 7
            i=i+1
            compteur = compteur + 3
        n=n-1
        compteur = compteur + 3
    compteur = compteur + 1
    return compteur

def interclassement(tab1, tab2, tab3):
    compteur = 0
    i, j, k = 0, 0, 0
    taillei, taillej = len(tab1), len(tab2)

    compteur = compteur + 8

    while i < taillei and j < taillej:
        compteur = compteur + 1
        if tab1[i] <= tab2[j]:
            tab3[k] = tab1[i]
            i = i + 1
            compteur = compteur + 3
        else:
            tab3[k] = tab2[j]
            j = j + 1
            compteur = compteur + 3
        k = k + 1
        compteur = compteur + 2

    compteur = compteur + 1
    while i < taillei:
        tab3[k] = tab1[i]
        i = i + 1
        k = k + 1
        compteur = compteur + 5

    compteur = compteur + 1
    while j < taillej:
        tab3[k] = tab2[j]
        j = j + 1
        k = k + 1
        compteur = compteur + 5

    return compteur

#Algo de tri fusion ainsi que l'interclassement réunis ( meilleur algo de trie )
#tab 10 : 356.4
#tab 500 : 35 275.2
#tab 5000 : 454 171.2
# Guillaume / Aurelien / Thomas k
def tri_fusion(tab):
    compteur = 0
    n = len(tab)
    compteur = compteur + 2
    if n > 1:
        millieu = n // 2

        tab1 = tab[:millieu]
        tab2 = tab[millieu:]
        compteur = compteur + 4

        tab1,compteur_rec = tri_fusion(tab1)
        compteur = compteur + compteur_rec
        tab2, compteur_rec = tri_fusion(tab2)
        compteur = compteur + compteur_rec

        compteur_rec = interclassement(tab1, tab2, tab)
        compteur = compteur + compteur_rec

    return tab,compteur

#Algo pour rechercher un nom de compagnie ou la destination
#Recherche par dichotomie
#tab 10 : 21
#tab 500 : 55.1
#tab 5000 : 56.7
#Thomas k
def recherche_dicho(tab:[int],e:int):
    compteur=0

    deb=0
    fin=len(tab)-1
    ind= -1

    compteur = 4 + compteur

    while deb <= fin:
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
            return ind,compteur
        
    compteur = 1 + compteur

    return ind,compteur

#Recherche dicho récursive
#tab 10 :31.0
#tab 500 : 75.4
#tab 5000 : 80
#Thomas k 
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
#tab 10 : 60.0
#tab 500 : 2969.8
#tab 5000 : 29 690.8
#Thomas k
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
#Thomas k
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
#tab 500 : 1009.8
#tab 5000 : renvoie une erreur car trop de répétition de récurrence
#Thomas K
def nbocc_rec(tab:[int],e:int,i:int = 0,occ:int=0,compteur:int = 2):
    compteur = compteur + 1
    if i == len(tab):
        return occ,compteur
    compteur = compteur + 1
    if tab[i] == e:
        occ = occ + 1
        compteur = compteur + 2

    return nbocc_rec(tab,e,i+1,occ,compteur)

#On trie tous les tableaux
#Thomas / Aurelien
i=0
while i < 10:
    tab_10[i],_ = tri_fusion(tab_10[i])
    tab_500[i],_ = tri_fusion(tab_500[i])
    tab_5000[i],_ = tri_fusion(tab_5000[i])
    i=i+1


#Nous allons supposer prendre la derniere valeur possible a trouver dans un tableau trié pour calculer la
#moyenne du nombre maximum dopération élémentaire dans notre cas la valeur max possible est 100
#Thomas / Aurelien / Guillaume  
calcul = 0
i=0

#Pour modifier l'algorythme que vous shouaitez tester il suffit de modifier le nom de la fonction deja présente 

#si cette fonction ne renvoie que 1 parametre alors 
#la forme dois etre de value = fonction()

#si cette fonction renvoie 2 valeur elle doit etre de la forme
# occ, value = fonction()
while i < 10:
    occ, value = recherche_dicho(tab_10[i],100)
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 10 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    occ, value = recherche_dicho(tab_500[i],100)
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 500 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    occ, value = recherche_dicho(tab_5000[i],100)
    calcul = calcul + value
    i = i+1
    
print(f"La moyenne d'operation elementaire pour les tableaux a 5000 est de : {calcul/10}")
