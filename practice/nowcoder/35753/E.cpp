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
constexpr double pi = 3.14159265358979;
void solve() {
  int r, n; cin >> r >> n;
	// double ans = pi * 2 / n * r * r / 2;// - sin(pi / n) * cos(pi / n) * r * r;
	double ans = sin(pi / n) * cos(pi / n) * r * r;
	// printf("%.2lf\n", pi);
	// printf("%.2lf\n", cos(pi / n));
	// printf("%.2lf\n", sin(pi / n));
	// printf("%.2lf\n", pi * 2 / n * r * r / 2);
	// printf("%.2lf\n", sin(pi / n) * cos(pi / n) * r * r);
	// printf("%.2lf\n", ans);
	ans *= n;
	printf("%.2lf", ans);
	// cout << fixed << setpresicion(2) << ans << "\n";
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
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
