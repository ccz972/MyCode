/***************************************************

@File    : P2986.cpp
@Time    : 2022/07/07 23:56:33
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

  int n; cin >> n;

  vector son(n, vector<pair<int, int> >());
  vector<ll> val(n);
  ll sum = 0;
  for(auto &x: val) cin >> x, sum += x;
  
  for(int i = 1; i < n; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    -- u, -- v;
    son[u].emplace_back(v, w);
    son[v].emplace_back(u, w);
  }

  vector<ll> f(n, 0), g(n, 0);
  vector<ll> sz(n); // dep(n);

  function<void(int, int)> dfs1 = [&](int u, int fa) {
    for (auto& [v, w] : son[u]) if(v != fa) {
      // val[v] += val[u];
      dfs1(v, u);
      val[u] += val[v];
      sz[u] += sz[v];
      f[u] += f[v] + val[v] * w;
    }
    sz[u] ++;
  };

  function<void(int, int)> dfs2 = [&](int u, int fa) {
    for (auto& [v, w] : son[u]) if(v != fa) {
      g[v] = g[u] - val[v] * w + (sum - val[v]) * w;     
      dfs2(v, u);
    }
  };

  dfs1(0, -1);
  g[0] = f[0];
  dfs2(0, -1);
  // for(auto x: g) cout << x << " ";
  // cout << "\n";
  ll ans = *min_element(g.begin(), g.end());
  cout << ans << "\n";
  
  
  return 0;
}