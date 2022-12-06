#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace Nanfeng {
  int n;
  vector<vector<int> > son;
  vector<int> top, parent, hson, depth, sz;

  void dfs1(int u, int fa, int d) {
    sz[u] = 1, parent[u] = fa, depth[u] = d;
    for(int &v: son[u]) if(v != fa) {
      dfs1(v, u, d + 1);
      sz[u] += sz[v];
      if(sz[hson[u]] < sz[v]) hson[u] = v;
    }
  }

  void dfs2(int u, int id) {
    top[u] = id;
    if(!hson[u]) return ;
    dfs2(hson[u], id);
    for(int &v: son[u]) {
      if(v == parent[u] || v == hson[u]) {
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

  void init() { 
    son.resize(n + 1); top.resize(n + 1), parent.resize(n + 1);
    hson.resize(n + 1), depth.resize(n + 1), sz.resize(n + 1);
  }
  
  // Nanfeng::n = n;
  // Nanfeng::init();
  // read edge
  // read root or root = 1
  // Nanfeng::dfs1(root, -1, 1);
  // Nanfeng::dfs2(root, root);

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, root; cin >> n >> m >> root;
  
  Nanfeng::n = n;
  Nanfeng::init();

  for (int  i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    Nanfeng::son[u].emplace_back(v);
    Nanfeng::son[v].emplace_back(u);
  }
  
  Nanfeng::dfs1(root, -1, 1);
  Nanfeng::dfs2(root, root);
  
  while (m -- ) {
    int u, v; cin >> u >> v;
    cout << Nanfeng::lca(u, v) << "\n";
  }


}