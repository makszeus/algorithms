#include <iostream>
#include <vector>

using ll = long long;

struct SegmentTree {
    
    int n; std::vector<ll> t;
    SegmentTree(const std::vector<ll>& a) {
        n = (int)a.size();
        t.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const std::vector<ll>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm, a);
        build(v << 1|1, tm + 1, tr, a);
        t[v] = t[v << 1] + t[v << 1|1];
    }

    ll sum(int l, int r) { 
        return sum(1, 0, n - 1, l, r);
    }
    ll sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) >> 1;
        return sum(v << 1, tl, tm, l, std::min(r, tm))
             + sum(v << 1|1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    void point_update(int pos, ll new_val) {
        point_update(1, 0, n - 1, pos, new_val);
    }

    void point_update(int v, int tl, int tr, int pos, ll new_val) {
        if (tl == tr) {
            t[v] = new_val;
            return;
        }
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            point_update(v << 1, tl, tm, pos, new_val);
        } else {
            point_update(v << 1|1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v << 1] + t[v << 1|1];
    }
};

int main() {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ll> a = {87, 73, -7, 38, 85};
    SegmentTree st(a);
    std::cout << st.sum(0,4) << "\n";
    st.point_update(1, -7);
    std::cout << st.sum(0,4) << "\n";

    return 0;
}
