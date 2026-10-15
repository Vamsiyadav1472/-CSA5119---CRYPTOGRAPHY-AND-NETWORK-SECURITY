#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char affine_encrypt(char p, int a, int b) {
    if (p >= 'A' && p <= 'Z') {
        return 'A' + ((a * (p - 'A') + b) % 26);
    }
    return p;
}

int main() {
    int a = 2, b = 3;
    if (gcd(a, 26) != 1) {
        printf("Error: 'a' must be coprime with 26 for the cipher to be one-to-one.\n");
    } else {
        printf("Encrypted of A with a=2, b=3: %c\n", affine_encrypt('A', a, b));
        printf("Encrypted of N with a=2, b=3: %c (Notice collision with A)\n", affine_encrypt('N', a, b));
    }
    return 0;
}