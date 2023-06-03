#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

struct myStack {
    stack<ll> st, mx, mn;

    ll getMax() {
        return (mx.empty() ? 0 : mx.top());
    }

    ll getMin() {
        return (mn.empty() ? INT64_MAX : mn.top());   
    }

    void push(ll x) {
        st.push(x);
        mx.push(max(getMax(), x));
        mn.push(min(getMin(), x));
    }

    void pop() {
        st.pop();
        mx.pop();
        mn.pop();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &x : v) {
        cin >> x;
    }

    int L = 0, R = 0;
    myStack s1, s2;

    auto add = [&](ll x) {
        s2.push(x);
    };

    auto remove = [&]() {
        if (s1.st.empty()) {
            while (!s2.st.empty()) {
                s1.push(s2.st.top());
                s2.pop();
            }
        }
        s1.pop();
    };

    auto good = [&]() {
        ll mx = max(s1.getMax(), s2.getMax());
        ll mn = min(s1.getMin(), s2.getMin());
        return (mx - mn <= k); 
    };

    ll ans = 0;
    while (R < n) {
        add(v[R]);

        while (!good()) {
            remove();
            L++;
        }

        ans += R - L + 1;
        R++;
    }
    
    cout << ans << '\n';
}