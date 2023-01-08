#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char get_character_from_integer(int num) {
    if (num >= 0 && num <= 9)
        return (char) (num + '0');
    else
        return (char) (num - 10 + 'A');
}

/*char *from_decimal_to_base(char *res, int base, int inputNum) {
    int index = 0;
    while (inputNum > 0) {
        res[index++] = get_character_from_integer(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    // Reverse la chaine de caractères pour avoir la bonne representation
    strrev(res);

    return res;
}*/

void print_decimal_to_base(int base, int inputNumber) {
    if (inputNumber == 0) {
        return;
    } else {
        print_decimal_to_base(base, inputNumber / base);
    }
    putchar(get_character_from_integer(inputNumber % base));
    return;
}

void en_binaire_recursif(int nombre) {
    // print_decimal_to_base(2, nombre);
    // OU
    if (nombre == 0) {
        return;
    } else {
        en_binaire_recursif(nombre >> 1);
        putchar((nombre & 1) ? '1' : '0');
    }
}

void en_binaire_bits(int nombre) {

}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        exit(-1);
    }
    int base = atoi(argv[1]);
    printf("base : %d\n", base);
    int inputNumber = atoi(argv[2]);
    printf("nombre : %d\n", inputNumber);
    if (inputNumber < 0) {
        putchar('-');
    }
    if (base >= 1 && base <= 36) {
        //print_decimal_to_base(base, -1*inputNumber);
        en_binaire_recursif(50);
    }
    printf("\n");
}