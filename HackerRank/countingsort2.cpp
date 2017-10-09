#include <iostream>
#include <vector>
#include <string>

using namespace std;

int counts[100];
vector<string> ids[100];

int main() {
    string tempstr;
    int n, temp;
    scanf("%i", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%i", &temp);
        cin >> tempstr;
        counts[temp] ++;
        if (i < n/2) {
            ids[temp].push_back("-");
        } else {
            ids[temp].push_back(tempstr);
        }
    }
    for (int i = 0; i < 100; i ++) {
        for (int j = 0; j < counts[i]; j ++) {
            cout << ids[i][j] << " ";
        }
    }
}