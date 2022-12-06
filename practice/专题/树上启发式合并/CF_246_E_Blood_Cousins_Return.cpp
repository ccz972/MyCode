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
  vector<int> name(n + 1), father(n + 1);
  map<string, int> mp; int now = 0;
  vector<vector<int> > son(n + 1);
  for (int i = 1; i <= n; i ++ ) {
    string s; cin >> s;  int fa; cin >> fa;
    if (!mp.count(s)) mp[s] = ++ now;
    name[i] = mp[s]; father[i] = fa;
    son[fa].eb(i);
  }
  
  int m; cin >> m;
  vector<vector<pair<int, int> > > query(n + 1);
  vector<int> ans(m + 1);

  rep(i, 1, m) {
    int id, k; cin >> id >> k;
    query[id].emplace_back(k, i);
  }


  vector<int> sz(n + 1), depth(n + 1), hson(n + 1);

  function<void(int)> dfs1 = [&] (int u) -> void {
    sz[u] = 1;
    for (int &v: son[u]) {
      depth[v] = depth[u] + 1; 
      dfs1 (v);
      if (!hson[u] || sz[v] > sz[hson[u]]) {
        hson[u] = v;
      }
      sz[u] += sz[v];
    }
  };

  set<int> s[(n * 2) + 5];
  
  function<void(int)> del = [&] (int u) -> void {
    s[depth[u]].clear();
    for (int &v : son[u]) {
      del(v);
    }
  };
  
  function<void(int)> update = [&] (int u) -> void {
    s[depth[u]].insert(name[u]);
  };

  function<void(int)> add = [&] (int u) -> void {
    update(u);
    for (int &v: son[u]) {
      add(v);
    }
  };

  

  function<void(int)> dfs2 = [&] (int u) -> void {
    for (int &v: son[u]) {
      if (v != hson[u]) {
        dfs2(v);
        del(v);
      }
    }

    if (hson[u]) dfs2 (hson[u]);

    for (int &v: son[u]) {
      if (v != hson[u]) add(v);
    }

    update(u);
    
    for (auto [k, i]: query[u]) {
      assert(depth[u] + k <= 2 * n);
      ans[i] = s[depth[u] + k].size();
    }
  };

  dfs1(0);
  dfs2(0);

  rep (i, 1, m) cout << ans[i] << "\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}