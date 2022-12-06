// Problem: B - Light It Up
// Contest: AtCoder - Aising Programming Contest 2022（AtCoder Beginner Contest 255）
// URL: https://atcoder.jp/contests/abc255/tasks/abc255_b
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
  int n, k; cin >> n >> k;
  vector<int> vis(n);
  rep(i, 1, k) {
  	int x; cin >> x;
  	vis[x - 1] = true;
  }
  vector<array<int, 2> > p(n);
  rep(i, 0, n - 1) {
  	cin >> p[i][0] >> p[i][1];
  }
  vector<double> ans(n, 1e10);
  auto get = [&] (int x, int y) -> double {
  	// cout << p[x][0] << " " << p[y][0] << "\n";
  	double res = (double)(1.0 * p[x][0] - p[y][0]) * (p[x][0] - p[y][0]) 
  						 + (double)(1.0 * p[x][1] - p[y][1]) * (p[x][1] - p[y][1]);
		return sqrt(res);
  };
	rep(i, 0, n - 1) if(vis[i]) {
		rep(j, 0, n - 1) if(!vis[j]) {
			// cout << i << " " << j << "\n";
			ans[j] = min(ans[j],  get(i, j));
		}
	}
	double ret = 0;
	rep(i, 0, n - 1) if(!vis[i]) {
		ret = max(ret, ans[i]);
	}
	printf("%.10lf", ret);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;// cin >> T;
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
