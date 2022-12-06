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
  vector<int> a(n * 2);
  for (auto i = 0; i < n; i ++ ) {
    cin >> a[i]; a[i + n] = a[i];
  }
  vector f(n * 2, vector<int>(n * 2));

  for (int len = 2; len <= n; len ++ ) {
    for (int l = 0; l + len - 1 < 2 * n; l ++ ) {
      int r = l + len - 1;
      for (int k = l; k < r; k ++ ) {
        chkmax(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i ++ ) {
    chkmax(ans, f[i][i + n - 1]);
  }
  
  cout << ans << "\n";
  

  return 0;
}