#include <cstring>
#include <iostream>

using namespace std;

int dp[100001][22][3];

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    memset(dp, 0, sizeof dp);

    int n, k;
    scanf("%i %i", &n, &k);

    for (int i = 0; i < n; i++) {
        char g;
        scanf(" %c", &g);
        int beaten_by;
        switch (g) {
            case 'H':
                beaten_by = 0;
                break;
            case 'P':
                beaten_by = 1;
                break;
            case 'S':
                beaten_by = 2;
                break;
        }

        for (int switches = 0; switches <= k; switches++) {
            for (int last_choice = 0; last_choice < 3; last_choice++) {
                dp[i + 1][switches][last_choice] = max(dp[i + 1][switches][last_choice],
                                                       dp[i][switches][last_choice] + (int)(last_choice == beaten_by));
                for (int next_choice = 0; next_choice < 3; next_choice++) {
                    dp[i + 1][switches + 1][next_choice] =
                        max(dp[i + 1][switches + 1][next_choice],
                            dp[i][switches][last_choice] + (int)(next_choice == beaten_by));
                }
            }
        }
    }

    int ans = 0;
    for (int choice = 0; choice < 3; choice++) {
        ans = max(ans, dp[n][k][choice]);
    }

    printf("%i\n", ans);
}
