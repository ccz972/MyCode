/***************************************************

@File    : III.cpp
@Time    : 2022/07/16 13:50:41
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/
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

constexpr int N = 101;
constexpr ll INF = 1E18;

ll f[2][N][N * N];

ll a[N], b[N], c[N];
ll sum[N];

void solve() {
  int n; cin >> n;

  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i] >> b[i] >> c[i];
  }
  sum[n] = n;
  for(int i = n - 1; i >= 1; i -- ) {
    sum[i] = sum[i + 1] + i;
  }
  // for(int i = n; i >= 1; i -- ) {
  //   cin >> a[i] >> b[i] >> c[i];
  // }

  for(int i = 0; i <= 1; i ++ ) {
    for(int j = 0; j <= n; j ++ ) {
      for(int k = 0; k <= n * n; k ++ ) {
        f[i][j][k] = -INF;
      }
    }
  }

  f[n & 1][1][n] = a[n];

  for(int i = n - 1; i >= 1; i -- ) {
    int cnt = n - i + 1; //总操作次数

    for(int j = 1; j <= cnt; j ++ ) {
      for(int k = 0; k <= sum[i]; k ++ ) {
        f[i & 1][j][k] = -INF;
      }
    }

    for(int j = 1; j <= cnt; j ++ ) {
      for(int k = 0; k <= sum[i]; k ++ ) {
        //case1
        if(k >= i) 
        chkmax(f[i & 1][j][k], f[i + 1 & 1][j - 1][k - i] + a[i]); 
        // if(i == n - 2 && j == 2 && k == 7) {
        //   debug(f[i & 1][j][k]);
        // }
        //case2
        chkmax(f[i & 1][j][k], f[i + 1 & 1][j][k] + 1ll * k * b[i] - 1ll * i * j * b[i]);
        // case3
        chkmax(f[i & 1][j][k], f[i + 1 & 1][j][k] + 1ll * j * c[i]);
      }
    }

  }

  ll ans = 0;
  // cout << f[1][2][7] << "\n";
  for(int j = 1; j <= n; j ++ ) {
    for(int k = n; k <= sum[1]; k ++ ) {
      chkmax(ans, f[1][j][k]);
    }
  }



  cout << ans << "\n";


  
} 

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}