#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2E5 + 10;

vector<int> son[N];
int depth1[N], depth2[N], depth3[N];
int fa1[N][20], fa2[N][20], fa3[N][20];

void dfs1(int u, int fa, int d) {
  depth1[u] = d;
  fa1[u][0] = fa;
  for (int i = 1; i < 20; i ++ ) fa1[u][i] = fa1[fa1[u][i - 1]][i - 1];
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u, d + 1);
  }
}

void dfs2(int u, int fa, int d) {
  depth2[u] = d;
  fa2[u][0] = fa;
  for (int i = 1; i < 20; i ++ ) fa2[u][i] = fa2[fa2[u][i - 1]][i - 1];
  for (int &v: son[u]) if (v != fa) {
    dfs2(v, u, d + 1);
  }
}

void dfs3(int u, int fa, int d) {
  depth3[u] = d;
  fa3[u][0] = fa;
  for (int i = 1; i < 20; i ++ ) fa3[u][i] = fa3[fa3[u][i - 1]][i - 1];
  for (int &v: son[u]) if (v != fa) {
    dfs3(v, u, d + 1);
  }
}

int lca(int x, int y) {
  if (x == y) return x;
  if (depth1[x] < depth1[y]) swap(x, y); 
  // x is lower
  for (int i = 19; i >= 0; i -- ) if (depth1[fa1[x][i]] >= depth1[y]) {
    x = fa1[x][i];
  }

  if (x == y) return x;
  // the height is same
  for (int i = 19; i >= 0; i -- ) if (fa1[x][i] != fa1[y][i]) {
    x = fa1[x][i], y = fa1[y][i];
  }
  return fa1[x][0];
}

int get1(int x, int k) {
  int now = depth2[x] - k;
  for (int i = 19; i >= 0; i -- ) if(depth2[fa2[x][i]] >= now) {
    x = fa2[x][i];
  } 
  return x;
}

int get2(int x, int k) {
  int now = depth3[x] - k;
  for (int i = 19; i >= 0; i -- ) if(depth3[fa3[x][i]] >= now) {
    x = fa3[x][i];
  } 
  return x;
}

int dis(int x, int y) {
  if (x == y) return 0;
  return depth1[x] + depth1[y] - 2 * depth1[lca(x, y)];
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs1(1, 0, 1);
  int L = 1, R = 1;
  for (int i = 1; i <= n; i ++ ) if (dis(1, L) < dis(1, i)) L = i;
  for (int i = 1; i <= n; i ++ ) if (dis(L, R) < dis(i, L)) R = i;
  dfs2(L, 0, 1); dfs3(R, 0, 1);
  int q; cin >> q;
  while (q -- ) {
    int u, k; cin >> u >> k;
    if (k > dis(u, L) && k > dis(u, R)) {
      cout << "-1\n";
    } else if (k <= dis(u, L)) {
      cout << get1(u, k) << "\n";
    } else {
      cout << get2(u, k) << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}