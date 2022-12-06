#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, m; cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n - 1; i ++ ) {
      if (i & 1) {
        m = (n & 1) ? n : n - 1;
        for (int j = 0; j < m; j ++ ) a[i][j] = 1;
      } else {
        m = (n & 1) ? n - 1 : n;
        for (int j = 0; j < m; j ++ ) a[i][j] = 1;
      }
    } 

    for (int i = 0; i < n - 1; i ++ ) {
      if (i & 1) {
        m = (n & 1) ? n : n - 1;
        for (int j = 0; j < m; j ++ ) a[j][i] = 1;
      } else {
        m = (n & 1) ? n - 1 : n;
        for (int j = 0; j < m; j ++ ) a[j][i] = 1;
      }
    } 

    int cnt = 0;
    for (int i = 0; i < n; i ++ ) if (a[n - 1][i]) {
      ++ cnt;
    }

    if ((n - 1 & 1) != (cnt & 1)) {
      a[n - 1][n - 1] = 1;
    }

    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < n; j ++ ) {
        cout << a[i][j];
      }
      cout << "\n";
    }
    

  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}