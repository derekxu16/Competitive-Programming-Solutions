#include <deque>
#include <utility>

template <typename T>
class MinOrMaxQueue {
   public:
    enum class Type { MIN, MAX };

   private:
    Type type;

    // A queue that holds pairs of elements and their effective indices. An invariant of `q` is that its first element
    // is always the min/max (depending on `type`) element in the queue.
    std::deque<std::pair<T, int>> q;

    // These variables are used to ensure that the interface of this data structure (push/pop) correctly behaves like
    // that of a queue's.
    int insert_index = 0;
    int erase_index = 0;

    // Helps ensure that `q`'s invariant always holds.
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

    /**
     * Pushes an element to the back of the queue.
     */
    void pushBack(T to_insert) {
        while (!q.empty() && shouldPopWhenInserting(to_insert)) {
            q.pop_back();
        }
        q.emplace_back(to_insert, insert_index);
        insert_index++;
    }

    /**
     * Removes an element from the front of the queue.
     */
    void popFront() {
        if (q.front().second == erase_index) {
            q.pop_front();
        }
        erase_index++;
    }

    /**
     * Returns the min/max (depending on the type of queue) element in the queue.
     */
    T front() { return q.front().first; }
};
