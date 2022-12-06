// Problem: D. Linguistics
// Contest: Codeforces - Codeforces Round #794 (Div. 2)
// URL: https://codeforces.com/contest/1686/problem/D
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
int a[4];
int b[4];

void solve(int id) {
	for(int i = 0; i < 4; i ++ ) cin >> a[i], b[i] = a[i];
	int cnta = 0, cntb = 0;
	string s; cin >> s;
	for(char c: s)
		if(c == 'A') cnta ++;
		else cntb ++;
	if(cnta != a[0] + a[2] + a[3] || cntb != a[1] + a[2] + a[3]) {
		cout << "NO\n";
		return;
	}
	int la = 0, lb = 0, res = 0;
	int n = s.size();
	for(int i = 0, j = 0; i < n; i ++ ) {
		j = i;
		while(j < n - 1 && s[j + 1] != s[i]) {
			++ j;
		}
		if((j - i + 1) & 1) {
			res += (j - i + 1) / 2;
		} else {
			if(s[i] == 'A') la += (j - i + 1) / 2;
			else lb += (j - i + 1) / 2;
		}
		i = j;
	}
	
	
	
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  int tt = 0;
  while(T --) solve(++ tt);

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
