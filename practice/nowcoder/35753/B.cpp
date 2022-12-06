// Problem: 圣杯地牢
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/35753/B
// Memory Limit: 262144 MB
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

constexpr int N = 100010;

ll a[N], b[N];
ll d[N];
ll sum;

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i], b[i] -= a[i], sum += b[i];
  
  rep(i, 1, n) if(b[i] < 0) {
  	cout << "NO\n";
  	return ;
  }
  
  ll all = 1ll * n * (n + 1) / 2;
  if(sum % all || sum < all) {
  	cout << "NO\n";
  	return ;
  } 
  
	ll cnt = sum / all;
	
	rep(i, 1, n) {
		d[i] = b[i] - b[i - 1];
		if(i == 1) d[i] -= b[n];
		ll res = (1 - n) * (cnt - d[i]);
		if((cnt - d[i]) % n) {
			cout << "NO\n";
			return;
		}
		res /= n;
		res += cnt;
		ll res1 = (cnt - d[i]) / n;
		if(res - res1 != d[i]) {
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
  
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
