#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for (int i = (b); i <= (s); ++i)
#define dec(i, b, s) for (int i = (b); i >= (s); --i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

constexpr int N = 2E5 + 10;
vector<int> son[N];
vector<int> g[N];
int tp, a[N], use[N];
bool ans, has_root, f;
int dfn[N], depth[N], sz[N], hson[N], top[N], parent[N];

void dfs1(int u, int fa, int d) {
  depth[u] = d;
  sz[u] = 1;
  parent[u] = fa;
  for (int &v : son[u])
    if (v != fa) {
      dfs1(v, u, d + 1);
      sz[u] += sz[v];
      if (hson[u] == -1 || sz[hson[u]] < sz[v]) hson[u] = v;
    }
}

void dfs2(int u, int id) {
  top[u] = id;
  dfn[u] = ++tp;
  if (hson[u] == 0) return;
  dfs2(hson[u], id);
  for (int &v : son[u])
    if (v != parent[u] && v != hson[u]) {
      dfs2(v, v);
    }
}

int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (depth[top[u]] > depth[top[v]]) {
      u = parent[top[u]];
    } else {
      v = parent[v];
    }
  }
  return depth[u] < depth[v] ? u : v;
}

void dfs3(int u, int fa) {
  int now = 0;
  for (int &v : g[u]) {
    if (v != fa) dfs3(v, u);
    if (!f || v != 1) {
      ++now;
    }
  }

  if (!(f && u == 1) && now > 2) {
    ans = true;
  }
  g[u].clear();
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  dfs1(1, 0, 1);
  dfs2(1, 1);
  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;
    has_root = false;

    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      if (a[i] == 1) has_root = true;
    }

    sort(a + 1, a + 1 + k, [&](int x, int y) { return dfn[x] < dfn[y]; });

    auto add = [&](int u, int v) {
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    };

    vector<int> stk{1};

    for (int i = 1; i <= k; i++) {
      if (a[i] != 1) {
        int p = lca(a[i], stk.back());
        if (p != stk.back()) {
          while (dfn[p] < dfn[stk[(int)stk.size() - 2]]) {
            add(stk.back(), stk[(int)stk.size() - 2]);
            stk.pop_back();
          }
          add(p, stk.back()), stk.pop_back();
          if (dfn[p] > dfn[stk.back()]) stk.emplace_back(p);
        }
        stk.emplace_back(a[i]);
      }
    }
    while (stk.size() > 1) {
      if (stk.back() != 1) {
        add(stk.back(), stk[(int)stk.size() - 2]);
        stk.pop_back();
      }
    }
    f = (!has_root && (int)g[1].size() == 1);
    // 表示关键点里面没有根，并且根(一定存在)在虚树中只连了一个点
    dfs3(1, 0);
    if (ans) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }

    ans = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();
  return 0;
}
