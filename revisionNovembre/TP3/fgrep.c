//
// Created by Michel K on 13/11/2022.
//

#include <stdio.h>

int Strstr(char big[], char small[]) {
    int j = 0;
    for (int i = 0; big[i]; i++) {
        if (big[i] != small[j]) {
            j = 0;
            continue;
        } else if (big[i] == small[j]) {
            j++;
        }
        if (small[j] == '\0') return 1;
    }
    return 0;
}

void fgrep2(char small[]) {
    int i = 0;
    char c;
    char ligneCourante[1024];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ligneCourante[i] = '\0';
            if (Strstr(ligneCourante, small)) {
                printf("%s\n", ligneCourante);
            }
            i = 0;
        } else {
            ligneCourante[i] = c;
            i++;
        }

    }
    ligneCourante[i] = '\0';
    // Pour la dernière ligne, on peut soit faire ça soit mettre un saut de ligne à la fin du fichier
    if (Strstr(ligneCourante, small)) {
        printf("%s\n", ligneCourante);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) fgrep2(argv[1]);
    else {
        printf("%s\n", "Fgrep function");
        return 1;
    }
    return 0;
}