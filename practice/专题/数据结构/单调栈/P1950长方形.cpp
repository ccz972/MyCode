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

int n, m; 
int tt, stk[N];
int a[N][N], h[N][N], l[N][N], r[N][N];
// char s[N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) {
    string s; cin >> s; s = " " + s;
    for(int j = 1; j <= m; j ++ ) if(s[j] == '.') {
      a[i][j] = 1;
    }
  }

  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      if(a[i][j]) {
        h[i][j] = h[i - 1][j] + 1;
      } else {
        h[i][j] = 0;
      }
    }
  }

  for(int i = 1; i <= n; i ++ ) {
    tt = 0; stk[tt] = 0;
    for(int j = 1; j <= m; j ++ ) {
      while(tt && h[i][stk[tt]] > h[i][j]) {
        -- tt;
      }
      l[i][j] = stk[tt];
      stk[++ tt] = j;
    }
    tt = 0; stk[tt] = m + 1;
    for(int j = m; j >= 1; j -- ) {
      while(tt && h[i][stk[tt]] >= h[i][j]) {
        -- tt;
      }
      r[i][j] = stk[tt];
      stk[++ tt] = j;
    }
  }


  ll ans = 0;

  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      ans += 1ll * (j - l[i][j]) * (r[i][j] - j) * h[i][j];
    }
  }

  cout << ans << "\n";
  


  return 0;
}