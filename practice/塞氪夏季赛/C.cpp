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

constexpr int N = 31;
constexpr int mid = 901;

// char g[N][N];
int s1[N][N];
int s2[N][N];
int f[N][N][N * N * 2];
int g[N][N][N * N * 2];

int n, m, c; 
//5    -5
//A - B = 5
//A - B = -5
//
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> c;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      char c; cin >> c;
      if(c == 'N') {
        s1[i][j] = 1;
        s2[i][j] = 1;
      } else if(c == 'T') {
        s1[i][j] = -1;
        s2[i][j] = 1;
      } 
    }
  } 

  for(int i = 1; i <= n; i ++)  {
    for(int j = 1; j <= n; j ++ ) {
      s1[i][j] += s1[i - 1][j] + s1[i][j - 1] - s1[i - 1][j - 1];
      s2[i][j] += s2[i - 1][j] + s2[i][j - 1] - s2[i - 1][j - 1];
    }
  }


  memset(f, -0x3f, sizeof f);
  memset(g, -0x3f, sizeof g);
  //[i1, j1], [i2, j2]   f[i2][j2][ ... ]
  for(int i1 = 1; i1 <= n; i1 ++  ) {
    for(int j1 = 1; j1 <= m; j1 ++ ) {
      for(int i2 = i1; i2 <= n; i2 ++ ) {
        for(int j2 = j1; j2 <= m; j2 ++ ) {
          int xx = s1[i2][j2] - s1[i1 - 1][j2] - s1[i2][j1 - 1] + s1[i1 -1][j1 - 1];
          int yy = s2[i2][j2] - s2[i1 - 1][j2] - s2[i2][j1 - 1] + s2[i1 -1][j1 - 1];
          chkmax(f[i2][j2][xx + mid], yy);
        }
      }
    }
  }


  for(int i2 = n; i2 >= 1; i2 --  ) {
    for(int j2 = m; j2 >= 1; j2 -- ) {
      for(int i1 = i2; i1 >= 1; i1 -- ) {
        for(int j1 = j2; j1 >= 1; j1 -- ) {
          int xx = s1[i2][j2] - s1[i1 - 1][j2] - s1[i2][j1 - 1] + s1[i1 -1][j1 - 1];
          int yy = s2[i2][j2] - s2[i1 - 1][j2] - s2[i2][j1 - 1] + s2[i1 -1][j1 - 1];
          chkmax(f[i1][j1][xx + mid], yy);
          //3  f[3 + mid]
        }
      }
    }
  }

  ll ans = 0;
  for(int i1 = 1; i1 <= n; i1 ++  ) {
    for(int j1 = 1; j1 <= m; j1 ++ ) {
      for(int i2 = i1; i2 <= n; i2 ++ ) {
        for(int j2 = j1; j2 <= m; j2 ++ ) {
          int xx = s1[i2][j2] - s1[i1 - 1][j2] - s1[i2][j1 - 1] + s1[i1 -1][j1 - 1];
          ll yy = s2[i2][j2] - s2[i1 - 1][j2] - s2[i2][j1 - 1] + s2[i1 -1][j1 - 1];
          if(xx > 0) {
            for(int k = max(0, xx - c + mid); k <= min(c - xx + mid, N * N * 2 - 1) ; k ++ ) {
              chkmax(ans, 1ll * yy + f[i1 - 1][m][k]);
              chkmax(ans, 1ll * yy + f[n][j1 - 1][k]);
              chkmax(ans, 1ll * yy + g[i2 + 1][1][k]);
              chkmax(ans, 1ll * yy + g[1][j2 + 1][k]);
            }
          } else if(xx < 0) {
            for(int k = max(0, -xx - c + mid); k <= min(c - xx + mid, N * N * 2 - 1) ; k ++ ) {
              chkmax(ans, 1ll * yy + f[i1 - 1][m][k]);
              chkmax(ans, 1ll * yy + f[n][j1 - 1][k]);
              chkmax(ans, 1ll * yy + g[i2 + 1][1][k]);
              chkmax(ans, 1ll * yy + g[1][j2 + 1][k]);
            }
          } else {
            for(int k = max(0, mid - c); k <= min(mid + c, N * N * 2 - 1) ; k ++ ) {
              chkmax(ans, 1ll * yy + f[i1 - 1][m][k]);
              chkmax(ans, 1ll * yy + f[n][j1 - 1][k]);
              chkmax(ans, 1ll * yy + g[i2 + 1][1][k]);
              chkmax(ans, 1ll * yy + g[1][j2 + 1][k]);
            }
          }
          
          //xx > c
          //p = -...

          // int now = c - xx + mid;
          // // now = min(now, N * N * 2 - 1);
          // if(now < N * N * 2) {
          //   chkmax(ans, 1ll * yy + f[i1 - 1][m][now]);
          //   chkmax(ans, 1ll * yy + f[n][j1 - 1][now]);
          //   chkmax(ans, 1ll * yy + g[i2 + 1][1][now]);
          //   chkmax(ans, 1ll * yy + g[1][j2 + 1][now]);
          // }

          // int now2 = -xx - c + mid;
          // // now2 = max(0, now2);
          // if(now2 >= 0) {
          //   chkmax(ans, 1ll * yy + f[i1 - 1][m][now]);
          //   chkmax(ans, 1ll * yy + f[n][j1 - 1][now]);
          //   chkmax(ans, 1ll * yy + g[i2 + 1][1][now]);
          //   chkmax(ans, 1ll * yy + g[1][j2 + 1][now]);
          // } 

          //c 没有映射
          //xx 没有映射
          //c - xx 映射了 ？


          //xx + p <= c
          //xx + p + mid <= c + mid
          //-(xx + p) <= c

          //p <= c - xx (+ mid)
          //p >= -xx - c 

          //p = c - xx
          //

          // [i1, j1] [i2, j2]
          //xx N 比 T 多了 xx 个

          //N 比 T 多 
          //还是 T 比 N 多

          // 

        }
      }
    }d
  }
  cout << ans << "\n";

  return 0;
}