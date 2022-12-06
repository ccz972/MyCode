#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int &x: a) cin >> x;
  for(int &x: b) cin >> x;
  vector<vector<int> > son(n);
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  vector<vector<int> > dp(n, vector<int>(n + 1, -1e9));

  function<void(int, int)> dfs = [&] (int u, int fa) {
    dp[u][0] = 0;
    for(int i = 1; i <= n; i ++ ) {
      dp[u][i] = b[i - 1] - a[u];
    }
    for(int &v: son[u]) if(v != fa) {
      dfs(v, u);
      //dp[u][i] 表示u选择了所有
      vector<int> ndp(n + 1, -1e9);
      for(int q = 0; q <= n; q ++ ) {
        for(int p = max(0, q - 1); p <= min(n, q + 1); ++ p) {
          ndp[q] = max(ndp[q], dp[v][p] + dp[u][q]);
        }
      }
      dp[u] = ndp;
    }
    
  };

  //dp[u][i] 表示考虑u的子树，并且距离u小于等于i的点都已经修复的最大收入
  
  dfs(0, -1);
  for(int i = 0; i < n; i ++ ) {
    cout << "i : " << i + 1 << "  ";
    for(int j = 0; j <= n; j ++ ) {
      cout << dp[i][j] << " \n"[j == n];
    }
  }
  cout << *max_element(dp[0].begin(), dp[0].end()) << "\n";
  return 0;
}