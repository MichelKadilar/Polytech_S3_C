//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>

int indice(const char str[], const char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

int main(void) {
    char c[5] = "absce";
    printf("%d", indice(c, 's'));
}