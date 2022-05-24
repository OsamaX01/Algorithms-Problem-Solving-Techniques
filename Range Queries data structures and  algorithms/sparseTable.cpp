#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int LOG = 18;

int mn[N][LOG], binLog[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn[i][0] = x;
    }

    // preprocessing   
    for (int i = 2; i <= n; i++) {
        binLog[i] = binLog[i / 2] + 1;
    }
    
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            mn[i][k] = min(mn[i][k - 1], mn[i + (1 << (k - 1))][k - 1]);
        }
    }

    // query answering
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int k = binLog[r - l + 1];
        cout << min(mn[l][k], mn[r - (1 << k) + 1][k]) << '\n';   
    }
}