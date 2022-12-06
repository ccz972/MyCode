#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> col(n + 1);
  rep(i, 1, n) cin >> col[i];
  vector<vector<int>> son(n + 1);
  for (int i = 1; i < n; i++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v), son[v].push_back(u);
  }
  vector<int> ans(m);
  vector<vector<pair<int, int> > > Q(n + 1);
  Rep(i, 0, m) {
    int u, k; cin >> u >> k;
    Q[u].emplace_back(k, i);
  }

  // my_multiset Tree;
  //   Tree.insert(10);
  //   Tree.insert(50);
  //   Tree.insert(30);
  //   Tree.insert(10);
  //   Tree.insert(10);
  //   Tree.insert(50);
  //   Tree.insert(40);
  //   assert(Tree.size() == 7);
  //   assert(Tree.order_of_key(40) == 4);
  //   assert(*Tree.find_by_order(5) == 50);
  //   assert(*Tree.lower_bound(45) == 50);
  //   assert(*Tree.upper_bound(35) == 40);
  

  vector<int> sz(n + 1), depth(n + 1), hson(n + 1), dfn(n + 1);
  vector<vector<int> > p (n + 1);
  int cur = 0;
  
  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    sz[u] = 1; dfn[u] = ++ cur; 
    if (u) p[depth[u]].emplace_back(dfn[u]);
    for (int &v: son[u]) if (v != fa) {
      depth[v] = depth[u] + 1;
      dfs1 (v, u);
      if (!hson[u] || sz[hson[u]] < sz[v]) {
        hson[u] = v;
      }
      sz[u] += sz[v];
    }
  };

  depth[1] = 1;
  dfs1(1, 0);

  vector<int> cnt(100010);
  fenwick<int> fen(100010);

  function<void(int, int)> del = [&] (int u, int fa) {
    // cnt[col[u]] --;
    //cnt[col[u]] --> cnt[col[u]] - 1
    fen.modify(cnt[col[u]], -1);
    cnt[col[u]] --;
    if (cnt[col[u]]) fen.modify(cnt[col[u]], 1);
    for (int &v: son[u]) if (v != fa) {
      del(v, u);
    }
  };

  auto update = [&] (int u) {
    if (cnt[col[u]]) fen.modify(cnt[col[u]], -1);
    cnt[col[u]] ++;
    fen.modify(cnt[col[u]], 1);
  };

  function<void(int, int)> add = [&] (int u, int fa) {
    update(u);
    for (int &v: son[u]) if (v != fa) {
      add(v, u);
    }
  };


  function<void(int, int)> dfs2 = [&] (int u, int fa) {
    for (int &v: son[u]) if (v != hson[u] && v != fa) {
      dfs2 (v, u);
      del(v, u);
    }

    if (hson[u]) dfs2(hson[u], u);

    for (int &v: son[u]) if (v != hson[u] && v != fa) {
      add(v, u);
    }

    update(u);

    //答案
    for (auto [k, i]: Q[u]) {
      ans[i] = fen.get(k, 100001);
    }
    // ans[u] = maxid - depth[u];
    // debug(u, ans[u], maxid);
  };

  dfs2(1, 0);

  Rep(i, 0, m) cout << ans[i] << "\n";




  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}