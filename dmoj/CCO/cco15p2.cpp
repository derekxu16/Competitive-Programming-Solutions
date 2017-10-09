#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <cstring>
#include <utility>

#define s(x) scanf("%i", &x);

using namespace std;

int dp(int,int);
vector<vector<int>> graph;
int edges[18][18];
int memo[18][262145];

int main() {
  int n,m;
  s(n);
  s(m);

  memset(memo,-1,sizeof memo);

  for (int i = 0; i < n; i ++) {
    graph.push_back(vector<int>());
  }

  int mask = pow(2,n) -1;

  int a,b,c;
  for (int i = 0; i < m; i ++) {
    scanf("%i%i%i",&a,&b,&c);
    graph[b].push_back(a);
    edges[b][a] = c;
  }
  printf("%i",dp(n-1,mask));
}

int dp(int end, int mask) {
  if (memo[end][mask] != -1)
    return memo[end][mask];

  int max = -9999999;
  int curr;
  if (end == 0) {
    return 0;
  }
  for (int node : graph[end]) {
    if ((mask & (1 << node)) != 0) {
      curr = dp(node, mask&~(1<<end)) + edges[end][node];
      if (curr > max)
        max = curr;
    }
  }
  memo[end][mask] = max;
  return max;
}
