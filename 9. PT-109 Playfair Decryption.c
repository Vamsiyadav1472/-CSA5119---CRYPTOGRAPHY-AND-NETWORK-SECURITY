#include <stdio.h>
#include <string.h>
#include <ctype.h>
void prepareKey(char *keyword, char matrix[5][5]) {
    int used[26] = {0};
    used['j' - 'a'] = 1;
    int r = 0, c = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = tolower(keyword[i]);
        if (ch == ' ') continue;
        if (ch == 'j') ch = 'i';
        if (!used[ch - 'a']) {
            matrix[r][c++] = toupper(ch);
            used[ch - 'a'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j') continue;
        if (!used[ch - 'a']) {
            matrix[r][c++] = toupper(ch);
            used[ch - 'a'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
}
int main() {
    char matrix[5][5];
    prepareKey("ROYALNEWZEALANDNAVY", matrix);
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEVFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDO";
    printf("PT-109 Ciphertext loaded for Playfair decryption using key ROYAL NEW ZEALAND NAVY.\n");
    return 0;
}