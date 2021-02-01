#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int letter_map[26];
int counts[20][20];
int memo[1048576];

int dp(int mask) {
    if (mask == 0) {
        return 0;
    }
    
    if (memo[mask] != -1) {
        return memo[mask];
    }

    int ans = 999999999;
    for (int i = 0; i < 20; i ++) {
        if ((mask & (1 << i)) == 0) {
            continue;
        }
        int sum = 0;
        for (int j = 0; j < 20; j ++) {
            if ((mask & (1 << j)) == 0) {
                continue;
            }
            sum += counts[j][i];
        }
        ans = min(ans, dp(mask ^ (1 << i)) + sum);
    }
    return memo[mask] = ans;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(letter_map, -1, sizeof letter_map);
    memset(memo, -1, sizeof memo);

    string s;
    cin >> s;

    int letter_key = 0;

    for (int i = 1; i < s.length(); i ++) {
        char first = s[i-1] - 'a';
        char second = s[i] - 'a';

        if (letter_map[first] == -1) {
            letter_map[first] = letter_key;
            letter_key ++;
        }
        if (letter_map[second] == -1) {
            letter_map[second] = letter_key;
            letter_key ++;
        }
        // Increment the count of the number of times that s[i-1] appears before s[i]
        counts[letter_map[first]][letter_map[second]] ++;
    }

    cout << dp((1 << 20) - 1) + 1 << endl;
}
