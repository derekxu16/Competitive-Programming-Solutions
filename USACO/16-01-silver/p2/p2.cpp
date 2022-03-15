#include <iostream>

using namespace std;

const int MAX_N = 50000;
int prefixes[MAX_N + 1] = {0};

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    scanf("%i", &n);

    // `first_occurrence_of[n]` holds the index of the first index `i` where `prefix[i] == n`.
    int first_occurrence_of[7] = {0, -1, -1, -1, -1, -1, -1};

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%i", prefixes + i);
        prefixes[i] += prefixes[i - 1];
        prefixes[i] %= 7;
        if (first_occurrence_of[prefixes[i]] == -1) {
            first_occurrence_of[prefixes[i]] = i;
        }
        ans = max(ans, i - first_occurrence_of[prefixes[i]]);
    }

    printf("%i\n", ans);
}
