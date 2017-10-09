#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> items;
int n;

int cont();
int dp(int);
int memo[100001];

int main() {
  int trials;
  int temp;
  scanf("%i", & trials);
  for (int z = 0; z < trials; z ++) {
    items.clear();
    memset(memo,-1,sizeof memo);
    scanf("%i", & n);
    for (int i = 0; i < n; i ++) {
      scanf("%i", &temp);
      items.push_back(temp);
    }
    int ans;
    printf("%i %i\n", cont(), dp(0));
  }
}

int dp(int i) {
  if (memo[i] != -1)
    return memo[i];
  if (i == n) {
    return 0;
  }
  if (i == n - 1)
    return items[i];
  int maxi = max(dp(i+1) + items[i], dp(i+1));
  if (i == n - 2 && maxi > 0) {
    maxi = max(maxi, dp(n) + items[i]);
  }
  memo[i] = maxi;
  return maxi;
}

int cont() {
  int maxi, curr;

  curr = items[0];
  maxi = curr;

  for (int i = 1; i < n; i ++) {
    curr = max(curr + items[i],items[i]);
    maxi = max(curr,maxi);
  }
  return maxi;
}
