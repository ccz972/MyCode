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

constexpr int N = 1E5 + 10;

int a[N], b[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    int ans = 0;

    auto get = [&] (int m) {
      int ret = 0; sort(b + 1, b + 1 + m);
      for (int i = 1, j = 1; i <= m; i ++ ) {
        while (j + 1 <= m && b[j + 1] == b[i]) {
          ++ j;
        }
        chkmax(ret, j - i + 1);
        i = j;
      }
      return ret;
    };
    // -200 <= d <= 200
    for (int i = -200; i <= 200; i ++ ) {
      for (int j = 1; j <= n; j ++ ) {
        b[j] = a[j] - i * j;
      }
      chkmax(ans, get(n));
    }
    //等差数列限定 [i, i + 499] 这一段，因此只需要考虑 (a_j - a_i) / (j - i) 即是公差
    for (int i = 1; i < n; i ++ ) {
      int m = 0, px = min(n, i + 499);
      for (int j = i + 1; j <= px; j ++ ) {
        if ( (a[j] - a[i]) % (j - i) == 0) {
          b[++ m] = (a[j] - a[i]) / (j - i);
        }
      }
      chkmax(ans, get(m) + 1);
    }

    cout << n - ans << "\n";

  };

  int T = 1; //cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}