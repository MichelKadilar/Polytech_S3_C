//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int main(void) {
    char c;
    int numbers[10] = {0};
    int letters[26] = {0};
    while ((c = getchar()) != EOF) {
        if (c != '\n' && c != '\t' && c != ' ') {
            if (c >= 'a' && c <= 'z') {
                letters[c - 'a'] += 1;
            } else if (c >= 'A' && c <= 'Z') {
                letters[c - 'A'] += 1;
            }
            if (c >= '0' && c <= '9') {
                numbers[c - '0'] += 1;
            }
        }
    }
    for (int letterIndex = 0; letterIndex < 26; letterIndex++) {
        if(letters[letterIndex] > 0){
            printf("Lettre %c : %d fois\n", ('a' + letterIndex), letters[letterIndex]);
        }
    }
    for (int numIndex = 0; numIndex < 10; numIndex++) {
        if(numbers[numIndex] > 0){
            printf("Chiffre %c : %d fois\n", ('0' + numIndex), numbers[numIndex]);
        }
    }
}