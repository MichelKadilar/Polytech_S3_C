//
// Created by Michel K on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>

void insertionDansTableau(int **tableau, int tailleTableau,
                          int valeurAInserer) {
    int *tableau2 = (int *) calloc((tailleTableau + 1), sizeof(int));
    for (int i = 0; i < tailleTableau; i++) {
        tableau2[i] = tableau[i];
    }
    tableau = (int *) calloc((tailleTableau + 1), sizeof(int));
    tableau[tailleTableau] = valeurAInserer;
    for (int i = tailleTableau; i > 0; i--) {
        if (valeurAInserer < tableau2[i - 1]) {
            tableau[i] = tableau2[i - 1];
            tableau2[i - 1] = valeurAInserer;
        }
    }
}

int main(int argc, char *argv[]) {
    int tailleTableauEntree =
            argc - 1; // -1 car on veut enlever le nom de l'executable des paramètres pour notre décompte.
    int tableau[tailleTableauEntree];
    for (int i = 0; i < tailleTableauEntree; i++) {
        tableau[i] = atoi(argv[i + 1]);
    }
}