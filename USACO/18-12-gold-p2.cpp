#include <iostream>

using namespace std;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    scanf("%i %i", &n, &k);

    int s[10001];
    for (int i = 0; i < n; i++) {
        scanf("%i", s + i);
    }

    int dp[10001] = {};
    for (int i = 1; i <= n; i++) {
        int max_s = 0;
        for (int j = i; j <= min(n, i + k - 1); j++) {
            max_s = max(max_s, s[j - 1]);
            dp[j] = max(dp[j], dp[i - 1] + max_s * (j - i + 1));
        }
    }

    printf("%i\n", dp[n]);
}
