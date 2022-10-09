//
// Created by Michel K on 03/10/2022.
//

#include <stdio.h>

int main(void){
    int i;
    scanf("%d", &i);
    if(i<0){
        printf("%d\n", -1*i);
    }
    else {
        printf("%d\n", i);
    }
    return 0;
}
