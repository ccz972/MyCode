// Problem: C. Check Problems
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; cin >> n;
	vector<vector<int> > son(n);
	for(int i = 1; i < n; i ++ ) {
		int u, v; cin >> u >> v;
		-- u, -- v;
		son[u].push_back(v);
		son[v].push_back(u);
	}
	
	vector<ll> f(n);
	vector<int> sz(n, 1);
	function<void(int, int)> dfs_1 = [&] (int u, int fa) {
		for(auto v: son[u]) if(v != fa) {
			dfs_1(v, u);
			sz[u] += sz[v];
		}
	};
	dfs_1(0, -1);
	function<void(int, int)> dfs_2 = [&] (int u, int fa) {
		vector<int> s;
		ll ct = 0;
		for(auto v: son[u]) if(v != fa) {
			s.push_back(sz[v]);
			ct += sz[v];
		}
		if(~fa) {
			s.push_back(n - 1 - ct);
			ct = n - 1; 
		}
		int N = s.size();
		ll ans = 0;
		for(int i = 0; i < N; i ++ ) {
			ans += (ll)s[i] * (ct - s[i] + 1);
			ct -= s[i];
		}
		f[u] = ans;
		for(auto v: son[u]) if(v != fa) {
			dfs_2(v, u);
		}
	};
	dfs_2(0, -1);
	int q; cin >> q;
	while(q -- ) {
		int x; cin >> x;
		cout << f[x - 1] << "\n";
	}
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

  return 0;
}
/*
 *
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
