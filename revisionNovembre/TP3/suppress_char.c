//
// Created by Michel K on 13/11/2022.
//

#include <stdio.h>

void suppress_char(char str[], char c) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != c) {
            if (i != j) str[j] = str[i];
            j += 1;
        }
    }
    str[j] = '\0';
}

int main(void) {
    char toto[] = "Super cool ton jouet";
    suppress_char(toto, 'o');
    printf("%s\n", toto);
}
