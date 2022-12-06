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
    vector<vector<pair<int, int> > > son(n);
    for (int i = 1, u, v, w; i < n; i++ ) {
      cin >> u >> v >> w; u --, v --;
      son[u].push_back(make_pair(v, w)), son[v].push_back(make_pair(u, w));
    }
    
    vector<int> a(n);
    for(int i = 1; i <= m; i ++ ) {
      int x; cin >> x; -- x;
      a[x] ++;
    }

    vector<int> sz(n), up(n);
    vector<array<int, 2> > dis(n);
    vector<ll> f(n), g(n);

    function<void(int, int)> dfs1 = [&](int u, int fa) {
      sz[u] = a[u];
      for (auto& [v, w] : son[u]) if(v != fa) {
        dfs1(v, u);
        
        sz[u] += sz[v];
        if(!sz[v]) continue;
        f[u] += f[v] + 2 * w;
        if(dis[u][0] < dis[v][0] + w) {
          dis[u][1] = dis[u][0], dis[u][0] = dis[v][0] + w;
        } else {
          chkmax(dis[u][1], dis[v][0] + w);
        }
      }
    };

    dfs1(0, -1);

    function<void(int, int)> dfs2 = [&](int u, int fa) {
      for (auto& [v, w] : son[u]) if(v != fa) {
        if(m - sz[v]) {
          g[v] = g[u] + (f[u] - f[v]);
          // if(!sz[v]) {
          g[v] = g[u] + (f[u] - f[v]);
          if(!sz[v]) g[v] += w * 2;
          if(dis[v][0] + w == dis[u][0]) {
            up[v] = max(up[u], dis[u][1]) + w;
          } else {
            up[v] = max(up[u], dis[u][0]) + w;
          } 
        }
        dfs2(v, u);
      }
    };

    dfs2(0, -1);

    for(int i = 0; i < n; i ++ ) {
      cout << f[i] + g[i] - max(dis[i][0], up[i]) << "\n";
    }


    /******************
      f[u] 把 u 子树内的任务做完，并且回到 u 的花费
      g[u] 表示子树外的 并且回到 u 的 花费

      dis[u][0 / 1] 表示 u 子树内的 最长 / 次长 链
      up[u] 表示 u 子树外的最长链

      ans[u] = f[u] + g[u] - max(dis[u][0], up[u])

      g[v] = g[u] + (f[u] - f[v])
      如果 v 中无关键点，那么 g[v] 需要加上 2 * w(u->v)


      up[v] 分为两种情况： 一种是其父节点 u 的最长链上的点，以及不为最长链上的点
      
    ******************/
     
    
    


  return 0;
}