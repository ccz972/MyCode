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

int n, cur, t, col[N], q[N], cnt[N], sz[N], dfn[N], idx[N];
vector<int> son[N];
ll ans[N], sum, mx;

void dfs1(int u, int fa) {
  dfn[u] = ++ cur; idx[dfn[u]] = u; sz[u] = 1;
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u); sz[u] += sz[v];
  }
}
void del() {
  while (t) { cnt[q[t -- ]] = 0; }
  sum = mx = 0;
}
void add(int x) {
  q[++ t] = col[x];
  ++ cnt[col[x]];
  if (cnt[col[x]] > mx) {
    sum = col[x];
    mx = cnt[col[x]];
  } else if (cnt[col[x]] == mx) {
    sum += col[x];
  }
}
void dfs2(int l, int r) {
  if (l == r) {
    // cout << "qwq\n";
    if (sz[idx[l]] == 1) ans[idx[l]] = col[idx[l]];
    return ; 
  }
  int mid = (l + r) / 2;
  dfs2(l, mid); dfs2(mid + 1, r);
  int p = mid; 
  del();
  //解决某个子树在两边都有的部分qwq 
  for (int i = mid, j; i >= l && i + sz[idx[i]] - 1 <= r; -- i) {
    j = i + sz[idx[i]] - 1;
    add(idx[i]);
    if (j <= mid) continue; // 如果 i 的子树 整个都在左边，那不管
    while (p < j) add(idx[++ p]); //整个子树都加上
    ans[idx[i]] = sum; 
  }
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
  dfs2(1, n);
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
