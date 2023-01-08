#include <stdio.h>
#include <string.h>


void xorcrypt(char msg[], char key[]){
    for(int i = 0, k=0; msg[i] != '\0'; i++, k++){
        if(key[k] == '\0'){ k = 0;}
        msg[i] = (msg[i] ^ key[k]);
    }
}

int main(void){
    char s[] = "HELLO, WORLD";

    printf("Avant chiffrement: %s\n", s);
    xorcrypt(s, "abcde");
    printf("Après chiffrement: %s\n", s);
    xorcrypt(s, "abcde");
    printf("Chaîne originale   %s\n", s);
    return 0;
}