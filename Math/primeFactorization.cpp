#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

vector<ll> primes;
set<int> factors;
int n;

void PrimeFactorization(ll x) {
    while (x % 2 == 0) {
        primes.push_back(2);
        x /= 2;
    }

    for (ll i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            primes.push_back(i);
            x /= i;
        }
    }

    if (x > 2) primes.push_back(x);
}

void rec(int idx, ll mul) {
    if (idx == n) {
        factors.emplace(mul);
        return;
    }
    rec(idx + 1, mul);
    rec(idx + 1, mul * primes[idx]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin >> x;
    PrimeFactorization(x);
    n = primes.size();
    rec(0, 1);

    cout << "Primes : ";
    for (auto it : primes) {
        cout << it << " ";
    }
    cout << "\nFactors : ";
    for (auto it : factors) {
        cout << it << " ";
    }
}