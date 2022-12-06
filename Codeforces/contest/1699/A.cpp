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
  int T;
  cin >> T;

  auto solve = [&] () {
    int n; cin >> n;
    if(n & 1) {
      cout << "-1\n";
    } else {
      cout << n / 2 << " 0 0\n"; 
    }
  };

  while (T--) {
    solve();
  }
  return 0;
}