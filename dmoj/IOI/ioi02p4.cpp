#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
#include <climits>

using namespace std;

#define mp make_pair

typedef pair<int, int> iPair;

int n, s;
int t[10001], f[10001];
int dp[10001];

int cost(int i, int j) {
    return s * (f[n] - f[j]) + (f[j] - f[i]) * (s + t[j]);
}

int main() {
    t[0] = f[0] = 0;
    scanf("%i %i", &n, &s);
    for (int i = 1; i <= n; i ++) {
        scanf("%i %i", t+i, f+i);
        t[i] += t[i-1];
        f[i] += f[i-1];
    }

    deque<iPair> v;
    v.push_back(mp(n,n));

    dp[n] = 0;

    for (int j = n-1; j >= 0; j --) {
        int k = (lower_bound(v.begin(), v.end(), mp(j, 0)))->second;
        dp[j] = dp[k] + cost(j,k);
        for (int z = 0; z < v.size(); z ++) {
            int i = v[z].first;
            int oldk = v[z].second;
            if (i < j && dp[j] + cost(i, j) < dp[oldk] + cost(i, oldk)) {
                v.pop_front();
                z--;
            } else {
                int l = 0, r = i;
                while (l < r) {
                    int mid = (l+r)/2;
                    if (dp[j] + cost(mid, j) <= dp[oldk] + cost(mid,  oldk)) {
                        l = mid+1;
                    } else {
                        r = mid;
                    }
                }
                v.push_front(mp(l-1, j));
                break;
            }
        }
        if (v.size() == 0) {
            v.push_back(mp(n, j));
        }
    }
    printf("%i", dp[0]);
}
