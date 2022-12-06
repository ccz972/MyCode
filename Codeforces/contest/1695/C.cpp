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

const int N = 1010, M = 2010;

bitset<M> f[N][N];
int a[N][N];
void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> a[i][j];
    }
  }  
  if((n + m) % 2 == 0) {
    cout << "NO\n";
    return ;
  }

  f[0][1][0] = 1;
  f[1][0][0] = 1;
  // cout << f[0][1] << "\n";
  // return;
  rep(i, 1, n) {  
    rep(j, 1, m) {
      if(a[i][j] == -1) {
        f[i][j] |= f[i - 1][j];
        f[i][j] |= f[i][j - 1];
      } else {
        f[i][j] |= f[i - 1][j] << 1;
        f[i][j] |= f[i][j - 1] << 1;
        // cout << f[i][j] << "\n";
        // return;
      }
    }
  }

  if(f[n][m][(n + m) / 2]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  rep(i, 0, n) {
    rep(j, 0, m) {
      f[i][j].reset();
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}