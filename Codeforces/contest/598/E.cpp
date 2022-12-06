#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll INFF = 0x3f3f3f3f3f3f3f3f;
// constexpr int N = 2E5 + 10;
// #define int ll
int dp[31][31][51];

int dfs(int x, int y, int k) {
  if (dp[x][y][k] || x * y == k || !k) {
    // debug(x, y, k, dp[x][y][k]);
    return dp[x][y][k];
  }
  int ret = 1E9;
  for (int i = 1; i <= x - i; i ++ ) {
    for (int j = 0; j <= k; j ++ ) {
      chkmin(ret, y * y + dfs(i, y, k - j) + dfs(x - i, y, j));
    }
  }
  for (int i = 1; i <= y - i; i ++ ) {
    for (int j = 0; j <= k; j ++ ) {
      chkmin(ret, x * x + dfs (x, y - i, k - j) + dfs(x, i, j));
    }
  }
  // debug(x, y, k, ret);
  return dp[x][y][k] = ret;
}

void solve() {
  int a, b, c; cin >> a >> b >> c;
  cout << dfs(a, b, c) << "\n";

}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}