#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
const ll oo = 1e18;
const int N = 1e5 + 5;
 
ll dis[N];
int n, m, par[N];
vector<pair<int, ll>> g[N];  
 
void Dijkstra() {
    priority_queue<pair<ll, int>> pq;
    for(int i = 0; i < n; i++) {
        dis[i] = oo;
    }
    dis[0] = 0;
    pq.push({0, 0});
 
    while(pq.size()) {
        int u = pq.top().second;
        ll d = -pq.top().first;
        pq.pop();
 
        for(auto x : g[u]) {
            if(d + x.second < dis[x.first]) {
                dis[x.first] = d + x.second;
                par[x.first] = u;
                pq.push({-dis[x.first], x.first});
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        a--, b--;
        g[a].push_back({b, k});
        g[b].push_back({a, k});
    }
    Dijkstra();
 
    if(dis[n - 1] == oo) {
        cout << -1;
        return 0;
    }
    
    vector<int> ans;
    int u = n - 1;
    while(par[u] != u) {
        ans.push_back(u + 1);
        u = par[u];
    }
    ans.push_back(1);
 
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}