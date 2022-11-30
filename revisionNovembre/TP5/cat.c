//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>
#include <string.h>

#define VRAI 1
#define FAUX 0
#define NUMEROTE 100
#define DOLLARISE 101
#define HELP 102
#define PAS_OPTION 0
#define BAD_OPTION -1

void print_option_courte(char c, int options1, int options2) {
    if (options1 && options2) {
        printf("Option courte : -%c\n", c);
    } else if (options1) {

    } else if (options2) {

    } else {
        printf("Option courte : -%c\n", c);
    }
}

void print_option_longue(char c) {
    printf("Option longue : --%c\n", c);
}

void print_argument(char *str) {
    printf("Argument : %s\n", str);
}

void print_help() {
    printf("There is the help option !");
}

void options(int *options, int argc, char *argv[]) {
    int optionN = PAS_OPTION;
    int optionE = PAS_OPTION;
    int optionH = PAS_OPTION;
    int bad_option = PAS_OPTION;

    while (argc > 0) {
        argv++;
        if ((*argv)[0] == '-') {
            if ((*argv)[1] == '-') {
                if (((*argv)[2]) != '\0') {
                    if (strcmp((*argv) + 2, "help") == 0) {
                        optionH = HELP;
                    }
                } else {
                    break;
                }
            } else {
                switch ((*argv)[1]) {
                    case 'n':
                        optionN = NUMEROTE;
                        break;
                    case 'E':
                        optionE = DOLLARISE;
                        break;
                    case 'h':
                        optionH = HELP;
                        break;
                    default:
                        bad_option = BAD_OPTION;
                        break;
                }
            }
        } else {
            break;
        }
        argc--;
    }
    options[0] = optionN;
    options[1] = optionE;
    options[2] = optionH;
    options[3] = bad_option;
}

int main(int argc, char *argv[]) {
    argc--;
    int option[4] = {PAS_OPTION};
    options(option, argc, argv);
    char c;
    int i = 0;
    int colonne = 0;
    if (!option[3]) {
        while ((c = getchar()) != EOF) {
            if (!option[2]) {
                if (option[0] && colonne == 0) {
                    printf("%d\t", i);
                    i++;
                    colonne++;
                }
                if (option[1] && c == '\n') {
                    printf("$%c", c);
                    colonne = 0;
                } else {
                    printf("%c", c);
                }
            } else {
                print_help();
                break;
            }
        }
    } else {
        printf("bad option\n");
    }
}