#include <stdio.h>

int main() {
    printf("20. Error Propagation Analysis:\n");
    printf("a. Beyond P2, blocks are NOT affected in CBC mode because plaintext blocks depend only on current and previous ciphertext blocks (P_i = D_K(C_i) XOR C_{i-1}).\n");
    printf("b. A bit error in source P1 propagates through all subsequent ciphertext blocks because each ciphertext block chains into the input of the next encryption operation.\n");
    return 0;
}