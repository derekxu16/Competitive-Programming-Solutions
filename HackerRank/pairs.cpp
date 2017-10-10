#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, bool> visited;
int main() {
    int n, k, temp, count = 0;
    scanf("%i %i", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        visited[temp] = 1;
    }
    for (auto it = visited.begin(); it != visited.end(); it ++) {
        if (it->second == 1 && visited[k+it->first] == 1) {
            count ++;
        }
    }
    printf("%i", count);
}
