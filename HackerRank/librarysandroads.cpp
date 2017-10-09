#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

bool visited[100005];
deque<int> q;
int main() {
    int queries, n, m;
    long long clib, croad;
    scanf("%i", &queries);
    for (int zzz = 0; zzz < queries; zzz ++) {
        scanf("%i %i %lli %lli", &n, &m, &clib, &croad);
        vector<vector<int> > graph(100005, vector<int>());
        q.clear();
        memset(visited, 0, sizeof visited);
        int a, b;
        long long cost = 0;

        for (int i = 0; i < m; i ++) {
            scanf("%i %i", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i ++) {
            if (visited[i]) {
                continue;
            }
            cost += clib;
            q.push_back(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop_front();
                if (visited[node]) {
                    continue;
                }
                if (node != i)
                    cost += croad;
                visited[node] = 1;
                for (int adj : graph[node]) {
                    if (!visited[adj]) {
                        q.push_back(adj);
                    }
                }
            }
        }
        printf("%lli\n", min(cost, (long long) (clib * n)));
    }
}