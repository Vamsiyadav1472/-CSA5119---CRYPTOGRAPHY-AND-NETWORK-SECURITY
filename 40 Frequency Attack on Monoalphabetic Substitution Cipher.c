#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#define ALPHABET_SIZE 26
#define MAX_TEXT_LEN 2048
double score_text(const char *text) {
    double score = 0.0;
    int len = strlen(text);
    if (len == 0) return 0.0;
    char common_letters[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    for (int i = 0; i < len - 1; i++) {
        char c1 = toupper(text[i]);
        char c2 = toupper(text[i+1]);
        if (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') {
            score += 1.0;
        }
    }
    return score;
}
void decrypt(const char *ciphertext, const char *key, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            plaintext[i] = tolower(key[idx]);
        } else if (c >= 'A' && c <= 'Z') {
            int idx = c - 'A';
            plaintext[i] = key[idx];
        } else {
            plaintext[i] = c;
        }
    }
    plaintext[len] = '\0';
}
void randomize_key(char *key) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        key[i] = 'A' + i;
    }
    for (int i = ALPHABET_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
    key[ALPHABET_SIZE] = '\0';
}
typedef struct {
    char plaintext[MAX_TEXT_LEN];
    char key[ALPHABET_SIZE + 1];
    double score;
} Candidate;
int compare_candidates(const void *a, const void *b) {
    Candidate *candA = (Candidate *)a;
    Candidate *candB = (Candidate *)b;
    if (candB->score > candA->score) return 1;
    if (candB->score < candA->score) return -1;
    return 0;
}
void break_substitution_cipher(const char *ciphertext, int top_n) {
    Candidate candidates[50];
    int cand_count = 0;
    printf("\n[*] Running frequency attack and hill-climbing optimization...\n");
    for (int restart = 0; restart < 50; restart++) {
        char current_key[ALPHABET_SIZE + 1];
        randomize_key(current_key);
        char current_plain[MAX_TEXT_LEN];
        decrypt(ciphertext, current_key, current_plain);
        double current_score = score_text(current_plain);
        int improved = 1;
        int steps = 0;
        while (improved && steps < 500) {
            improved = 0;
            steps++;
                        int idx1 = rand() % ALPHABET_SIZE;
            int idx2 = rand() % ALPHABET_SIZE;
            
            char temp = current_key[idx1];
            current_key[idx1] = current_key[idx2];
            current_key[idx2] = temp;

            char test_plain[MAX_TEXT_LEN];
            decrypt(ciphertext, current_key, test_plain);
            double test_score = score_text(test_plain);

            if (test_score > current_score) {
                current_score = test_score;
                improved = 1;
            } else {
                // Revert swap if no improvement
                temp = current_key[idx1];
                current_key[idx1] = current_key[idx2];
                current_key[idx2] = temp;
            }
        }
        decrypt(ciphertext, current_key, candidates[cand_count].plaintext);
        strcpy(candidates[cand_count].key, current_key);
        candidates[cand_count].score = current_score;
        cand_count++;
    }
    qsort(candidates, cand_count, sizeof(Candidate), compare_candidates);
    printf("\n--- Top %d Possible Plaintexts (Ordered by Likelihood) ---\n", top_n);
    int displayed = 0;
    for (int i = 0; i < cand_count && displayed < top_n; i++) {
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(candidates[i].plaintext, candidates[j].plaintext) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            displayed++;
            printf("\nRank %d (Score: %.2f):\nKey: %s\nPlaintext: %s\n", 
                   displayed, candidates[i].score, candidates[i].key, candidates[i].plaintext);
        }
    }
}
int main() {
    srand(time(NULL));
    char ciphertext[MAX_TEXT_LEN];
    int top_n = 10;
    printf("=== Monoalphabetic Substitution Cipher Frequency Attack Solver ===\n");
    printf("Enter the ciphertext to crack:\n> ");
    if (fgets(ciphertext, sizeof(ciphertext), stdin) != NULL) {
        ciphertext[strcspn(ciphertext, "\n")] = '\0';
    } else {
        printf("Error reading input.\n");
        return 1;
    }
    printf("Enter number of top candidate plaintexts to display (e.g., 10): ");
    if (scanf("%d", &top_n) != 1 || top_n <= 0) {
        top_n = 10; // Default fallback
    }
    break_substitution_cipher(ciphertext, top_n);
    return 0;
}