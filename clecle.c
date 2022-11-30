//
// Created by Michel K on 15/11/2022.
//

#include <stdarg.h>
#include <stdio.h>

void imprimer(char *str, ...) {
    va_list ap;
    va_start(ap, str);
    char *tmp = str;
    while (tmp != NULL) {
        printf("%s ", tmp);
        printf("%d ", va_arg(ap, int));
        tmp = va_arg(ap, char *);
        printf("toto\n");
    }
    va_end(ap);
}

int main(void) {
    //imprimer("toto", 1, "titi", 2, "tutu", 3);
    printf("%9.2f", 1.0);
}