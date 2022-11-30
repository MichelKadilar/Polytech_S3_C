//
// Created by Michel K on 10/10/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[20];
    while (1) {
        //fgets(str, strlen(str),)
        printf("Veuillez entrer une opération :\n");
        scanf("%s", &(str[0]));

        for (int i = 0; i < 20; i++) {
            printf("%d\n", str[i]);
        }

        return 0;

    }
    return 0;
}
