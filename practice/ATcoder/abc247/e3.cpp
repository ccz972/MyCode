#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 2E5 + 10;

int n, x, y;
int a[N], dp[N][2][2];

void solve() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }

  ll ans = 0;

  for (int i = 1; i <= n; i ++ ) {
    if (a[i] > x || a[i] < y) continue;
    bool fx = a[i] == x;
    bool fy = a[i] == y;
    dp[i][fx][fy] ++;
    for (int p = 0; p < 2; p ++ ) {
      for (int q = 0; q < 2; q ++ ) {
        dp[i][p | fx][q | fy] += dp[i - 1][p][q];
      }
    }
    ans += dp[i][1][1];
  }

  cout << ans << "\n";

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
