#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    const int MAX_LENGTH = 1000;

    int n, m, c;
    scanf("%i %i %i", &n, &m, &c);

    int gain[1001];
    for (int i = 1; i <= n; i ++) {
        scanf("%i", gain+i);
    }

    vector<int> graph[1001];
    for (int i = 0; i < m; i ++) {
        int u, v;
        scanf("%i %i", &u, &v);
        graph[u].push_back(v);
    }

    long long dp[1001][1001];
    fill(&dp[0][0], &dp[0][0] + (sizeof dp) / (sizeof dp[0][0]), -99999999999);
    dp[0][1] = gain[1];
    for (int length = 1; length <= MAX_LENGTH; length ++) {
        for (int u = 1; u <= n; u ++) {
            for (int v : graph[u]) {
                dp[length][v] = max(dp[length][v], dp[length-1][u] + gain[v] + c*(length - 1)*(length - 1) - c *length*length);
            }
        }
    }

    long long ans = 0;
    for (int length = 0; length <= MAX_LENGTH; length ++) {
        ans = max(ans, dp[length][1]);
    }
    printf("%lli\n", ans);
}
