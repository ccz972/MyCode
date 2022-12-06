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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i ++ ) if (s[i] != '0') {
      int j = i;
      while (j + 1 < n && s[j + 1] != '0') {
        ++ j;
      }
      chkmax(ans, j - i + 1);
      i = j;
    }

    for (int i = 0; i < n; i ++ ) if (s[i] != '1') {
      int j = i;
      while (j + 1 < n && s[j + 1] != '1') {
        ++ j;
      }
      chkmax(ans, j - i + 1);
      i = j;
    }

    cout << ans << "\n";

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