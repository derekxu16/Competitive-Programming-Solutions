#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    set<int> set;

    int n;
    scanf("%i", &n);

    int k[200000];
    for (int i = 0; i < n; i ++) {
        scanf("%i", k + i);
    }

    int ans = 0;
    int l = 0;
    for (int r = 0; r < n; r ++) {
        while (set.find(k[r]) != set.end()) {
            set.erase(k[l]);
            l ++;
        }
        set.insert(k[r]);
        ans = max(ans, (int)set.size());
    }

    printf("%i\n", ans);
}
