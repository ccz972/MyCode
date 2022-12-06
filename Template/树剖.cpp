
  
vector<vector<int> > g(n + 1);
for(int i = 1, u, v; i < n; i ++ ) {
  cin >> u >> v;
  g[u].emplace_back(v); g[v].emplace_back(u);
}

vector<int> fa(n + 1), depth(n + 1), sz(n + 1), son(n + 1), id(n + 1), top(n + 1); 
int ts = 0;

function<void(int, int)> dfs1 = [&] (int u, int father) {
  fa[u] = father;
  depth[u] = depth[father] + 1;
  sz[u] = 1;
  for(auto& v: g[u]) if(v != father) {
    dfs1(v, u);
    sz[u] += sz[v];
    if(sz[son[u]] < sz[v]) {
      son[u] = v;
    }
  } 
};

dfs1(1, 0);

function<void(int, int)> dfs2 = [&] (int u, int tp) {
  id[u] = ++ ts, top[u] = tp;
  if(!son[u]) return ;
  dfs2(son[u], tp);
  for(auto& v: g[u]) {
    if(v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
};    

dfs2(1, 1);

auto query_path = [&] (int u, int v, vector<pair<int, int> > &s) { //查询 u->v 经过的所有链
  while(top[u] != top[v]) {
    if(depth[top[u]] < depth[top[v]]) swap(u, v);
    s.emplace_back(id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if(depth[u] < depth[v]) swap(u, v);
  s.emplace_back(id[v], id[u]);
};

