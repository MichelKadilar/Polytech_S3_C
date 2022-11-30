//
// Created by Michel K on 19/11/2022.
//

#include <stdio.h>
#include <stdarg.h>

void print_base(int n, int base) {
    if (n < 0) {
        putchar('-');
        print_base(-n, base);
    } else {
        int d = n % base;
        if (n >= base) print_base(n / base, base);
        putchar(d + ((d < 10) ? '0' : 'A' - 10));
    }
}

void print_string(char str[]) {
    for (int i = 0; str[i]; i++) {
        putchar(str[i]);
    }
}

void printf2(char format[], ...) {
    va_list ap;
    va_start(ap, format);
    int i = 0;
    while (format[i]) {
        if (format[i] == '%') {
            switch (format[++i]) {
                case 'd':
                    print_base(va_arg(ap, int), 10);
                    break;
                case 'c':
                    putchar(va_arg(ap, int));
                    break;
                case 's':
                    print_string(va_arg(ap, char *));
                    break;
                case 'x':
                    print_base(va_arg(ap, int), 16);
                    break;
                case 'f': {
                    char buffer[20];  // DOUBLE et pas FLOAT (lire le warning!)
                    snprintf(buffer, 20, "%f", va_arg(ap, double));
                    print_string(buffer);
                    break;
                }
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar('%');
                    if (format[i] != '\0') {
                        putchar(format[i]);
                    } else {
                        va_end(ap);
                        return;
                    }
            }
        } else {
            putchar(format[i]);
        }
        i++;
    }
}

int main(void) {
    printf2("DEBUT\n%s%c c'est moi.\nTest nombres: 0x%x et %d et un négatif %d\n",
           "salut", ',', 161, 123, -12);
    printf2("Trois nombres sur la même ligne: %d %f %d\n", 1, 2.0, 3);
    printf2("Affichage d'un '%c' et encore un d'une autre façon '%%'\n", '%');
    printf2("Affichage d'un %% non suivi d'un caractère spécial ==> %z...\n");
    printf2("Attention au %% en fin de la chaîne format ==> %");
    printf2("\nFIN\n");
}