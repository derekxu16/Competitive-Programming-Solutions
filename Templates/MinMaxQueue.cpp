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
