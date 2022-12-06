#include <bits/stdc++.h>
using ll = long long;

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
}; // 路径压缩

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m; 
  std::cin >> n >> m;

  std::vector<std::array<int, 4> > a(m);
  
  ll cnt = 0;

  for (int i = 0; i < m; i ++ ) {
    for (int j = 0; j < 4; j ++ ) {
      std::cin >> a[i][j];
    }
    cnt += a[i][3];
  }

  if (cnt > n) {
    std::cout << "qcjjddw";
    return 0;
  }

  std::sort(a.begin(), a.end());

  std::vector<int> ans(n);
  DSU d(n + 10);

  std::set<int> vis;

  // for (auto [l, r, x, y] : a) {
  //   std::cout << l << " " << r << " " << x << " " << y << "\n";
  // }

  for (int i = 0; i < m; i ++ ) {
    auto [l, r, x, y] = a[i];
    vis.insert(x);
    // x 出现次数不少于 y 次
    -- l, -- r;
    for (int j = 0; j < y; j ++ ) {
      l = d.leader(l);
      d.merge(l + 1, l);
      ans[l ++ ] = x;
      if (l > r + 1) {
        std::cout << "qcjjddw";
        return 0;
      }
    }

  }

  int now = 1;
  while (vis.count(now)) {
    ++ now;
  }

  for (int i = 0; i < n; i ++ ) {
    std::cout << (ans[i] ? ans[i] : now) << " \n"[i == n - 1];
  }

  




  return 0;
}