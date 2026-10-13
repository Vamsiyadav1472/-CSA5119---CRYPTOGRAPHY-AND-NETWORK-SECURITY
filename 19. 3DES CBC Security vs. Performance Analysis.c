#include <stdio.h>

int main() {
    printf("19. 3DES CBC Analysis:\n");
    printf("a. For security: 3DES (specifically Option 1 with three independent keys) provides 112-bit security against meet-in-the-middle attacks.\n");
    printf("b. For performance: Standard DES or 2-key 3DES is faster, but 3DES is inherently slower due to triple encryption passes per block.\n");
    return 0;
}