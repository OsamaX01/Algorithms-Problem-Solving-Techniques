#include "bits/stdc++.h"
 
using namespace std;

typedef long long ll;
typedef long double ld;

void clearStack(stack<pair<int, int>> &st) {
    while (st.size()) {
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) {
        cin >> x;
    }
 
    stack<pair<int, int>> leftStack, rightStack;
    vector<int> maxLeft(n, -1), maxRight(n, n);
 
    for (int i = n - 1; i >= 0; i--) {
        while (leftStack.size() && leftStack.top().first <= v[i]) {
            maxLeft[leftStack.top().second] = i;
            leftStack.pop();
        }    
        leftStack.push({v[i], i});
    }
 
 
    for(int i = 0; i < n; i++) {
        while (rightStack.size() && rightStack.top().first < v[i]) {
            maxRight[rightStack.top().second] = i;
            rightStack.pop();
        }    
        rightStack.push({v[i], i});
    }

    clearStack(leftStack);
    clearStack(rightStack);
    vector<int> minLeft(n, -1), minRight(n, n);
 
    for (int i = n - 1; i >= 0; i--) {
        while (leftStack.size() && leftStack.top().first >= v[i]) {
            minLeft[leftStack.top().second] = i;
            leftStack.pop();
        }    
        leftStack.push({v[i], i});
    }
 
 
    for(int i = 0; i < n; i++) {
        while (rightStack.size() && rightStack.top().first > v[i]) {
            minRight[rightStack.top().second] = i;
            rightStack.pop();
        }    
        rightStack.push({v[i], i});
    }
}