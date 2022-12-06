#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, q; cin >> n >> q;
    vector<vector<int> > g(n + 1);
    for(int i = 2, p; i <= n; i ++ ) {
      cin >> p; g[p].emplace_back(i);
    }
    vector<int> fa(n + 1), depth(n + 1), sz(n + 1), son(n + 1); 

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

    vector<int> id(n + 1), top(n + 1);
    int ts = 0;

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

    auto query_path = [&] (int u, int v, vector<pair<int, int> > &s) {
      while(top[u] != top[v]) {
        
        if(depth[top[u]] < depth[top[v]]) swap(u, v);
        s.emplace_back(id[top[u]], id[u]);
        u = fa[top[u]];
      }
      if(depth[u] < depth[v]) swap(u, v);
      s.emplace_back(id[v], id[u]);
    };

    auto merge = [&] (vector<pair<int, int> > &seg) {
      if(seg.empty()) return;
      vector<pair<int, int> > res;
      sort(seg.begin(), seg.end());
      int st = seg[0].first, ed = seg[0].second;
      for(auto& P: seg) {
        int x = P.first, y = P.second;
        if(x > ed) {
          res.emplace_back(st, ed);
          st = x, ed = y;
        } else {
          chkmax(ed, y);
        }
      }
      res.emplace_back(st, ed);
      seg = res;
    };
    

    auto intersection = [&] (vector<pair<int, int> > &a, vector<pair<int, int> > b) {
      vector<pair<int, int> > res;
      int i = 0, j = 0;
      while(i < a.size() && j < b.size()) {
        int l = max(a[i].first, b[j].first);
        int r = min(a[i].second, b[j].second);
        if(l <= r) {
          res.emplace_back(l, r);
        }
        if(a[i].second < b[j].second) ++ i;
        else ++ j;
      }
      a = res;
    };

    while(q -- ) {
      int x, y, z;  cin >> x >> y >> z;
      vector<pair<int, int> > a, b, c;
      while(x -- ) {
        int u; cin >> u;
        query_path(1, u, a);
      }
      while(y -- ) {
        int u; cin >> u;
        query_path(1, u, b);
      }
      while(z -- ) {
        int u; cin >> u;
        c.emplace_back(id[u], id[u] + sz[u] - 1);
      }
      merge(a); merge(b); merge(c);
      intersection(a, b);
      intersection(a, c);
      int ans = 0;
      for(auto& P: a) {
        int p = P.first, q = P.second;
        ans += q - p + 1;
      }
      cout << ans << "\n";
    }
  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}