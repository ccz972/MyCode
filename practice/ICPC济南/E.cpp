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
#define int long long
void solve() {
	int n, k; cin >> n >> k;
	if (k == 1) {
		if (n == 1) cout << "Yes\n";
		else cout << "No\n";
	} else if (k == n - 1 || n == k) {
		cout << "Yes\n";
	} else if (k % 2 == 0) {
		cout << "Yes\n";
	} else { // k is ji shu  , k != 1
		if (n % 2 == 0) {
			int p = n / k, q = n % k;
			if ( (q >= p) and (n - (k - 1) * p + 1 <= k ) ) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		} else {
			int p = n / k, q = n % k;
			if (q < p - 1) {
				// debug(p); debug(q);
				cout << "No\n";
			} else {
				int ret = n - (k - 1) * p;
				// debug(p); debug(q); debug(ret); debug(k);
				if (ret <= k) {
					cout << "Yes\n";
				} else if (ret + 2 <= k) {
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;  cin >> T;
	while (T -- ) solve();
	return 0;
}


