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

int n, m;
ll k;

const int N = 510;

ll a[N][N];
ll sum[N][N];
void solve() {
  cin >> n >> m >> k;
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> a[i][j];
    }
  }  
  rep(i, 1, m) {
    rep(j, 1, n) {
      sum[i][j] += sum[i][j - 1] + a[j][i];
    }
  }
  ll ans = 0;
  rep(low, 1, n) {
    rep(high, low, n) {
      ll s = 0;
      for(int i = 1, j = 0; i <= m; i ++ ) {
        while(j < m && s + sum[j + 1][high] - sum[j + 1][low - 1] <= k) {
          s += sum[j + 1][high] - sum[j + 1][low - 1];
          ++ j;
        }
          ans += (j - i + 1);
        s -= sum[i][high] - sum[i][low - 1];
      }
    }
  }
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}