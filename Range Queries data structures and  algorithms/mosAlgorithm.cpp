#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

struct query {
    int l, r, idx, bIdx;
    bool operator < (query &u) const {
        if (bIdx != u.bIdx) return bIdx < u.bIdx;
        return (bIdx & 1 ? r < u.r : r > u.r);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n); 
    const int bLen = sqrt(n) + 1;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    int q;
    cin >> q;
    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--, queries[i].r--;
        queries[i].idx = i;
        queries[i].bIdx = queries[i].l / bLen;
    }
    sort (queries.begin(), queries.end());

    vector<ll> ans(q);
    int mos_l = 0, mos_r = -1;
    ll curAns = 0;

    auto add = [&](int idx) {
        curAns += a[idx];
    };

    auto remove = [&](int idx) {
        curAns -= a[idx];
    };

    for (auto q : queries) {
        while (mos_l > q.l) {
            mos_l--;
            add(mos_l);
        }
        while (mos_r < q.r) {
            mos_r++;
            add(mos_r);
        }
        while (mos_l < q.l) {
            remove(mos_l);
            mos_l++;
        }
        while (mos_r > q.r) {
            remove(mos_r);
            mos_r--;
        }
        ans[q.idx] = curAns;
    } 

    for (auto x : ans) {
        cout << x << '\n';
    }   
}