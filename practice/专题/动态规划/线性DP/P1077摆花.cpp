#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 110;
constexpr int mod = 1e6 + 7;

// int a[N];
// ll f[N][N][N];
// ll sum[N];

// void solve() {
//   int n, m; cin >> n >> m;
//   f[0][0][0] = 1;
//   rep(i, 1, n) cin >> a[i];
//   // rep(i, 0, m) sum[i] = 1;
//   sum[0] = 1;
//   rep(i, 1, n) {
//     rep(j, 0, m) {
//       rep(k, 0, min(j, a[i]) ) {
//         f[i][j][k] += sum[j - k];
//         f[i][j][k] %= mod;
//       }
//     }
//     rep(j, 0, m) {
//       sum[j] = 0;
//       rep(k, 0, min(j, a[i])) {
//         sum[j] += f[i][j][k];
//         sum[j] %= mod;
//       }
//     }
//   }
//   ll ans = 0;
//   rep(i, 0, a[n]) {
//     ans += f[n][m][i];
//     ans %= mod;
//   }

//   cout << ans << "\n";
// }

int n, m;
int f[N], sum[N], a[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  f[0] = 1;
  rep(i, 0, m) sum[i] = 1;
  rep(i, 1, n) {
    dec(j, m, 1) f[j] = (f[j] + sum[j - 1] - (j - min(a[i], j) - 1 >= 0 ? sum[j - min(a[i], j) - 1] : 0) + mod) % mod;
    rep(j, 1, m) sum[j] = (sum[j - 1] + f[j]) % mod;
  }   
  cout << f[m] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}