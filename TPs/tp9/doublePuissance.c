#include <stdio.h>

double puissance(double x, unsigned int n) {
    double y = 1;
    double z = x;
    while (n > 0) {
        if ((n & 1) == 1) {
            y = y * z;
        }
        z = z * z;
        n >>= 1;
    }
    return y;
}

int main(void) {
    printf("%f\n", puissance(100, 7));
}