#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;

int n, m, par[N];
bool vis[N];
vector<int> g[N]; 

void BFS(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    par[x] = -1;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto child : g[u]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                par[child] = u;
            }
            if(child == n) return; 
        }
    }
}
 

void shortestPath(int x, int sz) {
    if(par[x] != -1) shortestPath(par[x], sz + 1);
    else cout << sz << '\n';
 
    cout << x << ' ';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    BFS(1);
    if(!vis[n]) {
        return cout << "IMPOSSIBLE", 0;
    }
    shortestPath(n, 1);
}