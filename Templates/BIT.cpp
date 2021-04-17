#include <vector>
#include <iostream>

/**
 * Zero-indexed BIT
 */
class BIT {
   private:
    int n;
    std::vector<long long> v;

   public:
    BIT(int size) : n(size + 1), v(size, 0) {}

    void update(int ind, long long increment) {
        for (int i = ind + 1; i <= n; i += i & (-i)) {
            v[i] += increment;
        }
    }

    long long query(int r) {
        long long ans = 0;
        for (int i = r + 1; i > 0; i -= i & (-i)) {
            ans += v[i];
        }
        return ans;
    }

    long long query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
