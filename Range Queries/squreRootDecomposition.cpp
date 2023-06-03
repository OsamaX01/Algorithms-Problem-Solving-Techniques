#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int bLen = sqrt(n) + 1;
    vector<ll> b(bLen); 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i / bLen] += a[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int lb = l / bLen, rb = r / bLen;
        ll res = 0;

        if (lb == rb) {
            for (int i = l; i <= r; i++) {
                res += a[i]; 
            }
        }
        else {
            for (int i = l, end = (lb + 1) * bLen - 1; i <= end; i++) {
                res += a[i];
            }
            for (int i = lb + 1; i <= rb - 1; i++) {
                res += b[i];
            }
            for (int i = rb * bLen; i <= r; i++) {
                res += a[i];
            }
        }
        
        cout << res << '\n';
    }
}