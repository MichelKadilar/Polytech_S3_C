//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>

int iterate(int (*f)(int i1, int i2), int tab[], int tailleTab) {
    if (tailleTab == 1) {
        return *tab;
    }
    int c = *tab;
    return f(c, iterate(f, ++tab, --tailleTab));
}

int max_element(int i1, int i2) {
    if (i1 > i2) {
        return i1;
    } else return i2;
}

int somme_element(int i1, int i2) {
    return i1 + i2;
}

int produit_element(int i1, int i2) {
    return i1 * i2;
}

int main(void) {
    int tab[] = {5, 4, 2, 3, 7, 9, 1, 6};
    printf("%d\n", iterate(max_element, tab, 8));
    printf("%d\n", iterate(somme_element, tab, 8));
    printf("%d\n", iterate(produit_element, tab, 8));
}