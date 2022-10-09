//
// Created by Michel K on 03/10/2022.
//
#include <stdio.h>

int main(void) {
    char c;
    int nbLignes = 1;
    int nbMots = 0;
    int nbCar = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            nbLignes++;
            nbMots++;
        }
        if (c == '\t' || c == ' ') {
            nbMots++;
        }
        if (c != '\n' && c != '\t' && c != ' ') {
            nbCar++;
        }
    }
    printf("Nombre de caractères : %d \n", nbCar);
    printf("Nombre de mots : %d \n", nbMots);
    printf("Nombre de lignes : %d \n", nbLignes);
    return 0;
}
