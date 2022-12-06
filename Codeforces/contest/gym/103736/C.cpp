 
 
 
 // Problem: D. Tree Problem
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/D
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
constexpr int N = 5e5 + 10;
ll a[N], b[N], s[N];
void solve() {
  int n; cin >> n;
  
  rep(i, 1, n) {
  	cin >> a[i];
  	b[i - 1] = a[i] - a[i - 1];
  	
  }
	sort(b + 1, b + n);
	
	rep(i, 1, n) {
		s[i] = s[i - 1] + b[i];
		// cout << s[i] << " \n"[i == n];
	} 
	
  int q; cin >> q;
  while(q -- ) {
  	ll t; cin >> t;
		int idx = upper_bound(b + 1, b + n, t) - b;
		if(t >= b[n - 1]) {
			cout << s[n - 1] + t << "\n";
			
		} else { //
			ll ans = s[idx - 1] + t * (n - idx + 1);
			cout << ans << "\n";
		}
  	
  	
  }
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

 