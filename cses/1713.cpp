#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const int MAX = 1000000;

    int divisors[MAX + 1];
    fill(divisors, divisors + MAX + 1, 1);
    divisors[0] = 0;
    for (int i = 2; i <= MAX; i ++) {
        for (int j = i; j <= MAX; j += i) {
            divisors[j] ++;
        }
    }

    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%i", &x);
        printf("%i\n", divisors[x]);
    }
}
