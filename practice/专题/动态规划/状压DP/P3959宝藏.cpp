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

constexpr int N = 12, M = 1 << N;
constexpr int inf = 0x3f3f3f3f;

ll f[M][N];
int dist[N][N];
int g[M];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  
  memset(dist, 0x3f, sizeof dist);
  for (int i = 1; i <= m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    -- u, -- v;
    dist[u][v] = dist[v][u] = min(dist[u][v], w);
  }
  //f[i][j] 表示当前集合为 i，并且最大深度为 j 的最小花费
  //每次枚举 i 的子集，然后通过这个子集来连接剩余的点加到最底层即可
  //复杂度 O(3^n \times n ^ 2)
  memset(f, 0x3f, sizeof f);
  
  for (int i = 1; i < 1 << n; i ++ ) {
    for (int j = 0; j < n; j ++ ) if (i >> j & 1) {
      dist[j][j] = 0;
      for (int k = 0; k < n; k ++ ) if(dist[j][k] != inf) {
        g[i] |= 1 << k;        
      }
    }
  }

  for (int i = 0; i < n; i ++ ) {
    f[1 << i][0] = 0;
  }

  for (int i = 2; i < 1 << n; i ++ ) {
    for (int j = i; j; j = (j - 1) & i) if ((g[j] | i) == g[j]) {
      ll sum = 0;
      int p = (i ^ j);
      for (int k = 0; k < n; k ++ ) if (p >> k & 1) {
        int tmp = inf;
        for (int l = 0; l < n; l ++ ) if (j >> l & 1) {
          chkmin(tmp, dist[l][k]);
        }
        sum += tmp;
      }
      for (int k = 1; k < n; k ++ ) if(f[j][k - 1] != inf) {
        chkmin(f[i][k], f[j][k - 1] + sum * k);
      }
    }
  }
  ll ans = INT64_MAX;
  for (int i = 0; i < n; i ++ ) chkmin(ans, f[(1 << n) - 1][i]);
  
  cout << ans << "\n";

  return 0;
}