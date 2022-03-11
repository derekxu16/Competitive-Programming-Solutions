#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    vector<int> graph[8];
    int indegree[8] = {0};

    auto addEdge = [&graph, &indegree](int u, int v) {
        graph[u].push_back(v);
        indegree[v]++;
    };

    // Original constraints.
    addEdge(1, 7);
    addEdge(1, 4);
    addEdge(2, 1);
    addEdge(3, 4);
    addEdge(3, 5);

    // Additional constraints.
    while (true) {
        int u, v;
        scanf("%i %i", &u, &v);
        if (u == 0 && v == 0) {
            break;
        }
        addEdge(u, v);
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int u = 1; u <= 7; ++u) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }

    vector<int> top_ordering;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        top_ordering.push_back(u);

        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (top_ordering.size() == 7) {
        for (int u : top_ordering) {
            printf("%i ", u);
        }
        printf("\n");
    } else {
        printf("Cannot complete these tasks. Going to bed.\n");
    }
}
