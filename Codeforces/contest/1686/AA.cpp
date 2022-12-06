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
	
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<int> a(n); 
	int sum = 0;
	rep(i, 1, n) cin >> a[i - 1], sum += a[i - 1];
	for(int i = (1 << n) - 1; i >= 0; i -- ) {
		int now = 0;
		for(int j = n - 1; j >= 0; j -- ) if(i >> j & 1) {
			now += a[n - j - 1];
		}
		
		if(now <= m1 && sum - now <= m2) {
			for(int j = n - 1; j >= 0; j -- ) if(i >> j & 1) {
				cout << n - j << " ";
			}
			cout << "\n";
			for(int j = n - 1; j >= 0; j -- ) if(!(i >> j & 1)) {
				cout << n - j << " ";
			}
			return ;
		}
		
	}
	cout << "No Solution";

	
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


/*
1 3 6 7
2 4 5

2 3 5 6
1 4 7

2 4 5 6 7
1 3


*/