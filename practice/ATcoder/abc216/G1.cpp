#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
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
  vector<array<int, 3> > v(m);
  for (auto& [r, l, x]: v) {
    cin >> l >> r >> x;
  }
  sort(v.begin(), v.end());
  fenwick<int> fen(n + 1);
  set<int> s;
  for (int i = 1; i <= n; i ++ ) s.insert(i);
  vector<int> ans(n + 1);
  for (auto [r, l, x]: v) {
    while (fen.get(l, r) < x) {
      auto it = prev(s.upper_bound(r));
      ans[*it] = 1;
      fen.modify(*it, 1);
      s.erase(it);
    }
  }
  for (int i = 1; i <= n; i ++ ) {
    cout << ans[i] << " \n"[i == n];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}