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

constexpr int N = 110;
constexpr int p = 1e9 + 7;

ll f[N * 2][N][210];

void solve() {
  int n, m; cin >> n >> m;
  n += m;
  //遇到花j次
  f[0][0][2] = 1;
  for(int i = 1; i < n; i ++ ) {
    for(int j = 0; j < i && j < m; j ++ ) {
      for(int k = 0; k <= 100; k ++ ) if(f[i - 1][j][k]) {
        //dian
        ll &ret1 = f[i][j][k * 2];      
        ret1 = (ret1 + f[i - 1][j][k]) % p;
        if(k) {
          ll &ret2 = f[i][j + 1][k - 1];
          ret2 = (ret2 + f[i - 1][j][k]) % p;
        }
        // debug(ret1, ret2);
      }
    }
  }
  cout <<  f[n - 1][m - 1][1] << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}