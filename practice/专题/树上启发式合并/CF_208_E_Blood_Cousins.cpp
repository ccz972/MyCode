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

void solve() {
  int n; cin >> n;
  vector<int> father(n + 1);
  vector<vector<int> > son(n + 1);
  rep (i, 1, n) {
    int fa; cin >> fa;
    father[i] = fa; son[fa].eb(i);
  }

  vector<int> sz(n + 1), depth(n + 1), hson(n + 1);
  int px = __lg(n) + 2;
  vector<vector<int> > fa(n + 1, vector<int> (px, 0));

  function<void(int, int)> dfs1 = [&] (int u, int FA) {
    sz[u] = 1;
    if (u) {
      fa[u][0] = FA;
      Rep(i, 1, px) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
      }
    }
    for (int &v: son[u]) {
      depth[v] = depth[u] + 1;
      dfs1 (v, u);
      if (!hson[u] || sz[hson[u]] < sz[v]) {
        hson[u] = v;
      }
      sz[u] += sz[v];
    }
  };

  dfs1(0, -1);

  int m; cin >> m;

  vector<int> ans(m);
  vector<vector<PII > > query(n + 1);

  auto get = [&] (int v, int p) -> int {
    for (int i = px - 1; i >= 0; i -- ) if (depth[v] - depth[fa[v][i]] <= p) {
      p -= depth[v] - depth[fa[v][i]];
      v = fa[v][i];
    }
    return v;
  };

  Rep(i, 0, m) {
    int v, p; cin >> v >> p;
    if (depth[v] <= p) ans[i] = 0;
    else query[get(v, p)].eb(p, i);
  }

  vector<int> cnt(n * 2 + 10);

  function<void(int)> del = [&] (int u) -> void {
    cnt[depth[u]] = 0;
    for (int &v: son[u]) {
      del(v);
    }
  };


  function<void(int)> update = [&] (int u) -> void {
    cnt[depth[u]] ++;
  };


  function<void(int)> add = [&] (int u) -> void {
    update(u);
    for (int &v: son[u]) {
      add(v);
    }
  };

  

  function<void(int)> dfs2 = [&] (int u) -> void {
    for (int &v: son[u]) if (v != hson[u]) {
      dfs2(v);
      del(v);
    }

    if (hson[u]) dfs2(hson[u]);

    for (int &v: son[u]) if (v != hson[u]) {
      add(v);
    }

    update(u);
    for (auto [v, id] : query[u]) {
      ans[id] = cnt[depth[u] + v] - 1;
    }

  };

  dfs2(0);

  Rep(i, 0, m) cout << ans[i] << " ";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}