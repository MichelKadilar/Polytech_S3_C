//
// Created by Michel K on 24/10/2022.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void printf2(char *format, int base, ...) {
    va_list ap;
    va_start(ap, base);
    char c = *format; // 1er char de la chaine
    while (c != '\0' && c != '\n' && c != '\t' && c != ' ') {
        if (c == '%') {
            c = *(++format);
            if (c == 'd') {
                putchar('0' + va_arg(ap, int));
            }
        }
        c = *(++format);
    }
    va_end(ap);
}


int main(void) {
    printf2("%d\n", 5, 25, 4);
}
