#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
vector<int> graph[100001];
int indegree[100001] = {0};
/// `paths[u]` is the number of distinct paths from `u` to a vertex with outdegree 0.
int paths[100001] = {0};
/// `answer[u]` is the sum of the lengths of all paths from `u` to a vertex with outdegree 0.
long long answer[100001] = {0};

long long solve(int u) {
    if (graph[u].empty()) {
        paths[u] = 1;
        return 0;
    }
    if (answer[u] != 0) {
        return answer[u];
    }
    for (int v : graph[u]) {
        answer[u] += solve(v) % MOD;
        answer[u] %= MOD;
        paths[u] += paths[v] % MOD;
        paths[u] %= MOD;
    }
    // Increment the length of each path by 1.
    answer[u] += paths[u];
    answer[u] %= MOD;
    return answer[u];
}

int main() {
    int n, m;
    scanf("%i %i", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%i %i", &u, &v);
        graph[u].push_back(v);
        indegree[v]++;
    }

    long long final_answer = 0;
    for (int u = 1; u <= n; u++) {
        if (indegree[u] == 0) {
            final_answer += solve(u);
            final_answer %= MOD;
        }
    }
    printf("%lli\n", final_answer);
}
