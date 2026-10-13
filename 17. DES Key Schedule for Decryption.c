#include <stdio.h>

int main() {
    printf("17. DES Decryption Key Schedule:\n");
    printf("For decryption, subkeys are applied in reverse order: K16, K15, ..., K1.\n");
    printf("The shift schedule shifts are inverted or applied rightward instead of leftward to reverse key generation rotations.\n");
    return 0;
}