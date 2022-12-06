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
constexpr int N = 1E5 + 10;

vector<int> son[N];
int n, k; 
int col[N], ans[N], depth[N], sz[N], hson[N], cnt[N];

// set<int> s[N * 2];
set<int> s;
vector<int> have[N * 2];

void dfs1(int u, int fa) {
  sz[u] = 1;
  depth[u] = depth[fa] + 1;
  for (int &v : son[u]) if (v != fa) {
    dfs1(v, u);
    sz[u] += sz[v];
    if (!hson[u] || sz[v] > sz[hson[u]] ) {
      hson[u] = v;
    }
  }
}

void update(int u, int root) {
  if (depth[u] - depth[root] <= k) {
    s.insert(col[u]);
    have[depth[u]].emplace_back(col[u]);
    cnt[col[u]] ++;
  }
}

void add(int u, int fa, int root) {
  update(u, root);
  for (int &v: son[u]) if (v != fa) {
    add(v, u, root);
  }
}

void del(int u, int fa) {
  
  have[depth[u]].clear();

  if (s.count(col[u])) {
    cnt[col[u]] = 0;
    s.erase(s.find(col[u]));
  }
  for (int &v: son[u]) if (v != fa) {
    del(v, u);
  }
}

void dfs2(int u, int fa) {
  for (int &v: son[u]) if (v != fa && v != hson[u]) {
    dfs2(v, u);
    del(v, u);
  }

  if (hson[u]) dfs2(hson[u], u);

  for (int &v: son[u]) if (v != fa && v != hson[u]) {
    add(v, u, u);
  }

  update(u, u);
  //depth[u] 
  for (int x: have[depth[u] + k + 1]) {
    cnt[x] --;
    if (cnt[x] == 0) s.erase(s.find(x));
  }

  ans[u] = SZ(s);

}

void solve() {
  cin >> n >> k;
  rep(i, 1, n) cin >> col[i];
  Rep(i, 1, n) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  int q; cin >> q;
  while (q -- ) {
    int x; cin >> x;
    cout << ans[x] << "\n";
  }


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}