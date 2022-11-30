//
// Created by Michel K on 24/10/2022.
//

#include <stdarg.h>
#include <stdio.h>

int evaluer(char operateur, int operande, ...) {
    va_list ap;
    va_start(ap, operande);
    int nombre = operande;
    if (operateur == '+') {
        while ((operande = va_arg(ap, int)) >= 0) {
            nombre += operande;
        }
    } else if (operateur == '-') {
        while ((operande = va_arg(ap, int)) >= 0) {
            nombre -= operande;
        }
    } else if (operateur == '*') {
        while ((operande = va_arg(ap, int)) >= 0) {
            nombre *= operande;
        }
    } else if (operateur == '/') {
        while ((operande = va_arg(ap, int)) >= 0) {
            nombre /= operande;
        }
    } else {
        printf("%s\n", "problème au niveau de l'opérateur");
    }
    va_end(ap);
    return nombre;
}

int main(void) {
    printf("%d\n", evaluer('+', 1, 2, 3, -1));
    printf("%d\n", evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));
}