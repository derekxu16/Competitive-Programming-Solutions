#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {
    vector<pair<int, int>> stack;

    int n;
    scanf("%i", &n);

    int a;
    for (int i = 0; i < n; i ++) {
        scanf("%i", &a);
        while (!stack.empty() && stack.back().first >= a) {
            stack.pop_back();
        }

        if (stack.empty()) {
            printf("0 ");
        } else {
            printf("%i ", stack.back().second);
        }
        stack.emplace_back(a, i+1);
    }
}
