#include <iostream>
#include <vector>
using namespace std;

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
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    rec(0);
    for (auto v : ans) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}