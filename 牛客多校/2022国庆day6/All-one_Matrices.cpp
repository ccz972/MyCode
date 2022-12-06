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

constexpr int N = 3010;

int n, m, tt;
int a[N][N];
int up[N][N];
int s[N][N];
int stk[N];

void solve() {
  cin >> n >> m;
  rep (i, 1, n) {
    string S; cin >> S;
    rep (j, 1, m) {
      a[i][j] = (S[j - 1] - '0');
      s[i][j] = s[i - 1][j] + a[i][j];
    }
  }
  rep (j, 1, m) {
    rep (i, 1, n) {
      if (a[i][j] == 1) {
        up[i][j] = up[i - 1][j] + 1;
      } else {
        up[i][j] = 0;
      }
    }
  }

  rep(i, 1, n) {
    tt = 0, stk[tt] = 0;
    rep(j, 1, m) {
      while (tt && up[i][stk[tt]] > up[i][j]) {
        if (i == n || s[i + 1][])
        -- tt;
      }
      stk[++ tt] = up[i][j];
    }
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
