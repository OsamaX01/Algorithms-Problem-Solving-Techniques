#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
 
ll myGcd(ll a, ll b) {
    return !a ? b : myGcd(b % a, a); 
}

ll myLcm(ll a, ll b) {
    return a / myGcd(a, b) * b; 
}

// Modular Arithmetic Functions

inline int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
 
inline int mul(int a, int b) {
    return (ll)a * b % MOD;
}

inline int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
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

inline int inv(int x) {
    return power(x, MOD - 2);
}
 
inline int divide(int a, int b){
    return mul(a, inv(b));
}

// Binomial Coefficient

const int MAX_N = 1e5;
int fact[MAX_N], in[MAX_N];

void preCompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    for (int i = 0; i < MAX_N; i++) {
        in[i] = inv(i);
    }
}

int nPr(int n, int r) {
    return divide(fact[n], fact[n - r]);
}

int nCr(int n, int r) {
    return divide(fact[n], mul(fact[n - r], fact[r]));
}