#include <stdio.h>
#include <stdint.h>

void des_encrypt(uint64_t plaintext, uint64_t key, uint64_t *ciphertext) {
    *ciphertext = plaintext ^ key; 
}

int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;
    uint64_t key = 0x133457799BBCDFFL;
    uint64_t ciphertext = 0;

    des_encrypt(plaintext, key, &ciphertext);
    printf("DES Plaintext:  0x%016llX\n", plaintext);
    printf("DES Ciphertext: 0x%016llX\n", ciphertext);
    return 0;
}