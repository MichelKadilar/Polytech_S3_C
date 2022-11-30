//
// Created by Michel K on 03/10/2022.
//
#include <stdio.h>

int main(void) {
    int i = 0;
    int compteur = 0;
    int plusGrandEntierPositif = 0;
    int sommeEntiersPositifs = 0;
    while (i >= 0) {
        printf("saissiez un entier positif : ");
        scanf("%d", &i);
        if(i >= 0){
            compteur++;
            sommeEntiersPositifs += i;
        }
        if(i > plusGrandEntierPositif){
            plusGrandEntierPositif = i;
        }
    }
    printf("Nombre d'entiers positifs : %d \n", compteur);
    printf("Le maximum des %d nombres positifs saisis est %d . La somme est %d. \n", compteur, plusGrandEntierPositif, sommeEntiersPositifs);
    return 0;
}
