#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>

template <typename T>
class MinOrMaxQueue {
   public:
    enum class Type { MIN, MAX };

   private:
    Type type;

    std::deque<std::pair<T, int>> q;

    int insert_index = 0;
    int erase_index = 0;

    bool shouldPopWhenInserting(const T& to_insert) {
        switch (type) {
            case Type::MIN:
                return to_insert < q.back().first;
            case Type::MAX:
                return to_insert > q.back().first;
        }
    }

   public:
    MinOrMaxQueue(Type type) : type(type) {}

    void pushBack(T to_insert) {
        while (!q.empty() && shouldPopWhenInserting(to_insert)) {
            q.pop_back();
        }
        q.emplace_back(to_insert, insert_index);
        insert_index++;
    }

    void popFront() {
        if (q.front().second == erase_index) {
            q.pop_front();
        }
        erase_index++;
    }

    T front() { return q.front().first; }
};

using namespace std;

int main() {
    MinOrMaxQueue<long long> q(MinOrMaxQueue<long long>::Type::MIN);

    int n, a, b;
    scanf("%i %i %i", &n, &a, &b);

    long long sum[200001];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lli", sum + i);
        sum[i] += sum[i - 1];
    }

    long long ans = -9e18;
    for (int i = a; i <= n; i++) {
        if (i > b) {
            q.popFront();
        }
        q.pushBack(sum[i - a]);
        ans = max(ans, (long long)(sum[i] - q.front()));
    }

    printf("%lli\n", ans);
}
