//
// Created by Michel K on 12/11/2022.
//

#define FAUX 0
#define VRAI 1

#include <stdio.h>
#include <string.h>

int palindrome(const char str[]) {
    int string_size = strlen(str);
    for (int g = 0; g < string_size; g++) {
        if (str[g] != str[(string_size-1) - g]) {
            return 0; // pas un palindrome
        }
    }
    return 1; // c'est un palindrome
}

int main(void) {
    printf("%d\n", palindrome("kayak"));
    printf("%d\n", palindrome("ressasser"));
    printf("%d\n", palindrome("X"));
    printf("%d\n", palindrome("test"));
}