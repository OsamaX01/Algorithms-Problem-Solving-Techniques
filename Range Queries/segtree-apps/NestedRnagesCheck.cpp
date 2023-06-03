#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

struct Interval {
    int s, e, idx;
    bool operator < (Interval &rhs) {
        if (s == rhs.s) return e > rhs.e;
        return s < rhs.s;
    }
};

vector<int> tree;

int rsq(int cur, int l, int r, int s, int e) {
    if(l >= s && r <= e) {
        return tree[cur];
    }
    if(l > e || r < s) {
        return 0;
    }
 
    int m = (l + r) / 2;
    return rsq(2 * cur, l, m, s, e) + rsq(2 * cur + 1, m + 1, r, s, e);
}
 
void update(int cur, int l, int r, int idx) {
    if(l == r) {
        tree[cur] = true;
        return;
    }
 
    int m = (l + r) / 2;
    (idx <= m) ? update(2 * cur, l, m, idx) : update(2 * cur + 1, m + 1, r, idx);
    tree[cur] = tree[2 * cur] + tree[2 * cur + 1]; 
}
 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Interval> srt, end;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        srt.push_back({a, b, i});
    }
    sort(srt.begin(), srt.end());

    for (int i = 0; i < n; i++) {
        end.push_back({srt[i].e, srt[i].s, srt[i].idx});
    }
    sort(end.begin(), end.end());

    vector<int> ans1(n), ans2(n);
    vector<vector<int>> f(n);
    tree.resize(8 * n);

    auto handleEnd = [&](int treeIdx, int j) {
        int idx = f[end[j].idx].back();
        f[end[j].idx].pop_back();
        ans1[end[j].idx] = rsq(1, 0, n - 1, idx, treeIdx);
        ans2[end[j].idx] = idx - rsq(1, 0, n - 1, 0, idx);
        update(1, 0, n - 1, idx);
    };

    int i = 0, j = 0;
    while (i < n) {
        if (srt[i].s < end[j].s) {
            f[srt[i].idx].push_back(i); 
            i++;
        }
        else {
            handleEnd(i + j, j);
            j++;
        }
    }

    while (j < n) {
        handleEnd(i + j, j);
        j++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans2[i] << ' ';
    }
}