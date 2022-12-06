#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
clock_t start = clock();
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    if (!x) return 0;
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  T get(int l, int r) {
    return get(r) - get(l - 1);
  }

};

void merge(vector<pair<int, int> > &segs) {  //区间合并
  if (segs.empty()) return;
  vector<pair<int, int> > res;
  sort(segs.begin(), segs.end());
  int st = segs[0].first, ed = segs[0].second;
  for (auto seg : segs) {
    if (seg.first > ed) {
      res.emplace_back(st, ed);
      st = seg.first, ed = seg.second;
    } else
      ed = max(ed, seg.second);
  }
  res.emplace_back(st, ed);
  segs = res;
}

vector<pair<int, int> > intersection(vector<pair<int, int> > a, vector<pair<int, int> > b) {
  //求区间交
  vector<pair<int, int> > res;
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    int l = max(a[i].first, b[j].first);
    int r = min(a[i].second, b[j].second);
    if (l <= r) res.emplace_back(l, r);
    if (a[i].second < b[j].second)
      i++;
    else
      j++;
  }
  return res;
}

void solve() {
  int n, q;
  cin >> n >> q;

  vector<vector<int> > g(n + 1);

  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  // fenwick<int> fen[10];
  vector<fenwick<int>> fen(11, fenwick<int>(n + 10));

  vector<int> col(n + 1); for (int i = 1; i <= n; i ++ ) cin >> col[i];

  vector<int> fa(n + 1), depth(n + 1), sz(n + 1), son(n + 1), id(n + 1), top(n + 1), dfn(n + 1);
  int ts = 0;

  function<void(int, int)> dfs1 = [&](int u, int father) {
    fa[u] = father;
    depth[u] = depth[father] + 1;
    sz[u] = 1;
    for (auto &v : g[u])
      if (v != father) {
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) {
          son[u] = v;
        }
      }
  };

  dfs1(1, 0);

  function<void(int, int)> dfs2 = [&](int u, int tp) {
    id[u] = ++ts, top[u] = tp;
    dfn[id[u]] = u;
    if (!son[u]) return;
    dfs2(son[u], tp);
    for (auto &v : g[u]) {
      if (v == fa[u] || v == son[u]) continue;
      dfs2(v, v);
    }
  };

  dfs2(1, 1);

  auto query_path = [&](int u, int v, vector<pair<int, int> > &s) {  //查询 u->v 经过的所有链
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      s.emplace_back(id[top[u]], id[u]);
      u = fa[top[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    s.emplace_back(id[v], id[u]);
  };

  for (int i = 1; i <= n; i ++ ) {
    int color = col[i];
    fen[color].modify(id[i], 1);
  }
  // debug(id);
  while (q-- ) {
    int op;
    cin >> op;
    if (op & 1) {
      int x, y; cin >> x >> y;
      fen[col[x]].modify(id[x], -1);
      col[x] = y;
      fen[col[x]].modify(id[x], 1);
    } else {
      int m; cin >> m;
      vector<pair<int, int> > all;
      for (int i = 0; i < m; i ++ ) {
        int x; cin >> x;
        // query_path(dfn[id[x]], dfn[id[x] + sz[x] - 1], all);
        all.emplace_back(id[x], id[x] + sz[x] - 1);     
        // debug(id[x], id[x] + sz[x] - 1);  
      }
      merge(all);
      // debug(all);
      for (int i = 1; i <= 10; i ++ ) {
        int ans = 0;
        for (auto &[l, r]: all) {
          ans += fen[i].get(l, r);
        }
        cout << ans << " ";
      }
      cout << "\n";
    } 
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC *
  // 1000 << "ms" << endl;
#endif
  return 0;
}
