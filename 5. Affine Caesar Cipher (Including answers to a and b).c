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

void affineEncrypt(char *text, int a, int b) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            text[i] = ((a * (c - 'A') + b) % 26) + 'A';
        } else if (islower(c)) {
            text[i] = ((a * (c - 'a') + b) % 26) + 'a';
        }
    }
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
    printf("a. Limitations on b: b must be an integer from 0 to 25.\n");
    printf("b. Values of a not allowed: a must be coprime to 26. Values like 0, 2, 4, 6, 8, 10, 12, 13, 14, 16, 18, 20, 22, 24 are disallowed.\n\n");
    
    char text[100] = "HELLO";
    int a = 5, b = 8;
    printf("Original: %s\n", text);
    affineEncrypt(text, a, b);
    printf("Encrypted: %s\n", text);
    affineDecrypt(text, a, b);
    printf("Decrypted: %s\n", text);
    return 0;
}