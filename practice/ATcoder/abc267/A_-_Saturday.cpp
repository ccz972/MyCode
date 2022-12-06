#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  string s;
  cin >> s;
  if (s[0] == 'M') {
  	cout << 5;
  } else if (s[0] == 'T') {
  	if (s[1] == 'u')
  		cout << 4;
  	else 
  		cout << 2;
  } else if (s[0] == 'W') {
  	cout << 3;
  } else if (s[0] == 'F') {
  	cout << 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}