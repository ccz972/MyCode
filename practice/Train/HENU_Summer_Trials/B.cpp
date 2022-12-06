// Problem: B. 选数 (easy-version)
// Contest: Codeforces - HENU Summer Trials
// URL: https://codeforces.com/gym/384484/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
  int n, m; cin >> n >> m;
  vector<int> a(n);
  
  for(int &x: a) {
  	cin >> x;
  	x %= m;
  	if(!x) {
  		cout << "YES\n";
  		return ;
  	}
  }
  // for(int x: a) cout << x << " ";
  // cout << "\n";
  vector<int> f(m);
	f[0] = 1;
	
	for(int i = 0; i < n; i ++ ) {
		auto g = f;
		for(int j = 0; j < m; j ++ ) {
			if(f[j]) {
				g[(j + a[i]) % m] ++ ;
			}
		}
		for(int j = 0; j < m; j ++ ) {
			f[j] = g[j];
			// cout << f[j] << " ";
		}
		// cout << "\n";
	}
	
	if(f[0] > 1) cout << "YES\n";
	else cout << "NO\n";
  // for(int i = 0; i < n; i ++ ) {
  	// cin >> a[i];
  	// b[i] = a[i] % m;
  	// if(i) b[i] = (b[i] + b[i - 1]) % m;
  // }
	// map<int, int> mp;
	// mp[0] = 1;
	// for(int i = 0; i < n; i ++ ) {
		// if(mp.count(b[i])) {
			// cout << "YES\n";
			// return ;
		// }
		// mp[b[i]] ++;
	// }
	// cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
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
