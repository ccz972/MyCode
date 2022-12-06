#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define chkmax(a, b) a = (a >= b ? a : b)
#define pow2(a) ((a) * (a))
constexpr int N = 310;
constexpr int P = 1E6 + 3;
ll a[N], f[N][N], g[N][N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i ++ ) {
    g[i][i] = a[i];
    for (int j = i + 1; j <= n; j ++ ) {
      g[i][j] = g[i][j - 1] * a[j] % P;
    }
  }
  for (int len = 2; len <= n; len ++ ) {
    for (int l = 1; l + len - 1 <= n; l ++ ) {
      int r = l + len - 1;
      for (int k = l; k < r; k ++ ) {
        // cout << l << " " << k << " " << r << " " << pow2(g[l][k] - g[k + 1][r]) << "\n";
        chkmax(f[l][r], f[l][k] + f[k + 1][r] + pow2(g[l][k] - g[k + 1][r]));
      }
    }
  }
  cout << f[1][n] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- ) {
    solve();
  }
  return 0;
}