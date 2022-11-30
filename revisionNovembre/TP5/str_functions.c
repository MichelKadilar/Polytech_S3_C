//
// Created by Michel K on 20/11/2022.
//
#include <stdio.h>
#include <stdlib.h>

char *strcpy2(char *dest, const char *src) {
    int i;
    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

size_t strlen2(const char *s) {
    int taille = 0;
    while (*s != '\0') {
        taille++;
        s++;
    }
    return taille;
}

char *strdup2(const char *s) {
    char *str = (char *) malloc(sizeof(char) * (strlen2(s) + 1));
    return str ? strcpy2(str, s) : NULL;
}

char *strchr2(const char *s, int c) {
    while (*s != '\0') {
        if (*s == c) {
            return (char *) s;
        }
        s++;
    }
    return NULL;
}

int main(void) {
    char str_src[] = "Bonjour je suis Michel";
    char *str_dst = (char *) malloc(50 * sizeof(char));
    //printf("%s\n", strcpy2(str_dst, str_src));
    printf("%zu\n", strlen2(str_dst));
    printf("%s\n", strdup2(str_src));
    printf("%s\n", strchr2(str_src, 'c'));
    free(str_dst);
}