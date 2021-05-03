#include <iostream>

int main() {
    const long long MOD = 1e9 + 7;

    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i ++) {
        long long a, b;
        scanf("%lli %lli", &a, &b);

        a %= MOD;

        long long ans = 1;
        for (int bit = 0; bit <= 31; bit ++) {
            if (b & (1 << bit)) {
                ans *= a;
                ans %= MOD;
            }
            a *= a;
            a %= MOD;
        }

        printf("%lli\n", ans);
    }
}
