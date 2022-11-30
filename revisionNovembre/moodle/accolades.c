//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>

int main(void) {
    char c;
    int nbOuvrantes = 0;
    while ((c = getchar()) != EOF) {
        if (c == '{') {
            nbOuvrantes++;
        } else if (c == '}') {
            nbOuvrantes--;
            if (nbOuvrantes < 0) {
                printf("Unexpected '}'");
                break;
            }
        }
    }
    if (nbOuvrantes > 0) {
        printf("Missing '}': %d\n", nbOuvrantes);
    } else if (nbOuvrantes == 0) {
        printf("Correct");
    }
    return 0;
}