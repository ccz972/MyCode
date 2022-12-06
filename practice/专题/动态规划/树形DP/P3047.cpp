/***************************************************

@File    : P3047.cpp
@Time    : 2022/07/08 14:41:49
@Author  : Nanfeng1997 
@Url     : https://www.luogu.com.cn/problem/P3047

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
  int n, k; cin >> n >> k;
  
  vector son(n, vector<int>());
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  vector<int> w(n);
  for(int &x: w) cin >> x;

  vector f(n, vector<int>(k + 1));
  vector g(n, vector<int>(k + 1));

  function<void(int, int)> dfs1 = [&](int u, int fa) {
    f[u][0] = w[u];
    for (auto& v : son[u]) if(v != fa) {
      dfs1(v, u);
      for(int i = 0; i < k; i ++ ) if(f[v][i]) {
        f[u][i + 1] += f[v][i];
      }
    }
  };

  dfs1(0, -1);



  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (auto& v : son[u]) if(v != fa) {
      g[v] = f[v];
      for(int i = 0; i < k; i ++ ) {
        g[v][i + 1] += g[u][i];
        if(i) g[v][i + 1] -= f[v][i - 1];
      }
      dfs2(v, u);
      
    }
  };

  g[0] = f[0];

  dfs2(0, -1);
  for(int i = 0; i < n; i ++ ) {
    ll sum = 0;
    for(int j = 0; j <= k; j ++ ) {
      sum += g[i][j];
    }
    cout << sum << "\n";
  }
  // for(int i = 0; i < n; i ++ ) {
  //   cout << i + 1 << ">: ";
  //   for(int j = 0; j <= k; j ++ ) {
  //     cout << g[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  return 0;
}