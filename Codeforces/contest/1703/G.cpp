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

constexpr int N = 1E5 + 10;
constexpr ll INF = 1E18;
ll a[N];
ll f[N][33];
ll get(ll x, int cnt) {
  while(x && cnt) {
    x /= 2;
    cnt --;
  }
  return x;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
      cin >> a[i];
      for(int j = 0; j <= 32; j ++ ) {
        f[i][j] = -INF;
      }
    }
    for(int i = 1; i <= 32; i ++ ) f[0][i] = -INF;
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++ ) {
      for(int j = 0; j <= 32; j ++ ) {
        chkmax(f[i][j], f[i - 1][j] + get(a[i], j) - m);
        if(j)
          chkmax(f[i][j], f[i - 1][j - 1] + get(a[i], j));
        if(j == 32) {
          chkmax(f[i][j], f[i - 1][j]);
        }
      }
      // f[i][]
    }
    ll ans = INT_MIN;
    for(int i = 0; i <= 32; i ++ ) {
      chkmax(ans, f[n][i]);
    }
    cout << ans << "\n";
  }
  return 0;
}