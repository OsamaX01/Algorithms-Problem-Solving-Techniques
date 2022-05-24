#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;

int n, m;
bool vis[N];
vector<int> g[N]; 

void DFS(int v) {
    vis[v] = true;
    for (auto u : g[v]) {
        if (!vis[u]) {
            DFS(u);
        }
    }
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
 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            DFS(i);
        }
    }
}