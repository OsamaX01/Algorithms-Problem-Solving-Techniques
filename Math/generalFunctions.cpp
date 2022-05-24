#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
 
ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

inline int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
 
inline int mul(int a, int b) {
    return (ll)a * b % MOD;
}

int power(int x, int p) {
    int ret = 1;
    while (p > 0) {
        if (p % 2) {
        ret = mul(ret, x);
    }
    p /= 2;
    x = mul(x, x);
  }
  return ret;
}