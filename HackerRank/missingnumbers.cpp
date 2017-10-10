#include <iostream>
#include <algorithm>

using namespace std;

int count1[10001], count2[10001];
int main() {
    int n, temp;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        count1[temp] ++;
    }
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        count2[temp] ++;
    }

    for (int i = 0; i <= 10000; i ++) {
        if (count2[i] > count1[i]) {
            printf("%i ", i);
        }
    }
}
    
