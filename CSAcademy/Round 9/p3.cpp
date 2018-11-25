#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int a[50][50], cols[50];
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            scanf("%i", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i ++) {
        if (!a[i][0]) {
            for (int j = 0; j < m; j++) {
                a[i][j] = !a[i][j];
            }
        }
    }

    for (int j = 0; j < m; j ++) {
        for (int i = 0; i < n; i ++) {
            cols[j] += a[i][j];
        }
    }

    long long ans = 0;
    for (int j = 0; j < m; j ++) {
        ans += (long long)pow(2, m - j - 1) * max(cols[j], n - cols[j]);
    }
    printf("%lli", ans);
}