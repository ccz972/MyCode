#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}
//树上背包

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  // n个物品，体积为m
  vector<vector<int>> son(n + 2);

  for (auto i = 0; i < n; i++) {
    int x;
    cin >> x;  //买 i 必须先买 x
    son[x].push_back(i + 1);
  }

  vector<int> v(n + 1), w(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];  //体积
  }

  for (int i = 1; i <= n; i++) {
    cin >> w[i];  //价值
  }

  // dfs序
  vector<int> l(n + 2), r(n + 2), id(n + 2);
  int tot = 0;

  function<void(int)> dfs = [&](int u) {
    l[u] = ++tot;
    id[tot] = u;
    for (auto &v : son[u]) {
      dfs(v);
    }
    r[u] = tot;
  };

  dfs(0);

  //背包
  vector<vector<int>> f(tot + 3, vector<int>(m + 1));

  for (int i = tot; i >= 1; i--) {
    int u = id[i];
    for (int j = 0; j <= m; j++) {
      f[i][j] = f[r[u] + 1][j];
      if (j >= v[u]) {
        chkmax(f[i][j], f[i + 1][j - v[u]] + w[u]);
      }
    }
  }

  cout << f[1][m];

  return 0;
}