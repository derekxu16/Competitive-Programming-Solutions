#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> low, high;

    int n, k;
    scanf("%i %i", &n, &k);

    int a[200000];
    for (int i = 0; i < n; i++) {
        scanf("%i", a + i);
    }

    low.insert(a[0]);
    for (int i = 1; i <= n; i++) {
        if (i >= k) {
            printf("%i ", *low.rbegin());
            if (low.find(a[i-k]) != low.end()) {
                low.erase(low.find(a[i-k]));
                if (low.size() < high.size()) {
                    low.insert(*high.begin());
                    high.erase(high.begin());
                }
            } else {
                high.erase(high.find(a[i-k]));
                if (low.size() - high.size() == 2) {
                    high.insert(*low.rbegin());
                    low.erase(--low.end());
                }
            }
            if (i == n) {
                break;
            }
        }
        if (!low.empty() && a[i] > *low.rbegin()) {
            if (low.size() <= high.size()) {
                if (a[i] > *high.begin()) {
                    low.insert(*high.begin());
                    high.erase(high.begin());
                    high.insert(a[i]);
                } else {
                    low.insert(a[i]);
                }
            } else {
                high.insert(a[i]);
            }
        } else {
            low.insert(a[i]);
            if (low.size() - high.size() == 2) {
                high.insert(*low.rbegin());
                low.erase(--low.end());
            }
        }
    }
    printf("\n");
}
