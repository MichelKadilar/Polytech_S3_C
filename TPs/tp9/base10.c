#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(-1);
    }
    for (int j = 0; argv[1][j] != '\0'; j++) {
        putchar(argv[1][j]);
    }
    putchar('\n');
}