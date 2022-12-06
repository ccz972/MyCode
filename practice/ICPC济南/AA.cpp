#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(x, y) (x) = (x) >= (y) ? (x) : (y)
#define chkmin(x, y) (x) = (x) <= (y) ? (x) : (y)
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
#define int ll
set<int> s;

void dfs(int x) {
	if (s.count(x)) return ;
	s.insert(x);
	if (x <= 1) return ;
	dfs(x >> 1);
	s.insert(x - 1);
	s.insert(x + 1);
	dfs((x + 1) >> 1);
	dfs((x - 1) >> 1);
}

void solve() {
	int n = rnd(998244353) + 1; //cin >> n;
	dfs(n);
	// cout << SZ(s) << "\n";
	// s.clear();
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; cin >> T;
	int mx = 27869;
	while (T -- ) {
		int ti = 500;
		while (ti -- ) {
			solve();
		}
		chkmax(mx, SZ(s));
		// cout << SZ(s) << "\n";		
		s.clear();
	}
	cout << mx << "\n";
	return 0;
}

/*


10
1000011000
900011100
998244353
198244353
998244352
998241253
28244353
182443533
928244353
298244354

*/