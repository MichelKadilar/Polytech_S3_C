//
// Created by Michel K on 03/10/2022.
//
#include <stdio.h>

int main(void) {
    int i = 0;
    int compteur = 0;
    while (i >= 0) {
        printf("saissiez un entier positif : ");
        scanf("%d", &i);
        if(i >= 0){
            compteur++;
        }
    }
    printf("Nombre d'entiers positifs : %d \n", compteur);
    return 0;
}
