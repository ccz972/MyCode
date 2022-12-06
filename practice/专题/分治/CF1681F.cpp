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
  int size(int u) {
    return sz[find(u)];
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
  int n; cin >> n;
  vector<vector<pair<int, int> > > w(n);
  for (int i = 1; i < n; i ++ ) {int a, b, c; cin >> a >> b >> c; w[c - 1].emplace_back(a, b); }
  DSU_DEL d(n + 1);
  ll ans = 0;
  function<void(int, int)> dfs = [&] (int l, int r) {
    if (l == r) {
      ll res = 0;
      for (auto &[u, v]: w[l]) {
        ans += 1ll * d.size(u) * d.size(v);
        res += 1ll * d.size(u) * d.size(v);
      }
    } else {
      int mid = (l + r) / 2;
      int h = d.history();
      for (int i = l; i <= mid; i ++ ) {
        for (auto &[u, v]: w[i]) {
          d.merge(u, v);
          
        }
      }
      dfs(mid + 1, r);
      d.roll(h);
      for (int i = mid + 1; i <= r; i ++ ) {
        for (auto &[u, v]: w[i]) {
          d.merge(u, v);
        }
      }
      dfs(l, mid);
      d.roll(h);
    }
  };

  dfs(0, n - 1);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}