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
  int n, x; cin >> n >> x;
  ll ans = INT64_MAX;
  vector<array<int, 2> > a(n);
  for(auto &[x, y]: a) cin >> x >> y; 
  ll now = 0;
  for(int i = 0; i < n && i < x; i ++ ) {
    now += a[i][0] + a[i][1];
    ll ret = now;
    int cnt = x - i - 1;
    chkmin(ans, ret + 1ll * a[i][1] * cnt);
  }
  cout << ans << "\n";

  return 0;
}