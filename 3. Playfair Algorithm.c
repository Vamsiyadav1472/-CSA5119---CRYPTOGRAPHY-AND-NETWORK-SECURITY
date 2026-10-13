#include <stdio.h>
#include <string.h>
#include <ctype.h>
void prepareKey(char *keyword, char matrix[5][5]) {
    int used[26] = {0};
    used['j' - 'a'] = 1;
    int r = 0, c = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = tolower(keyword[i]);
        if (ch == 'j') ch = 'i';
        if (!used[ch - 'a']) {
            matrix[r][c++] = ch;
            used[ch - 'a'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j') continue;
        if (!used[ch - 'a']) {
            matrix[r][c++] = ch;
            used[ch - 'a'] = 1;
            if (c == 5) { c = 0; r++; }
        }
    }
}
void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'j') ch = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void playfairEncryptPair(char matrix[5][5], char *a, char *b) {
    int r1, c1, r2, c2;
    findPosition(matrix, *a, &r1, &c1);
    findPosition(matrix, *b, &r2, &c2);
    if (r1 == r2) {
        *a = matrix[r1][(c1 + 1) % 5];
        *b = matrix[r2][(c2 + 1) % 5];
    } else if (c1 == c2) {
        *a = matrix[(r1 + 1) % 5][c1];
        *b = matrix[(r2 + 1) % 5][c2];
    } else {
        *a = matrix[r1][c2];
        *b = matrix[r2][c1];
    }
}
int main() {
    char matrix[5][5];
    prepareKey("KEYWORD", matrix);
    char pair1 = 'a', pair2 = 'b';
    printf("Original pair: %c%c\n", pair1, pair2);
    playfairEncryptPair(matrix, &pair1, &pair2);
    printf("Encrypted pair: %c%c\n", pair1, pair2);
    return 0;
}