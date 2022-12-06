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

char s[4][4];

void solve() {
  for (int i = 0; i < 4; i ++ ) {
    cin >> s[i];
  }
  for (int i = 0; i < 3; i ++ ) {
    for (int j = 0; j < 3; j ++ ) {
      char c = s[i][j]; bool flag = true;
      if (s[i][j + 1] != c || s[i + 1][j] != c || s[i + 1][j + 1] != c) {
        flag = false;
      }
      if (flag) {
        return cout << "Yes\n", void();
      }
    }
  }

  cout << "No\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
