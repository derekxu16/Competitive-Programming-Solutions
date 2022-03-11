#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> iPair;
#define mp make_pair

struct Node {
    int v, cost;
    Node(int v_, int cost_) {
        v = v_;
        cost = cost_;
    }
};

bool visited[100001];
iPair toBot[100001];
int toBot2[100001];
vector<Node> graph[100001];
vector<int> radii;
int longestInTree = 0;

int travelTime(int N, int M, int L, int A[], int B[], int T[]);

void dfs(int start, int parent) {
    visited[start] = true;
    for (Node adj: graph[start]) {
        if (adj.v == parent) continue;
        dfs(adj.v, start);
        if (toBot[adj.v].first + adj.cost > toBot[start].first) {
            toBot2[start] = toBot[start].first;
            toBot[start] = mp(toBot[adj.v].first + adj.cost, adj.v);
        } else if (toBot[adj.v].first + adj.cost > toBot2[start]) {
            toBot2[start] = toBot[adj.v].first + adj.cost;
        }
    }
}

int solve(int start, int parent, int longest) {
    int shortest = 999999999;
    for (Node adj : graph[start]) {
        if (adj.v == parent) continue;
        if (toBot[start].second == adj.v) {
            shortest = min(shortest, solve(adj.v, start, max(longest, toBot2[start]) + adj.cost));
        } else {
            shortest = min(shortest, solve(adj.v, start, max(longest, toBot[start].first) + adj.cost));
        }
    }
    longestInTree = max(max(toBot[start].first, longest), longestInTree);
    return min(shortest, max(toBot[start].first, longest));
}

int main() {
    int N = 12, M = 8, L = 2;
    int A[] = {0, 8, 2, 5, 5, 1, 1, 10};
    int B[] = {8, 2, 7, 11, 1, 3, 9, 6};
    int T[] = {4, 2, 4, 3, 7, 1, 5, 3};
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    for (int i = 0; i < M; i ++) {
        graph[A[i]].push_back(Node(B[i], T[i]));
        graph[B[i]].push_back(Node(A[i], T[i]));
    }
    for (int i = 0; i < N; i ++) {
        if (visited[i])
            continue;
        dfs(i, -1);
        radii.push_back(solve(i, -1, 0));
    }

    sort(radii.begin(), radii.end(), greater<int>());

    return max(longestInTree, max(radii.size() > 1 ? radii[0] + L + radii[1] : 0, radii.size() >= 3 ? radii[1] + 2*L + radii[2] : 0));
}
