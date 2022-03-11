#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int,int> iPair;
#define mp make_pair

int d[1600][3601];


struct Edge {
    int adj, w, type;
    Edge(int adj_, int w_, int type_) {
        adj = adj_;
        w = w_;
        type = type_;
    }
};

struct Path {
    int a, b, c;
    Path(int a_, int b_, int c_) {
        a = a_;
        b = b_;
        c = c_;
    }
};

struct Comp {
    bool operator() (Path &a, Path &b) {
        if (a.a == b.a)
            return a.c > b.c;
        return a.a > b.a;
    }
};

vector<Edge> graph[1600];
priority_queue<Path, deque<Path>, Comp > q;

int main() {
    int s, n, e;
    scanf("%i %i %i", &s, &n, &e);

    int a, b, c, f;
    for (int i = 0; i < e; i ++) {
        scanf("%i %i %i %i", &a, &b, &c, &f);
        graph[a].push_back(Edge(b,c,f));
        graph[b].push_back(Edge(a,c,f));
    }
    memset(d, 9999999, sizeof d);

    d[0][0] = 0;

    q.push(Path(d[0][0],0,0));

    while (!q.empty()) {
        //Get closest node
        int node = q.top().b;
        int j = q.top().c;
        q.pop();


        if (node == n-1)
            break;

        for (Edge adj: graph[node]) {
            //For each adjacent node, relax the edges and update shortest length
            int sun = 0;
            if (adj.type) {
                sun = adj.w;
            }
            if (j + sun > s)
                continue;
            if (d[node][j] + adj.w < d[adj.adj][j+sun]) {
                d[adj.adj][j+sun] = d[node][j] + adj.w;
                q.push(Path(d[adj.adj][j+sun], adj.adj, j+sun));
            }
        }
    }

    int ans = 99999999;

    for (int i = 0; i <= s; i ++) {
        if (d[n-1][i] < ans)
            ans = d[n-1][i];
    }

    if (ans == 99999999)
        printf("-1");
    else
        printf("%i", ans);
}