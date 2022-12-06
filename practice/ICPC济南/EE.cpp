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
	// n = rnd(10) + 2;
	// k = rnd(n - 1) + 1;
	cin >> n;
	vector<int> a(n);
	// cout << n << "\n";
	debug(n);
	// set<int> s;
	vector<bool> vis(n + 1);
	iota(all(a), 1);
	do {
		for (int k = 3; k <= n; k += 2) if (!vis[k]) {
			// if (s.count(k)) continue;
			if (test(a, k)) {
				// s.insert(k);
				vis[k] = true;
			}
		}
	} while (next_permutation(all(a)));
	// for (int x: s) cout << x << " ";
	rep(i, 1, n) if (vis[i]) {
		cout << i << " ";
	}
	cout << "\n\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	while (T -- )
	solve();
	
	return 0;
}