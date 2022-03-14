#include <iostream>

using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    scanf("%i %i %i %i", &a, &b, &c, &d);
    if (c < a) {
        swap(a, c);
        swap(b, d);
    }

    int ans = b - a + d - c;
    if (c < b) {
        ans -= min(b, d) - c;
    }
    printf("%i\n", ans);
}
