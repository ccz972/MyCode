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


constexpr int N = 1E5 + 1;
constexpr int M = 101;
constexpr int P = 1E9 + 7;

int n, k;
vector<int> son[N];

int f[N][M][2][2], tmp[M][2][2];
int sz[N];

void add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

void dfs (int u, int fa) {
  sz[u] = 1;
  f[u][0][0][0] = f[u][1][1][0] = 1;
  for (int &v: son[u]) if (v != fa) {
    dfs (v, u);
    
    for (int i = 0; i <= min(sz[u], k); i ++ ) {
      tmp[i][0][0] = f[u][i][0][0]; f[u][i][0][0] = 0;
      tmp[i][0][1] = f[u][i][0][1]; f[u][i][0][1] = 0;
      tmp[i][1][0] = f[u][i][1][0]; f[u][i][1][0] = 0;
      tmp[i][1][1] = f[u][i][1][1]; f[u][i][1][1] = 0;
    }
    
    for (int i = 0; i <= min(sz[u], k); i ++ ) {
      for (int j = 0; j <= sz[v] && i + j <= k; j ++ ) {
        //0 0 
        
        add(f[u][i + j][0][0], 1ll * tmp[i][0][0] * f[v][j][0][1] % P);

        add(f[u][i + j][0][1], 1ll * tmp[i][0][1] * (f[v][j][0][1] + f[v][j][1][1]) % P);
        add(f[u][i + j][0][1], 1ll * tmp[i][0][0] * (f[v][j][1][1]) % P);

        add(f[u][i + j][1][0], 1ll * tmp[i][1][0] * (f[v][j][0][0] + f[v][j][0][1]) % P);

        add(f[u][i + j][1][1], 1ll * tmp[i][1][0] * (f[v][j][1][0] + f[v][j][1][1]) % P);
        add(f[u][i + j][1][1], 1ll * tmp[i][1][1] * (f[v][j][1][0] + f[v][j][1][1]) % P);
        add(f[u][i + j][1][1], 1ll * tmp[i][1][1] * (f[v][j][0][0] + f[v][j][0][1]) % P);
      }
    }
    sz[u] += sz[v];
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  /*
  f[i][j][2]  表示 i 这个子树，安装了 j 个监听器，并且 0/1 表示 当前节点 装/不装 监听器，并且 i 的子树都处于被监听状态
  update 
  如果当前点选，那么他的所有儿子爱选不选
  如果当前点选，那么他至少有一个儿子选 ？ 好像无法处理()
  */

  // SOLUTION
  /*
  f[i][j][0/1][0/1] 表示 i 这个子树，安装了 j 个监听器，并且 0/1 表示 当前节点 装/不装 监听器， 0/1表示当前节点有无被监听
  */
  dfs(1, 0);

  int ans = f[1][k][0][1] + f[1][k][1][1];
  ans %= P;
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}