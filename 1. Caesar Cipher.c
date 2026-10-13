#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isupper(c)) {
            text[i] = ((c - 'A' + shift) % 26) + 'A';
        } else if (islower(c)) {
            text[i] = ((c - 'a' + shift) % 26) + 'a';
        }
    }
}

void caesarDecrypt(char *text, int shift) {
    caesarEncrypt(text, 26 - (shift % 26));
}

int main() {
    char text[100] = "HelloWorld";
    int k = 3;
    printf("Original: %s\n", text);
    caesarEncrypt(text, k);
    printf("Encrypted: %s\n", text);
    caesarDecrypt(text, k);
    printf("Decrypted: %s\n", text);
    return 0;
}