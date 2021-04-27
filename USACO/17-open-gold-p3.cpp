#include <iostream>
#include <vector>

using namespace std;

enum class State {
    UNSEEN,
    OPEN,
    CLOSED,
};

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    State states[100001];
    fill(states, states + 10000, State::UNSEEN);
    int last_occurrence[100001];
    int a[100000];

    int n;
    scanf("%i", &n);

    vector<int> stack;
    int ans = 1;
    for (int i = 0; i < n; i ++) {
        scanf("%i", a+i);
        if (i > 0 && a[i] == a[i-1]) {
            i --;
            n --;
        }
        last_occurrence[a[i]] = i;
    }

    int depth = 0;
    for (int i = 0; i < n; i ++) {
        if (states[a[i]] == State::CLOSED) {
            printf("-1\n");
            return 0;
        } else if (states[a[i]] == State::UNSEEN) {
            states[a[i]] = State::OPEN;
            stack.push_back(a[i]);
            ans = max(ans, depth + 1);
            if (a[i] != 0 && last_occurrence[a[i]] > i) {
                depth ++;
            }
        } else if (states[a[i]] == State::OPEN) {
            while (stack.back() != a[i]) {
                states[stack.back()] = State::CLOSED;
                stack.pop_back();
            }
            if (a[i] != 0 && i == last_occurrence[a[i]]) {
                depth --;
            }
        }
    }

    printf("%i\n", ans);
}
