//
// Created by Michel K on 13/11/2022.
//

#include <stdio.h>
#include <string.h>

void strcpy2(char s1[], char s2[]) {
    if (strlen(s1) >= strlen(s2)) {
        int i = 0;
        do {
            s1[i] = s2[i];
        } while (s2[i++] != '\0');
    }
}

int strcmp2(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++) {
    }
    return s1[i] - s2[i];
}

void strupper2(char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = 'A' + (s[i] - 'a');
        }
    }
}


int main(void) {
    printf("%d\n", strcmp2("trotro", "trot"));
    char toto[] = "toto";
    char bobo[] = "AoBo";
    strupper2(toto);
    strupper2(bobo);
    printf("%s\n", toto);
    printf("%s\n", bobo);

}