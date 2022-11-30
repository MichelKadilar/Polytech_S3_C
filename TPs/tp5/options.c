//
// Created by Michel K on 14/11/2022.
//
#define FAUX 0
#define VRAI 1

#include <stdio.h>

int main(int argc, char *argv[]) {
    argv++;
    argc--;
    int parametreTrouve = FAUX;
    for (int i = 0; i < argc; i++) {
        if (parametreTrouve == FAUX) {
            if (argv[i][0] == '-' && argv[i][1] != '-') {
                if (argv[i][1] == '\0') {
                    continue;
                }
                for (int j = 1; argv[i][j] != '\0'; j++) {
                    printf("Option courte : %c\n", argv[i][j]);
                }
            } else if (argv[i][0] == '-' && argv[i][1] == '-' && (argv[i][2] <= 'z' && argv[i][2] >= 'a')) {
                for (int j = 2; argv[i][j] != '\0'; j++) {
                    printf("Option longue : %c\n", argv[i][j]);
                }
            } else if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')) {
                parametreTrouve = VRAI;
                if (argv[i][0] == '-') {
                    continue;
                }
                printf("Parametre : %s\n", argv[i]);
            }
        } else {
            printf("Parametre : %s\n", argv[i]);
        }
    }
}