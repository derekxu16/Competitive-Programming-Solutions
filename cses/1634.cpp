#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, x;
    scanf("%i %i", &n, &x);

    int dp[1000001];
    fill(dp, dp + 1000001, 999999999);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%i", &c);

        for (int j = 0; j < x; j++) {
            if (j + c > x) {
                continue;
            }
            dp[j + c] = min(dp[j + c], dp[j] + 1);
        }
    }

    printf("%i\n", dp[x] == 999999999 ? -1 : dp[x]);
}
