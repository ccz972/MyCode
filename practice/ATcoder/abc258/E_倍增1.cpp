#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmaX(T &X, T y) { X = maX(X, y); }
template <typename T> void chkmin(T &X, T y) { X = min(X, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; ll X; cin >> n >> q >> X;
  vector<int> w(n * 2);
  for (int i = 0; i < n; i ++ ) {
    cin >> w[i]; w[i + n] = w[i];
  }
  vector<ll> s(n * 2 + 1);
  for (int i = 0; i < n * 2; i ++ ) {
    s[i + 1] = s[i] + w[i];
  }

  vector dp(64, vector<array<ll, 2> > (n + 1));

  for (int i = 0; i < n; i ++ ) {
    ll q = X / s[n], r = X % s[n];
    int idX = lower_bound(s.begin(), s.end(), r + s[i]) - s.begin();

    //[i + 1, idx] 闭区间

    dp[0][i + 1] = {idX % n + 1, q * n + idX - i};
  } 
  //dp[i][j] 表示 j 往右 (1 << i) 个箱子的终点 以及 多少个？
  for (int i = 1; i < 64; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      dp[i][j] = dp[i - 1][dp[i - 1][j][0]];
    }
  }

  while(q -- ) {
    ll x; cin >> x;
    -- x;
    ll now = 1;
    for (int i = 63; i >= 0; i -- ) if (x >> i & 1) {
      now = dp[i][now][0];
    }

    cout << dp[0][now][1] << "\n";
  }

  return 0; 
}