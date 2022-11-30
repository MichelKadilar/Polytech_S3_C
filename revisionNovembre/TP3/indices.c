//
// Created by Michel K on 12/11/2022.
//
#define FAUX 0
#define VRAI 1

#include <stdio.h>

int indice(const char str[], const char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int indice_droite(const char str[], const char c) {
    int indice_dernier_trouve = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            indice_dernier_trouve = i;
        }
    }
    return indice_dernier_trouve;
}

int main(void) {
    printf("%d\n", indice("Test", 'T'));
    printf("%d\n", indice("Test", 't'));
    printf("%d\n", indice("Test", 'z'));
    printf("%d\n", indice("Tester", 'e'));
    printf("%d\n", indice_droite("Test", 'T'));
    printf("%d\n", indice_droite("Test", 't'));
    printf("%d\n", indice_droite("Test", 'z'));
    printf("%d\n", indice_droite("Tester", 'e'));
}