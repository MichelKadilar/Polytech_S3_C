//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>
#include <string.h>

void print_reverse_a_word(char *word) {
    int size = strlen(word);
    for (int i = size - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
}

int main(int argc, char *argv[]) {
    argc--;
    argv++;
    if (argv[0][0] == '-' && argv[0][1] == 'r') {
        argc--;
        argv++;
        while (argc > 0) {
            print_reverse_a_word(*argv);
            printf(" ");
            argc--;
            argv++;
        }
    } else {
        while (argc > 0) {
            printf("%s ", *argv);
            argc--;
            argv++;
        }
    }
}