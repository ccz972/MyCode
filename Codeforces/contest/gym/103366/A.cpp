#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for(int i(a); i <= b; ++ i)

const int N = 510;
const int mod = 998244353;

int a[N][N];

ll f[2][N][N * 2];

void solve() {
  int n, m; cin >> n >> m;
  int p, q; cin >> p >> q;

  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> a[i][j];
    }
  }

  f[1][1][a[1][1]] = 1;
  rep(i, 1, n) {
    rep(j, 1, m) {
      rep(k, 0, n + m) if(f[i & 1][j][k]) {
        // cout << f[i & 1][j][k] << "\n";
        f[i + 1 & 1][j][k + a[i + 1][j]] += f[i & 1][j][k];

        // cout << i << " " << j << " " << k << " " << f[i & 1][j][k] << "\n";
        // cout << i + 1 << " " << j << " " << k + a[i + 1][j] << " " << f[i + 1 & 1][j][k + a[i + 1][j]] << "\n";
        f[i + 1 & 1][j][k + a[i + 1][j]] %= mod;
        // if(j == m) {
        //   cout << f[i + 1 & 1][j][k + a[i + 1][j]] << "\n";
        // }
        f[i & 1][j + 1][k + a[i][j + 1]] += f[i & 1][j][k];
        f[i & 1][j + 1][k + a[i][j + 1]] %= mod;
      }
    }
    if(i != n)
    memset(f[i & 1], 0, sizeof f[i & 1]);
  }
  ll ret = 0;
  for(int i = 0; i <= n + m + 1; i ++ ) {
    if(i >= q && n + m - 1 - i >= p) {
      ret += f[n & 1][m][i];
      ret %= mod;
    }
  }
  // for(int i = 0; i <= n + m + 1; i ++ ) {
  //   cout << f[n & 1][m][i] << " ";
  // }
  // cout << "\n";
  cout << ret << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}