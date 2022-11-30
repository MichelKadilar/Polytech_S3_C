//
// Created by Michel K on 03/10/2022.
//
#include <stdio.h>

int main() {
    int c;
    int i = 1;
    printf("%d ", i);
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            i++;
            printf("\n%d", i);
        } else {
            putchar(c);
        }
    }
    return 0;
}
