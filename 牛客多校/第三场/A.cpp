/***************************************************

@File    : A.cpp
@Time    : 2022/07/25 11:59:41
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> n >> k;
  vector<int> a(k);
  for(int &x: a) {
    cin >> x;
    -- x;
  }

  vector<int> w1(n);
  for(int &x: w1) cin >> x;

  vector<vector<int>> son1(n);

  for (int i = 1, fa; i < n; i++ ) {
    cin >> fa; -- fa;
    son1[fa].push_back(i);
  }

  vector<int> w2(n);
  for(int &x: w2) cin >> x;

  vector<vector<int>> son2(n);
  for (int i = 1, fa; i < n; i++ ) {
    cin >> fa; -- fa;
    son2[fa].push_back(i);
  }
  
  if(k == 2) {
    int ans = 0;
    if(w1[a[0]] > w2[a[0]]) ++ ans;
    if(w1[a[1]] > w2[a[1]]) ++ ans;
    cout << ans << "\n";
    return 0;
  }


  vector<int> dep1(n + 10), dep2(n + 10), lg1((n << 1) + 10), lg2((n << 1) + 10), dfn1((n << 1) + 10), dfn2((n << 1) + 10), que1((n << 1) + 10), que2((n << 1) + 10);
  int idx1 = 0, idx2 = 0;
  vector<vector<int> > fa1((n << 1) + 10, vector<int>(21));
  vector<vector<int> > fa2((n << 1) + 10, vector<int>(21));

  function<void(int)> dfs1 = [&] (int u) {
    dfn1[u] = ++ idx1, que1[idx1] = u;
    // dep1[u] = dep[fa] + 1;
    for(auto &v: son1[u])  {
      dep1[v] = dep1[u] + 1;
      dfs1(v);
      que1[++ idx1] = u;
    }
  };

  function<void(int)> dfs2 = [&] (int u) {
    dfn2[u] = ++ idx2, que2[idx2] = u;
    // dep1[u] = dep[fa] + 1;
    for(auto &v: son2[u]) {
      dep2[v] = dep2[u] + 1;
      dfs2(v);
      que2[++ idx2] = u;
    }
  };

  dfs1(0);
  
  dfs2(0);

  auto build1 = [&] () {
    for(int i = 1; i <= idx1; i ++ ) fa1[i][0] = que1[i];
    for(int i = 1; i <= idx2; i ++ ) fa2[i][0] = que2[i];
    for(int j = 1; j <= 20; j ++ ) {
      for(int i = 1; i + (1 << j) <= idx1; i ++ ) {
        int f1 = fa1[i][j - 1], f2 = fa1[i + (1 << j - 1)][j - 1];
        fa1[i][j] = dep1[f1] < dep1[f2] ? f1 : f2;
      }

      for(int i = 1; i + (1 << j) <= idx2; i ++ ) {
        int f1 = fa2[i][j - 1], f2 = fa2[i + (1 << j - 1)][j - 1];
        fa2[i][j] = dep2[f1] < dep2[f2] ? f1 : f2;
      }
    }
    lg1[0] = -1;
    lg2[0] = -1;
    for(int i = 1; i <= idx1; i ++ ) lg1[i] = lg1[i >> 1] + 1;
    for(int i = 1; i <= idx2; i ++ ) lg2[i] = lg2[i >> 1] + 1;
  };

  build1();

  auto lca1 = [&] (int u, int v) {
    if(dfn1[u] > dfn1[v]) swap(u, v);
    u = dfn1[u], v = dfn1[v];
    int kk = lg1[v - u + 1], f1 = fa1[u][kk], f2 = fa1[v - (1 << kk) + 1][kk];
    return dep1[f1] < dep1[f2] ? f1 : f2;
  };

  auto lca2 = [&] (int u, int v) {
    if(dfn2[u] > dfn2[v]) swap(u, v);
    u = dfn2[u], v = dfn2[v];
    int kk = lg2[v - u + 1], f1 = fa2[u][kk], f2 = fa2[v - (1 << kk) + 1][kk];
    return dep2[f1] < dep2[f2] ? f1 : f2;
  };

  struct node {
    int mx, cmx, mi, cmi;
  } p, q;
  p.mx = p.cmx  = q.mx = q.cmx = 0;
  p.mi = p.cmi = q.mi = q.cmi = 1E9;
  

  for(int i = 0; i < k; i ++ ) {
    int now1 = dfn1[a[i]]; int now2 = dfn2[a[i]];
    if(now1 > p.mx) {
      p.cmx = p.mx;
      p.mx = now1;
    } else {
      chkmax(p.cmx, now1);
    }
    if(now2 > q.mx) {
      q.cmx = q.mx;
      q.mx = now2;
    } else {
      chkmax(q.cmx, now2);
    }

    if(now1 < p.mi) {
      p.cmi = p.mi;
      p.mi = now1;
    } else {
      chkmin(p.cmi, now1);
    }
    if(now2 < q.mi) {
      q.cmi = q.mi;
      q.mi = now2;
    } else {
      chkmin(q.cmi, now2);
    }
  }


  int ans = 0;
  for(int i = 0; i < k; i ++ ) {
    int now = a[i];
    int mx1, mx2, mi1, mi2;
    if(dfn1[now] == p.mx) {
      //cmx
      mx1 = que1[p.cmx];
    } else {
      mx1 = que1[p.mx];
    }

    if(dfn2[now] == q.mx) {
      mx2 = que2[q.cmx];
    } else {
      mx2 = que2[q.mx];
    }
    
    if(dfn1[now] == p.mi) {
      //cmi
      mi1 = que1[p.cmi];
    } else {
      mi1 = que1[p.mi];
    }

    if(dfn2[now] == q.mi) {
      mi2 = que2[q.cmi];
    } else {
      mi2 = que2[q.mi];
    }

    int Lca1 = lca1(mx1, mi1);
    int Lca2 = lca2(mx2, mi2);

    if(w1[Lca1] > w2[Lca2]) {
      ++ ans;
    }
  }

  cout << ans << "\n";


  return 0;
}