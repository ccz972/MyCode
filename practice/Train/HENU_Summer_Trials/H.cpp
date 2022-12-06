// Problem: H. 神奇数字
// Contest: Codeforces - HENU Summer Trials
// URL: https://codeforces.com/gym/384484/problem/H
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
  int a, b, c; cin >> a >> b >> c;
  int g = abs(b - a);
	if(g == 1) {
		cout << "-1\n";
		return ;
	}
	// cout << g << "\n";
	for(int i = 2; i <= g / i; i ++ ) {
		if(g % i == 0) {
			if(a % i == b % i && a % i == c % i) {
				cout << i << "\n";
				return ;
			}
			int j = g / i;
			if(a % j == b % j && a % j == c % j) {
				cout << j << "\n";
				return ;
			}
		}
	}
	cout << "-1\n";
  //a = k1 x + p
  //b = k2 x + p
  //c = k3 x + p
	
	//b - a = (k2 - k1)x 
	
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
