/***************************************************

@File    : CF708C_Centroids.cpp
@Time    : 2022/07/08 15:10:14
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
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n; cin >> n;
  vector son(n, vector<int>());

  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }


  
  /**
  考虑以重心为根的树，那么每个节点的子树的大小一定都是 <= n / 2 的

  如果某个点为重心,令fa[x] 是 x 的父节点， 
  f[x] 代表 n - sz[x] 部分的最大的不超过 n / 2 的子树大小

  Case1： n - sz[x] <= n / 2
  Case2： n - sz[x] - f[x] <= n / 2

  对于求 f[x] ，首先 n - sz[x] > n / 2，必然不可能断掉 (x, fa[x]) 这条边
  那么 f[x] 可以分为 包含 fa[x] 和 不包含 fa[x] 的部分
  令 d[x] 为 x 为 "根" 的子树中大小不超过 n / 2 的最大子树的大小, 集合 S 是 x 的兄弟节点的集合, 

  f[x] = 1. n - sz[x] (n - sz[x] <= n / 2)
         2. max(d[j], j \in S)
         3. f[fa[x]]

  第二部分 max(d[j], j \in S)  求的时候可以优化
  记 d[x][0] 为最大， d[x][1] 为次大, 因为d[x][0]可能为d[fa[x]]



  **/

  vector<int> sz(n), f(n);
  vector<array<int, 2> > d(n);

  int ans = INT_MAX;
  int root = -1;
  
  function<void(int, int)> dfs1 = [&](int u, int fa) {
    int mx = 0;
    sz[u] = 1;
    for (auto& v : son[u]) if(v != fa) {
      dfs1(v, u);
      sz[u] += sz[v];
      chkmax(mx, sz[v]);
    }
    chkmax(mx, n - sz[u]);
    if(mx < ans) {
      ans = mx;
      root = u;
    }
  };

  dfs1(0, -1);
  // cout << root << ">>>> \n";
  function<void(int, int)> dfs2 = [&](int u, int fa) {
    sz[u] = 1;
    for (auto& v : son[u]) if(v != fa) {
      dfs2(v, u);
      sz[u] += sz[v];
      if(sz[v] > d[u][0]) {
        d[u][1] = d[u][0];
        d[u][0] = sz[v];
      } else {
        chkmax(d[u][1], sz[v]);
      }
    }
  };

  dfs2(root, -1);

  function<void(int, int)> dfs3 = [&](int u, int fa) {
    
    if(~fa) {
      if(d[fa][0] == sz[u]) f[u] = max(f[fa], d[fa][1]);
      else f[u] = max(d[fa][0], f[fa]);
    }

    if(n - sz[u] <= n / 2) chkmax(f[u], n - sz[u]);

    if(u == root) f[u] = 0;

    for (auto& v : son[u]) if(v != fa) {
      dfs3(v, u);
    }
  };

  dfs3(root, -1);
  for(int i = 0; i < n; i ++ ) {
    if(n - sz[i] <= n / 2) {
      cout << "1 ";
    } else if(n - sz[i] - f[i] <= n / 2) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
  }

  return 0;
}