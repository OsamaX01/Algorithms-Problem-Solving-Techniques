#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

vector<int> tpl_sort(int n, vector<vector<int>> &adj, vector<int> &inDegree) {
    queue<int> q;
    vector<int> tp;
 
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
 
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        tp.push_back(front);
        for (auto u : adj[front]) {
            if (--inDegree[u] == 0) q.push(u);
        }
    }
 
    return tp;
}