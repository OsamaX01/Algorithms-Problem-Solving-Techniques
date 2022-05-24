#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
class Sack {
public:
    int n;
    vector<int> root;
    vector<set<int>> sts;
    
    void init(const vector<int> &v) {
        n = v.size();
        root.resize(n);
        sts.resize(n);
        for (int i = 0; i < n; i++) {
            root[i] = i;
            sts[i].emplace(v[i]);
        }
    }
 
    int find(int u) {
        if (u == root[u]) {
            return u;
        }
        return root[u] = find(root[u]);
    }
 
    void merge(int v, int u) {
        v = find(v);
        u = find(u);
 
        if (sts[u].size() < sts[v].size()) {
            swap(u, v);
        }
        for (auto x : sts[v]) {
            sts[u].emplace(x);
        }
        sts[v].clear();
        
        root[v] = u;
    }
};
 
////////////////////////
 
Sack sack;
vector<int> v, ans;
vector<vector<int>> adj;
 
void dfs(int v, int p) {
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sack.merge(u, v);
        }
    }
    ans[v] = sack.sts[sack.find(v)].size();
}
 
///////////////////////
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    v.resize(n);
    for (auto &x : v) {
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
 
    sack.init(v);
    ans.resize(n);
    dfs(0, -1);
 
    for (auto x : ans) {
        cout << x << ' ';
    }
}