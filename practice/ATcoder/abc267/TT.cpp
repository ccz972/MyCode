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

int n, m;
vector<int> son[N];
int parent[N], top[N], hson[N], depth[N], sz[N];
int cnt[N]; // 记录每个重链(以头记录)有多少个点
int Rank[N]; //记录每个点在其所在重链的rank
int Fa[N][20];

void dfs1(int u, int fa, int d) {
  sz[u] = 1, parent[u] = fa, depth[u] = d;
  for(int &v: son[u]) if(v != fa) {
    dfs1(v, u, d + 1);
    sz[u] += sz[v];
    if(sz[hson[u]] < sz[v]) hson[u] = v;
  }
}

void dfs2(int u, int id) {
  top[u] = id;
  if(!hson[u]) return ;
  dfs2(hson[u], id);
  for(int &v: son[u]) {
    if(v == parent[u] || v == hson[u]) {
      continue;
    }
    dfs2(v, v);
  }
}

void dfs3(int u, int fa) {
  for (int &v: son[u]) if (v != fa) {
    if (top[v] != top[u]) Rank[v] = 1;
    else Rank[v] = Rank[u] + 1;
    dfs3(v, u);
  }
}

void dfs4(int u, int fa) {
  Fa[u][0] = fa;
  for (int i = 1; i < 20; i ++ ) {
    Fa[u][i] = Fa[Fa[u][i - 1]][i - 1];
  }
  for (int& v: son[u]) if (v != fa) {
    dfs4(v, u);
  }
}


void solve() {
  cin >> n;
  rep (i, 1, n - 1) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  dfs1(1, -1, 1);
  dfs2(1, 1);
  Rank[1] = 1;
  dfs3(1, 0);
  dfs4(1, 0);
  rep (i, 1, n) cnt[top[i]] ++;
  
  // rep (i, 1, n) cout << top[i] << " \n"[i == n];
  // rep (i, 1, n) cout << hson[i] << " \n"[i == n];

  int q; cin >> q;
  while (q -- ) {
    int u, k; cin >> u >> k;
    // Case1 : 往上跳

    if (depth[u] == )

    auto p = k;
    auto now = u;
    bool flag = false;
    while (now != 1) {
      if (Rank[now] >= p) {
        auto res = now;
        // Rank[ans] = Rans[now] - p + 1;
        for (int i = 19; i >= 0; i -- ) if (top[Fa[now][i]] == top[now] && Rank[Fa[now][i]] <= Rank[res] - p + 1) {
          now = Fa[now][i];
        }

        flag = true;
        cout << now << "\n";
        break;
      }
    }

    // Case 往下跳

    // 输出v满足，dist[u, v] = k
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}