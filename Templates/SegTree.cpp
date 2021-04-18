#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int min;
    int gcd;
    int num_equal;

    bool operator==(const Node& other) {
        return min == other.min && gcd == other.gcd &&
               num_equal == other.num_equal;
    }
};

template <class T>
class SegTree {
   private:
    int n;
    std::vector<T> & items;
    std::vector<T> st;
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
        }
    }

    T merge(T l_ans, T r_ans);

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
            if (l <= index && index <= (l + r) / 2) {
                update(left(node), l, (l + r) / 2, index);
            } else {
                update(right(node), (l + r) / 2 + 1, r, index);
            }

            T l_ans = st[left(node)];
            T r_ans = st[right(node)];
            T ans = merge(l_ans, r_ans);
            st[node] = ans;
        }
    }

   public:
    SegTree(std::vector<T> & v);

    /**
     * Return the answer on the range [a, b].
     */
    T query(int a, int b);

    void update(int ind, T val) {
        items[ind] = val;
        update(1, 0, n - 1, ind);
    }
};

template<>
SegTree<int>::SegTree(std::vector<int> & v)
    : n(v.size()), items(v), st(4*n, 0), out_of_bounds_value(-1) {
    build(1, 0, n - 1);
}

template<>
SegTree<Node>::SegTree(std::vector<Node> & v)
    : n(v.size()),
      items(v),
      st(4 * n, {0, 0, 0}),
      out_of_bounds_value({-1, -1, -1}) {
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
void SegTree<Node>::buildLeaf(int i, int l, int r) {
    if (l == r) {
        st[i] = items[l];
    } else {
        throw "l == r must be true at a leaf";
    }
}

template<>
int SegTree<int>::merge(int l_ind, int r_ind) {
    return (items[l_ind] < items[r_ind]) ? l_ind : r_ind;
}

template<>
Node SegTree<Node>::merge(Node l_ans, Node r_ans) {
    int a = l_ans.gcd, b = r_ans.gcd;
    while (b) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    int count = 0;
    if (l_ans.gcd == a) {
        count += l_ans.num_equal;
    }
    if (r_ans.gcd == a) {
        count += r_ans.num_equal;
    }

    return {std::min(l_ans.min, r_ans.min), a, count};
}

template<>
int SegTree<int>::query(int a, int b) {
    return items[query(1, 0, n - 1, a, b)];
}

template<>
Node SegTree<Node>::query(int a, int b) {
    return query(1, 0, n - 1, a, b);
}
