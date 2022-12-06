#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i(a); i <= b; ++ i)

typedef long long ll;

const int N = 2005;
ll l[N], r[N];
ll dp[N][N];

void slv(){

  int n; cin >> n;

  rep(i, 1, n) cin >> l[i] >> r[i];
  
  ll ans = 0;

  rep(i, 2, n) {
    ans += i * (i - 1);
  }

  rep(i, 1, n - 1) {
    ans -= i * (n - i);
  }

  reverse(l + 1, l + 1 + n);
  reverse(r + 1, r + 1 + n);

  rep(i, 1, n) {
    rep(j, 0, i - 1) {
      dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] - l[i] * (n - j - 1) + l[i] * j);
      dp[i][j] = max(dp[i][j], dp[i - 1][j] -  r[i] * (i - 1 - j) + r[i] * (n - 1 - (i - 1 - j)));
    }
  }

  ll anss = 0;
  rep(i, 0, n) anss = max(anss, dp[n][i]);
      
  cout << ans + anss << '\n';
}
int main() {
  slv();
  return 0;
}