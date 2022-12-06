#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for (int i = (b); i <= (s); ++i)
#define dec(i, b, s) for (int i = (b); i >= (s); --i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}

constexpr int N = 1E6 + 10;

int a[N];
ll f[N], g[N];
// f[j][i]表示第i个选，前 i-1个选了j组最大子段和
// g[j][i]表示第i个不选，前 i-1个选了j组最大子段和

void solve() {
  int n, m;
  while (cin >> m >> n) {
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
      f[i] = g[i] = 0;
    } //I'm ok !
    ll ans = INT64_MIN;
    for (int j = 1; j <= m; j++) {
      ans = INT64_MIN;
      for (int i = j; i <= n; i++) {
        f[i] = max(f[i - 1] + a[i], g[i - 1] + a[i]);
        g[i - 1] = ans;
        chkmax(ans, f[i]);  //相当于取了前缀 max
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();
  return 0;
}