//
// Created by Michel K on 17/10/2022.
//

#include <stdio.h>

void strupper(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            // Convert lowercase to uppercase
            s[i] = s[i] - 32;
        }
        i++;
    }
}

int main(void) {
    char s[] = "abcd";
    strupper(s);
    printf("%s", s);
}