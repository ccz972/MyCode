/***************************************************

@File    : P1272重建道路2.cpp
@Time    : 2022/07/07 22:50:21
@Author  : Nanfeng1997 
@Url     : https://www.luogu.com.cn/problem/P3354

***************************************************/
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
#ifdef LOCAL
  freopen("P1273_4.in", "r", stdin);
#endif

  cin.tie(nullptr)->sync_with_stdio(false);
  int n, p; cin >> n >> p;

  vector son(n, vector<int>());

  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
  }

  vector f(n + 1, vector<int>(n + 1, 2e5));
  vector<int> sz(n + 1);
  int ans = INT_MAX;
  function<void(int)> dfs = [&](int u) {
    f[u][1] = son[u].size() + (u != 0);
    for (auto& v : son[u]) {
      dfs(v);
      sz[u] += sz[v];
      auto tmp = f[u];
      for(int i = 2; i <= sz[u] + 1; i ++ ) {
        for(int j = 1; j < i && j <= sz[v]; j ++ ) {
          //f[i][j]表示在i的子树中选，并且加进来j个节点最少需要删多少条边 当前子树不和父节点相连 需要删 fa(u)->u
          chkmin(tmp[i], f[v][j] + f[u][i - j] - 2); //u->v 的边和 v->u 的边都没了，所以要 -2
        }
      }
      f[u] = tmp;
    }
    sz[u] ++;
  };

  dfs(0);
  for(int i = 0; i < n; i ++ ) {
    chkmin(ans, f[i][p]);
  }
  cout << ans << "\n";

  return 0;
}