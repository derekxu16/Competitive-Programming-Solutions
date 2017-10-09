#include <iostream>
#include <vector>

using namespace std;

vector<int> set;
vector<int> uRank;

void initialize(int);

int c, limit, connected = 1, nodes;

int find(int x) {
    int next = set[x];
    if (x == next)
        return x;
    else
        return set[x] = find(next);
}

void initialize(int n) {
    c = 0;
    limit = n * (n-1) / 2;
    nodes = n;
    for (int i = 0; i <= n; i ++)
        set.push_back(i);
        uRank.push_back(1);
}

int hasEdge(int a, int b) {
    int first,second;

    first = find(a);
    second = find(b);
    c ++;
    if (c == limit)
        return true;
    if (connected == nodes - 1)
        return false;
    if (first == second) {
        return false;
    } else {
        if (uRank[first] < uRank[second]) {
            set[first] = set[second];
        } else {
            set[first] = set[second];
            uRank[second] ++;
        }
        connected ++;
        return true;
    }
}
int main() {
    initialize(4);
    cout << hasEdge(0,3);
    cout << hasEdge(2,0);
    cout << hasEdge(0,1);
    cout << hasEdge(1,2);
    cout << hasEdge(1,3);
    cout << hasEdge(2,3);

    // cout << hasEdge(0,3);
    // cout << hasEdge(1,0);
    // cout << hasEdge(0,2);
    // cout << hasEdge(3,1);
    // cout << hasEdge(1,2);
    // cout << hasEdge(2,3);
}