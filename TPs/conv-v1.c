//
// Created by Michel K on 03/10/2022.
//

#include <stdio.h>

float convertCelsiusToFarenheit(float celcius) {
    return ((9.0 * celcius) / 5.0) + 32.0;
}

int main(void) {
    for(float i=0; i<=20.0; i = i+0.5){
        printf("%-.2fC\t% -.2fF\n", i, convertCelsiusToFarenheit(i));
    }


}
