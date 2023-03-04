#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<int> color;
 
bool isBip(int src) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
 
        for (auto u : adj[v]) {
            if (color[u] == -1) {
                q.push(u);
                color[u] = 1 - color[v];
            } 
            else {
                if (color[u] == color[v]) {
                    return true;
                }
            }
        }
    }
 
    return false;
}