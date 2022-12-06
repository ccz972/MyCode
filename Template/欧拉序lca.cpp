  int root = 1; //改一下根节点
  vector<vector<int> > son(n + 1);
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  vector<int> depth(n + 1), sz(n + 1), parent(n + 1), dfn(n + 1), que((n << 1) + 10);
  int ts = 0;  

  function<void(int, int, int)> dfs1 = [&] (int u, int fa, int dep) {
    sz[u] = 1; depth[u] = dep; parent[u] = fa;
    dfn[u] = ++ ts;  que[ts] = u;
    for(auto &v: son[u]) if(v != fa) {
      dfs1(v, u, dep + 1);
      sz[u] += sz[v];
      que[++ ts] = u;
    }
  };
    
  dfs1(root, 0, 1);

  int m = __lg((n << 1) + 10) + 1;
  vector<vector<int> > f(m, vector<int>((n << 1) + 10));

  for(int i = 1; i <= ts; i ++ ) f[0][i] = que[i];
  for(int j = 1; j < m; j ++ ) {
    for(int i = 1; i + (1 << j) <= ts; i ++ ) {
      int f1 = f[j - 1][i], f2 = f[j - 1][i + (1 << (j - 1))];
      f[j][i] = depth[f1] < depth[f2] ? f1 : f2;
    }
  }

  auto lca = [&] (int u, int v) {
    if(dfn[u] > dfn[v]) swap(u, v);
    u = dfn[u], v = dfn[v];
    int k = __lg(v - u + 1);
    int f1 = f[k][u], f2 = f[k][v - (1 << k) + 1];
    return depth[f1] < depth[f2] ? f1 : f2;
  };