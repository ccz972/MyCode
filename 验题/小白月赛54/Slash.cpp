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

constexpr int N = 110, M = N * 2;

int n, m;
char s[N];
char g[N][N];
int f[N][N][M];


void solve() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  // printf("%d\n", len);
  for(int i = 1; i <= n; i ++ ) {
    scanf("%s", g[i] + 1);
  }
  //
  int ans = 0;
  for(int i = 0; i <= n; i ++ ) {
    for(int j = 0; j <= m; j ++ ) {
      f[i][j][0] = 1;
    }
  }
  for(int i = 1; i <= n; i ++ ) {
    for(int j = 1; j <= m; j ++ ) {
      for(int k = 0; k <= i + j - 2; k ++ ) {
        if(f[i - 1][j][k] && g[i][j] == s[((k + 1) % len == 0 ? len : (k + 1) % len)]) {
          f[i][j][k + 1] = true;
          // debug(i, j, k + 1);
          chkmax(ans, k + 1);
        } 
        if(f[i][j - 1][k] && g[i][j] == s[((k + 1) % len == 0 ? len : (k + 1) % len)]) {
          f[i][j][k + 1] = true;
          chkmax(ans, k + 1);
          // debug(i, j, k + 1);
        } 
      }
      for(int k = 0; k <= i + j - 2; k ++ ) {
        if(f[i - 1][j][k] || f[i][j - 1][k]) {
          f[i][j][k / len * len] = true;
        }
      }
      for(int k = 0; k <= i + j - 2; k ++ ) if(f[i][j][k]) {
        chkmax(ans, k);
      }
    }
  }
  // printf("%d\n", ans);
  printf("%d\n", ans / len);
  // cout << ans / len ;

}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}