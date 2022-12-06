#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1010;

int dp[N][N];

void solve() {
  int n; cin >> n;
  ll ans = 0;
  for(int i = 0; i < n; i ++ ) {
    int num; cin >> num;
    int x = num / 1000, y = num % 1000;
    x = 999 - x, y = 999 - y;
    array<int, 3> a, b;
    a[0] = x / 100, a[1] = x / 10 % 10, a[2] = x % 10;
    b[0] = y / 100, b[1] = y / 10 % 10, b[2] = y % 10;
    x = 999 - x, y = 999 - y;
    for(int j = 0; j <= a[0]; j ++ ) {
      for(int k = 0; k <= a[1]; k ++ ) {
        for(int l = 0; l <= a[2]; l ++ ) {
          ans += dp[j * 100 + k * 10 + l][y];
        }
      }
    }

    for(int j = 0; j <= b[0]; j ++ ) {
      for(int k = 0; k <= b[1]; k ++ ) {
        for(int l = 0; l <= b[2]; l ++ ) {
          dp[x][j * 100 + k * 10 + l] ++;
        }
      }
    }

  }

  cout << ans << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
