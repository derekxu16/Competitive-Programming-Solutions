#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int counts[2] = {};
    for (int i = 0; i < s.size(); i += 2) {
        counts[s[i] - 'A'] += s[i + 1] - '0';
    }

    cout << (counts[0] > counts[1] ? "A" : "B");
}
