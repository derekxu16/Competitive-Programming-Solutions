#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%i %i", &n, &m);

    vector<int> graph[100001];

    for (int i = 0; i < m; i ++) {
        int u, v;
        scanf("%i %i", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    deque<int> q(1, 1);
    int visited_from[100001];
    fill(visited_from, visited_from + n + 1, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        if (u == n) {
            vector<int> ans;
            int node = n;
            while (node != 1) {
                ans.push_back(node);
                node = visited_from[node];
            }
            ans.push_back(node);

            printf("%lu\n", ans.size());
            for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it ++) {
                printf("%i ", *it);
            }
            printf("\n");
            return 0;
        }

        for (int v : graph[u]) {
            if (visited_from[v] != -1) {
                continue;
            }
            visited_from[v] = u;
            q.push_back(v);
        }
    }
    printf("IMPOSSIBLE\n");
}
