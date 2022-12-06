#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;

int n, col[N], cnt[N], sz[N];
vector<int> son[N];
ll ans[N], mx, sum;
bool is[N];

void dfs1(int u, int fa) {
  sz[u] = 1; int id = 0;
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u);
    sz[u] += sz[v];

    id = (sz[v] > sz[id] ? v : id);
  }
  if (id) is[id] = true;
}

void init(int u, int fa) {
  cnt[col[u]] --;
  for (int &v: son[u]) if (v != fa) {
    init(v, u);
  }
}

void dfs2(int u, int fa, int id) {
  cnt[col[u]] ++;
  if (cnt[col[u]] > mx) {
    mx = cnt[col[u]];
    sum = col[u];
  } else if (cnt[col[u]] == mx) {
    sum += col[u];
  }
  for (int &v: son[u]) if (v != fa && v != id) {
    dfs2(v, u, id);
  }
} 


void dfs3(int u, int fa) {
  int id = 0;
  for (int &v: son[u]) if (v != fa) {
    if (!is[v]) {
      dfs3(v, u);
      init(v, u);
      sum = mx = 0;
    } else {
      id = v;
    }
  }
  if (id) dfs3(id, u);
  dfs2(u, fa, id);
  ans[u] = sum;
}



void solve() {
  cin >> n;
  rep (i, 1, n) cin >> col[i];
  for (int i = 1, u, v; i < n; i ++ ) {
    cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs3(1, 0);
  rep (i, 1, n) cout << ans[i] << " \n"[i == n];
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
