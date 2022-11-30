//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>
#include <stdlib.h>

int abs(int x) {
    return x > 0 ? x : -1 * x;
}

int main(void) {
    int x;
    scanf("%d", &x);
    printf("Valeur absolue : %d\n", abs(x));
}