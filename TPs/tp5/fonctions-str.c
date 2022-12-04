#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dest, const char *src){
    while(*src) {
        *dest = *src;
        src++;
    }
    return dest;
}

size_t strlen(const char *s){
    int size = 0;
    while(*s) size++;
    return size;
}

int main(void) {
    char *s1 = (char *) malloc(6 * sizeof(char));
    printf("%s\n", strcpy(s1, "Hello"));

    printf("%llu\n", strlen("Hello"));
}