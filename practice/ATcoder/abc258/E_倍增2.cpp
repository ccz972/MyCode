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
  int n, q; ll x; cin >> n >> q >> x;
  ll tot = 0;
  vector<int> w(n);
  for (int i = 0; i < n; i ++ ) {
    cin >> w[i];
    tot += w[i];
  }

  vector dp(64, vector<ll> (n));

  ll tmp = x % tot, cnt = 0;

  //two points 初始化 倍增数组
  //dp[0][i] 表示 [i, dp[0][i] ]
  for (int i = 0; i < n; i ++ ) {
    while(tmp > 0) tmp -= w[(cnt ++ ) % n];
    dp[0][i] = cnt % n;
    tmp += w[i];
  }

  for (int i = 1; i < 64; i ++ ) {
    for (int j = 0; j < n; j ++ ) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }

  vector<ll> cycle(n);
  //two points 初始化 每个点最多可以跳到哪里 (对 tot 取模后，因此最多跳 n)
  tmp = x % tot;
  for (int i = 0, j = 0; i < n; i ++ ) {
    while(tmp > 0) tmp -= w[(j ++) % n];
    cycle[i] = j - i + x / tot * n;
    tmp += w[i];
  }
  
  while(q -- ) {
    ll k; cin >> k; k --;
    ll now = 0;
    for (int i = 63; i >= 0; i -- ) if (k >> i & 1) {
      now = dp[i][now];
    }
    cout << cycle[now] << "\n";
  }

  return 0; 
}