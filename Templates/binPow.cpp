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
