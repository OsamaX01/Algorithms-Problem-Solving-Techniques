#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
const int N = 2e5 + 5;
int n, m, root[N];
 
int find(int u) {
    if(root[u] == u) 
        return u;
    return root[u] = find(root[u]);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        root[i] = i;
    }
    
    for(int i = 0; i < m; i++) {
        int a , b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        root[b] = root[a];    
    }
 
    set<int> st;
    vector<int> node;
    for(int i = 1; i <= n; i++) {
        int x = find(i);
        if(!st.count(x)) {
            node.push_back(i);
            st.emplace(x);
        }
    }
 
    cout << st.size() - 1 << '\n';
    for(int i = 0; i < int(node.size()) - 1; i++) {
        cout << node[i] << ' ' << node[i + 1] << '\n';
    }
}
