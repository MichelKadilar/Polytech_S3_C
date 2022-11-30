//
// Created by Michel K on 19/11/2022.
//
#include <stdio.h>
#include <stdarg.h>

void cat_strings(char str1[], ...) {
    va_list ap;
    va_start(ap, str1);
    char *str = str1;
    do {
        printf("%s\n", str);
    } while ((str = va_arg(ap, char *)) != NULL);
    va_end(ap);
}

int main(void) {
    cat_strings("es", "sai", NULL);
}