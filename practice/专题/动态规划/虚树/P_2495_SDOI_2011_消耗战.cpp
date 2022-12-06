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

void solve() {
  int n; cin >> n;
  vector<vector<pair<int, int> > > son(n + 1);

  for(int i = 1; i < n; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    son[u].emplace_back(v, w); son[v].emplace_back(u, w);
  }

  int root = 1, cur = 0;
  vector<int> parent(n + 1), depth(n + 1), hson(n + 1, -1), sz(n + 1), dfn(n + 1, -1);

  function<void(int, int, int)> dfs1 = [&] (int u, int fa, int dep) {
    depth[u] = dep, sz[u] = 1, parent[u] = fa;
    for(auto& [v, w] : son[u]) if(v != fa) {
      dfs1(v, u, dep + 1);
      sz[u] += sz[v];
      if(hson[u] == -1 || sz[u] > sz[hson[u]]) hson[u] = v;
    }
  };

  function<void(int, int)> dfs2 = [&] (int u, int t) {
    dfn[u] = ++ cur;
    if(hson[u] == -1) return;
    dfs2(hson[u], t);
    for(auto& [v, w] : son[u]) {
      if(v == parent[u] || v == hson[u]) continue;
      dfs2(v, v);
    }
  };

  int m = __lg(n) + 1;

  vector<vector<int> > dp1(n + 1, vector<int>(m, 0));
  vector<vector<int> > dp2(n + 1, vector<int>(m, 1E7));

  function<void(int, int)> dfs3 = [&](int u, int fa) {
    for (auto& [v, w] : son[u]) if(v != fa) {
      dp1[v][0] = u; dp2[v][0] = w;
      
      for(int i = 1; i < m; i ++ ) {
        dp1[v][i] = dp1[dp1[v][i - 1]][i - 1];
        dp2[v][i] = min(dp2[v][i - 1], dp2[dp1[v][i - 1]][i - 1]);
      }
      
      dfs3(v, u);
    }
  };

  
  dfs1(root, -1, 1); dfs2(root, root); dfs3(root, 0);
  
  
  function<int(int, int)> lca = [&] (int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    for(int k = m - 1; k >= 0; k -- ) if(depth[dp1[a][k]] >= depth[b]) {
      a = dp1[a][k];
    }
    if(a == b) return a;

    for(int k = m - 1; k >= 0; k -- ) if(dp1[a][k] != dp1[b][k]) {
      a = dp1[a][k];
      b = dp1[b][k];
    }
    return dp1[a][0];
  };

  

  function<int(int, int)> get = [&] (int x, int y) {
    if(depth[x] == depth[y]) return 0;
    if(depth[x] < depth[y]) swap(x, y);
    int ret = 1E8;
    for(int i = m - 1; i >= 0; i -- ) if(depth[dp1[x][i]] >= depth[y]) {
      chkmin(ret, dp2[x][i]);
      x = dp1[x][i];
    }
    return ret;
  };

  vector<vector<pair<int, int> > > g(n + 1);

  int q; cin >> q;
  vector<int> vis(n + 1);
  vector<ll> dp(n + 1);

  while(q -- ) {
    
    int k; cin >> k;
    vector<int> a(k); for(int &x: a) cin >> x, vis[x] = 1;

    sort(a.begin(), a.end(), [&](int x, int y) {
      return dfn[x] < dfn[y];
    });

    vector<int> use;
    vector<int> stk{1};
    auto add = [&] (int x, int y, int z) {g[x].emplace_back(y, z); g[y].emplace_back(x, z); };
    for(int i = 0; i < k; i ++ ) {
      if(a[i] != 0) {
        int p = lca(a[i], stk.back());
        if(p != stk.back()) {
          while(dfn[p] < dfn[stk[(int)stk.size() - 2]]) {
            add(stk.back(), stk[(int)stk.size() - 2], get(stk.back(), stk[(int)stk.size() - 2]));
            stk.pop_back();
          }
          add(p, stk.back(), get(p, stk.back())); stk.pop_back();
          if(dfn[p] > dfn[stk.back()]) stk.emplace_back(p);
        }
        stk.emplace_back(a[i]);
      }
    }

    while(stk.size() > 1) {
      if(stk.back() != 1) {
        add(stk.back(), stk[(int)stk.size() - 2], get(stk.back(), stk[(int)stk.size() - 2]));
        stk.pop_back();
      }
    }

    function<void(int, int)> dfs = [&] (int u, int fa) {
      use.emplace_back(u);
      for(auto& [v, w] : g[u]) if(v != fa) {
        dfs(v, u);
        if(vis[v]) {
          dp[u] += w;
        } else {
          dp[u] += min((ll)w, dp[v]);
        }
      }
    };

    dfs(1, -1);    

    cout << dp[1] << "\n";
    
    for(int &x: use) g[x].clear(), dp[x] = 0;
    for(int &x: a) vis[x] = 0;
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}