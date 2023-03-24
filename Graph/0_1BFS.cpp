#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int INF = 1e9;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
vector<vector<int>> adj;

void solve(int src) {
    deque<int> q;
    vector<int> cost(n, INF);
    vector<bool> vis(n);
    
    q.push_front(src);
    cost[src] = 0;

    while (!q.empty()) {
        auto v = q.front();
        q.pop_front();
        
        if (vis[v]) continue;
        vis[v] = true;

        for (auto u : adj[v]) {
            if (vis[u]) continue;
            bool one = (u == v + 1); // some condition
            int cur = cost[v] + one; 
            cost[u] = min(cost[u], cur);
            (one ? q.push_back(u) : q.push_front(u));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}