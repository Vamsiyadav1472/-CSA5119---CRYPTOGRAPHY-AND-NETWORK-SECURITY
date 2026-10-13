#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptAdditive(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = ((text[i] - base - shift + 26) % 26) + base;
        }
    }
}

int main() {
    char cipher[] = "KHOOR";
    printf("Additive cipher automated frequency attack framework loaded.\n");
    for (int s = 0; s < 26; s++) {
        char temp[100];
        strcpy(temp, cipher);
        decryptAdditive(temp, s);
        printf("Shift %2d: %s\n", s, temp);
    }
    return 0;
}