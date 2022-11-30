//
// Created by Michel K on 12/11/2022.
//
#define FAUX 0
#define VRAI 1

#include <stdio.h>

int main(void) {
    int premierSlash = FAUX;
    int premiereEtoile = FAUX;
    int deuxiemeSlash = FAUX;
    int deuxiemeEtoile = FAUX;
    char c1, c2;
    while ((c1 = getchar()) != EOF) {
        if (c1 == '/' && (c2 = getchar()) == '*') {
            c1 = ' ';
            c2 = ' ';
        }
    }
}