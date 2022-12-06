#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << 0 << "\n";
    return 0;
  }

  std::vector<std::vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  i64 ans = 0;
  std::vector<std::array<i64, 4>> mx(n);
  std::vector<std::array<i64, 2>> mx1(n);
  std::vector<i64> dp(n), up(n), dp1(n), up1(n);

  std::function<void(int, int)> dfs1 = [&](int x, int p) {
    for (auto y : adj[x]) {
      if (y == p) {
        continue;
      }
      dfs1(y, x);
      i64 v = dp[y];
      for (int i = 0; i < 4; i++) {
        if (v > mx[x][i]) {
          std::swap(v, mx[x][i]);
        }
      }
      v = dp1[y];
      for (int i = 0; i < 2; i++) {
        if (v > mx1[x][i]) {
          std::swap(v, mx1[x][i]);
        }
      }
    }
    dp[x] = mx[x][0] + a[x];
    dp1[x] = std::max(mx1[x][0], mx[x][0] + mx[x][1] + a[x]);
    ans = std::max(ans, dp[x]);
  };
  dfs1(0, -1);

  std::function<void(int, int)> dfs2 = [&](int x, int p) {
    ans = std::max(ans, mx[x][0] + mx[x][1] + mx[x][2] + mx[x][3]);
    ans = std::max(ans, dp1[x] + up1[x]);
    for (auto y : adj[x]) {
      if (y == p) {
        continue;
      }
      up[y] = mx[x][dp[y] == mx[x][0]] + a[x];
      i64 v = up[y];
      for (int i = 0; i < 4; i++) {
        if (v > mx[y][i]) {
          std::swap(v, mx[y][i]);
        }
      }
      up1[y] = std::max(mx1[x][dp1[y] == mx1[x][0]],
                        (dp[y] == mx[x][0]   ? mx[x][1] + mx[x][2]
                         : dp[y] == mx[x][1] ? mx[x][0] + mx[x][2]
                                             : mx[x][0] + mx[x][1]) +
                            a[x]);
      v = up1[y];
      for (int i = 0; i < 2; i++) {
        if (v > mx1[y][i]) {
          std::swap(v, mx1[y][i]);
        }
      }
      dfs2(y, x);
    }
  };
  dfs2(0, -1);

  std::cout << ans << "\n";

  return 0;
}
