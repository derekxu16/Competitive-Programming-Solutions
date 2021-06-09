#include <iostream>

/**
 * Computes a^b % m using binary exponentiation.
 */
long long binPow(long long a, long long b, long long m) {
    a %= m;

    long long ans = 1;
    for (int bit = 0; bit <= 31; bit++) {
        if (b & (1 << bit)) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        a %= m;
    }

    return ans;
}

int main() {
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lli %lli %lli", &a, &b, &c);
        // a^(p-1) = 1 (mod p), so a^(b^c) = a^(b^c % (p-1)) (mod p)
        printf("%lli\n", binPow(a, binPow(b, c, 1e9 + 6), 1e9 + 7));
    }
}
