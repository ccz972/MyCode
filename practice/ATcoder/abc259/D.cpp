#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
};

struct point {
  int x, y;
} s, t;

struct circle {
  int x, y;
  int r;
};




int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  cin >> s.x >> s.y >> t.x >> t.y;

  vector<circle> a(n);
  for(int i = 0; i < n; i ++  ) {
    cin >> a[i].x >> a[i].y >> a[i].r;
  }

  DSU d(n + 1);
  for(int i = 0; i < n; i ++ ) {
    auto [X1, Y1, R1] = a[i];
    for(int j = 0; j < n; j ++ ) {
      auto [X2, Y2, R2] = a[j];
      ll r1 = 1ll * (X1 - X2) * (X1 - X2) + 1ll * (Y1 - Y2) * (Y1 - Y2);
      ll r2 = 1ll * (R1 + R2) * (R1 + R2);
      if(r1 <= r2 && r1 >= 1ll * (max(R1, R2) - min(R1, R2)) * (max(R1, R2) - min(R1, R2))) d.merge(i, j);
    }
  }

  for(int i = 0; i < n; i ++ ) {
    auto [X1, Y1, R1] = a[i];
    ll r1 = 1ll * (s.x - X1) * (s.x - X1) + 1ll * (s.y - Y1) * (s.y - Y1);
    if(r1 != 1ll * R1 * R1) continue;
    for(int j = 0; j < n; j ++ ) {
      auto [X2, Y2, R2] = a[j];
      ll r2 = 1ll * (t.x - X2) * (t.x - X2) + 1ll * (t.y - Y2) * (t.y - Y2);
      if(r2 != 1ll * R2 * R2) continue;
      if(d.same(i, j)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }

  cout << "No\n";

  

  

  return 0;
}