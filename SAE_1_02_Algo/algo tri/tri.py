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


#Algo pour trié (selection)
#tab 10 : 192.2
#tab 500 : 135 114.4
#tab 5000 : 12 562 505.0

def tri_par_selec(tab):
    compteur = 0

    i=0
    b=0
    temp=0
    n=len(tab)

    compteur= compteur + 4

    while i<n:
        b=i
        j=i+1
        compteur = compteur + 4
        while j<n:
            compteur = compteur + 1
            if tab[b]>tab[j]:
                b=j
                compteur =compteur +2
            j=j+1
        tab[b]=temp
        tab[b]=tab[i]
        tab[i]=temp
        i=i+1
        compteur = compteur + 8
        compteur = compteur + 1
    compteur = compteur + 1
    return compteur


#Algo pour trié (selection)
#tab 10 :
#tab 500 :
#tab 5000 :
def tri_insert(tab):
    compteur = 0
    l=len(tab)
    i=1
    compteur = compteur + 2
    while i<l:
        tri_insert(tab[:i+1],tab[i])
        i=i+1
        compteur = compteur + 4
    compteur = compteur + 1
    return compteur


#Algo pour trié (selection)
#tab 10 :
#tab 500 :
#tab 5000 :
def tri_a_bulles(tab):
    compteur = 0
    l=len(tab)-1
    tri=False
    compteur = compteur + 3

    while l>0 and tri==False:
        i=0
        Tri=True
        compteur = compteur + 5
        while i>l:
            compteur = compteur + 1
            if tab[i]>tab[i+1]:
                tmp=tab[i]
                tab[i]=tab[i+1]
                tab[i+1]=tmp
                tri=False
                compteur = compteur + 8
            i=i+1
            compteur = compteur + 2
        l=l-1
        compteur = compteur + 2
    comteur = compteur + 1


#Algo pour trié (selection)
#tab 10 :
#tab 500 :
#tab 5000 :
def insere_trie(tab,v):
    compteur = 0
    j=len(tab)-2
    compteur = compteur + 2
    while v<tab[j] and j>=0:
        tab[j]=tab[j+1]
        j=j-1
        compteur = compteur + 7 
    tab[j+1]=v
    compteur = compteur + 3
    return compteur


#Algo pour trié (selection)
#tab 10 :
#tab 500 :
#tab 5000 :
def interclassement(tab1,tab2,tab3):
    compteur = 0
    i,j,k=0
    taillei=len(tab1)
    taillej=len(tab2)
    compteur = compteur + 5
    while i<taillei and j<taillej:
        compteur = compteur + 3
        if tab1[i]<=tab2[j]:
            tab3[k]=tab1[i]
            i=i+1
            k=k+1
            compteur = compteur + 6 
        else :
            tab3[k]=tab2[j]
            j=j+1
            k=k+1
    compteur = compteur + 5
    return compteur


#Algo pour trié (selection)
#tab 10 :
#tab 500 :
#tab 5000 :
def tri_fusion(tab):
    compteur = 0
    n=len(tab)
    compteur = compteur +1
    if n>i:
        milieu = n/2
        tri_fusion(tab[:milieu])
        tri_fusion(tab[milieu:])
        tab3=empty(int,n)
        interclassement(tab[:milieu],tab[milieu:],tab3)
        copie(tab3,tab)
        compteur = 