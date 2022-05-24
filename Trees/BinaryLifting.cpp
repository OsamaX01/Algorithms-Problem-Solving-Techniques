#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;
const int LOG = 18;

int n, q, up[N][LOG], depth[N], parent[N];

void fill() { // 1 based parents
    for (int v = 1; v <= n; v++) {
        if (v > 1) depth[v] = depth[parent[v]] + 1;

        up[v][0] = parent[v];
        for (int bit = 1; bit < LOG; bit++) {
            up[v][bit] = up[up[v][bit - 1]][bit - 1];
        }
    }
}

int getKthAncestor(int u, int k) {
    if (depth[u] < k) return -1;

    for (int bit = LOG - 1; bit >= 0; bit--) {
        if (k & (1 << bit)) u = up[u][bit];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    parent[1] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    fill();

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << getKthAncestor(a, b) << '\n';
    }
}