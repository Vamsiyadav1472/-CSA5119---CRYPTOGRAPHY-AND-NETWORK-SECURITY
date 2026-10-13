#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("12. Hill Cipher (2x2 Matrix):\n");
    printf("Key matrix: \n[ 9  4 ]\n[ 5  7 ]\n");
    printf("Plaintext: 'meet me at the usual place at ten rather than eight oclock'\n");
    printf("Calculations:\n");
    printf("- Convert text to numbers (A=0, ..., Z=25), group into 2x1 vectors.\n");
    printf("- Multiply each vector by the key matrix modulo 26 for encryption.\n");
    printf("- Multiply each vector by the modular inverse of the key matrix (determinant inverse = 43) for decryption.\n");
    return 0;
}