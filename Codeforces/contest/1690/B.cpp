// Problem: B. Array Decrements
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/B
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
  vector<int> b(n);
  rep(i, 1, n) {
  	cin >> a[i - 1];
  }
  rep(i, 1, n) {
  	cin >> b[i - 1];
  }
  int t = -1;
  int mi = -1e9;
  for(int i = 0; i < n; i ++ ) if(b[i]) {
  	if(a[i] < b[i]) {
  		cout << "NO\n";
  		return ;
  	}	
  	if(~t && t != a[i] - b[i]) {
  		cout << "NO\n";
  		return ;  		
  	}
  	if(t == -1) {
  		t = a[i] - b[i];
  	}
  } else {
		chkmax(mi, a[i]);
  }
  if(t == -1 || (t >= mi))
	  cout << "YES\n";
	else 
		cout << "NO\n";
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
