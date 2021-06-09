#include <cstring>
#include <iostream>

using namespace std;

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    int n, k;
    scanf("%i %i", &n, &k);
    k++;

    int g[400];
    for (int i = 0; i < n; i++) {
        scanf("%i", g + i);
    }

    int dp[401][402];
    for (int i = 0; i <= n; i++) {
        for (int nets = 0; nets <= k; nets++) {
            dp[i][nets] = 999999999;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int nets = 0; nets < k; nets++) {
            int max_g = 0;
            int sum_g = 0;
            for (int j = i; j < n; j++) {
                max_g = max(max_g, g[j]);
                sum_g += g[j];

                dp[j + 1][nets + 1] = min(dp[j + 1][nets + 1], dp[i][nets] + max_g * (j - i + 1) - sum_g);
            }
        }
    }

    printf("%i\n", dp[n][k]);
}
