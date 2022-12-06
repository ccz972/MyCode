#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e5 + 10;

int ans, f[N], g[N];
vector<int> son[N];

void dfs(int u, int fa) {
  int mx = 0, cmx = 0;
  for(auto v: son[u]) if(v != fa) {
    dfs(v, u);
    if(f[v] >= mx) {
      cmx = mx; mx = f[v];
    } else if(f[v] > cmx) {
      cmx = f[v];
    }
  }
  f[u] = mx + 1;
  g[u] = mx + cmx;
  ans = max(ans, max(f[u], g[u]));
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}