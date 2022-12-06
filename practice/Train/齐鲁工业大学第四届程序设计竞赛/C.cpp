#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, m; cin >> n >> m;
  int q; cin >> q;
  while (q -- ) {
    int x, y, k; cin >> x >> y >> k;
    if (!x && !y) {
      cout << "1 1 1\n";
    } else {
      int t = 0;
      if (!x) {
        t = (m - 1) / y;
      } else if (!y) {
        t = (n - 1) / x;
      } else {
        t = min((m - 1) / y, (n - 1) / x);
      }
      cout << k / (t + 1) + 1 << " " << 1 + (k % (t + 1)) * x << " " << 1 + (k % (t + 1)) * y << "\n";
    }
  }
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
