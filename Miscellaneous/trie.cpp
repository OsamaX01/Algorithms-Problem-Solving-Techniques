#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
 
const int N = 1e5 * 19;   
 
struct node {
	int cnt, nxt[2];
	node() {
		cnt = 0;
		nxt[0] = nxt[1] = -1;
	}
}; 
 
int id = 0;
node trie[N];
 
void insert(string &s) {
	int cur = 1;
	for(auto c : s) {
		bool parity = ((c - '0') & 1);
		if(trie[cur].nxt[parity] == -1) {
			trie[cur].nxt[parity] = ++id;
		}
		cur = trie[cur].nxt[parity];
	}
	trie[cur].cnt++;
}
 
void remove(string &s) {
	int cur = 1;
	for(auto c : s) {
		bool parity = ((c - '0') & 1);
		if(trie[cur].nxt[parity] == -1) {
			trie[cur].nxt[parity] = ++id;
		}
		cur = trie[cur].nxt[parity];
	}
	trie[cur].cnt--;
}
 
int get(string &s) {
	int cur = 1;
	for(auto c : s) {
        if(trie[cur].nxt[c - '0'] == -1) return 0;
        cur = trie[cur].nxt[c - '0'];
	}
	return trie[cur].cnt;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
	int t;
	cin >> t;
	while(t--) {
		char ch;
		string s;
		cin >> ch >> s;
		reverse(s.begin(), s.end());
		while (s.size() < 18) {
			s.push_back('0');
		}
		if(ch == '+') insert(s);
		else if(ch == '-') remove(s);
		else cout << get(s) << '\n';
	}
}