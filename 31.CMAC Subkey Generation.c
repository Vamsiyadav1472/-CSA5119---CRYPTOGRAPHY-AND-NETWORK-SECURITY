#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define BLOCK_SIZE_128 16 // 16 bytes = 128 bits
uint8_t left_shift_one_bit(uint8_t *block, int len) {
    uint8_t overflow = 0;
    for (int i = len - 1; i >= 0; i--) {
        uint8_t next_overflow = (block[i] & 0x80) ? 1 : 0;
        block[i] = (block[i] << 1) | overflow;
        overflow = next_overflow;
    }
    return overflow;
}
void generate_cmac_subkeys(const uint8_t *L, uint8_t *K1, uint8_t *K2, int block_size) {
    uint8_t const_val = (block_size == 8) ? 0x1B : 0x87;
    memcpy(K1, L, block_size);
    uint8_t msb_l = left_shift_one_bit(K1, block_size);
        if (msb_l) {
        K1[block_size - 1] ^= const_val;
    }
    memcpy(K2, K1, block_size);
    uint8_t msb_k1 = left_shift_one_bit(K2, block_size);
        if (msb_k1) {
        K2[block_size - 1] ^= const_val;
    }
}
void print_hex(const char *label, const uint8_t *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
}
int main() {
    uint8_t L[BLOCK_SIZE_128] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    uint8_t K1[BLOCK_SIZE_128];
    uint8_t K2[BLOCK_SIZE_128];
    printf("=== CMAC Subkey Generation (128-bit block / AES standard) ===\n\n");
    print_hex("Cipher Output L", L, BLOCK_SIZE_128);
    generate_cmac_subkeys(L, K1, K2, BLOCK_SIZE_128);
    printf("\n");
    print_hex("First Subkey K1 ", K1, BLOCK_SIZE_128);
    print_hex("Second Subkey K2", K2, BLOCK_SIZE_128);

    return 0;
}