//
// Created by Michel K on 19/11/2022.
//
#include <stdio.h>
#include <stdarg.h>

int evaluer(char operateur, int operande1, ...) {
    if (operande1 > 0) {
        va_list ap;
        va_start(ap, operande1);
        int resultat = operande1;
        int operandeCourant;
        while ((operandeCourant = va_arg(ap, int)) > 0) {
            if (operateur == '+') {
                resultat += operandeCourant;
            } else if (operateur == '-') {
                resultat -= operandeCourant;
            } else if (operateur == '*') {
                resultat *= operandeCourant;
            } else if (operateur == '/') {
                if (operandeCourant != 0) {
                    resultat /= operandeCourant;
                }
            }
        }
        return resultat;
    }
    return 0;
}

int main(void) {
    printf("%d\n", evaluer('+', 1, 2, 3, -1));
    printf("%d\n", evaluer('-', 10, evaluer('*', 2, 2, 2, -1), 2, -1));
}