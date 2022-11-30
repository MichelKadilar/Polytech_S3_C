//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int main(void) {
    int x = 0;
    int cpt = 0;
    int max = x;
    int somme = 0;
    do {
        printf("Veuillez entrer un nombre entier : ");
        scanf("%d", &x);
        if (x >= 0) {
            if (x > max) {
                max = x;
            }
            cpt++;
            somme += x;
        }
    } while (x >= 0);
    printf("Le maximum des %d nombres positifs ou nuls saisis est %d. La somme de ces nombres est %d. \n", cpt, max,
           somme);
}