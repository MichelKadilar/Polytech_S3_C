//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>

int palindrome(char str[]) {
    int i;
    for (i = 0; str[i]; i++) {
    }
    int j = 0;
    int indiceFin = i - 1;
    while (indiceFin > j) {
        while (str[j] == ' ') {
            j++;
        }
        while (str[indiceFin] == ' ') {
            indiceFin--;
        }
        if (str[indiceFin] != str[j]) {
            printf("%c\n", str[indiceFin]);
            printf("%c\n", str[j]);
            return 0;
        }
        j++;
        indiceFin--;
    }
    return 1;
}

int main() {
    printf("%d\n", palindrome("karine alla en irak"));
}
