#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> iPair;
typedef long long ll;
typedef pair<long long, long long> pll;
#define mp make_pair

int main() {
    int n, e1, e2;
    scanf("%i %i %i", &n, &e1, &e2);

    if (e1 > e2) {
        swap(e1, e2);
    }
    
    int a, b;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        scanf("%i %i", &a, &b);
        if (a < b) {
            if (a >= e1) {
                ans ++;
            }
        } else {
            if (a <= e2) {
                ans ++;
            }
        }
    }
    printf("%i", ans);
}