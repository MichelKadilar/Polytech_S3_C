//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>

int carre(int i) {
    return i * i;
}

void map(int (*f)(int entier), int *tab, int tailleTab) {
    for (int i = 0; i < tailleTab; i++) {
        *tab = f(*tab);
        tab++;
    }
}

int print(int entier) {
    printf("%d\n", entier);
    return entier;
}

int main(void) {
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tailleTab = 10;
    map(carre, tab, tailleTab);
    map(print, tab, tailleTab);
}