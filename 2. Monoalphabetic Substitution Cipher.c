#include <stdio.h>
#include <string.h>
#include <ctype.h>

void monoEncrypt(char *text, char *plainAlpha, char *cipherAlpha) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        int is_upper = isupper(c);
        char lower_c = tolower(c);
        for (int j = 0; j < 26; j++) {
            if (lower_c == plainAlpha[j]) {
                text[i] = is_upper ? toupper(cipherAlpha[j]) : cipherAlpha[j];
                break;
            }
        }
    }
}

void monoDecrypt(char *text, char *plainAlpha, char *cipherAlpha) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        int is_upper = isupper(c);
        char lower_c = tolower(c);
        for (int j = 0; j < 26; j++) {
            if (lower_c == cipherAlpha[j]) {
                text[i] = is_upper ? toupper(plainAlpha[j]) : plainAlpha[j];
                break;
            }
        }
    }
}

int main() {
    char plainAlpha[] = "abcdefghijklmnopqrstuvwxyz";
    char cipherAlpha[] = "qwertyuiopasdfghjklzxcvbnm";
    char text[100] = "HelloWorld";
    printf("Original: %s\n", text);
    monoEncrypt(text, plainAlpha, cipherAlpha);
    printf("Encrypted: %s\n", text);
    monoDecrypt(text, plainAlpha, cipherAlpha);
    printf("Decrypted: %s\n", text);
    return 0;
}