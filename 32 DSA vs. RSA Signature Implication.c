#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dsa_sign(const char *message, int *r, int *s) {
    int k = rand() % 100 + 1; 
    *r = (k * 17) % 97;       
    *s = (k + 5) % 97;       
}

int main() {
    srand(time(NULL));
    char *msg = "Confidential Data";
    int r1, s1, r2, s2;

    dsa_sign(msg, &r1, &s1);
    dsa_sign(msg, &r2, &s2);

    printf("DSA Signature 1: r=%d, s=%d\n", r1, s1);
    printf("DSA Signature 2: r=%d, s=%d (Different due to random k)\n", r2, s2);
    printf("Implication: Reusing 'k' in DSA leaks the private key, unlike RSA which is deterministic.\n");
    return 0;
}