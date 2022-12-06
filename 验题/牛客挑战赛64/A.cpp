#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

struct DSU {
  vector<int> f, siz, rank;
  int cnt; //统计还剩多少个连通块
  DSU(int n) : cnt(n), f(n), rank(n, 0), siz(n, 1) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return -1;
    else -- cnt;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; //按秩合并 and 路径压缩 
 

void solve() {
  int n; cin >> n;
  DSU d(n + 1);
  vector<vector<int> > son(n + 1);
  int m1, m2; cin >> m1 >> m2;
  vector<int> ans(n + 1, 0x3f3f3f3f);
  for (int i = 1; i <= m1; i ++ ) {
    int u, v; cin >> u >> v;
    if (d.same(1, u) || d.same(1, v)) {
      d.merge(u, v);
      for (int &x: son[u]) d.merge(1, x);
      for (int &x: son[v]) d.merge(1, x);
      son[u].clear(); son[v].clear();
    } else {
      son[u].emplace_back(v);
      son[v].emplace_back(u);
    }
  }
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i ++ ) if (d.same(1, i)) {
    ans[i] = 0;
    vis[i] = true;
  }
  // for (int i = 1; i <= n; i ++ ) {
  //   cout << ans[i] << " \n"[i == n];
  // }
  auto bfs = [&] (int x, int res) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (q.size()) {
      auto t = q.front(); q.pop();
      for (int &x: son[t]) {
        if (!vis[x]) {
          d.merge(1, x);
          chkmin(ans[x], res);
          q.push(x);
          vis[x] = true;
        }
      }
      son[t].clear();
    }
  };

  for (int i = 1; i <= m2; i ++ ) {
    int u, v; cin >> u >> v;

    if (d.same(1, u) || d.same(1, v)) {
      d.merge(u, v);
      chkmin(ans[u], i);
      chkmin(ans[v], i);
      if (!vis[v]) {
        bfs(v, i);
      } 

      if (!vis[u]) {
        bfs(u, i);
      }

    } else {
      son[u].emplace_back(v);
      son[v].emplace_back(u);
    }

  }
  for (int i = 1; i <= n; i ++ ) {
    if (ans[i] == 0x3f3f3f3f) ans[i] = -1;
    cout << ans[i] << "\n";
  }

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
