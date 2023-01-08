//
// Created by Michel K on 05/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline() {
    int TBLOC = 5;
    char *s = malloc(TBLOC * sizeof(char));
    char c;
    while ((c = getchar()) && c != EOF && c != '\n') {
        *(s++) = c;
        if (s == NULL) {
            char *str_tmp = strdup(s);
            s = (char *) realloc(s, (TBLOC = TBLOC * 2));
            strcpy(s, str_tmp);
        }
    }
    *s = '\0';
    return s;
}

int main(void) {
    char *s = NULL;
    do {
        printf("Entrer une chaîne: ");
        fflush(stdout);
        s = readline();
        if (s) {
            printf("Chaîne lue : '%s'\n", s);
            free(s);
        }
    } while (s);
    return 0;
}