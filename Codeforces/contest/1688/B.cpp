// Problem: B. Patchouli's Magical Talisman
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.ml/contest/1688/problem/B
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
  int n; cin >> n;
  vector<int> a(n);
  bool flag = false;
  for(int &x: a) cin >> x, flag |= (x & 1);
	if(flag) {
		int ans = 0;
		for(int &x: a) if(!((x & 1))) {
			ans ++;
		}
		// cout << "YES ";
		cout << ans << "\n";
		return ;
	}
	vector<int> cnt(n);
	for(int i = 0; i < n; i ++ ) {
		int x = a[i], need = 0;
		while(x > 0) {
			x /= 2;
			need ++;
			if(x & 1) {
				break;
			}
		}
		cnt[i] = need;
	}
	int mi = INT_MAX, id = -1;
	for(int i = 0; i < n; i ++ ) if(cnt[i] < mi) {
		id = i;
		mi = cnt[i];
	}
	cout << mi + n - 1 << "\n";
  //x = x1 + x2
  //x = x / 2
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
