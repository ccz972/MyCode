#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
clock_t start = clock();
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

template <typename T>
struct Fenwick {
  int n;
  std::vector<T> a;
  Fenwick(int n) : n(n), a(n) {}
  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }
  T sum(int x) {
    T ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += a[i - 1];
    }
    return ans;
  }
  T rangeSum(int l, int r) { return sum(r) - sum(l); }
  int kth(T k) {
    int x = 0;
    for (int i = 1 << std::__lg(n); i; i /= 2) {
      if (x + i <= n && k >= a[x + i - 1]) {
        x += i;
        k -= a[x - 1];
      }
    }
    return x;
  }
};
void solve() {
  Fenwick<ll> fen(100);
  fen.add(0, 1);
  for (int i = 1; i <= 10; i ++ ) {
    cout << fen.sum(i) << "\n";
  }
  // fen.add(3, 2);
  // cout << fen.sum(99) << "\n";
  // cout << fen.kth(0) << "\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC *
  // 1000 << "ms" << endl;
#endif
  return 0;
}
