//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>

int strcmp2(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int main(void) {
    char tmp[] = "abc";
    char tmp2[] = "abcd";
    printf("%d", strcmp2(tmp, tmp2));
}