#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

vector<int> compress(vector<int> &v) {
    set<int> st(v.begin(), v.end());
    return vector<int>(st.begin(), st.end());
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> compressed = compress(a);
    vector<int> mapped(n);
    for (int i = 0; i < n; i++) {
        mapped[i] = lower_bound(compressed.begin(), compressed.end(), a[i]) - compressed.begin();
    }
}