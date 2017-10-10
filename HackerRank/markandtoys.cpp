#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> >q;
    int n, k, temp, ans = 0;
    scanf("%i %i", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        q.push(temp);
    }
    while(!q.empty()) {
        int toy = q.top();
        q.pop();
        if (toy > k) {
            break;
        }
        k -= toy;
        ans ++;
    }
    printf("%i", ans);
}