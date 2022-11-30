//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>

void strcpy2(char s1[], char s2[]) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
}

int main(void) {
    char c[100] = {};
    strcpy2(c, "abcde");
    printf("%s", c) ;
}