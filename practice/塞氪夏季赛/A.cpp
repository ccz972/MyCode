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
constexpr int N = 200010;

int a[N];
ll f[N];

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  int ans = 0;
  f[1] = 1;

  for(int i = 1; i <= n; i ++ ) {
    chkmax(ans, i + a[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();

  return 0;
}