#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2000;
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
    int n, m, a, b;
    scanf("%i %i %i %i", &n, &m, &a, &b);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%i %i", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (dfs(a, b)) {
        printf("GO SHAHIR!\n");
    } else {
        printf("NO SHAHIR!\n");
    }
}
