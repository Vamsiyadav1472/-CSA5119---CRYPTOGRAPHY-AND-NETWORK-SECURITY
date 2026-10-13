#include <stdio.h>

int main() {
    printf("26. RSA Key Leak Evaluation:\n");
    printf("If Bob leaks his private key d, anyone can compute phi(n) and factor n = pq. Reusing modulus n with new public/private keys is completely insecure; a new modulus must be generated.\n");
    return 0;
}