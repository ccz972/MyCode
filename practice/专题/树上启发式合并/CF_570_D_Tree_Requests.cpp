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

  /**
   * dsu on tree 暴力求解即可。
  */

  int n, m; cin >> n >> m;
  vector<int> father(n + 1);
  vector<vector<int>> son(n + 1);
  for (int i = 2; i <= n; i++ ) {
    cin >> father[i];
    son[father[i]].push_back(i); 
  }
  string s; cin >> s;
  s = " " + s;
  vector<array<int, 26> > cnt(n + 1);
  vector<vector<pair<int, int> > > Q(n + 1);
  vector<int> ans(m);
  Rep(i, 0, m) {
    int u, k; cin >> u >> k;
    Q[u].eb(k, i);
  }

  vector<int> depth(n + 1), sz(n + 1), hson(n + 1), dfn(n + 1);
  int cur = 0;
  function<void(int)> dfs1 = [&] (int u) {
    sz[u] = 1; dfn[u] = ++ cur;
    for (int &v: son[u]) {
      depth[v] = depth[u] + 1;
      dfs1(v);
      if (!hson[u] || sz[v] > sz[hson[u]]) hson[u] = v;
      sz[u] += sz[v];
    } 
  };
  
  dfs1(1);

  function<void(int)> del = [&] (int u) {
    cnt[depth[u]][s[u] - 'a'] -- ;
    for (int &v: son[u]) {
      del(v);
    }
  };

  auto update = [&] (int u) {
    cnt[depth[u]][s[u] - 'a'] ++;
  };

  function<void(int)> add = [&] (int u) {
    update(u);
    for (int &v: son[u]) {
      add(v);
    }
  };

  function<void(int)> dfs2 = [&] (int u) {
    for (int &v: son[u]) if (v != hson[u]) {
      dfs2(v);
      del(v);
    } 
    if (hson[u]) dfs2 (hson[u]);
    for (int &v: son[u]) if (v != hson[u]) {
      add(v);
    } 
    
    update(u);

    for (auto [k, i]: Q[u]) {
      int cntj = 0;
      Rep(j, 0, 26) {
        cntj += cnt[k - 1][j] & 1;
      }
      if (cntj > 1) ans[i] = false;
      else ans[i] = true;
    }
    //
  };
  
  dfs2(1);

  Rep(i, 0, m) cout << (ans[i] ? "Yes" : "No") << "\n";

  

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}