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

constexpr int N = 1010;

int w[N], t[N];
int f[N][N];

int main() {
#ifdef LOCAL
  freopen("out.txt", "w", stdout);  
#else 
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) {
    cin >> w[i] >> t[i];
  }
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  for(int i = 1; i <= n; i ++ ) {
    for(int j = N - 1; j >= w[i]; j -- ) {
      for(int k = N - 1; k >= t[i]; k -- ) {
        chkmin(f[j][k], f[j - w[i]][k - t[i]] + 1);
      }
    }

    
    for(int k = 0; k < N; k ++ ) {
      for(int j = 1; j < N; j ++ ) {
        chkmin(f[j][k], f[j - 1][k]);
      }
    }

    for(int j = 0; j < N; j ++ ) {
      for(int k = N - 2; k >= 0; k -- ) {
        chkmin(f[j][k], f[j][k + 1]);
      }
    }

    for(int k = 0; k < N; k ++ ) {
      for(int j = 1; j < N; j ++ ) {
        chkmin(f[j][k], f[j - 1][k]);
      }
    }

    for(int j = 0; j < N; j ++ ) {
      for(int k = N - 2; k >= 0; k -- ) {
        chkmin(f[j][k], f[j][k + 1]);
      }
    }

    // for(int j = w[i]; j < N; j ++ ) {
    //   for(int k = t[i]; k < N; k ++ ) {
    //     chkmin(f[j][k], f[j - 1][k]);
    //     // chkmin(f[j][k], f[j][k - 1]);
    //     chkmin(f[j][k], f[j - w[i]][k - t[i]] + 1);
    //   }
    // }
    // for(int j = 1; j < N; j ++ ) {
    //   for(int k = 0; k < N; k ++ ) {
    //     chkmin(f[j][k], f[j - 1][k]);
    //   }
    // }
    // for(int j = 0; j < N; j ++ ) {
    //   for(int k = N - 2; k >= 0; k -- ) {
    //     chkmin(f[j][k], f[j][k + 1]);
    //   }
    // }
    // for(int j = 1; j < N; j ++ ) {
    //   for(int k = 0; k < N; k ++ ) {
    //     chkmin(f[j][k], f[j - 1][k]);
    //   }
    // }
    // for(int j = 0; j < N; j ++ ) {
    //   for(int k = N - 2; k >= 0; k -- ) {
    //     chkmin(f[j][k], f[j][k + 1]);
    //   }
    // }
  }

  
  // for(int i = 0; i < N; i ++ ) {
  //   for(int j = 0; j < N; j ++ ) {
  //     // if(f[i][j] == 2) {
  //     //   cout << i << " " << j << "\n";
  //     //   exit(0);
  //     // }
  //     cout << f[i][j] << " \n"[j == 30];
  //   }
  // }

  // for(int i = 10; i <= 30; i ++ ) {
  //   cout << f[10][i] << " \n"[i == 30];
  // }

  while(m -- ) {
    int x, y; cin >> x >> y;
    // x 钱， y重量
    //f[i][j]表示使用i元钱，并且运了j个水果，用的最少车辆
    if(f[x][y] <= N) {
      cout << f[x][y] << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}