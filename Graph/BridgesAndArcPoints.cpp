#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

class BridgesAndArticulationPoints {
    int n, cnt = 0;
    vector<int> num, low;
    vector<bool> isArcPoint;
    vector<pair<int, int>> bridges;
    int root, rootChilds;
public:
    BridgesAndArticulationPoints(vector<vector<int>> &adj) {
        n = adj.size();
        num.resize(n);
        low.resize(n);
        isArcPoint.resize(n);

        function<void(int, int)> dfs = [&](int v, int p) {
            num[v] = ++cnt;
            low[v] = num[v];
            for (auto u : adj[v]) {
                if (num[u] == 0) {
                    if (p == -1) rootChilds++;
                    dfs(u, v);
                    if (low[u] > num[v]) bridges.push_back({v, u});
                    if (low[u] >= num[v]) isArcPoint[v] = true;
                    low[v] = min(low[v], low[u]);
                } 
                else if (u != p) {
                    low[v] = min(low[v], num[u]);
                } 
            }
        };

        for (int i = 0; i < n; i++) {
            if (num[i] == 0) {
                root = i;
                rootChilds = 0;
                dfs(i, -1);
                isArcPoint[root] = (rootChilds > 1);
            }
        }
    }

    bool isArticulationPoint(int v) {
        return isArcPoint[v];
    }

    vector<int> getArticulationPoints() {
        vector<int> arcPoints;
        for (int v = 0; v < n; v++) {
            if (isArcPoint[v]) {
                arcPoints.push_back(v);
            }
        }
        return arcPoints;
    }

    vector<pair<int, int>> getBridges() {
        return bridges;
    }
};
