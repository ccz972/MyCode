#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2010;

int n, m;
ll dp[N][N];
ll a[N];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  memset(dp, -0x3f, sizeof dp);
  // dp[0][0] = 0;
  for (int i = 0; i <= n; i ++ ) dp[i][0] = 0;
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= m; j ++ ) {
      dp[i][j] = dp[i - 1][j];
      chkmax(dp[i][j], dp[i - 1][j - 1] + a[i] * j);
    }
    // for (int j = 1; j <= m; j ++ ) {
    //   cout << dp[i][j] << " \n"[j == m];
    // }
  }  
  cout << dp[n][m] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}