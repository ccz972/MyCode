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



constexpr int N = 5010;
constexpr int M = 75;
constexpr int P = 150;

namespace Nanfeng1 {
  int n, a[N];
  int dp[N][M + 1][P + 1];

  void solve() {

    //dp[i][j][k]表示前　ｉ　个人，　ｗ　现在的值为　ｊ　，有　ｋ　个敌人没有打败的攻击力的最大值
    
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    memset(dp, -1, sizeof dp);

    dp[0][1][0] = 1;

    int ans = 0;

    for (int i = 0; i <= n; i ++ ) {
      for (int j = 1; j <= M; j ++ ) {
        for (int k = 0; k <= P; k ++ ) if (~dp[i][j][k]) {
          chkmax(ans, i - k);
          // debug(i, j, k, dp[i][j][k]);
          if (dp[i][j][k] >= a[i + 1]) {
            chkmax(dp[i + 1][j + 1][k], dp[i][j][k]);
          } else {
            chkmax(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
          }
          if (dp[i][j][k] + j >= a[i + 1]) {
            chkmax(dp[i + 1][j][k], dp[i][j][k] + j);
          } else {
            chkmax(dp[i + 1][j][k + 1], dp[i][j][k] + j);
          }
        }
      }
    }  
    cout << ans << "\n";
  }
}

namespace Nanfeng2 {
  int dp[2][P + 10][M + 10];
  int n, ans, a[N];

  void solve () {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i]; 
    memset(dp, -1, sizeof dp);
    dp[0][0][1] = 1;
    for (int i = 0; i <= n; i ++ ) {
      memset(dp[i + 1 & 1], -1, sizeof dp[i + 1 & 1]);
      for (int j = 0; j <= P; j ++ ) {
        for (int k = 1; k <= M ; k ++ ) if (dp[i & 1][j][k] != -1) {
          chkmax(ans, i - j);
          if (dp[i & 1][j][k] >= a[i + 1]) {
            chkmax(dp[i + 1 & 1][j][k + 1], dp[i & 1][j][k]);
          } else {
            chkmax(dp[i + 1 & 1][j + 1][k + 1], dp[i & 1][j][k]);
          }
          if (dp[i & 1][j][k] + k >= a[i + 1]) {
            chkmax(dp[i + 1 & 1][j][k], dp[i & 1][j][k] + k);
          } else {
            chkmax(dp[i + 1 & 1][j + 1][k], dp[i & 1][j][k] + k);
          }
        }
      }
    }

    // dp[0][0][1] = 1;
    // for (int i = 0; i <= n; i ++ ) {
    //   for (int j = 0; j <= 142; j ++ ) {
    //     for (int k = 1; k <= 73; k ++ ) if (~dp[i][j][k]) {
    //       chkmax(ans, i - j);
    //       if (dp[i][j][k] >= a[i + 1]) {
    //         chkmax(dp[i + 1][j][k + 1], dp[i][j][k]);
    //       } else {
    //         chkmax(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
    //       }
    //       if (dp[i][j][k] + k >= a[i + 1]) {
    //         chkmax(dp[i + 1][j][k], dp[i][j][k] + k);
    //       } else {
    //         chkmax(dp[i + 1][j + 1][k], dp[i][j][k] + k);
    //       }
    //     }
    //   }
    // }

    cout << ans;
  }
}




int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Nanfeng2::solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
