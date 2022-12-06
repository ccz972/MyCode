// https://www.luogu.com.cn/problem/CF891C
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

struct DSU_DEL {
  int n;
  vector<int> f, sz; 
  vector<pair<int&, int> > his_sz;
  vector<pair<int&, int> > his_fa;
  DSU_DEL(int _n) : n(_n), f(_n), sz(_n, 1) { iota(f.begin(), f.end(), 0); }

  int find(int x) {
    while (x != f[x]) x = f[x]; 
    return x;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu == fv) return ;
    if (sz[fu] < sz[fv]) swap(fu, fv);
    his_sz.push_back({sz[fu], sz[fu]});
    sz[fu] += sz[fv];
    his_fa.push_back({f[fv], f[fv]});
    f[fv] = fu;
  }

  int history() {
    return his_fa.size();
  }

  void roll(int h) {
    while (his_fa.size() > h) {
      his_fa.back().first = his_fa.back().second;
      his_fa.pop_back();
      his_sz.back().first = his_sz.back().second;
      his_sz.pop_back();
    }
  }
};


void solve() {
  int n, m; cin >> n >> m;
  struct node {int u, v, w; bool operator < (const node& T) const {return w < T.w; }};
  vector<node> a(m);
  Rep(i, 0, m) { cin >> a[i].u >> a[i].v >> a[i].w; }
  auto [U, V, W] = *max_element(all(a));
  vector<vector<int> > pos(W + 1);
  Rep(i, 0, m) { pos[a[i].w].emplace_back(i); }
  //f[i]
  int q; cin >> q;
  vector<int> ans(q, 1);
  // vector query(int);
  vector<vector<pair<int, int> > > query(W + 1);
  Rep(i, 0, q) {
    int k; cin >> k;
    while (k -- ) {
      int u; cin >> u; -- u;
      //存某个权值下，这个点的编号
      //第i个人，第j条边
      query[a[u].w].push_back(make_pair(i, u)); 
    }
  }
  rep(i, 0, W) if (!query[i].empty()) { sort(all(query[i])); }
  DSU_DEL d(n + 1);
  for (int i = 1; i <= W; i ++ ) {
    int p = SZ(query[i]);
    int h = d.history();
    for (int j = 0; j < p; j ++ ) {
      int k = j;
      while (k + 1 < p && query[i][k + 1].first == query[i][j].first) {
        ++ k;
      }
      for (int l = j; l <= k; l ++ ) {
        auto [u, v, w] = a[query[i][l].second];
        if (d.same(u, v)) {ans[query[i][l].first] = 0; break; }
        d.merge(u, v);
      }
      d.roll(h);
      j = k;
    }

    for (int x: pos[i]) d.merge(a[x].u, a[x].v);

  }
  for (int i = 0; i < q; i ++ ) {
    cout << (ans[i] ? "YES" : "NO") << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}