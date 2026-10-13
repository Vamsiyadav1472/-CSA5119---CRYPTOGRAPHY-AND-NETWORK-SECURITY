#include <stdio.h>
#include <math.h>

int main() {
    printf("11. Playfair Key Space Analysis:\n");
    printf("a. Total possible keys without restrictions: 25! approx 1.55 x 10^25, which is roughly 2^84.\n");
    printf("b. Taking into account equivalent rows/columns and letter inversions (I/J): \n");
    printf("   The number of effectively unique keys is 25! / (5! * 5! * 2) approx 3.11 x 10^18 (roughly 2^61).\n");
    return 0;
}