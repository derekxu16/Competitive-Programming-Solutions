#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n, temp;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    int i = 0, cost = 0, currbound = -1;
    while (i < n) {
        if (arr[i] > currbound) {
            currbound = arr[i]+4;
            cost ++;
        }
        i ++;
    }
    printf("%i", cost);
}
