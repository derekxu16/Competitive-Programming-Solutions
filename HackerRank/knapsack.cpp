#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <cmath>

using namespace std;

int n, k;
vector<int> items;
int memo[2001][2001];

int dp(int,int);
int main() {
  int t, temp;
  scanf("%i", &t);
  for (int cases = 0; cases < t; cases ++) {
    scanf("%i %i", &n, &k);
    items.clear();
    memset(memo,-1,sizeof memo);
    for (int i = 0; i < n; i ++) {
      scanf("%i", & temp);
      items.push_back(temp);
    }
    printf("%i\n", dp(0,k));
  }
}

int dp (int i, int capacity) {
  if (memo[i][capacity] != -1)
    return memo[i][capacity];
  if (i >= n)
    return 0;
  int curr, max = 0;

  int limit = floor(capacity/items[i]);

  for (int j = 0; j <= limit; j ++) {
    curr = dp(i+1,capacity - j*items[i]) + items[i] * j;
    if (curr > max)
      max = curr;
  }
  memo[i][capacity] = max;
  return max;
}
