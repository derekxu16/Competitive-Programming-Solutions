#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
typedef pair<int,int> iPair;
#define mp make_pair

vector<int> path;
unordered_set<int> graph[100001];
bool visited[100001];

int temp;
const long long MOD = 10000000007;
int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    long long ans = 0;
    n ++; m++;

    long long ways;
    for (int i = 1; i < min(n,m); i ++) {
        ways = 1;
        ways = (m-i) % MOD;
        ways *= (n-i) % MOD;
        ways %= MOD;
        ways *= (i % MOD) % MOD;
        ways %= MOD;
        ans += ways % MOD;
        ans %= MOD;
    }

    printf("%lli", ans%MOD);

}