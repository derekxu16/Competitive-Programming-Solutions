#include <iostream>
#include <algorithm>
#include <set>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int, int> iPair;
#define mp make_pair

int a[100000], q[100000], dsu[100000];
long long sum[100000];

int find(int x) {
    if (x == dsu[x]) {
        return x;
    } else {
        return dsu[x] = find(dsu[x]);
    }
}

int main() {
    memset(sum, -1, sizeof sum);

    int n;
    long long ans = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", a+i);
        dsu[i] = i;
    }
    for (int i = 0; i < n; i ++) {
        scanf("%i", q+i);
    }

    deque<long long> answers;
    for (int i = n-1; i >= 0; i --) {
        int query = q[i]-1;
        sum[query] = a[query];
        if (query > 0 && sum[find(query-1)] > -1) {
            sum[query] += sum[find(query-1)];
            dsu[find(query-1)] = query;
        }
        if (query < n-1 && sum[find(query+1)] > -1) {
            sum[query] += sum[find(query+1)];
            dsu[find(query+1)] = query;
        }
        ans = max(ans, sum[query]);
        answers.push_front(ans);
    }
    for (long long a : answers) {
        printf("%lli\n", a);
    }
}