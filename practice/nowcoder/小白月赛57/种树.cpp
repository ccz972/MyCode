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
  int n; cin >> n;
  string s; cin >> s;
  int cnt = count(s.begin(), s.end(), '1');
  if (cnt == n) {
    cout << "0\n";
  } else {
    if (s[0] == '1' || s.back() == '1') {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}