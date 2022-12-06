#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay3 array<int, 3>
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
  int n; cin >> n;
  vector<int> a(n + 1), last(n + 1);
  vector<int> idx(1000010);
  rep (i, 1, n) { cin >> a[i]; last[i] = idx[a[i]]; idx[a[i]] = i; }
  
  int m; cin >> m;
  vector<ay3> query(m);
  vector<int> ans(m);
  Rep(i, 0, m) {
    int l, r; cin >> l >> r;
    query[i] = {r, l, i};
  }
  sort(all(query)); //按右端点排序
  int R = 0;
  fenwick<int> fen(n + 1);
  for (auto [r, l, id] : query) {
    while (R < r) {
      ++ R;
      if (last[R]) fen.modify(last[R], -1);
      fen.modify(R, 1);
    }
    ans[id] = fen.get(l, r);
  }

  Rep(i, 0, m) cout << ans[i] << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}