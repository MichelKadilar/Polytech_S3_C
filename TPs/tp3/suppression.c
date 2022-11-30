//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>
#include <string.h>

void decale_vers_gauche(char str[], int position_decalage) {
    int i = position_decalage;
    while (str[i] != '\0') {
        str[i] = str[i + 1];
        i++;
    }
}

void decaler_n_fois_vers_gauche(int n, char str[], int position_decalage) {
    for (int i = 0; i < n; i++) {
        decale_vers_gauche(str, position_decalage - i);
    }
}

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
                        return i + sizeB -
                               1; // renvoie la position du dernier caractère de str correspoondant à la substring
                    }
                    indiceB++;
                }
            } else {
                i++;
            }
        }
        return -1;
    }
}

void suppression(char str[], char suppr[]) {
    int res = Strstr(str, suppr);
    if (res != -1) {
        int sizeSuppr = strlen(suppr);
        decaler_n_fois_vers_gauche(sizeSuppr, str, res);
    }
}

int main(void) {
    char s[] = "bonjour";
    char s2[] = "on";
    suppression(s, s2);
    printf("%s", s);
}
