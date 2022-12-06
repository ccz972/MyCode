// Problem: C - ±1 Operation 1
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_c
// Memory Limit: 1024 MB
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
  ll x, a, d, n; cin >> x >> a >> d >> n;
  x -= a;
  ll ans = abs(x);
  if(!d) {
  	cout << ans;
  	return;
  }
  //x = k * d (0 <= k <= n - 1)
	chkmin(ans, abs((n - 1) * d - x));
	ll l = x / d;
	if(l >= 0 && l <= n - 1) chkmin(ans, abs(l * d - x));
	if(l >= 1 && l <= n - 2) chkmin(ans, abs((l - 1) * d - x));
	if(l >= -1 && l <= n) chkmin(ans, abs((l + 1) * d - x));
	cout << ans << "\n";
  
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
