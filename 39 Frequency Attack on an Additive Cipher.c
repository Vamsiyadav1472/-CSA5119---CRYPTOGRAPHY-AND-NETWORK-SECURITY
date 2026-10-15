#include <stdio.h>
#include <string.h>

void additive_frequency_attack(const char *ciphertext, int top_n) {
    printf("--- Additive Cipher Frequency Attack (Top %d Plaintexts) ---\n", top_n);
    char text[100];
    for (int shift = 0; shift < top_n; shift++) {
        strcpy(text, ciphertext);
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] = 'A' + (text[i] - 'A' - shift + 26) % 26;
            }
        }
        printf("Shift %2d: %s\n", shift, text);
    }
}

int main() {
    char ciphertext[] = "KHOOR";
    additive_frequency_attack(ciphertext, 10);
    return 0;
}