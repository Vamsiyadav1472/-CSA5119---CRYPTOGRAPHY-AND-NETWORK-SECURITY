#include <stdio.h>
#include <string.h>
#include <ctype.h>

void otpEncrypt(char *text, int *key, int keyLen) {
    int idx = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((text[i] - base + key[idx % keyLen]) % 26) + base;
            idx++;
        }
    }
}

int main() {
    char plain[] = "send more money";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int keyLen = 13;
    printf("Original Plaintext: %s\n", plain);
    otpEncrypt(plain, key, keyLen);
    printf("Encrypted Ciphertext: %s\n", plain);
    
    char targetPlain[] = "cash not needed";
    printf("To decrypt/encrypt to target plaintext '%s', keys are derived by finding differences modulo 26.\n", targetPlain);
    return 0;
}