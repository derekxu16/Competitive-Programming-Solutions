#include <iostream>
#include <vector>

template <class T>
class SegTree {
   private:
    int n;
    std::vector<T> & items;
    std::vector<T> st;
    std::vector<int> wins;
    T out_of_bounds_value;

    int left(int node) {
        return node * 2;
    };

    int right(int node) {
        return node * 2 + 1;
    };

    void buildLeaf(int node, int l, int r);

    void build(int node, int l, int r) {
        if (l == r) {
            buildLeaf(node, l, r);
        } else {
            build(left(node), l, (l + r) / 2);
            build(right(node), (l + r) / 2 + 1, r);

            T l_ans = st[left(node)];
            T r_ans = st[right(node)];
            st[node] = merge(l_ans, r_ans);
            wins[st[node]] ++;
        }
    }

    /**
     * Merge function that takes in indices.
     */
    int merge(int l_ind, int r_ind);

    T query(int node, int l, int r, int a, int b) {
        if (a > r || b < l) {
            return out_of_bounds_value;
        }
        if (a <= l && r <= b) {
            return st[node];
        }
        T l_ans = query(left(node), l, (l + r) / 2, a, b);
        T r_ans = query(right(node), (l + r) / 2 + 1, r, a, b);

        if (l_ans == out_of_bounds_value) return r_ans;
        if (r_ans == out_of_bounds_value) return l_ans;

        return merge(l_ans, r_ans);
    }

    void update(int node, int l, int r, int index) {
        if (l == r) {
            buildLeaf(node, l, r);
        } else {
            wins[st[node]] --;
            if (l <= index && index <= (l + r) / 2) {
                update(left(node), l, (l + r) / 2, index);
            } else {
                update(right(node), (l + r) / 2 + 1, r, index);
            }

            T l_ans = st[left(node)];
            T r_ans = st[right(node)];
            T ans = merge(l_ans, r_ans);
            st[node] = ans;
            wins[st[node]] ++;
        }
    }

   public:
    SegTree(std::vector<int> & v);

    /**
     * Return the answer on the range [a, b].
     */
    T query(int a, int b);

    void update(int ind, T val) {
        items[ind] = val;
        update(1, 0, n - 1, ind);
    }

    int countWins(int i) {
        return wins[i];
    }
};

template<>
SegTree<int>::SegTree(std::vector<int> & v)
    : n(v.size()), items(v), st(4*n, 0), wins(n, 0), out_of_bounds_value(-1) {
    build(1, 0, n - 1);
}

template<>
void SegTree<int>::buildLeaf(int node, int l, int r) {
    if (l == r) {
        st[node] = l;
    } else {
        throw "l == r must be true at a leaf";
    }
}

template<>
int SegTree<int>::merge(int l_ind, int r_ind) {
    return (items[l_ind] > items[r_ind]) ? l_ind : r_ind;
}

template<>
int SegTree<int>::query(int a, int b) {
    return query(1, 0, n - 1, a, b);
}

using namespace std;

int main() {
    int n, m;
    scanf("%i %i", &n, &m);
    n = 1 << n;

    vector<int> skill;
    skill.resize(n);
    for (int& s : skill) {
        scanf("%i", &s);
    }
    SegTree<int> st(skill);
     
    for (int i = 0; i < m; i ++) {
        char q;
        scanf(" %c", &q);
        if (q == 'R') {
            int ind, val;
            scanf("%i %i", &ind, &val);
            st.update(ind-1, val);
        } else if (q == 'W') {
            printf("%i\n", st.query(0, n-1) + 1);
        } else if (q == 'S') {
            int ind;
            scanf("%i", &ind);
            printf("%i\n", st.countWins(ind-1));
        }
    }
}
