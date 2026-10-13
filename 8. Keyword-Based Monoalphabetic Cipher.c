#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKeyAlpha(char *keyword, char *cipherAlpha) {
    int used[26] = {0};
    int idx = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = tolower(keyword[i]);
        if (!used[ch - 'a']) {
            cipherAlpha[idx++] = ch;
            used[ch - 'a'] = 1;
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (!used[ch - 'a']) {
            cipherAlpha[idx++] = ch;
            used[ch - 'a'] = 1;
        }
    }
    cipherAlpha[26] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char cipherAlpha[27];
    generateKeyAlpha(keyword, cipherAlpha);
    printf("Plain alphabet:  abcdefghijklmnopqrstuvwxyz\n");
    printf("Cipher alphabet: %s\n", cipherAlpha);
    return 0;
}