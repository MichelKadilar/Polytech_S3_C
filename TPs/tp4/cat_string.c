//
// Created by Michel K on 24/10/2022.
//

#include <stdarg.h>
#include <stdio.h>

void cat_strings(char str1[], ...) {
    va_list ap;
    va_start(ap, str1);
    char *str = str1;
    while (str != NULL) {
        printf("%s\n", str);
        str = va_arg(ap, char *);
    }
    va_end(ap);
}

int main(void) {
    cat_strings("TOTO", "Nicolas", "est", "gentil", "et", NULL);
}

