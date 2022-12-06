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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i = 0; i < n; i ++ ) {
      for(int j = 0; j < n; j ++ ) {
        char c; cin >> c;
        a[i][j] = c - 48;
        // cin >> a[i][j];
      }
    }
    ll ans = 0;
    for(int i = 0; i < n; i ++ ) {
      for(int j = 0; j < n; j ++ ) {
        int now = 0;
        int x = i, y = j;
        now += a[x][y];
        int tmp = y;
        y = n - 1 - x;
        x = tmp;
        now += a[x][y];
        tmp = y;
        y = n - 1 - x;
        x= tmp;
        now += a[x][y];
        tmp = y;
        y = n - 1 - x;
        x = tmp;
        now += a[x][y];
        tmp = y;
        y = n - 1 - x;
        x = tmp;
        //i, j  
        //j, n - 1 - i
        // now += a[i][n - j - 1];
        // now += a[n - i - 1][n - j - 1];
        // now += a[n - i - 1][j];
        ans += min(now, 4 - now);
        // cout << ">> " << now << " " << 4 - now << "\n";
      }
    }
    // cout << ans << "\n";
    cout << ans / 4 << "\n";
    // for(int t = 0; t < n; t ++ ) {
    //   int now = 0;
    //   if(t > n - t) break;
    //   for(int i = t; i < n - t; i ++ ) {
    //     for(int j = t; j < n - t; j ++ ) {
    //       now += a[i][j];
    //     }
    //   }
    //   //[t - n - t]
    //   int res = (n - t - t) * 4 - 4;
    //   ans += min(res - now, now);
    // }
    // cout << ans << "\n";
  }
  return 0;
}