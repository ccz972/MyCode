// Problem: A. Print a Pedestal (Codeforces logo?)
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/A
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
int a[3];
void solve() {
  int n; cin >> n;
  
  if(n % 3 == 1) {
  	a[1] = n / 3 + 2;
  	a[0] = n / 3;
  	a[2] = n / 3 - 1;
		//7  2     2 4 1 
  } else if(n % 3 == 2) {
  	// 4 5 2
  	a[1] = n / 3 + 2;
  	a[0] = n / 3 + 1;
  	a[2] = n / 3 - 1;	
  } else {
  	// 2 3 1
		a[1] = n / 3 + 1;
		a[0] = n / 3;
		a[2] = n / 3 - 1;
  }
  rep(i, 0, 2) {
  	cout << a[i] << " ";
  }
  cout << "\n";
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
