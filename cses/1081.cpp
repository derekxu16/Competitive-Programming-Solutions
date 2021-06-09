#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%i", &n);

    int seen[1000001] = {};
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%i", &a);

        for (int factor = 1; factor * factor <= a; factor++) {
            if (a % factor == 0) {
                seen[factor]++;
                if (seen[factor] >= 2) {
                    ans = max(ans, factor);
                }

                if (factor == a / factor) {
                    continue;
                }

                seen[a / factor]++;
                if (seen[a / factor] >= 2) {
                    ans = max(ans, a / factor);
                }
            }
        }
    }

    printf("%i\n", ans);
}
