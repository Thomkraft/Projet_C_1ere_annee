import random


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


#Algo pour trier (selection)
#tab 10 : 218.4
#tab 500 : 373 674.0
#tab 5000 : 37 240 611.6
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

#Algo de tri fusion ainsi que l'interclassement réunis
#tab 10 : 356.4
#tab 500 : 35 275.2
#tab 5000 : 454 171.2
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


calcul = 0
i=0

while i < 10:
    _,value = tri_fusion(tab_10[i])
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 10 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    _,value = tri_fusion(tab_500[i])
    calcul = calcul + value
    i = i+1
print(f"La moyenne d'operation elementaire pour les tableaux a 500 est de : {calcul/10}")

calcul = 0
i = 0
while i < 10:
    _,value = tri_fusion(tab_5000[i])
    calcul = calcul + value
    i = i+1
    
print(f"La moyenne d'operation elementaire pour les tableaux a 5000 est de : {calcul/10}")

