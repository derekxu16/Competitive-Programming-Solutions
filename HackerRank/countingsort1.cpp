#include <iostream>

using namespace std;

int count[100];

int main() {
    int n, temp;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        count[temp] ++;
    }
    for (int i = 0; i < 100; i ++) {
        printf("%i ", count[i]);
    }
}