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

int main() {
    int n, m, temp, a, b;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        path.push_back(temp);
    }

    for (int i = 0 ; i < m; i ++) {
        scanf("%i %i", &a, &b);
        graph[a].insert(b);
        graph[b].insert(a);
    }

    vector<int> currpath;
    currpath.push_back(1);
    bool found = false;
    visited[1] = 1;
    for (int i = 1; i < n; i ++) {
        int target = path[i];
        found = false;
        for (int p = currpath.size() - 1; p >= 0; p --) {
            int parent = currpath[p];
            if (graph[parent].find(target) != graph[parent].end()) {
                currpath.push_back(target);
                found = true;
                visited[target] = 1;
                break;
            } else {
                for (auto it = graph[parent].begin(); it!= graph[parent].end(); it ++) {
                    if (!visited[*it]) {
                        printf("0");
                        return 0;
                    }
                }
                currpath.pop_back();
            }
        }
        if (!found) {
            printf("0");
            return 0;
        }
    }
    printf("1");

}