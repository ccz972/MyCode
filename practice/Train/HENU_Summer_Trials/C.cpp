// Problem: C. 选数 (hard-version)
// Contest: Codeforces - HENU Summer Trials
// URL: https://codeforces.com/gym/384484/problem/C
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
  int n, m; cin >> n >> m;
  vector<int> cnt(m);
  for(int i = 0; i < n; i ++ ) {
  	int x; cin >> x;
  	x %= m;
  	if(!x) {
  		cout << "YES\n";
  		return ;
  	}
  	cnt[x] ++; 
  }
	vector<int> v;
	for(int i = 0; i < m; i ++ ) {
		int x = i, y = cnt[i];
		int s = 1;
		while(s <= y) {
			v.push_back((x * s) % m);
			y -= s;
			s <<= 1;
		}
		if(y) {
			v.push_back((y * x) % m);
		}
	}
	n = v.size();
	bitset<2001> f;
	f.set(0);
	for(int i = 0; i < n; i ++ ) {
		int x = v[i];
		if(f[m - x]) {
			cout << "YES\n";
			return ;
		}
		f |= f << x;
		f |= f >> m;
		// for(int j = 0; j < m * 2; j ++ ) {
			// cout << f[j] << " ";
		// }
		// cout << "\n"
		// f >>= x;
		// f <<= m;
	}
	cout << "NO\n";
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
