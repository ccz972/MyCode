/***************************************************

@File    : P3478_STA-Station.cpp
@Time    : 2022/07/07 23:40:43
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
#ifdef LOCAL
  freopen("P3478.in", "r", stdin);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  // 7
  int n; cin >> n;

  vector son(n, vector<int>());

  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  vector<ll> f(n, 0), g(n, 0);
  vector<int> sz(n);

  function<void(int, int)> dfs1 = [&](int u, int fa) {
    for (auto& v : son[u]) if(v != fa) {
      dfs1(v, u);
      sz[u] += sz[v];
      f[u] += f[v] + sz[v];
      // f[u] += f[v] + 1; 错误代码也能过？
    }
    sz[u] ++;
  };

  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (auto& v : son[u]) if(v != fa) {
      g[v] = g[u] + n - sz[v] - sz[v];     
      dfs2(v, u);
    }
  };

  dfs1(0, -1);
  g[0] = f[0];
  dfs2(0, -1); 
  ll ans = *max_element(g.begin(), g.end());
  for(int i = 0; i < n; i ++ ) if(g[i] == ans) {
    cout << i + 1 << "\n";
    return 0;
  }  
  
  return 0;
}