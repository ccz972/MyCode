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
  int n;
  cin >> n;
  string op(2 * n, ' '); 
  vector<int> a(n * 2);
  vector f(2 * n, vector<ll>(2 * n, -2e9)); //max
  vector g(2 * n, vector<ll>(2 * n, 2e9)); //min

  for(int i = 0; i < n; i ++ ) {
    cin >> op[i] >> a[i];
    op[i + n] = op[i], a[i + n] = a[i]; 
    f[i][i] = g[i][i] = f[i + n][i + n] = g[i + n][i + n] = a[i];
  }


  

  for (int len = 2; len <= n; len ++ ) {
    for (int l = 0; l + len - 1 < 2 * n; l ++ ) {
      int r = l + len - 1;
      for (int k = l; k < r; k ++ ) if(op[k + 1] == 't') {
        chkmax(f[l][r], f[l][k] + f[k + 1][r]);
        chkmin(g[l][r], g[l][k] + g[k + 1][r]);
        debug(f[l][r], g[l][r]);
      } else {
        chkmax(f[l][r], max(f[l][k] * f[k + 1][r], g[l][k] * g[k + 1][r]));
        chkmin(g[l][r], min(f[l][k] * g[k + 1][r], g[l][k] * f[k + 1][r]));
        debug(f[l][r], g[l][r]);
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i ++ ) {
    chkmax(ans, f[i][i + n - 1]);
  }

  cout << ans << "\n";
  for (int i = 0; i < n; i ++ ) if(ans == f[i][i + n - 1]) {
    cout << i + 1 << " ";
  }


  return 0;
}