// Problem: C. Circular Local MiniMax
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/C
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
  map<int, int> mp;
  for(int &x: a) cin >> x, mp[x] ++;
  if(n & 1) {
  	cout << "NO\n";
  	return ;
  }
  for(auto [k, v] : mp) {
  	if(v > n / 2) {
  		cout << "NO\n";
  		return ;
  	}
  }
  
  sort(a.begin(), a.end());
  
  vector<int> b(n);
  int j = 0;
  for(int i = 0; i < n; i += 2) {
  	b[i] = a[j ++];
  }
  for(int i = 1; i < n; i += 2) {
  	b[i] = a[j ++];
  }
  
  auto chk = [&] (int idx) {
  	bool flag1 = (b[idx] > b[(idx + 1) % n] && b[idx] > (b[(idx + n - 1) % n]));
  	bool flag2 = (b[idx] < b[(idx + 1) % n] && b[idx] < (b[(idx + n - 1) % n]));
  	return flag1 || flag2;
  };
  
  
  for(int i = 0; i < n; i ++ ) {
  	if(!chk(i)) {
  		cout << "NO\n";
  		return ;
  	}
  }
  
  cout << "YES\n";
  for(int x: b) cout << x << " ";
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
