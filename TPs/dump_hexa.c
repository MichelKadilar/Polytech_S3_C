//
// Created by Michel K on 09/10/2022.
//
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char c;
    char string[4000];
    char stringInHexa[4000];
    int compteurPositionString = 0;
    while ((c = getchar()) != EOF) {
        string[compteurPositionString] = c;
        stringInHexa[compteurPositionString] = strtol(&c, NULL, 16);
        compteurPositionString++;
    }
    printf("%d\n", compteurPositionString);
    for (int i = 0; i < compteurPositionString; i++) {
        printf("%X", stringInHexa[i]);
    }

}
