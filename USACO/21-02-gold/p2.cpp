#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);

    int a[300], dp[300][300] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%i", a + i);
    }

    for (int j = 1; j < n; j++) {
        for (int i = j - 1; i >= 0; i--) {
            if (a[i] == a[j]) {
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
            }
            for (int k = j - 1; k > i; k--) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    printf("%i\n", n - dp[0][n - 1]);
}
