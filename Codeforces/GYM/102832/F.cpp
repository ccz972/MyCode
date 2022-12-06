#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E5 + 10;

int n, a[N], sz[N];
bool top[N];
ll ans;
vector<int> son[N];

void dfs1(int u, int fa) {
  sz[u] = 1; int p = 0;
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u);
    sz[u] += sz[v];
    if (!p || sz[p] < sz[v]) p = v;
  }
  top[p] = true;
}

void calc(int u, int fa) {
  
}

void dfs2(int u, int fa) {
  for (int &v: son[u]) if (v != fa && !top[v]) {
    calc(v, u);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs1(1, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}