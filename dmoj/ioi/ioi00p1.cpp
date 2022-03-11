#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int dp[2][5001];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    
    string s;
    cin >> s;

    string t = "";
    
    for (int i = n-1; i >= 0; i --) {
        t += s[i];
    }

    for (int j = 0; j <= n; j ++) {
        dp[0][j] = 0;
        dp[1][j] = 0;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[1][j] = max(dp[1][j], dp[0][j]);
            dp[1][j] = max(dp[1][j], dp[1][j-1]);
            if (s[i-1] == t[j-1]) {
                dp[1][j] = max(dp[1][j], dp[0][j-1] + 1);
            }
        }
        for (int j = 0; j <= n; j ++) {
            dp[0][j] = dp[1][j];
        }
        for (int j = 0; j <= n; j ++) {
            dp[1][j] = 0;
        }
    }

    cout << n - dp[0][n];
}
