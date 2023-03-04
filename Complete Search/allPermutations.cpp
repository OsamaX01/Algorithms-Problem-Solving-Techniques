#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

int n, a[16];
vector<vector<int>> ans;

// generating all permutations
void rec(int i) {
    if (i == n) {
        ans.push_back(vector<int> (a, a + n));
    }

    for (int j = i; j < n; j++) {
        swap(a[i], a[j]);
        rec(i + 1);
        swap(a[i], a[j]);
    }
}

int main() {
    return 0;
}