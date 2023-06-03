#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int a[55][55];
    ll cs[55][55] = {};

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cs[i][j] = a[i][j] + cs[i - 1][j] + cs[i][j - 1] - cs[i - 1][j - 1];
        }
    }

    // trying to calculate all boxex if size x * y
    int x = 0, y = 0;
    ll ans = 0;
    for (int i = x; i <= n; i++) {
        for (int j = y; j <= m; j++) {
            ans = min(ans, cs[i][j] - cs[i - x][j] - cs[i][j - y] + cs[i - x][j - y]);
            // to access sum from a, b
        }
    }

    // you also might have queries of this type
    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        cout << cs[x2][y2] - cs[x1][y2] - cs[x2][y1] + cs[x1][y1] << '\n';  
    }
}