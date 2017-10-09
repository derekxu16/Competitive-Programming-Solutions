#include <iostream>
#include <algorithm>

using namespace std;

int coins[50];
long long dp[251];
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < m; i ++) {
        scanf("%i", &coins[i]);
    }
    dp[0] = 1;
    for (int i = 0; i < m; i ++) {
        int currval = coins[i];
        for (int j = n; j >= 0; j --) {
            for (int k = currval; j-k >= 0; k += currval) {
                if (dp[j-k])
                    dp[j] += dp[j-k];
            }
        }
    }
    printf("%lli", dp[n]);
}