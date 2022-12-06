// Problem: I. IHI's Homework
// Contest: Codeforces - The 2022 Hangzhou Normal U Summer Trials
// URL: https://codeforces.com/gym/103736/problem/I
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

constexpr int N = 1e5 + 10;
char s[N];
struct node {
	int op; 
	char x, y;
}a[N];
void solve() {
	int n; cin >> n;
	string s;
	rep(i, 1, n) {
		int op; cin >> op;
		a[i].op = op;
		if(op == 1) {
			char c; cin >> c;
			a[i].x = c;
			s.push_back(c);
		} else if(op == 2) {
			if(s.size()) {
				s.pop_back();
			}
		} else {
			char x, y; cin >> x >> y;
			a[i].x = x, a[i].y = y;
		}
	}
	if(s.empty()) {
		cout << "The final string is empty";
		return ;
	}
	vector<int> f(26, -1);
	for(int i = n; i >= 1; i -- ) {
		if(a[i].op == 3) {
			int x = a[i].x - 'a', y = a[i].y - a;
			if(f[x] == -1) {
				f[x] = y;
			}
		}
	}
	n = s.size();
	for(int i = 0; i < n; i ++ ) {
		if(f[s[i] - 'a'] == -1) {
			cout << s[i];
		} else {
			cout << (char)('a' + f[s[i] - 'a']);
		}
	}
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
