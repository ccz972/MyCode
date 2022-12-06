#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PII pair<int, int>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"
mt19937 rng(random_device{}());
int rnd(int x) {
	return rng() % x;
}
int n, k;
bool test(vector<int> &a, int k) {
	for (int i = 0; i < n; i ++ ) {
		int j = i + k;
		if (j >= n) break;
		if ((a[i] & 1) != (a[j] & 1)) return false;
	}
	return true;
}

void solve() {
/*
n : 19
7 9 11 13 15 17 19 

*/
	cin >> n;
	vector<int> a(n);
	debug(n);
	vector<bool> vis(n + 1);
	iota(all(a), 1);
	
	int timE = 1000000;
	while (timE -- ) {
		shuffle(all(a), rng);
		shuffle(all(a), rng);
		shuffle(all(a), rng);
		// if (test(a, 7)) {
			// for (int x: a) cout << x << " ";
			// cout << "\n";
			// exit(0);
		// }
		for (int i = 3; i <= n; i += 2) if (!vis[i]) {
			vis[i] = test(a, i);
		}
	}
	
	// for (int x: s) cout << x << " ";
	rep(i, 1, n) if (vis[i]) {
		cout << i << " ";
	}
	cout << "\n\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; // cin >> T;
	while (T -- )
	solve();
	
	return 0;
}