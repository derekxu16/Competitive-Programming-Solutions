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

using namespace std;

// prob[a] is the probability of choosing present a.
long long prob[1000001] = {};
// asked[a] is the number of children that asked for present a.
long long asked[1000001] = {};

int main() {
    const long long MOD = 998244353;

    long long n;
    scanf("%lli", &n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%i", &k);

        for (int j = 0; j < k; j++) {
            int a;
            scanf("%i", &a);

            asked[a]++;

            prob[a] += binPow(n * k, MOD - 2, MOD);
            prob[a] %= MOD;
        }
    }

    long long n_inverse = binPow(n, MOD - 2, MOD);
    long long ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        ans += prob[i] * asked[i] % MOD * n_inverse % MOD;
        ans %= MOD;
    }
    printf("%lli\n", ans);
}
