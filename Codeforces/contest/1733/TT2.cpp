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

constexpr int N = 5110;
constexpr ll INF = 1E18;
ll f[2][N][4][2];

void solve() {
  int n; ll x, y; cin >> n >> x >> y;
  string s, t; cin >> s >> t;
  s = " " + s, t = " " + t;
  int COUNT = 0; for (int i = 1; i <= n; i ++ ) COUNT += (s[i] != t[i]);
  if (COUNT & 1) return cout << "-1\n", void();
  for (int i = 0; i < 2; i ++ ) {
    for (int j = 0; j <= n; j ++ ) {
      for (int k = 0; k < 4; k ++ ) {
        for (int l = 0; l < 2; l ++ ) {
          f[i][j][k][l] = INF;
        }
      }
    }
  }
  f[0][0][0][0] = 0;
  //f[i][j][k][l] 前i个满足，有j个下一个能用，k个下一个不能用.l个必须用
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 0; j <= i; j ++ ) {
      for (int k = 0; k <= 3; k ++ ) {
        for (int l = 0; l < 2; l ++ ) {
          //使用上次必须用的
          if (s[i] != t[i]) {
            if (l) {
              chkmin(f[i & 1][j + k][0][0], f[i - 1 & 1][j][k][l]);
              //整两次下次不能用的
              chkmin(f[i & 1][j + k][2][0], f[i - 1 & 1][j][k][l] + y * 2);
            } else {
              //整一个下一次必须用的
              chkmin(f[i & 1][j + k][0][1], f[i - 1 & 1][j][k][l] + x);
              //整一个下一次必须用的  整两个下次不能用的
              chkmin(f[i & 1][j + k][2][1], f[i - 1 & 1][j][k][l] + x + y * 2);
              //整一个下次不能用的
              chkmin(f[i & 1][j + k][1][0], f[i - 1 & 1][j][k][l] + y);
              //整三个下次不能用的
              chkmin(f[i & 1][j + k][3][0], f[i - 1 & 1][j][k][l] + y * 3);
              //使用可以用的
              if (j) {
                chkmin(f[i & 1][j - 1 + k][0][0], f[i - 1 & 1][j][k][l]);
              }
            }
          } else {
            if (l) {
              //如果有上次必须用的，那么用掉再来一个下一次必须用的
              chkmin(f[i & 1][j + k][0][1], f[i - 1 & 1][j][k][l] + x);
              //如果有上次必须用的，那么用掉再来一个下一次不能用的
              chkmin(f[i & 1][j + k][1][0], f[i - 1 & 1][j][k][l] + y);
              //如果有上次必须用的，那么用掉再来三个下一次不能用的
              chkmin(f[i & 1][j + k][3][0], f[i - 1 & 1][j][k][l] + y * 3);
            } else {
              //用掉一次可以用的，再来一个下次必须用的
              if (j) {
                chkmin(f[i & 1][j - 1 + k][0][1], f[i - 1 & 1][j][k][l] + x);
              }
              //一个都不用
              chkmin(f[i & 1][j + k][0][l], f[i - 1 & 1][j][k][l]);
              // //用两次下次不能用的
              chkmin(f[i & 1][j + k][2][l], f[i - 1 & 1][j][k][l] + y * 2);
            }
          }
        }
      }
    }
    for (int j = 0; j <= i; j ++ ) {
      for (int k = 0; k < 4; k ++ ) {
        for (int l = 0; l < 2; l ++ ) {
          f[i - 1 & 1][j][k][l] = INF;
        }
      }
    }
  }
  ll ans = INF;
  for (int i = 0; i <= n; i += 2) {
    chkmin(ans, f[n & 1][i][0][0]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}

