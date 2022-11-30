//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

void inserer(int v, int tableau[10], int nb_elements_dans_tableau) {
    int indexInsertion = 0;
    for (int i = 0; i < nb_elements_dans_tableau; i++) {
        if (tableau[i] <= v) {
            indexInsertion++;
        }
    }
    for (int k = nb_elements_dans_tableau - 1; k >= indexInsertion; k--) {
        tableau[k + 1] = tableau[k];
    }
    tableau[indexInsertion] = v;
}

int main(void) {
    int v = -2;
    int tableau[10];
    int nb_elements_dans_tableau = 9;
    for (int i = 0; i < 9; i++) {
        tableau[i] = i;
    }
    inserer(v, tableau, nb_elements_dans_tableau);
    for (int i = 0; i < 10; i++) {
        printf("%d ", tableau[i]);
    }
}
