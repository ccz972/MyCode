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

constexpr int N = 5E5 + 5;
constexpr int M = 1E9;

#define ls(u) (tr[u].l)
#define rs(u) (tr[u].r)
#define val(u) (tr[u].val)

struct node {
  int l, r;
  int val;
} tr[N * 32];

int tot = 1;


void pushup(int u) {
  val(u) = val(ls(u)) + val(rs(u));
}

void update(int u, int &rt, int l, int r) {
  if (!rt) {
    rt = ++ tot;
    ls(rt) = rs(rt) = val(rt) = 0; 
  } 

  if (l == r) {
    val(rt) ++;
    return ;
  }

  int mid = (l + r - 1) / 2;
  if (u <= mid) {
    update(u, ls(rt), l, mid);
  } else {
    update(u, rs(rt), mid + 1, r);
  }
  pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
  if (!rt) return 0;
  if (L <= l && r <= R) return val(rt);
  if (l > R || r < L) return 0;
  // L R待查区间
  int mid = (l + r - 1) / 2;
  // debug(l, r, L, R);
  return query(ls(rt), l, mid, L, R) + query(rs(rt), mid + 1, r, L, R);
}

void solve() {
  int n; cin >> n;
  ll ans = 0;
  int root = 1;
  for (int i = 1; i <= n; i ++ ) {
    int x; cin >> x;
    if (x + 1 <= M) {
      ans += query(1, 1, M, x + 1, M);
    }
    update(x, root, 1, M);
  }  
  cout << ans << "\n";
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
