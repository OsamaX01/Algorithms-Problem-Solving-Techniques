#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
/*
    Problem link: https://cses.fi/problemset/task/1138
    The Idea is to make euler tour to have the following array then apply range sum query on it
    (These elements are based on the sample)
    Node ID:  1 2  2 3 4  4 5  5  3   1
    Seg tree: 4 2 -2 5 2 -2 1 -1 -5  -4
 
    example:
    path (1 -> 4) is the sum of elements from the root (index 0) to the first appearence of 4 (index 4) = 11
*/
 
int n, q, timer;
vector<vector<int>> adj;
vector<int> weights, tour, inTime, outTime; 
 
void eulerTour(int v, int p) {
    inTime[v] = timer++;
    tour.push_back(weights[v]);
    for (auto u : adj[v]) {
        if (u != p) {
            eulerTour(u, v);
        }
    }
    outTime[v] = timer++;
    tour.push_back(-weights[v]);
}
 
////////////////
 
vector<ll> tree;
 
void build(int cur, int l, int r) {
    if (l == r) {
        tree[cur] = tour[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * cur, l, m);
    build(2 * cur + 1, m + 1, r);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
}
 
ll rsq(int cur, int l, int r, int s, int e) {
    if (l >= s && r <= e) return tree[cur];
    if (l > e || r < s) return 0;
    int m = (l + r) / 2;
    return rsq(2 * cur, l, m, s, e) + rsq(2 * cur + 1, m + 1, r, s, e);
}
 
void update(int cur, int l, int r, int idx, int val) {
    if (l == r) {
        tree[cur] = val;
        return;
    }
    int m = (l + r) / 2;
    (idx <= m) ? update(2 * cur, l, m, idx, val) : update(2 * cur + 1, m + 1, r, idx, val);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1];
}
 
////////////////
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
 
    weights.resize(n);
    for (auto &x : weights) {
        cin >> x;
    }
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
 
    inTime.resize(n);
    outTime.resize(n);
    eulerTour(0, -1);
 
    int tourSize = tour.size();
    tree.resize(tourSize * 4);
    build(1, 0, tourSize - 1);
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, val;
            cin >> v >> val;
            update(1, 0, tourSize - 1, inTime[v - 1], val);
            update(1, 0, tourSize - 1, outTime[v - 1], -val);
        }
        else {
            int v;
            cin >> v;
            cout << rsq(1, 0, tourSize - 1, 0, inTime[v - 1]) << '\n';
        }
    }
}