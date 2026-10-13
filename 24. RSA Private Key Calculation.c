#include <stdio.h>

long extendedGcd(long a, long b, long *x, long *y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    long x1, y1;
    long gcd = extendedGcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main() {
    long n = 3599;
    long e = 31;
    long p = 59, q = 61; // Since 59 * 61 = 3599
    long phi = (p - 1) * (q - 1);
    long d, y;
    extendedGcd(e, phi, &d, &y);
    if (d < 0) d += phi;
    printf("24. RSA Calculation:\n");
    printf("Modulus n = %ld, Public key e = %ld\n", n, e);
    printf("Primes p = %ld, q = %ld\n", p, q);
    printf("Phi(n) = %ld\n", phi);
    printf("Calculated Private key d = %ld\n", d);
    return 0;
}