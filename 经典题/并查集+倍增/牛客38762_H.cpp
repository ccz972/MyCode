#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

// constexpr int mod = 998244353;
// constexpr int mod = 1000000007;

class UnionFind {
 public:
  int n;
  vector<int> f;
  UnionFind(const int &n) : n(n), f(n) { iota(f.begin(), f.end(), 0); }
  inline int get(int x) { return x == f[x] ? x : f[x] = get(f[x]); }
  inline bool unite(int x, int y) {
    int gx = get(x), gy = get(y);
    if (gx != gy) {
      f[gx] = gy;
      return 1;
    }
    return 0;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  n <<= 1;
  vector<UnionFind> f(__lg(n) + 1, UnionFind(n + 1));
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    int l1 = l, r1 = r, l2 = n - r1 + 1, r2 = n - l1 + 1;
    for (int k = __lg(n); k >= 0; k--) {
      if (l1 + (1 << k) - 1 <= r1) {
        f[k].unite(l1, l2);
        l1 += 1 << k;
        l2 += 1 << k;
      }
    }
  }
  for (int k = __lg(n); k > 0; k--) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      int pos = f[k].get(i);
      f[k - 1].unite(i, pos);
      f[k - 1].unite(i + (1 << k - 1), pos + (1 << k - 1));
    }
  }
  n /= 2;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (f[0].get(i) == f[0].get(n - i + 1) || f[0].get(i) == f[0].get(n + i)) {
      ans++;
    }
  }
  if (ans == n) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout << setprecision(6);
  int tt = 1;
  // cin >> tt;
  for (int _ = 1; _ <= tt; _++) {
    solve();
  }
  return 0;
}