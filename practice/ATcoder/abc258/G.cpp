#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  bitset<3001> f[3001];
  for (int i = 1; i <= n; i ++ ) {
    string s; cin >> s;
    for (int j = i + 1; j <= n; j ++ ) if (s[j - 1] == '1') {
      f[i][j] = 1;
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = i + 1; j <= n; j ++ ) if(f[i][j]) {
      auto k = f[i] & f[j];
      ans += k.count();
    }
  }
  cout << ans << "\n";

  return 0;
}