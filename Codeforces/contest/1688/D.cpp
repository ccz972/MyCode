// Problem: D. The Enchanted Forest
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.ml/contest/1688/problem/D
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
constexpr int N = 2e5 + 10;
ll a[N];
void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) {
  	cin >> a[i];
  	a[i] += a[i - 1];
  }
  ll ans = 0;
  if(k <= n) {
		for(int i = k; i <= n; i ++ ) {
			chkmax(ans, (ll)a[i] - a[i - k]);
		}
		ans += (ll)k * (k - 1) / 2;
  } else {
  	ans = a[n];
		ans += (ll)(1ll * k - 1 + k - n) * n / 2;
  }
  
  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
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
