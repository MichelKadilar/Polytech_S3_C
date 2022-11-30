//
// Created by Michel K on 14/11/2022.
//
#define VRAI 1
#define FAUX 0

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int parametreNumero = FAUX;
    int parametreDollar = FAUX;
    int parametreTrouve = FAUX;
    int parametreHelp = FAUX;
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
