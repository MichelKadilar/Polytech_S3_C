//
// Created by Michel K on 24/10/2022.
//

#include <stdarg.h>
#include <stdio.h>

float moyenne(int count, ...) {
    va_list ap;
    va_start(ap, count);
    double somme = 0.0;
    for (int i = 0; i < count; i++) {
        somme += va_arg(ap, double);
    }
    va_end(ap);
    return (float) (somme / count);
}

int main(void) {
    printf("%f\n", moyenne(2, 5.0, 7.0));
}