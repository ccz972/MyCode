#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

ll val[10];
ll s[110];
ll f[102][51][34][26][21];
void solve() {
  int n; ll t; cin >> n >> t;
  for (int i = 1; i <= 4; i ++ ) {
    cin >> val[i];
    val[i] += val[i - 1];
  }

  for (int i = 1; i <= n; i ++ ) {
    cin >> s[i];
    s[i] += s[i - 1];
  }
  //f[i][j][k][l][m]表示前i个，j个1，k个2 l个3 m个4
  // memset(f, -0x3f, sizeof f);
  f[0][0][0][0][0] = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i ++ ) {
    for (ll j = 0, cntj = 0, costj = 0; cntj <= i + 1 && costj <= t; j ++, cntj += 2, costj += val[1]) {
      for (ll k = 0, cntk = 0, costk = 0; cntj + cntk <= i + 1 && costj + costk <= t; k ++, cntk += 3, costk += val[2]) {
        for (ll l = 0, cntl = 0, costl = 0; cntj + cntk + cntl <= i + 1 && costj + costk + costl <= t; l ++, cntl += 4, costl += val[3]) {
          for (ll m = 0, cntm = 0, costm = 0; cntj + cntk + cntl + cntm <= i + 1 && costj + costk + costl + costm <= t; m ++, cntm += 5, costm += val[4]) {
            f[i][j][k][l][m] = f[i - 1][j][k][l][m];
            if (j) {
              chkmax(f[i][j][k][l][m], f[max(0, i - 2)][j - 1][k][l][m] + s[i] - s[i - 1]);
            }
            if (k) {
              chkmax(f[i][j][k][l][m], f[max(0, i - 3)][j][k - 1][l][m] + s[i] - s[i - 2]);
            }
            if (l) {
              chkmax(f[i][j][k][l][m], f[max(0, i - 4)][j][k][l - 1][m] + s[i] - s[i - 3]);
            }
            if (m) {
              chkmax(f[i][j][k][l][m], f[max(0, i - 5)][j][k][l][m - 1] + s[i] - s[i - 4]);
            }
            chkmax(ans, f[i][j][k][l][m]);
          }
        }
      }
    }
  }

  cout << ans << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
