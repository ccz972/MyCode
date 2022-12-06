#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 101;

#ifndef ONLINE_JUDGE
  #include <debugger>
#endif

inline void chkmax(ll &a, ll b) {
  a = a > b ? a : b;
}

ll f[N][N][N], g[N][N][N];
ll a[N], b[N], c[N];

void solve() {
  
  int n; cin >> n;

  for(int i = n; i >= 1; i -- ) {
    cin >> a[i] >> b[i] >> c[i];
  }

  memset(f, -0x3f, sizeof f);
  memset(g, 0, sizeof f);
  
  f[1][0][0] = a[1];
  g[1][0][0] = n;

  for(int i = 2; i <= n; i ++ ) {
    //i - 1
    for(int j = 0; j <= i - 1; j ++ ) {
      for(int k = 0; k + j <= i - 1; k ++ ) {
        //选1操作 // A + a_i
        if(f[i][j][k] < f[i - 1][j][k] + a[i]) {
          f[i][j][k] = f[i - 1][j][k] + a[i]; 
          g[i][j][k] = g[i - 1][j][k] + n - i + 1; 
        } else if(f[i][j][k] == f[i - 1][j][k] + a[i]) {
          chkmax(g[i][j][k], g[i - 1][j][k] + n - i + 1);
        }

        //这次选2操作

        //
        ll attack = i - (j + 1) - k;
        ll &ret = f[i][j + 1][k], cnt = g[i - 1][j][k];
        //  b[i] <- i
        // ret   
        if(ret < f[i - 1][j][k] + cnt * b[i] - attack * (n - i + 1) * b[i]) {
          ret = f[i - 1][j][k] + cnt * b[i] - attack * (n - i + 1) * b[i];
          g[i][j + 1][k] = cnt;
        } else if(ret == f[i - 1][j][k] + cnt * b[i] - attack * (n - i + 1) * b[i]) {
          chkmax(g[i][j + 1][k], cnt);
        } 


        //这次选3操作
        if(f[i][j][k + 1] < f[i - 1][j][k] + attack * c[i]) {
          f[i][j][k + 1] = f[i - 1][j][k] + attack * c[i];
          g[i][j][k + 1] = g[i - 1][j][k];
        } else if(f[i][j][k + 1] == f[i - 1][j][k] + attack * c[i]) {   
          chkmax(g[i][j][k + 1], g[i - 1][j][k]);
        }
        //
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; i + j < n; j ++ ) {
      chkmax(ans, f[n][i][j]); 
    }
  }


  memset(f, -0x3f, sizeof f);
  memset(g, 0, sizeof f);
  
  f[1][0][0] = a[1];
  g[1][0][0] = n;

  for(int i = 2; i <= n; i ++ ) {
    //i - 1
    for(int j = 0; j <= i - 1; j ++ ) {
      for(int k = 0; k + j <= i - 1; k ++ ) {
        //选1操作 // A + a_i

        if(g[i][j][k] < g[i - 1][j][k] + n - i + 1) {
          g[i][j][k] = g[i - 1][j][k] + n - i + 1; 
          f[i][j][k] = f[i - 1][j][k] + a[i]; 
        } else if(g[i][j][k] == g[i - 1][j][k] + n - i + 1) {
          chkmax(f[i][j][k], f[i - 1][j][k] + a[i]);
        } 

        //这次选2操作

        //
        ll attack = i - (j + 1) - k;
        ll &ret = f[i][j + 1][k], cnt = g[i - 1][j][k];
        //  b[i] <- i
        // ret   


        if(g[i][j + 1][k] < cnt) {
          ret = f[i - 1][j][k] + cnt * b[i] - attack * (n - i + 1) * b[i];
          g[i][j + 1][k] = cnt;
          // if(i == 3 && j + 1 == 1 && k == 0) {
          //   debug(f[i][j + 1][k], g[i][j + 1][k]);
          // }
        } else if(g[i][j + 1][k] == cnt) {
          chkmax(ret, f[i - 1][j][k] + cnt * b[i] - attack * (n - i + 1) * b[i]);
        } 

        //这次选3操作
        if(g[i][j][k + 1] < g[i - 1][j][k] ) {
          f[i][j][k + 1] = f[i - 1][j][k] + attack * c[i];
          g[i][j][k + 1] = g[i - 1][j][k];
        } else if(g[i][j][k + 1] == g[i - 1][j][k] ) {   
          chkmax(f[i][j][k + 1], f[i - 1][j][k] + attack * c[i]);
        }
        //
      }
    }
  }
  // cout << ">>>> " <<  f[2][0][0] << " " << g[2][0][0] << "\n";
  // cout << ">>>> " <<  f[3][1][0] << " " << g[3][1][0] << "\n";
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; i + j < n; j ++ ) {
      chkmax(ans, f[n][i][j]); 
    }
  }


  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  // cin >> T;
  while(T -- )
    solve();
  return 0;
}