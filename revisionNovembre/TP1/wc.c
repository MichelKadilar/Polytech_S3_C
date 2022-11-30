//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int main(void) {
    char c;
    int nb_chars = 0;
    int nb_mots = 0;
    int nb_lignes = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            nb_mots++;
        }
        if (c == '\n') {
            nb_mots++;
            nb_lignes++;
        }
        nb_chars++;
    }
    printf("Nombre mots : %d\n", nb_mots);
    printf("Nombre lignes : %d\n", nb_lignes);
    printf("Nombre chars : %d\n", nb_chars);
}