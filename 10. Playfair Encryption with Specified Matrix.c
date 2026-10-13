#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findPosition(char matrix[5][5], char ch, int *row, int *col) {
    ch = toupper(ch);
    if (ch == 'J') ch = 'I';
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

int main() {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'V', 'W', 'X', 'Y', 'E'},
        {'A', 'R', 'G', 'D', 'S'},
        {'B', 'C', 'L', 'T', 'Z'}
    };
    char message[] = "Must see you over Cadogan West Coming at once";
    printf("Matrix and message initialized for Playfair encryption.\n");
    return 0;
}