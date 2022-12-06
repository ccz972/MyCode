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

  vector<int> sz(n + 1), depth(n + 1), hson(n + 1), dfn(n + 1);
  vector<vector<int> > p (n + 1);
  int cur = 0;
  
  function<void(int, int)> dfs1 = [&] (int u, int FA) {
    sz[u] = 1; dfn[u] = ++ cur; 
    if (u) p[depth[u]].emplace_back(dfn[u]);
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

  int m; cin >> m; // qwq

  vector<vector<array<int, 2> > > query(n + 1);
  Rep(i, 0, m) {
    int v, k; cin >> v >> k;  
    if (depth[v] > k) query[v].push_back({k, i});
  }

  vector<int> stk(n + 10); int tt = 0;

  vector<vector<PII > > Q(n + 1);

  function<void(int)> dfs2 = [&] (int u) {
    stk[++ tt] = u;
    for (auto [k, i]: query[u]) {
      int u = stk[tt - k];
      Q[u].eb(k, i);
    }
    for (int &v: son[u]) {
      dfs2 (v);
    }
    -- tt;
  };

  dfs2(0);

  vector<int> ans(m);

  rep(i, 1, n) {
    for (auto [k, id]: Q[i]) {
      int dep = depth[i] + k;
      int l = lower_bound(all(p[dep]), dfn[i]) - p[i].begin();
      int r = lower_bound(all(p[dep]), dfn[i] + sz[i]) - p[i].begin();
      ans[id] = r - l - 1;
    }
  }
  Rep(i, 0, m) cout << ans[i] << " ";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}