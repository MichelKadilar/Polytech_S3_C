//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

float celsius_to_faren(float temp_in_celsius) {
    return ((9.0 * temp_in_celsius) / 5.0) + 32.0;
}

int main(void) {
    for (float i = 0; i < 20; i += 0.5) {
        printf("%.1fC\t\t%.1fF\n", i, celsius_to_faren(i));
    }
}