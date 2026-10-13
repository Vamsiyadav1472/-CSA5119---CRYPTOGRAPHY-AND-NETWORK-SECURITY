#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return 1;
}

void affineDecrypt(char *text, int a, int b) {
    int a_inv = modInverse(a, 26);
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            text[i] = (a_inv * (c - 'A' - b + 26) % 26) + 'A';
        } else if (islower(c)) {
            text[i] = (a_inv * (c - 'a' - b + 26) % 26) + 'a';
        }
    }
}

int main() {
    int a = 23, b = 6;
    char ciphertext[100] = "BU";
    printf("Ciphertext: %s\n", ciphertext);
    affineDecrypt(ciphertext, a, b);
    printf("Decrypted with a=%d, b=%d: %s\n", a, b, ciphertext);
    return 0;
}