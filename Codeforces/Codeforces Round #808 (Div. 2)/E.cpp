/***************************************************

@File    : E.cpp
@Time    : 2022/07/26 17:29:52
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

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
};


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<vector<int> > son(n + 1);
  vector<pair<int, int> > a(m);
  vector<int> vis(m);

  for(int i = 0, u, v; i < m; i ++ ) {
    cin >> u >> v; //-- u, -- v;
    a[i] = make_pair(u, v);
  } 

  DSU d(n + 1);

  for(int i = 0; i < m; i ++ ) {
    auto [u, v] = a[i];
    int fu = d.leader(u), fv = d.leader(v);
    if(fu == fv) continue;
    d.merge(u, v);
    vis[i] = true;
    son[u].emplace_back(v); son[v].emplace_back(u);
  }

  vector<int> dep(n + 1);
  vector<vector<int> > fa(n + 1, vector<int>(20));

  function<void(int, int)> dfs = [&] (int u, int f) {
    fa[u][0] = f;
    for(int i = 1; i < 20; i ++ ) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for(auto& v: son[u]) if(v != f) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
      // debug(v, u);
    }
  };

  dep[1] = 1;

  
  dfs(1, 0);
  

  auto lca = [&] (int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int k = 19; k >= 0; k -- ) {
      if(dep[fa[a][k]] >= dep[b]) {
        a = fa[a][k];
      }
    }
    if(a == b) return a;
    
    for(int k = 19; k >= 0; k -- ) if(fa[a][k] != fa[b][k]) {
      a = fa[a][k]; b = fa[b][k];
    }
    return fa[a][0];
  };

  vector<int> s(n + 1);
  
  for(int i = 0; i < m; i ++ ) if(!vis[i]) {
    auto [u, v] = a[i];
    int p = lca(u, v);
    if(dep[u] > dep[v]) swap(u, v);
    //u is v's father
    if(p == u) {
      s[1] ++;
      s[v] ++;
      int q = v;
      for(int k = 19; k >= 0; k -- ) if(dep[fa[q][k]] > dep[u]) {
        q = fa[q][k];
      }
      s[q] --;
      
    } else {
      s[u] ++;
      s[v] ++;
    }
  }

  function<void(int, int)> dfs2 = [&] (int u, int fa) {
    // debug(u, s[u]);
    for(auto& v: son[u]) if(v != fa) {
      s[v] += s[u];
      // debug(u, v);
      dfs2(v, u);
      
    }
  };

  dfs2(1, 0);

  for(int i = 1; i <= n; i ++ ) if(s[i] == m - n + 1) {
    cout << "1";
  } else {
    // cout << s[i] << "\n";
    cout << "0";
  }

  



  return 0;
}