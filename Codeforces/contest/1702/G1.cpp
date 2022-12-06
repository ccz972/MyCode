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

// struct LCA { // index is the range of [1, n]
//   int n;
//   vector<vector<int> > g;
//   vector<int> top, parent, son, depth, sz;

  

//   LCA(int _n, vector<vector<int> >& _son) : n(n), g(_son), top(_n + 1), parent(_n + 1), son(_n + 1), depth(_n + 1), sz(_n + 1) {
//     dfs1(1, -1, 1);
//     dfs2(1, 1);
//   }
  
// };  // index is the range of [1, n]

// vector<int> top, parent, son, depth, sz;
vector<vector<int>> g;

struct LCA { // index is the range of [1, n]
  int n;
  // vector<vector<int> > g;
  vector<int> top, parent, son, depth, sz;

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

  LCA(int _n) : n(n), top(_n + 1), parent(_n + 1), son(_n + 1), depth(_n + 1), sz(_n + 1) {
    dfs1(1, -1, 1);
    dfs2(1, 1);
  }
  
};  // index is the range of [1, n]

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  // top.resize(n + 1), parent.resize(n + 1), son.resize(n + 1), depth.resize(n + 1), sz.resize(n + 1);
  g.resize(n + 1);
  for (int i = 1, u, v; i < n; i++ ) {
    cin >> u >> v; //u --, v --;
    g[u].push_back(v), g[v].push_back(u);
  }
  // dfs1(1, -1, 1);
  // dfs2(1, 1);
  LCA L(n);
  auto solve = [&] () {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x; //mp[x] ++;
    if(n == 1) {
      cout << "YES\n";
      return ;
    }
    int x = a[0], y = a[1];

    auto dis = [&] (int X, int Y) {
      return L.depth[X] + L.depth[Y] - 2 * L.depth[L.lca(X, Y)];
    };
    
    for(int i = 2; i < n; i ++ ) {
      int z = a[i];
      vector<int> l(3);
      l[0] = dis(x, y), l[1] = dis(y, z), l[2] = dis(x, z);
      auto r = l;
      sort(l.begin(), l.end());
      
      if(l[0] + l[1] != l[2]) {
        cout << "NO\n";
        return ;
      }

      if(r[1] == l.back()) {
        x = y;
        y = z;
      } else if(r[2] == l.back()) {
        y = z;
      }
    }

    cout << "YES\n";

  };

  int Q; cin >> Q;
  while(Q -- ) {
    solve();
  }

  

  return 0;
}
