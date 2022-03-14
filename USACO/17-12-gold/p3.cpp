#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>

template <typename T>
class MinMaxQueue {
   public:
    enum class Type { MIN, MAX };

   private:
    Type t;
    std::deque<std::pair<T, int>> q;
    int insert_index = 0;
    int erase_index = 0;
    bool shouldPopWhenInserting(const T& to_insert) {
        switch (t) {
            case Type::MIN:
                return to_insert < q.back().first;
            case Type::MAX:
                return to_insert > q.back().first;
        }
    }

   public:
    MinMaxQueue(Type t) : t(t) {}
    void pushBack(T to_insert) {
        while (!q.empty() && shouldPopWhenInserting(to_insert)) {
            q.pop_back();
        }
        q.emplace_back(to_insert, insert_index);
        insert_index ++;
    }
    void popFront() {
        if (q.front().second == erase_index) {
            q.pop_front();
        }
        erase_index ++;
    }
    T front() {
        return q.front().first;
    }
};

using namespace std;

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    MinMaxQueue<int> q(MinMaxQueue<int>::Type::MAX);

    int n;
    long long m;
    scanf("%i %lli", &n, &m);

    int f[100000], s[100000];
    for (int i = 0; i < n; i ++) {
        scanf("%i %i", f+i, s+i);
    }

    long long sum = 0;
    int ans = 2e9;
    int l = 0;
    int r = 0;
    while (r < n) {
        if (sum < m) {
            q.pushBack(s[r]);
            sum += f[r];
            r ++;
        } else {
            ans = min(ans,  q.front());
            q.popFront();
            sum -= f[l];
            l ++;
        }
    }
    if (sum >= m) {
        ans = min(ans, q.front());
    }

    printf("%i\n", ans);
}
