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

struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
}; // 路径压缩

struct LCA { // index is the range of [1, n]
  int n;
  vector<vector<int> > g;
  vector<int> top, parent, son, depth, sz, s, point;

  void dfs1(int u, int fa, int d) {
    sz[u] = 1, parent[u] = fa, depth[u] = d;
    for(int &v: g[u]) if(v != fa) {
      dfs1(v, u, d + 1);
      sz[u] += sz[v];
      if(sz[son[u]] < sz[v]) son[u] = v;
    }
  }

  void dfs2(int u, int id) {
    top[u] = id;
    if(!son[u]) return ;
    dfs2(son[u], id);
    for(int &v: g[u]) {
      if(v == parent[u] || v == son[u]) {
        continue;
      }
      dfs2(v, v);
    }
  }

  void dfs3(int u, int fa) {
    for(int &v: g[u]) if(v != fa) {
      s[v] += s[u];
      dfs3(v, u);
    }
  }

  void dfs4(int u, int fa) {
    for(int &v: g[u]) if(v != fa) {
      point[v] += point[u];
      dfs4(v, u);
    }
  }

  int lca(int a, int b) {
    while(top[a] != top[b]) {
      if(depth[top[a]] > depth[top[b]]) {
        a = parent[top[a]];
      } else {
        b = parent[top[b]];
      }
    }
    if(depth[a] < depth[b]) {
      return a;
    } else {
      return b;
    }
  }

  LCA(int _n, vector<vector<int> >& _son) : n(n), g(_son), top(_n + 1), parent(_n + 1), son(_n + 1), depth(_n + 1), sz(_n + 1, 0), s(n + 1, 0), point(n + 1) {
    dfs1(1, 0, 1);
    dfs2(1, 1);
  }
  
};  // index is the range of [1, n]

void solve() {
  int n; cin >> n;
  vector<vector<int> > son(n + 1);
  DSU d(n + 1);
  vector<vector<int> > g(n + 1);
  vector<array<int, 2> > last;
  for (int i = 1; i <= n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
    if (!d.same(u, v)) {
      d.merge(u, v);
      g[u].push_back(v);
      g[v].push_back(u);
    } else {
      last.push_back({u, v});
    }
  }


  LCA lca1(n, g);
  
  
  // debug(last);
  vector<int> p(n + 1);

  for (auto &[u, v]: last) {
    if (lca1.depth[u] > lca1.depth[v]) swap(u, v);

    lca1.s[u] ++;
    p[v] ++;
  }

  for (int i = 1; i <= n; i ++ ) if (p[i]) {
    for (auto v: g[i]) {
      lca1.s[v] -= p[i];
    }
  }

  lca1.dfs3(1, 1); 
  
  for (int i = 1; i <= n; i ++ ) {
    if (lca1.s[i] - lca1.s[lca1.parent[i]] > 0) {
      lca1.point[i] = 1;
    }
  }


  
  int q; cin >> q;
  
  while (q -- ) {
    int u, v; cin >> u >> v;
    int p = lca1.lca(u, v);
    int ret1 = lca1.point[u] - lca1.point[p];
    int ret2 = lca1.point[v] - lca1.point[p];
    if (ret1 + ret2 >= 2) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }

}

void solve2() {
  int n; cin >> n;
  vector<vector<int> > son(n + 1);
  DSU d(n + 1);
  array<int, 2> last;
  for (int i = 1; i <= n; i ++ ) {
    int u, v; cin >> u >> v;
    if (!d.same(u, v)) {
      d.merge(u, v);
      son[u].push_back(v);
      son[v].push_back(u);
    } else {
      // last.push_back({u, v});
      last = {u, v};
    }
  }
  vector<int> parent(n + 1), depth(n + 1), sz(n + 1), top(n + 1), hson(n + 1);
  function<void(int, int, int)> dfs1 = [&] (int u, int fa, int d) {
    sz[u] = 1, parent[u] = fa, depth[u] = d;
    for(int &v: son[u]) if(v != fa) {
      dfs1(v, u, d + 1);
      sz[u] += sz[v];
      if(sz[hson[u]] < sz[v]) hson[u] = v;
    }
  };

  dfs1(1, 0, 1);


  function<void(int, int)> dfs3 = [&] (int u, int id) {
    top[u] = id;
    if (!hson[u]) return ;
    dfs3(hson[u], id);
    for (int &v: son[u]) {
      if (v == parent[u] || v == hson[u]) {
        continue;
      }
      dfs3(v, v);
    }
  };

  dfs3(1, 1);

  auto lca = [&] (int a, int b) {
    while(top[a] != top[b]) {
      if(depth[top[a]] > depth[top[b]]) {
        a = parent[top[a]];
      } else {
        b = parent[top[b]];
      }
    }
    if(depth[a] < depth[b]) {
      return a;
    } else {
      return b;
    }
  };

  vector<int> s(n + 1);

  auto got = [&] () {
    auto [u, v] = last;
    auto p = lca(u, v);

    while (u != p) {
      s[u] ++;
      u = parent[u];
    }

    while (v != p) {
      s[v] ++;
      v = parent[v];
    }

    s[p] ++;

  };

  got();

  function<void(int, int, int)> dfs2 = [&] (int u, int fa, int d) {
    for(int &v: son[u]) if(v != fa) {
      s[v] += s[u];
      dfs2(v, u, d + 1);
    }
  };

  dfs2(1, 0, 1);


  
  
  int q; cin >> q;
  
  while (q -- ) {
    int u, v; cin >> u >> v;
    int p = lca(u, v);
    int ret1 = s[u] - s[p];
    int ret2 = s[v] - s[p];
    
    if (ret1 + ret2 + (s[p] - s[parent[p]] > 0) >= 2) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve2();
  return 0;
}