#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;

int n, m;
bool vis[N];
vector<int> g[N]; 

void BFS(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;

    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto child : g[u]) {
            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
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
 
    BFS(1);
}