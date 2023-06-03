#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int N = 2e5 + 5; 
int tree[4 * N];
// kthElement - Sliding median
int median(int cur, int l, int r, int target) {
    if (l == r) {
        return l;
    }

    int m = (l + r) / 2;
    if (tree[2 * cur] > target) {
        return median(2 * cur, l, m, target);
    }
    else {
        return median(2 * cur + 1, m + 1, r, target - tree[2 * cur]);
    }
}

void update(int cur, int l, int r, int idx, int val) {
    if(l == r) {
        tree[cur] += val;
        return;
    }
    int m = (l + r) / 2;
    (idx <= m) ? update(2 * cur, l, m, idx, val) : update(2 * cur + 1, m + 1, r, idx, val);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1]; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        update(1, 0, N - 1, a[i], 1);
    }

    int l = 0, r = k, target = (k - 1) / 2;
    while (r < n) {
        cout << median(1, 0, N  - 1, target) << ' ';
        update(1, 0, N - 1, a[l], -1);
        cin >> a[r];
        update(1, 0, N - 1, a[r], 1);
        l++, r++;
    }
    cout << median(1, 0, N  - 1, target) << ' ';
}