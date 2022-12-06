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


struct node {
  int l, r;
  ll val = 0, tag = 0;
} tr[N * 2]; 

int a[N];

int tot = 1;
int root = 1;

#define ls(u) (tr[u].l)
#define rs(u) (tr[u].r)
#define val(u) (tr[u].val)
#define tag(u) (tr[u].tag)

void pushup(int u) {
  val(u) = val(ls(u)) + val(rs(u));
}

void build(int &u, int l, int r) {
  if (!u) u = ++ tot;
  if (l == r) {
    val(u) = a[l];
    return ;
  }
  int mid = (l + r - 1) / 2;
  build(ls(u), l, mid);
  build(rs(u), mid + 1, r);
  pushup(u);
}

void pushtag(int &u, int l, int r, int k) {
  if (!u) u = ++ tot;
  // debug(u, ls(u), rs(u), k);
  val(u) += 1ll * (r - l + 1) * k;
  tag(u) += k;
}

void pushdown(int u, int l, int r) {
  if (tag(u)) {
    int mid = (l + r - 1) / 2;
    pushtag(ls(u), l, mid, tag(u));
    pushtag(rs(u), mid + 1, r, tag(u));
    tag(u) = 0;
  }
}

void update(int &u, int l, int r, int L, int R, int k) {
  if (!u) u = ++ tot;
  if (L <= l && R >= r) {
    pushtag(u, l, r, k); 
    return ;
  } 
  pushdown(u, l, r);
  int mid = (l + r - 1) / 2;
  if (L <= mid) update(ls(u), l, mid, L, R, k);  
  if (R >= mid + 1) update(rs(u), mid + 1, r, L, R, k);
  pushup(u);
}

ll query(int u, int l, int r, int L, int R) {
  if (L <= l && R >= r) return val(u);
  pushdown(u, l, r);
  int mid = (l + r - 1) / 2;
  ll ret = 0;
  if (L <= mid) ret += query(ls(u), l, mid, L, R);
  if (R >= mid + 1) ret += query(rs(u), mid + 1, r, L, R);
  return ret;
}
//1 7 6 2 3
void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) cin >> a[i]; 
  
  build(root, 1, n);
  while (m -- ) {
    int op; cin >> op;
    if (op & 1) {
      int x, y, k; cin >> x >> y >> k;
      update(root, 1, n, x, y, k);
    } else {
      int x, y; cin >> x >> y;
      cout << query(root, 1, n, x, y) << "\n";
    }
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
