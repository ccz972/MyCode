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

constexpr int N = 3E5 + 10;

vector<int> son[N];
vector<array<int, 3> > query[N];
int Left[N], Right[N];
int n, m, q, cur; 
int dfn[N], sz[N], idx[N];
ll ans[N];

struct segment_tree {
  ll tr1[N], tr2[N];
  int lowbit(int x) {
    return x & -x;
  }

  void add(ll tr[], int x, ll c) {
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
  }

  void update(int p, int l, int r, int d) {
    add(tr1, l, d);
    add(tr1, r + 1, -d);
    add(tr2, l, d * 1LL * l);
    add(tr2, r + 1, 1LL * (r + 1) * -d);
  }

  ll sum(ll tr[], int x) {
    ll res = 0 ;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
  }

  ll ans(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
  }
  
  ll query(int p, int l, int r) {
    return ans(r) - ans(l - 1);
  }
     
}T; 


void dfs1(int u) {
  dfn[u] = ++ cur; sz[u] = 1; idx[dfn[u]] = u; 
  for (int &v: son[u]) {
    dfs1(v);
    sz[u] += sz[v];
  }
}

void dfs (int l, int r) {
  if (l == r) {
    if (sz[idx[l]] != 1) return ;
    T.update(1, Left[idx[l]], Right[idx[l]], 1);
    for (auto [L, R, id] : query[idx[l]]) {
      ans[id] = T.query(1, L, R);
    }
    T.update(1, Left[idx[l]], Right[idx[l]], -1);
    return ;
  }
  int mid = (l + r) / 2;

  dfs (l, mid); dfs(mid + 1, r);

  int p = mid;
  for (int i = mid, j; i >= l && i + sz[idx[i]] - 1 <= r; -- i) {
    j = i + sz[idx[i]] - 1;
    T.update(1, Left[idx[i]], Right[idx[i]], 1);
    if (j <= mid) continue;
    while (p < j) ++ p, T.update(1, Left[idx[p]], Right[idx[p]], 1);
    for (auto [L, R, id] : query[idx[i]]) {
      ans[id] = T.query(1, L, R);
    }
  }

  p = mid;

  for (int i = mid, j; i >= l && i + sz[idx[i]] - 1 <= r; -- i) {
    j = i + sz[idx[i]] - 1;
    T.update(1, Left[idx[i]], Right[idx[i]], -1);
    if (j <= mid) continue;
    while (p < j) ++p, T.update(1, Left[idx[p]], Right[idx[p]], -1);
  }


}

void solve() {
  cin >> n >> m;
  
  for (int i = 1; i <= m; i ++ ) {
    int u, v; cin >> u >> v;
    int x, y; cin >> x >> y;
    son[u].emplace_back(v);
    Left[v] = x, Right[v] = y;
  }
  Left[1] = 1, Right[1] = n;

  // T.build(1, 1, n + 3);
  
  dfs1(1);

  cin >> q;

  for (int i = 0; i < q; i ++ ) {
    int x, L, R; cin >> x >> L >> R;
    query[x].push_back({L, R, i});
  }

  dfs(1, m + 1);

  for (int i = 0; i < q; i ++ ) {
    cout << ans[i] << "\n";
  }

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
