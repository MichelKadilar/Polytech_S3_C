//
// Created by Michel K on 03/10/2022.
//

#include <stdio.h>

int main(void) {
    int c;
    int letters[26] = {0};
    int digits[10] = {0};
    while ((c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z')) {
            letters[(c - 'A') + 32]++;
        }
        if ((c >= 'a' && c <= 'z')) {
            letters[c - 'a']++;
        }
        if ((c >= '0' && c <= '9')) {
            digits[c - '0']++;
        }
    }
    for (int le = 0; le < 26; le++) {
        if (letters[le] > 0) {
            printf("Lettre %c, comptée %d fois \n", 'a' + le, letters[le]);
        }
    }
    for (int num = 0; num < 10; num++) {
        //printf("%d : %d \n", num + '0', letters[num]);
        if (digits[num] > 0) {
            printf("Chiffre %d, comptée %d fois \n", num, digits[num]);
        }
    }
    return 0;
}
