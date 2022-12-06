// Problem: E. Railway System
// Contest: Codeforces - Codeforces Round #796 (Div. 2)
// URL: https://codeforces.ml/contest/1688/problem/E
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


template <typename T> inline void querymax(T &x, T y) { x = max(x, y); }
template <typename T> inline void querymin(T &x, T y) { x = min(x, y); }

constexpr int N = 510;

pair<int, int> a[N];
int res[N];

int main() {
  auto query = [&] () {
		cout << "? ";
		for(int i = 1; i <= m; i ++ ) {
			cout << res[i];
		}
		cout << endl;	
		int x; cin >> x;
		return x;  	
  };

	int n, m; cin >> n >> m;
  for(int i = 1; i <= m; i ++ ) {
  	res[i] = 1;
		a[i].first = query();
		a[i].second = i;
		res[i] ^= 1;
  }

  sort(a + 1, a + 1 + m);
  
  for(int i = 1; i <= m; i ++ ) res[i] = 1;
	int last = query();
	int ans = a[1].first;
	
	for(int i = m - 1; i >= 1; i -- ) {
		res[a[i + 1].second] = 0;
		int x = query();
		if(x + a[i + 1].first == last) {
			ans += a[i + 1].first;
		}
		last = x;
	}
	cout << "! " << ans << endl;
  
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
