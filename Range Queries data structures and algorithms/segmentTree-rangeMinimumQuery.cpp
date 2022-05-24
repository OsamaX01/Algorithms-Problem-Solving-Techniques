#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

const int oo = 1e9;

int n, k;
vector<int> v, tree;

void build(int cur, int s, int e) {
    if (s == e) {
        tree[cur] = v[s];
        return;
    }
    int m = (s + e) / 2;
    build(cur * 2, s, m);
    build(cur * 2 + 1, m + 1, e);
    tree[cur] = min(tree[cur * 2], tree[cur * 2 + 1]);
}

int rmq(int cur, int s, int e, int l, int r) {
    if (s >= l && e <= r) {
        return tree[cur];
    }
    if (s > r || e < l) {
        return oo;
    }
    int m = (s + e) / 2;
    return min(rmq(cur * 2, s, m, l, r), rmq(cur * 2 + 1, m + 1, e, l, r));
}

void update(int cur, int s, int e, int idx, int val) {
    if (s == e) {
        tree[cur] = val;
        return;
    }
    int m = (s + e) / 2;
    (idx <= m) ? update(cur * 2, s, m, idx, val) : update(cur * 2 + 1, m + 1, e, idx, val);
    tree[cur] = min(tree[2 * cur], tree[2 * cur + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n), tree.resize(4 * n);
    for (auto &it : v) {
        cin >> it;
    }
    build(1, 0, n - 1);
    while (k--) {
        int type;
        cin >> type;
        if (type == 1) {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << rmq(1, 0, n - 1, l, r) << endl;
        }
    }
}