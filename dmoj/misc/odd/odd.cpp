#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%i", &x);
        ans ^= x;
    }

    printf("%i\n", ans);
}
