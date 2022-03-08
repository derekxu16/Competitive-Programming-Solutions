#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
int component[1001] = {0};
int component_size[1001] = {0};

void dfs(int u, int current_component) {
    if (component[u] != 0) {
        return;
    }

    component[u] = current_component;
    component_size[current_component] += 1;

    for (int v : graph[u]) {
        dfs(v, current_component);
    }
}

int main() {
    int n;
    scanf("%i", &n);

    int num_edges = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int does_edge_exist;
            scanf("%i", &does_edge_exist);
            if (does_edge_exist) {
                num_edges += 1;
                graph[u].push_back(v);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        if (component[u] == 0) {
            dfs(u, u);
        }
    }

    int sum = 0;
    for (int c = 1; c <= n; c++) {
        if (component_size[c] == 0) {
            continue;
        }
        sum += component_size[c] - 1;
    }

    printf("%i\n", num_edges / 2 - sum);
}
