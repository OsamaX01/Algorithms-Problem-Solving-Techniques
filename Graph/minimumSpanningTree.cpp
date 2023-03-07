#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
struct Edge {
    int v, u;
    ll w;
    bool operator < (const Edge &rhs) {
        return w < rhs.w;
    }
};
 
// see full implementation at DisjointSetUnion.cpp
class UnionFind { 
public:
    UnionFind(int N) {}
    int findSet(int i) {}
    bool isSameSet(int i, int j) {}
    void unionSet(int i, int j) {}
};
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> eList(m);
    for (auto &[v, u, w] : eList) {
        cin >> v >> u >> w;
        v--, u--;
    }
 
    sort(eList.begin(), eList.end());
    UnionFind uf(n);
 
    ll totalW = 0;
    int numOfEdges = 0;
    for (auto [v, u, w] : eList) {
        if (!uf.isSameSet(v, u)) {
            uf.unionSet(v, u);
            totalW += w;
            numOfEdges++;
            if (numOfEdges == n - 1) break;
        }
    }

    return 0;
}
