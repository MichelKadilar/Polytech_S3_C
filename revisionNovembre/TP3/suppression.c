#include <stdio.h>

void decalage_a_gauche_de_n(char str[], int indice, int n) {
    int i;
    for (i = indice; str[i]; i++) {
        str[i - n] = str[i];
    }
    str[i - n] = '\0';

}

void suppression(char str[], const char suppr[]) {
    int k, j, i;
    for (i = 0; str[i]; i++) {
        for (j = i, k = 0; suppr[k]; j++, k++) {
            if (str[j] != suppr[k]) break;
        }
        if (suppr[k] == '\0') {
            decalage_a_gauche_de_n(str, j, k);
        }
    }
}

int main(void) {
    char str[] = "Le voleur vole et s'envole en volant les affaires volees";
    char suppr[] = "vole";
    suppression(str, suppr);
    printf("%s\n", str);
}
