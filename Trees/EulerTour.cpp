#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
int n, q, timer = 0;
vector<int> weight, inNode, outNode, tour;
vector<vector<int>> adj;
 
void eulerTour(int v, int p) {
    inNode[v] = timer++;
    tour.push_back(weight[v]);
    for (auto u : adj[v]) {
        if (u != p) {
            eulerTour(u, v);
        }
    }
    outNode[v] = timer - 1;
}
 
////////////////
vector<ll> tree;
 
void build(int cur, int s, int e) {
    if (s == e) {
        tree[cur] = tour[s];
        return;
    }
    int m = (s + e) / 2;
    build(cur * 2, s, m);
    build(cur * 2 + 1, m + 1, e);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}
 
ll rsq(int cur, int s, int e, int l, int r) {
    if (s >= l && e <= r) {
        return tree[cur];
    }
    if (s > r || e < l) {
        return 0;
    }
    int m = (s + e) / 2;
    return rsq(cur * 2, s, m, l, r) + rsq(cur * 2 + 1, m + 1, e, l, r);
}
 
void update(int cur, int s, int e, int idx, int val) {
    if (s == e) {
        tree[cur] = val;
        return;
    }
    int m = (s + e) / 2;
    (idx <= m) ? update(cur * 2, s, m, idx, val) : update(cur * 2 + 1, m + 1, e, idx, val);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    weight.resize(n);
    for (auto &x : weight) {
        cin >> x;
    }
 
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; 
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }    
    
    inNode.resize(n);
    outNode.resize(n);
 
    eulerTour(0, -1);
    
    tree.resize(4 * n);
    build(1, 0, n - 1);
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, w;
            cin >> v >> w;
            v--;
            tour[inNode[v]] = w;
            update(1, 0, n - 1, inNode[v], w);
        }
        else {
            int v;
            cin >> v;
            v--;
            int sz = outNode[v] - inNode[v]; 
            cout << rsq(1, 0, n - 1, inNode[v], inNode[v] + sz) << '\n';
        }
    }
}