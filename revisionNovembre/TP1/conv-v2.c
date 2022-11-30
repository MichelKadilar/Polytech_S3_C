//
// Created by Michel K on 10/11/2022.
//

#include <stdio.h>

int celsius_to_faren(float temp_in_celsius) {
    double temp = ((9.0 * temp_in_celsius) / 5.0) + 32.0;
    if ((temp - (int) temp) < 0.5) {
        return (int) temp;
    } else {
        return ((int) temp) + 1;
    }
}

int main(void) {
    for (float i = 0; i < 20; i += 0.5) {
        printf("%.1fC\t\t%dF\n", i, celsius_to_faren(i));
    }
}