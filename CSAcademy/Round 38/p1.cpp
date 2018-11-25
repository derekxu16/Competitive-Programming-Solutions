#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int a[101][2];
    memset(a, 0, sizeof a);

    int n;
    scanf("%i", &n);

    for (int i = 0; i < n; i ++) {
        int size;
        char foot;
        scanf("%i %c", &size, &foot);
        if (foot == 'L') {
            a[size][0] += 1;
        } else if (foot == 'R') {
            a[size][1] += 1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i ++) {
        int pairs = min(a[i][0], a[i][1]);
        ans += pairs;
    }
    printf("%i", ans);
}