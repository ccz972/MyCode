#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 8010;

ll f[N][N];
int n, a[N];
int mx[N][N];
ll mi[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  for(int i = 1; i <= n; i ++ ) {
    mx[i][i] = a[i];
    for(int j = i + 1; j <= n; j ++ ) {
      mx[i][j] = a[j];
      chkmax(mx[i][j], mx[i][j - 1]);
    }
  }

  // for(int i = 1; i <)
  memset(f, 0x3f, sizeof f);
  for(int i = 1; i <= n; i ++ ) {
    f[i][1] = mx[1][i];
  }
  
  for(int i = 1; i <= n; i ++ ) {

  }

  //  ___
  for(int j = 1; j <= n; j ++ ) { //j 组
    for(int k = j; k <= n; k ++ ) {
      // f[k][j] ->     
      // i > k |  f[i][j] = min(f[i][j], f[k][j] + mx[k, i] );  

      //   mx[i][k] // k - i
    }
  }

  for(int j = 2; j <= n; j ++ ) {
    for(int i = j; i <= n; i ++ ) {
      // for(int k = j - 1; k < i; k ++ ) {
      //   chkmin(f[i][j], f[k][j - 1] + mx[k + 1][i]);
      // }
      f[i][j] = min({....});
    }  

    // f[ [j-1, i-1] ][j - 1] + mx[ [j-1,i-1] ] [i]

    // f[ k ][j - 1] + mx[ k ] [i]
    //mi[k] = f[k][j - 1] + mx[k] [i]
  }

  for(int i = 1; i <= n; i ++ ) {
    cout << f[n][i] << "\n";
  }


  // for(int j = )
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}