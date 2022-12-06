#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
using namespace std;
 
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
 

void solve() {
	string s; cin >> s;
	int n = s.size();
  //如果 n <= 2 ，直接输出 0
	if(n <= 2) {
		cout << "0\n";
		return;
	}

	int cnt = 0;

	for(char c: s) cnt += (c == '0');
	
  if(cnt == n - cnt) {
    cout << cnt - 1 << "\n";
  } else {
    cout << min(cnt, n - cnt) << "\n";
  }
  
 
}
 
int main() {
	int TTT; cin >> TTT;
	while(TTT -- )
		solve();
	return 0;
}
 