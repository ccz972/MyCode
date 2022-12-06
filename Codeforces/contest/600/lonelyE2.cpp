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

int n, cur, t, mx, q[N], a[N], sz[N], idx[N], dfn[N], cnt[N];
vector<int> son[N];
ll ans[N], sum;

void dfs1(int u, int fa) {
  dfn[u] = ++ cur; idx[cur] = u; sz[u] = 1;
  for (int &v: son[u]) if (v != fa) {
    dfs1(v, u); sz[u] += sz[v];
  }
}

void del() {
  while (t) cnt[q[t -- ]] = 0;
  sum = mx = 0;
}

void add(int x) {
  cnt[a[x]] ++;
  if (cnt[a[x]] > mx) {
    sum = a[x];
    mx = cnt[a[x]];
  } else if (cnt[a[x]] == mx) {
    sum += a[x];
  }
  q[++ t] = a[x];
}

void dfs2(int l, int r) {
  if (l == r) {
    if (sz[idx[l]] == 1) ans[idx[l]] = a[idx[l]];
    return ;
  }

  int mid = (l + r) / 2;

  dfs2(l, mid); dfs2(mid + 1, r);

  int p = mid;
  del();
  for (int i = mid; i >= l; i -- ) {
    int j = i + sz[idx[i]] - 1;
    if (j > r) break;
    add(idx[i]);
    if (j <= mid) continue;
    while (p < j) add(idx[++ p]);
    ans[idx[i]] = sum;
  }
}

void solve() {
  cin >> n;
  rep (i, 1, n) cin >> a[i];
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }

  dfs1(1, 0);
  dfs2(1, n);

  for (int i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];

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
