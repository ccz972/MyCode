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
  while (T--) {
    ll n; cin >> n;
    ll mx = INT64_MAX;
    ll i = 1;
    while(i <= n) {
      chkmin(mx, n - i);
      i *= 10;
    }
    cout << mx << "\n";
  }
  return 0;
}