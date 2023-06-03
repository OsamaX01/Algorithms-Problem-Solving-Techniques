#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

vector<int> v, tree;
// first element at least x
void build(int cur, int l, int r) {
    if(l == r) {
        tree[cur] = v[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * cur, l, m);
    build(2 * cur + 1, m + 1, r);
    tree[cur] = max(tree[2 * cur], tree[2 * cur + 1]);
}

int search(int cur, int l, int r, int x)  {
    if(l == r) {
        if(tree[cur] < x) return 0;
        return l + 1;
    }
    int m = (l + r) / 2;
    if(tree[2 * cur] >= x) return search(2 * cur, l, m, x);
    else return search(2 * cur + 1, m + 1, r, x);
}

void update(int cur, int l , int r, int idx, int val) {
    if(l == r) {
        tree[cur] = val;
        return;
    }
    int m = (l + r) / 2;
    (idx <= m) ? update(2 * cur, l, m, idx, val) : update(2 * cur + 1, m + 1, r, idx, val);
    tree[cur] = max(tree[2 * cur], tree[2 * cur + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    v.resize(n), tree.resize(4 * n);
    for (auto &x : v) {
        cin >> x;
    }

    build(1, 0, n - 1);

    while (q--) {
        int x;
        cin >> x;
        int res = search(1, 0, n - 1, x);
        if(res != 0) {
            v[res - 1] -= x; 
            update(1, 0, n - 1, res - 1, v[res - 1]);
        }
        cout << res << ' ';
    }
}