#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;
vector<int> graph[MAX_N + 1];
bool visited[MAX_N + 1] = {false};

bool dfs(int u, int goal) {
    if (visited[u]) {
        return false;
    }
    if (u == goal) {
        return true;
    }

    visited[u] = true;
    bool ans = false;
    for (int v : graph[u]) {
        ans |= dfs(v, goal);
    }

    return ans;
}

int main() {
    int n, m;
    scanf("%i %i", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%i %i", &u, &v);
        graph[u].push_back(v);
    }

    int p, q;
    scanf("%i %i", &p, &q);
    if (dfs(p, q)) {
        printf("yes\n");
    } else {
        memset(visited, 0, sizeof visited);
        if (dfs(q, p)) {
            printf("no\n");
        } else {
            printf("unknown\n");
        }
    }
}
