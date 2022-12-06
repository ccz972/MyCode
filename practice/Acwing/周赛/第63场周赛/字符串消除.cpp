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
  string s, t; //cin >> s;
  cin >> t;
  int cnt = 0;
  for(int i = 0; t[i]; i ++ ) {
    s += t[i];
    if(s.size() >= 2) {
      if(s.back() == s[s.size() - 2]) {
        ++ cnt;
        s.pop_back();s.pop_back();
      }
    }
  }
  if(cnt & 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}