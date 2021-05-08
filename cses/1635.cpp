#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    const int MOD = 1e9 + 7;

    int n, x;
    scanf("%i %i", &n, &x);

    int coins[100] = {};
    for (int i = 0; i < n; i++) {
        scanf("%i", coins + i);
    }

    int dp[1000001] = {};
    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            int coin = coins[j];
            if (i + coin > x) {
                continue;
            }
            dp[i + coin] += dp[i] % MOD;
            dp[i + coin] %= MOD;
        }
    }

    printf("%i\n", dp[x] % MOD);
}
