#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100000;
vector<int> graph[MAX_N + 1];
bool visited[MAX_N + 1] = {false};
bool on_stack[MAX_N + 1] = {false};
bool contains_cycle = false;
vector<int> top_ordering;

void dfs(int u) {
    if (on_stack[u]) {
        contains_cycle |= true;
        return;
    }
    if (visited[u]) {
        return;
    }
    on_stack[u] = true;
    visited[u] = true;
    for (int v : graph[u]) {
        dfs(v);
    }
    on_stack[u] = false;
    top_ordering.push_back(u);
}

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%i %i", &u, &v);
        graph[u].push_back(v);
    }

    for (int u = 1; u <= n; ++u) {
        dfs(u);
    }

    if (contains_cycle) {
        printf("IMPOSSIBLE\n");
    } else {
        for (auto it = top_ordering.rbegin(); it != top_ordering.rend(); it++) {
            printf("%i ", *it);
        }
        printf("\n");
    }
}
