#include <stdio.h>
#include <string.h>

void otp_vigenere_encrypt(char *text, int *key, int key_len) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'A' + (text[i] - 'A' + key[i % key_len]) % 26;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'a' + (text[i] - 'a' + key[i % key_len]) % 26;
        }
    }
}

int main() {
    char text[] = "HELLO";
    int key[] = {3, 19, 5, 7, 11};
    
    otp_vigenere_encrypt(text, key, 5);
    printf("Encrypted Text: %s\n", text);
    return 0;
}