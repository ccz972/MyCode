#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e5 + 10;

ll w[N], f[N], g[N];
vector<int> son[N];

void dfs(int u, int fa) {
  ll s1 = 0, s2 = 0; //z
  for(auto v: son[u]) if(v != fa) {
    dfs(v, u);
    s1 += f[v], s2 += g[v];
    g[u] += max(f[v], g[v]);
  }
  f[u] = max(w[u] + s2, s1);
}

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> w[i];
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  dfs(1, 0);
  cout << max(f[1], g[1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}