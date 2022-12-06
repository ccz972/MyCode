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

constexpr int N = 20;
constexpr int M = 1 << 20;

int a[N];
int dist[N][N];
ll f[M][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < n; i ++ ) cin >> a[i];
  for(int i = 1; i <= k; i ++ ) {
    int x, y, c; cin >> x >> y >> c;
    dist[x - 1][y - 1] = c;
  }

  for(int i = 0; i < n; i ++ ) {
    f[1 << i][i] = a[i];
  }

  for(int i = 1; i < 1 << n; i ++ ) {
    for(int j = 0; j < n; j ++ ) if(i >> j & 1) {
      //f[i][j]
      for(int k = 0; k < n; k ++ ) if(not (i >> k & 1)) {
        chkmax(f[i ^ (1 << k)][k], f[i][j] + a[k] + dist[j][k]);
      }
    }
    // for(int j = 0; j < n; j ++ ) if(i >> j & 1) {
    //   int p = i ^ (1 << j); int now = a[j];
    //   for(int q = 0; q < n; q ++ ) if(i >> q & 1) now += dist[q][j];
    //   chkmax(f[i], f[p] + now);
    //   if(i == 40) {
    //     cout << p << " " << f[p] << " " << now << " " << f[i] << "\n";
    //   } // 45 44 40 32 
    //   //5 3 2 0
    //   //6 4 3 1
    //   //1 + 5 + 13 + 2 + 15 + 8 = 
    // }
    // // debug(i, f[i]);
  }
  
  ll ans = 0;
  for(int i = 0; i < 1 << n; i ++ ) if(__builtin_popcount(i) == m) {
    // debug(i);
    for(int j = 0; j < n; j ++ ) if(i >> j & 1)
      chkmax(ans, f[i][j]);
  }
  cout << ans << "\n";




  return 0;
}