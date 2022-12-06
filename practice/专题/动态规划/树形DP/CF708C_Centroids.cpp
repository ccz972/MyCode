/***************************************************

@File    : CF708C_Centroids.cpp
@Time    : 2022/07/08 15:10:14
@Author  : Nanfeng1997 
@Url     : https://www.luogu.com.cn/problem/P3354

奇迹会发生在那些相信并为之拼尽全力的人身上 !
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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> son(n);
  for (int i = 1, u, v; i < n; i++ ) {
    cin >> u >> v; u --, v --;
    son[u].emplace_back(v), son[v].emplace_back(u);
  }

  vector<array<int, 2> > f(n), g(n);
  // vector<int> mx(n, 0);
  vector<int> sz(n);
  
  function<void(int, int)> dfs1 = [&](int u, int fa) {
    for (auto& v : son[u]) if(v != fa) {
      // chkmax(mx[u], dfs1(v, u) + 1);
      dfs1(v, u);
      sz[u] += sz[v];
      int now = min(sz[v], n / 2);
      if(now >= f[u][0]) {
        f[u][1] = f[u][0];
        f[u][0] = now;
      } else {
        chkmax(f[u][1], now);
      }
      // vector<int> x{f[v][0] + 1, f[v][1] + 1, f[u][1], f[u][0]};
      // sort(x.begin(), x.end());
      // f[u][0] = x[0];
      // f[u][1] = x[1];    
    }
    sz[u] ++;
    int now = min(sz[u], n / 2);
    if(now >= f[u][0]) {
      f[u][1] = f[u][0];
      f[u][0] = now;
    } else {
      chkmax(f[u][1], now);
    }
    // return mx[u];
  };

  dfs1(0, -1);

  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (auto& v : son[u]) if(v != fa) {
      if(f[v][0] + 1 == g[u][0]) {
        g[v][0] = g[u][1] + 2;
      } else {
        g[v][0] = g[u][0] + 2;
      }
      dfs2(v, u);
    }
  };

  dfs2(0, -1);

  for(int i = 0; i < n; i ++ ) {
    if(g[i][0] * 2 <= n) {
      cout << "1 ";
    } else {
      int mx = 0;
      for(auto v: son[i]) {
        if()
      }
    }
    // cout << (g[i][0] * 2 <= n) << "\n";
  } 

  return 0;
}