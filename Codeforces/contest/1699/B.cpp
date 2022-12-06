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

constexpr int N = 100;
int a[N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  
  auto solve = [&] () {
    int n, m; cin >> n >> m;
    if(n == 2) {
      for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
          if(i == 1) {
            if(j % 4 == 0 || j % 4 == 1) {
              cout << "1 ";
            } else {
              cout << "0 ";
            }
          } else {
            if(j % 4 == 0 || j % 4 == 1) {
              cout << "0 ";
            } else {
              cout << "1 ";
            }
          }
        }
        cout << "\n";
      }
    } else if(m == 2) {
      for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
          if(j == 2) {
            if(i % 4 == 0 || i % 4 == 1) {
              cout << "1 ";
            } else {
              cout << "0 ";
            }
          } else {
            if(i % 4 == 0 || i % 4 == 1) {
              cout << "0 ";
            } else {
              cout << "1 ";
            }
          }
        }
        cout << "\n";
      }
    } else {
      for(int i = 1; i <= n; i ++ ) {
        if(i % 8 == 1 || i % 8 == 3 || i % 8 == 6 || i % 8 == 0) {
          a[1][i] = 1;
        } else {
          a[1][i] = 0; 
        }
        a[0][i] = a[1][i];
      }
      // a[0][1] = 1;
  
      for(int i = 2; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
          if(j == 1) {
            int cnt = (a[i - 1][j] != a[i - 1][j + 1]) + (a[i - 1][j] != a[i - 2][j]);
            if(cnt == 1) {
              a[i][j] = a[i - 1][j] ^ 1;
            } else {
              a[i][j] = a[i - 1][j];
            }
          } else if(j == m) {
            int cnt = (a[i - 1][j] != a[i - 1][j - 1]) + (a[i - 1][j] != a[i - 2][j]);
            if(cnt == 1) {
              a[i][j] = a[i - 1][j] ^ 1;
            } else {
              a[i][j] = a[i - 1][j];
            }
          } else {
            int cnt = (a[i - 1][j] != a[i - 1][j - 1]) + (a[i - 1][j] != a[i - 1][j + 1]) + (a[i - 1][j] != a[i - 2][j]);
            if(cnt == 1) {
              a[i][j] = a[i - 1][j] ^ 1;
            } else {
              a[i][j] = a[i - 1][j];
            }
          }
        }
      }
      for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
          cout << a[i][j] << " \n"[j == m];
        }
      }
    }
  };

  while (T--) {
    solve();
  }
  return 0;
}