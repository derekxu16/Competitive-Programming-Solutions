#include <algorithm>
#include <iostream>
#include <vector>
 
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
 
using namespace std;
 
int main() {
    int n, q;
    scanf("%i %i", &n, &q);
 
    BIT bit(n);
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lli", &a);
        bit.update(i, a);
        bit.update(i+1, -a);
    }
 
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%i", &type);
        switch (type) {
            case 1:
                int l, r, u;
                scanf("%i %i %i", &l, &r, &u);
                bit.update(l - 1, u);
                bit.update(r, -u);
                break;
            case 2:
                int k;
                scanf("%i", &k);
                printf("%lli\n", bit.query(k - 1));
                break;
        }
    }
}
