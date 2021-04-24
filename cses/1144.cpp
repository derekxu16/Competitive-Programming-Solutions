#include <algorithm>
#include <iostream>
#include <vector>

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

    long long query(int l, int r) { return query(r) - query(l - 1); }
};

using namespace std;

struct Query {
    char type;
    int arg1;
    int arg2;
    Query(char type, int arg1, int arg2) : type(type), arg1(arg1), arg2(arg2) {}
};

int main() {
    int n, q;
    scanf("%i %i", &n, &q);

    vector<int> salaries;
    vector<int> sorted_salaries;
    vector<Query> queries;
    for (int i = 0; i < n; i++) {
        int s;
        scanf("%i", &s);
        salaries.push_back(s);
        sorted_salaries.push_back(s);
        queries.emplace_back('i', i + 1, s);
    }

    for (int i = 0; i < q; i++) {
        char c;
        scanf(" %c", &c);
        switch (c) {
            case '!':
                int k, x;
                scanf("%i %i", &k, &x);
                sorted_salaries.push_back(x);
                queries.emplace_back('!', k, x);
                break;
            case '?':
                int a, b;
                scanf("%i %i", &a, &b);
                queries.emplace_back('?', a, b);
                break;
        }
    }
    sort(sorted_salaries.begin(), sorted_salaries.end());

    BIT bit(2 * n);
    for (Query query : queries) {
        switch (query.type) {
            case 'i': {
                int k = query.arg1;
                int i = lower_bound(sorted_salaries.begin(),
                                    sorted_salaries.end(), salaries[k - 1]) -
                        sorted_salaries.begin();
                bit.update(i, 1);
                break;
            }
            case '!': {
                int k = query.arg1;
                int x = query.arg2;

                int i = lower_bound(sorted_salaries.begin(),
                                    sorted_salaries.end(), salaries[k - 1]) -
                        sorted_salaries.begin();
                bit.update(i, -1);

                salaries[k - 1] = x;

                i = lower_bound(sorted_salaries.begin(), sorted_salaries.end(),
                                salaries[k - 1]) -
                    sorted_salaries.begin();
                bit.update(i, 1);
                break;
            }
            case '?': {
                int a = query.arg1;
                int b = query.arg2;
                int l = lower_bound(sorted_salaries.begin(),
                                    sorted_salaries.end(), a) -
                        sorted_salaries.begin();
                int r = (--upper_bound(sorted_salaries.begin(),
                                       sorted_salaries.end(), b)) -
                        sorted_salaries.begin();
                printf("%lli\n", bit.query(l, r));
                break;
            }
        }
    }
}
