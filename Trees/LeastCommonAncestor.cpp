#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
const int LOG = 19;

vector<int> g[N];
int up[N][LOG], depth[N];

void fill(int v, int p) {
    for (auto u : g[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        up[u][0] = v;
        for (int bit = 1; bit < LOG; bit++) {
            up[u][bit] = up[up[u][bit - 1]][bit - 1];
        }
        fill(u, v);
    }
}

int getKth(int v, int k) {
    for (int bit = LOG - 1; bit >= 0; bit--) {
        if (k & (1 << bit)) v = up[v][bit];
    }
    return v;
}

int getLCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    a = getKth(a, depth[b] - depth[a]);
    if (a == b) return a;

    for (int bit = LOG - 1; bit >= 0; bit--) {
        if (up[a][bit] != up[b][bit]) {
            a = up[a][bit];
            b = up[b][bit];
        }
    }

    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;  
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(1, -1);

    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int lca = getLCA(a, b);
        cout << lca << '\n';
    }
}