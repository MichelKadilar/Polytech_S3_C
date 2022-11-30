//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int main(void) {
    int x = 0;
    int cpt = 0;
    do {
        printf("Veuillez entrer un nombre entier : ");
        scanf("%d", &x);
        if (x >= 0) {
            cpt++;
        }
    } while (x >= 0);
    printf("Vous avez entré : %d nombres positifs ou nuls \n", cpt);
}