struct LCA { // index is the range of [1, n]
  int n;
  vector<vector<int> > g;
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

  LCA(int _n, vector<vector<int> >& _son) : n(n), g(_son), top(_n + 1), parent(_n + 1), son(_n + 1), depth(_n + 1), sz(_n + 1) {
    dfs1(1, -1, 1);
    dfs2(1, 1);
  }
  
};  // index is the range of [1, n]
