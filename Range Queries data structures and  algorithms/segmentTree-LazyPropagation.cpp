#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
struct node {
    ll ans, lazy;
};
 
vector<int> a;
vector<node> seg;
 
inline void pull(int cur) {
    seg[cur].ans = seg[2 * cur].ans + seg[2 * cur + 1].ans;
}
 
void push(int cur, int l, int r) {
    if (seg[cur].lazy != 0) {
        if (l != r) {
            seg[2 * cur].lazy += seg[cur].lazy;
            seg[2 * cur + 1].lazy += seg[cur].lazy;
        }
        seg[cur].ans += seg[cur].lazy * (r - l + 1);
        seg[cur].lazy = 0;
    }
}
 
void build(int cur, int l, int r) {
    if (l == r) {
        seg[cur].ans = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * cur, l, m);
    build(2 * cur + 1, m + 1, r);
    pull(cur);
}
 
void update(int cur, int l, int r, int s, int e, int val) {
    push(cur, l, r);
    if (l > e || r < s) {
        return;   
    }
    if (l >= s && r <= e) {
        seg[cur].lazy += val;
        push(cur, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(2 * cur, l, m, s, e, val);
    update(2 * cur + 1, m + 1, r, s, e, val);
    pull(cur);
}
 
ll get(int cur, int l, int r, int s, int e) {
    push(cur, l, r);
    if (l > e || r < s) {
        return 0;   
    }
    if (l >= s && r <= e) {
        return seg[cur].ans;
    }
    int m = (l + r) / 2;
    return get(2 * cur, l, m, s, e) + get(2 * cur + 1, m + 1, r, s, e);
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }
 
    seg.resize(4 * n);
    build(1, 0, n - 1);
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            update(1, 0, n - 1, l, r, val);
        }
        else {
            int idx;
            cin >> idx;
            idx--;
            // int l, r;
            // cin >> l >> r;
            // l--, r--;
            cout << get(1, 0, n - 1, idx, idx) << '\n';
        }
    }
}