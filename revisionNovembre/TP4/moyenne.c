//
// Created by Michel K on 19/11/2022.
//
#include <stdio.h>
#include <stdarg.h>

float moyenne(int count, ...) {
    va_list ap;
    va_start(ap, count);
    float somme = 0.0;
    for (int i = 0; i < count; i++) {
        somme += va_arg(ap, double);
    }
    va_end(ap);
    return count != 0 ? somme / count : 0;
}

int main(void) {
    printf("%.1f\n", moyenne(2, 10.0, 15.0));
    printf("%.1f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5));
    printf("%.1f\n", moyenne(0.0));
}