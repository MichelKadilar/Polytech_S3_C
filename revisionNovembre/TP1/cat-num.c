//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int main(void) {
    int numLigne = 1;
    char c;
    printf("%d ", numLigne);
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            numLigne++;
            printf("\n%d ", numLigne);
        }
        else {
            printf("%c", c);
        }
    }
}