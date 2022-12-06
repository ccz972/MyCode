#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(a, b) ((a) = (a) >= (b) ? (a) : (b))
#define chkmin(a, b) ((a) = (a) <= (b) ? (a) : (b))
constexpr int N = 1E6 + 10;

int v[N];
vector<int> son[N];
int f[N];
int g[N];
int sz[N];

void dfs1(int u, int fa) {
  sz[u] = 1;
  f[u] = v[u];
  for (int &v : son[u])
    if (v != fa) {
      dfs1(v, u);
      sz[u] += sz[v];
      chkmin(f[u], f[v]);
    }
}

void dfs2(int u, int fa) {
  int mi = g[u], cmi = v[u];
  if (mi > cmi) swap(mi, cmi);
  for (int &v : son[u])
    if (v != fa) {
      if (f[v] < mi) {
        cmi = mi;
        mi = f[v];
      } else {
        chkmin(cmi, f[v]);
      }
    }
  for (int &v : son[u])
    if (v != fa) {
      if (f[v] == mi) {
        g[v] = cmi;
      } else {
        g[v] = mi;
      }
      dfs2(v, u);
    }
}

int ans[N];
int n;

void dfs(int u, int fa) {
  int cnt = 0, mx = 0;
  for (auto x : son[u]) {
    if (x == fa) {
      mx = max(mx, n - sz[u]);
      if (g[u] < v[u]) {
        if (!cnt) {
          cnt++;
          ans[v[u]] = n - sz[u];
        } else
          ans[v[u]] = 0;
      }
      continue;
    }
    mx = max(mx, sz[x]);
    dfs(x, u);
    if (f[x] < v[u]) {
      if (!cnt) {
        cnt++;
        ans[v[u]] = sz[x];
      } else
        ans[v[u]] = 0;
    }
  }
  if (!cnt) ans[v[u]] = mx;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i += 1) cin >> v[i], f[i] = g[i] = 1E9;
  ;
  for (int i = 2; i <= n; i += 1) {
    int fa;
    cin >> fa;
    son[fa].emplace_back(i);
    son[i].emplace_back(fa);
  }

  dfs1(1, 0);
  g[1] = 1E9;
  dfs2(1, 0);
  dfs(1, 0);
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << n << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();
  return 0;
}