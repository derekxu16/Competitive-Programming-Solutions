#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

vector<int> a;
int dp[16][1000001];
int main() {
    memset(dp, 0, sizeof(dp));

    int n, t;
    scanf("%i %i", &n, &t);

    for (int i = 0; i < n; i ++) {
        int temp;
        scanf("%i", &temp);
        a.push_back(temp);
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= t; j ++) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = a[i-1]; j <= t; j ++) {
            dp[i][j] += dp[i-1][j-a[i-1]];
        }
    }

    printf("%i", dp[n][t]);
}
