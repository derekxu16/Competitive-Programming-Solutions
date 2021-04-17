#include <iostream>

template <int... ArgsT>
class BIT {
   private:
    long long val = 0;

   public:
    void update(int val) {
        this->val += val;
    }

    long long query() {
        return val;
    }
};

/**
 * Zero-indexed BIT
 */
template <int N, int... Ns>
class BIT<N, Ns...> {
   private:
    BIT<Ns...> bit[N + 1];

   public:
    template<typename... Args>
    void update(int ind, Args... args) {
        for (int i = ind + 1; i <= N; i += i & (-i)) {
            bit[i].update(args...);
        }
    }

    template<typename... Args>
    long long query(int l, int r, Args... args) {
        long long ans = 0;
        for (int i = r + 1; i > 0; i -= i & (-i)) {
            ans += bit[i].query(args...);
        }
        for (int i = l; i > 0; i -= i & (-i)) {
            ans -= bit[i].query(args...);
        }
        return ans;
    }
};

using namespace std;

int main() {
    int n, q;
    scanf("%i %i", &n, &q);

    BIT<200000> bit;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lli", &a);
        bit.update(i, a);
    }

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%i", &type);
        switch (type) {
            case 1:
                int k, u;
                scanf("%i %i", &k, &u);
                bit.update(k - 1, u - bit.query(k - 1, k - 1));
                break;
            case 2:
                int l, r;
                scanf("%i %i", &l, &r);
                printf("%lli\n", bit.query(l - 1, r - 1));
                break;
        }
    }
}
