#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// #define int ll 

constexpr int N = 1E5 + 100;
constexpr ll INF = 1E18 + 10;

ll a[N], b[N];
array<ll, 2> p[N];
ll f[N];

struct segTree {

  struct node {
    int l, r;
    ll mi, tag;
  } tr[N << 2];

  void pushup(int u) {
    tr[u].mi = min(tr[u << 1].mi, tr[u << 1 | 1].mi);
  }

  void build(int u, int l, int r) {
    tr[u] = {l, r, INF, INF};
    if(l != r) {
      int mid = (l + r) / 2;
      build(u << 1, l, mid);
      build(u << 1 | 1, mid + 1, r);
      pushup(u);
      // debug(tr[u].mi, tr[u << 1].mi, tr[u << 1 | 1].mi);
    }
  }

  void pushdown(int u) {
    node &lson = tr[u << 1]; node &rson = tr[u << 1 | 1];
    // chkmin(tr[u].mi, tr[u].tag); 
    chkmin(lson.mi, tr[u].tag); chkmin(rson.mi, tr[u].tag); 
    chkmin(lson.tag, tr[u].tag); chkmin(rson.tag, tr[u].tag);
    tr[u].tag = INF;
  }

  void modify(int u, int l, int r, ll v) {
    
    if(l <= tr[u].l && tr[u].r <= r) {
      chkmin(tr[u].mi, v);
      chkmin(tr[u].tag, v);
    } else if(r < tr[u].l || l > tr[u].r) {
      return ;
    } else {
      pushdown(u);
      modify(u << 1, l, r, v);
      modify(u << 1 | 1, l, r, v);
      pushup(u);
    }
  }

  ll query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
      return tr[u].mi;
    } 
    if(r < tr[u].l || l > tr[u].r) {
      return INF;
    }
    pushdown(u);
    return min(query(u << 1, l, r), query(u << 1 | 1, l, r));
  }

} T;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, t; cin >> n >> m >> t;
  T.build(1, 1, m + 10);
  a[0] = 0, b[0] = t;

  for(int i = 1; i <= m; i ++ ) {
    // cin >> a[i] >> b[i];
    cin >> p[i][0] >> p[i][1];
  }

  sort(p + 1, p + 1 + m);

  for(int i = 1; i <= m; i ++ ) {
    a[i] = p[i][0], b[i] = p[i][1];
  }

  a[m + 1] = n, a[m + 2] = INT64_MAX;

  for(int i = 0; i <= m; i ++ ) {
    ll val = (i ? T.query(1, i, i) : -1);
    int idx = upper_bound(a + 1, a + 3 + m, a[i] + b[i]) - a;
    assert(a[idx - 1] <= a[i] + b[i]);
    if(i + 1 > idx - 1) continue;
    T.modify(1, i + 1, idx - 1, val + 1);
  }

  ll ans = T.query(1, m + 1, m + 1);
  if(ans > m + 10) ans = -1;
  cout << ans << "\n";


  

  return 0;
}