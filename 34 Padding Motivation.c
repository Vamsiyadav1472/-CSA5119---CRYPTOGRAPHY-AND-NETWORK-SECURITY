#include <stdio.h>
#include <string.h>

void apply_padding(unsigned char *block, int current_len, int block_size) {
    block[current_len] = 0x80; // 1 bit followed by zeros
    for (int i = current_len + 1; i < block_size; i++) {
        block[i] = 0x00;
    }
}

int main() {
    unsigned char block[8] = "TEST";
    int len = strlen((char*)block);
    
    apply_padding(block, len, 8);
    printf("Padded block applied successfully.\n");
    return 0;
}