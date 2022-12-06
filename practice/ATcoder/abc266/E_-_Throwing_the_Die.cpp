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

double dp[110];

void solve() {
  int n; cin >> n;
  dp[1] = 3.5;
  double ans = 0;
  // dp[i] 表示剩余 i 次机会的期望值 dp[0] = 0;
  // i >= 1 , 已知 dp[i - 1], 求 dp[i] 
  // 对于 dp[i] 来说 
  // 如果最后一次的期望值 大于 dp[i - 1] ， 则此时收手
  // 如果最后一次的期望值 小于 dp[i - 1] ， 则此时不收手

  for (int i = 2; i <= n; i ++ ) {
    for (int j = 1; j <= 6; j ++ ) {
      dp[i] += max(dp[i - 1], (double)j) / 6;
    }
  }
  
  ans = dp[n];
  cout << fixed << setprecision(10) << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}