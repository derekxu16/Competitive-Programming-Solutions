#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define mp make_pair

int find_subset(int l, int u, int w[], int n, int result[]) {
    vector<pair<int, int> > a;
    for (int i = 0; i < n; i ++) {
        a.push_back(mp(w[i], i));
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    int left = 0, right = 0;
    while (right < n && sum + a[right].first <= u) {
        sum += a[right].first;
        right ++;
    }

    while (sum < l) {
        if (left >= right) {
            return 0;
        }
        if (right < n) {
            sum += a[right].first;
            right ++;
        }
        sum -= a[left].first;
        left ++;
    }

    int ansInd = 0;
    for (int i = left; i < right; i ++) {
        result[ansInd] = a[i].second;
        ansInd ++;
    }
    return right-left;
}
