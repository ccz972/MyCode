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

void chkmax(int &a, int b) {
  a = a > b ? a : b;
}

const int mod = 998244353;
const int N = 3e3 + 10;

int f[N][N];
int g[N];
int a[N], b[N];

void solve() {
  int n, m; cin >> n >> m;
  f[0][0] = 1;
  for (int i = 1; i <= n; i ++ ) {
    int p; cin >> p;
    for (int j = 0; j < p; j ++ ) cin >> a[j];
    for (int j = 0; j < p; j ++ ) cin >> b[j];
    memset(g, 0, sizeof g);
    for (int j = 0; j < p; j ++ ) {
      int v = b[j], w = a[j]; //cin >> w >> v;
      for (int k = 3000; k >= v; k -- ) if(k == v || g[k - v]) {
        chkmax(g[k], g[k - v] + w);
      }
    }

    for (int j = 0; j <= 3000; j ++ ) if(!j || g[j]) {
      if (g[j] > m) g[j] = m;
      for (int k = 0; k < g[j]; k ++ ) {
        f[i][m] = (f[i][m] + f[i - 1][m - k]) % mod;
      }

      //f[i][j] 表示前i个中选，伤害值为j的方案数字

      //对于小于g[j]的转移，我们不能选 g[j]，因此
      //
      for (int k = m; k >= g[j]; k -- ) {
        f[i][k] = (f[i][k] + f[i - 1][k - g[j]]) % mod;
      }
    }

  }
  
  cout << f[n][m] << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}