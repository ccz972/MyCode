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

void solve() {
  int a, b; cin >> a >> b;
  char c = (a > b ? '0' : '1');
  string s(a + b, c);
  for(int i = 0; i < min(a, b); i ++ ) {
    s[i * 2] = '0';
    s[i * 2 + 1] = '1';
  }
  cout << s << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}