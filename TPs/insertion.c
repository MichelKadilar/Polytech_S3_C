//
// Created by Michel K on 09/10/2022.
//

#include <stdio.h>
#include <stdlib.h>

void insertionDansTableau(int **tableau, int nbElementsDansTableau, int valeurAInserer) {
    *tableau = realloc(*tableau, (nbElementsDansTableau + 1) * sizeof(int));
    (*tableau)[nbElementsDansTableau] = valeurAInserer;
    for (int i = nbElementsDansTableau; i > 0; i--) {
        int j = i;
        while ((*tableau)[j] < (*tableau)[j - 1]) {
            int temp = (*tableau)[j];
            (*tableau)[j] = (*tableau)[j - 1];
            (*tableau)[j - 1] = temp;
            j--;
        }
    }
}

int main(int argc, char *argv[]) {
    int tailleTableauEntree =
            argc - 1; // -1 car on veut enlever le nom de l'executable des paramètres pour notre décompte.
    int compteurNbElementsDansTableau = 0;
    int *tableau = malloc(0);
    for (int i = 0; i < tailleTableauEntree; i++) {
        insertionDansTableau(&tableau, compteurNbElementsDansTableau, atoi(argv[i + 1]));
        compteurNbElementsDansTableau++;
    }
    for (int indiceAffichage = 0; indiceAffichage < tailleTableauEntree; indiceAffichage++) {
        printf("%d ", tableau[indiceAffichage]);
    }
}