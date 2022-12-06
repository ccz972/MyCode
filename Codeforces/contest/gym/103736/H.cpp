// Problem: H. Optimal Biking Strategy
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i(a); i <= b; i ++)
#define dec(i, a, b) for(int i(a); i >= b; i --)
#define int long long
#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif


template <typename T> inline void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> inline void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1e6 + 10;
constexpr ll inf = 1e18;
ll f[N][6];
ll a[N];
void solve() {
  int n, p, s; cin >> n >> p >> s;
  // vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
  int k; cin >> k;
 	memset(f, 0x3f, sizeof f);
	
	for(int i = 0; i <= k; i ++ ) {
		f[1][i] = a[1] - a[0];
	}
	a[n + 1] = inf;
	for(int i = 1; i <= n; i ++ ) {
		for(int j = 0; j <= k; j ++ ) if(f[i][j] < inf) {
			chkmin(f[i + 1][j], f[i][j] + a[i + 1] - a[i]);
			for(int K = 0; K <= j; K ++ ) {
				if(a[i] + K * s >= a[n]) {
					chkmin(f[n][j - K], f[i][j]);
				} else if(a[i] + K * s < a[i + 1]) {
					continue;
				} else {
					int idx = upper_bound(a + 1, a + 1 + n, a[i] + K * s) - a;
					-- idx;
					chkmin(f[idx][j - K], f[i][j]);
				}
			}
			
		}
	}
	
	ll ans = INT64_MAX;
	for(int i = 0; i <= k; i ++ )  {
		chkmin(ans, f[n][i]);
	}
	ans += p - a[n];
	cout << ans ;
	
	
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;// cin >> T;
  while(T --) solve();

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
