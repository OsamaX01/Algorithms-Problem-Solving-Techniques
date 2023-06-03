#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
typedef long long ll;
using namespace __gnu_pbds;

template <typename K>
using indexed_set = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

/*
 find_by_order() and order_of_key().
 The first returns an iterator to the k-th largest element (counting from zero),
 the second — the number of items in a set that are strictly smaller than our item.
*/
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    indexed_set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

    int idx = 0;
    auto getNext = [&]() {
        idx = (idx + k) % st.size();
    };

    while (!st.empty()) {
        getNext();
        auto it = st.find_by_order(idx);
        cout << *it << ' ';
        st.erase(it);
    }
}