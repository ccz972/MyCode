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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n; cin >> n >> n;
    vector<int> a(20), b(20);
    // cout << n << "\n";
    for (int i = 0; i <= n; i ++ ) {
      int x; cin >> x;
      for (int j = 0; j <= 17; j ++ ) {
        a[j] += (x >> j & 1);
        b[j] += (i >> j & 1);
      }
    }
    // debug(a), debug(b);
    int ret = 0;
    for (int i = 0; i <= 17; i ++ ) if (a[i] != b[i]) {
      ret |= 1 << i;
    }
    cout << ret << "\n";




  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}