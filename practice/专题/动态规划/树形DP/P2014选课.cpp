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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int> > son(n + 1);
  vector<int> w(n + 1), sz(n + 1);

  for(int i = 1; i <= n; i ++ ) {
    int x; cin >> x >> w[i];
    son[x].push_back(i);
  }
  vector<vector<int> > f(n + 1, vector<int> (m + 1));


  function<void(int)> dfs = [&](int u) {
    for (auto& v : son[u]) {
      dfs(v);
      sz[u] += sz[v];
      vector<int> tmp(sz[u] + 1);
      for(int i = 1; i <= min(sz[u], m); i ++ ) tmp[i] = f[u][i]; 
      for(int i = 0; i <= min(sz[u], m); i ++ ) {
        for(int j = 1; j <= min(sz[v], i); j ++ ) {
          chkmax(tmp[i], f[v][j] + f[u][i - j]);
        }
      }
      for(int i = 1; i <= min(sz[u], m); i ++ ) f[u][i] = tmp[i]; 
    }
    sz[u] ++;
    if(u) {
      for(int i = min(sz[u], m); i >= 1; i -- ) {
        f[u][i] = f[u][i - 1] + w[u];
      }
    }
    f[u][0] = 0;
    
  };

  dfs(0);

  cout << f[0][m] << "\n";

  return 0;
}