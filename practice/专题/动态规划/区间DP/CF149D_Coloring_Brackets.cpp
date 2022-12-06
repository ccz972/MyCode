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

constexpr int N = 701;
constexpr int mod = 1e9 + 7;

ll dp[N][N][3][3];
int n, stk[N], pos[N];

void dfs(int l, int r) {
  if (l + 1 == r) { 
    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
  } else if(pos[l] == r) {
    dfs(l + 1, r - 1);
    for (int a = 0; a < 3; a ++ ) {
      for (int b = 0; b < 3; b ++ ) if( (!a && b) || (!b && a)) {
        for (int c = 0; c < 3; c ++ ) if(not (a && c && (a == c))) {
          for (int d = 0; d < 3; d ++ ) if(not (b && d && (b == d))) {
            dp[l][r][a][b] += dp[l + 1][r - 1][c][d];
            dp[l][r][a][b] %= mod;
          }
        }
      }
    }

  } else {
    int idx = pos[l];
    
    dfs(l, idx); dfs(idx + 1, r);
    for (int a = 0; a < 3; a ++ ) {
      for (int b = 0; b < 3; b ++ )  {
        for (int c = 0; c < 3; c ++ ) if(!(b && c && (b == c))) {
          for (int d = 0; d < 3; d ++ ) {
            ll &ret = dp[l][r][a][d];
            ret += (dp[l][idx][a][b] * dp[idx + 1][r][c][d]) % mod;
            ret %= mod;
          }
        }
      }
    }
  } 
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s; cin >> s;
  n = s.size();
  int tt = 0;
  for (int i = 0; i < n; i ++ ) {
    if(s[i] == '(') {
      stk[++ tt] = i + 1;
    } else {
      pos[i + 1] = stk[tt];
      pos[stk[tt]] = i + 1;
      -- tt;
    }
  } 
  dfs(1, n);
  //djalskdjkalsj
  // debug(dp[1][n][0][1] , dp[1][n][1][0] , dp[1][n][0][2], dp[1][n][2][0]);
  // debug(dp[2][3][0][1] , dp[2][3][1][0] , dp[2][3][0][2], dp[2][3][2][0]);
  // debug(dp[4][5][0][1] , dp[4][5][1][0] , dp[4][5][0][2], dp[4][5][2][0]);
  // debug(dp[2][5][0][1] , dp[2][5][1][0] , dp[2][5][0][2], dp[2][5][2][0]);
  // ll ans = dp[1][n][0][1] + dp[1][n][1][0] + dp[1][n][0][2] + dp[1][n][2][0];
  ll ans = 0;
  for(int i = 0; i < 3; i ++ ) {
    for(int j = 0; j < 3; j ++ ) {
      ans += dp[1][n][i][j];
      ans %= mod;
    }
  }
  cout << ans << "\n";
  return 0;
}