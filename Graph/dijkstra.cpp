#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int n; // number of nodes
vector<vector<pair<ll, int>>> adj;
 
// returns a vector that represents minimum distance rom a soruce node to each other node
vector<ll> dijkstra(int src) { 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

    vector<ll> distance(n, INT64_MAX);
    vector<bool> visited(n, false);
    distance[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (visited[v]) continue;
        visited[v] = true;

        for (auto [w, u] : adj[v]) {
            if (distance[v] + w <= distance[u]) {
                distance[u] = distance[v] + w;
                pq.push({distance[u], u});
            }
        }
    }
    
    return distance;
}
 
int main() {
    return 0;
}