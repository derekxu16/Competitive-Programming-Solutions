#include <iostream>
#include <algorithm>

int a[100001];
int main() {
    int t, n, temp, total = 0;
    bool done;
    scanf("%i", &t);
    for (int zzz = 0; zzz < t; zzz ++) {
        a[0] = 0;
        total = 0;
        done = false;
        scanf("%i", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%i", &temp);
            a[i] = a[i-1] + temp;
            total += temp;
        }
        for (int i = 1; i <= n; i ++) {
            if (a[i-1] == total-a[i]) {
                printf("YES\n");
                done = true;
                break;
            }
        }
        if (!done) printf("NO\n");
    }
}
