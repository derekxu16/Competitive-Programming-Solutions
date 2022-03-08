#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%i %i", &n, &k);

    int a[500000];
    int count[1000001] = {0};

    int distinct = 0;
    pair<int, int> ans = {0, 0};
    int l = 0;
    for (int r = 0; r < n; r ++) {
        scanf("%i", a + r);
        while (distinct == k && count[a[r]] == 0) {
            count[a[l]] --;
            if (count[a[l]] == 0) {
                distinct --;
            }
            l ++;
        }
        if (count[a[r]] == 0) {
            distinct ++;
        }
        count[a[r]] ++;
        if (r - l > ans.second - ans.first) {
            ans = {l, r};
        }
    }

    printf("%i %i\n", ans.first + 1, ans.second + 1);
}
