//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strstr(char a[], char b[]) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int i = 0;
    int indiceB = 0;

    if (sizeB == 0) {
        return -1;
    } else {
        while (i <= (sizeA - sizeB)) { // Si A = 4 et B = 2, pour ne pas chercher plus loin que nécessaire.
            if (a[i] == b[indiceB]) {
                indiceB++;
                while ((i + indiceB <= i + indiceB + (sizeB - 1)) && (indiceB < sizeB)) {
                    if (a[i + indiceB] != b[indiceB]) {
                        i = i + indiceB + 1;
                        indiceB = 0;
                        break;
                    }
                    if (indiceB == sizeB - 1) {
                        return 1;
                    }
                    indiceB++;
                }
            } else {
                i++;
            }
        }
        if (i == sizeA) {
            return -1;
        }
        return 0;
    }
}

int main(int argc, char *argv[]) {
    char s[100];
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(-1);
    }
    while (fgets(s, 100, inputFile) != NULL) {
        if (Strstr(s, argv[2]) == 1) {
            printf("%s", s);
        }
    }


}