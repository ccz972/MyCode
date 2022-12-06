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

struct DSU {
  vector<int> f, siz, rank;
  int cnt; //统计还剩多少个连通块
  DSU(int n) : cnt(n), f(n), rank(n, 0), siz(n, 1) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return -1;
    else -- cnt;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; //按秩合并 and 路径压缩 
 

void solve() {
  int n; cin >> n;
  vector<pair<int, int> > a(n), b(n);
  vector<int> p{0, 1};
  Rep(i, 0, n) {
    cin >> a[i].first >> a[i].second;
    p.pb(a[i].first); p.pb(a[i].second);
  }

  sort(all(p));
  p.erase(unique(all(p)), p.end());
  
  Rep(i, 0, n) {
    b[i] = {lower_bound(all(p), a[i].first) - p.begin(), lower_bound(all(p), a[i].second) - p.begin()};
  }

  DSU d(SZ(p) + 1);

  for (auto [x, y]: b) {
    d.merge(x, y);
  }

  int ans = 1;

  Rep(i, 0, n) {
    auto [x, y] = b[i];
    if (d.same(x, 1)) chkmax(ans, a[i].first);
    if (d.same(y, 1)) chkmax(ans, a[i].second);
  }

  cout << ans << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}