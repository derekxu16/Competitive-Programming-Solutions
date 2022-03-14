#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<long long> set;

    int n, a, b;
    scanf("%i %i %i", &n, &a, &b);

    long long sum[200001];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lli", sum + i);
        sum[i] += sum[i - 1];
    }

    long long ans = -9e18;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            set.erase(set.find(sum[i - b - 1]));
        }
        set.insert(sum[i - a]);
        ans = max(ans, (long long)(sum[i] - *set.begin()));
    }

    printf("%lli\n", ans);
}
