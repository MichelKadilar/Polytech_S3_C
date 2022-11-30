//
// Created by Michel K on 14/11/2022.
//

#include <stdio.h>
#include <string.h>

void print_reverse(char str[]) {
    int size = strlen(str);
    for (int i = size - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

int main(int argc, char *argv[]) {
    argc--;
    argv++;
    if (argc > 0) {
        if (strcmp(*(argv), "-r") == 0) {
            argc--;
            while (argc > 0) {
                print_reverse(*(++argv));
                printf(" ");
                argc--;
            }
        } else {
            while (argc > 0) {
                printf("%s ", *(argv++));
                argc--;
            }
        }
    }
}