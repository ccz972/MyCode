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

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> w(n); for(auto &x: w) cin >> x;
  vector<ll> p(n); for(auto &x: p) cin >> x;
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  // S 
  // S * w[i] + S * p[i] * w[j]
  // S * w[j] + S * p[j] * w[i]
  // w[i] - w[j] + (p[i] * w[j]) - (p[j] * w[i]) > 0
  // 
  //
  sort(id.begin(), id.end(), [&](int i, int j) {
    return w[i] * 10000 + p[i] * w[j] > w[j] * 10000 + p[j] * w[i];
  });

  vector<vector<long double> > dp(n + 1, vector<long double>(m + 1));
  // dp[n][0] = 1;
  for(int i = n - 1; i >= 0; i -- ) {
    for(int j = 1; j <= m; j ++ ) {
      dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - 1] * 0.0001 * p[id[i]] + w[id[i]]);
    }
  }

  cout <<  dp[0][m] << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
