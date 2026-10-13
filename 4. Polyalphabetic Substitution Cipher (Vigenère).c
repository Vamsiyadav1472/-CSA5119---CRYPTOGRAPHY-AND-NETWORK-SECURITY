#include <stdio.h>
#include <string.h>
#include <ctype.h>

void vigenereEncrypt(char *text, char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    for (int i = 0, j = 0; i < textLen; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char k = tolower(key[j % keyLen]) - 'a';
            if (isupper(c)) {
                text[i] = ((c - 'A' + k) % 26) + 'A';
            } else {
                text[i] = ((c - 'a' + k) % 26) + 'a';
            }
            j++;
        }
    }
}

void vigenereDecrypt(char *text, char *key) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    for (int i = 0, j = 0; i < textLen; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char k = tolower(key[j % keyLen]) - 'a';
            if (isupper(c)) {
                text[i] = ((c - 'A' - k + 26) % 26) + 'A';
            } else {
                text[i] = ((c - 'a' - k + 26) % 26) + 'a';
            }
            j++;
        }
    }
}

int main() {
    char text[100] = "HelloWorld";
    char key[] = "KEY";
    printf("Original: %s\n", text);
    vigenereEncrypt(text, key);
    printf("Encrypted: %s\n", text);
    vigenereDecrypt(text, key);
    printf("Decrypted: %s\n", text);
    return 0;
}