// Problem: C. awoo's Favorite Problem
// Contest: Codeforces - Educational Codeforces Round 130 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1697/problem/C
// Memory Limit: 256 MB
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
	int n; cin >> n;
  string s, t; cin >> s >> t;
	string x1 = s, x2 = t;
	sort(x1.begin(), x1.end());
	sort(x2.begin(), x2.end());
	if(x1 != x2) {
		cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n; i ++ ) {
		if(s[i] == t[i]) continue;
		if((s[i] == 'a' && t[i] == 'c') || (t[i] == 'a' && s[i] == 'c')) {
			cout << "NO\n";
			return ;			
		}
		int s1 = 0, s2 = 0, t1 = 0, t2 = 0;
		int j = i; 
		while(j < n && (s[j] == s[i] || s[j] == t[i]) && (t[j] == s[i] || t[j] == t[i])) {
			s1 += (s[j] == s[i]);
			s2 += (s[j] == t[i]);
			t1 += (t[j] == s[i]);
			t2 += (t[j] == t[i]);
			++ j; 
		}
		if(s1 != t1 || s2 != t2) {
			cout << "NO\n";
			return ;
		}
		int c1 = 0, c2 = 0;
		
		if(s[i] == 'a' || t[i] == 'a') {
			for(int k = i; k < j; k ++ ) {
				c1 += (s[k] == 'a');
				c2 += (t[k] == 'a');
				if(c1 < c2) {
					cout << "NO\n";
					return ;
				}
			}
		} else {
			for(int k = i; k < j; k ++ ) {
				c1 += (s[k] == 'c');
				c2 += (t[k] == 'c');
				if(c1 > c2) {
					cout << "NO\n";
					return ;
				}
			}
		}
		
		i = j - 1;
		// cout << "i = " << i << "\n";
	}
	cout << "YES\n";
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
