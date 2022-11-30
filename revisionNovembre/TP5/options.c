//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>

#define VRAI 1
#define FAUX 0

void print_option_courte(char c) {
    printf("Option courte : -%c\n", c);
}

void print_option_longue(char c) {
    printf("Option longue : --%c\n", c);
}

void print_argument(char *str) {
    printf("Argument : %s\n", str);
}


int main(int argc, char *argv[]) {
    argc--;
    int is_parameter_found = FAUX;
    while (argc > 0) {
        argv++;
        if (!is_parameter_found) {
            if ((*argv)[0] == '-') {
                if ((*argv)[1] == '-') {
                    if (((*argv)[2]) != '\0') {
                        for (int i = 2; (*argv)[i]; i++) {
                            print_option_longue((*argv)[i]);
                        }
                    } else {
                        is_parameter_found = VRAI;
                    }
                } else {
                    for (int i = 1; (*argv)[i]; i++) {
                        print_option_courte((*argv)[i]);
                    }
                }
            } else {
                is_parameter_found = VRAI;
                print_argument(*argv);
            }
        } else {
            print_argument(*argv);
        }
        argc--;
    }
}