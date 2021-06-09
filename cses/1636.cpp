#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const int MOD = 1e9 + 7;

    int n, x;
    scanf("%i %i", &n, &x);

    int dp[1000001] = {};
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%i", &c);

        for (int j = 0; j < x; j++) {
            if (j + c > x) {
                continue;
            }
            dp[j + c] += dp[j] % MOD;
            dp[j + c] %= MOD;
        }
    }

    printf("%i\n", dp[x] % MOD);
}
