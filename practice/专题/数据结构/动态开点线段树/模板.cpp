// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #define rep(i, a, b) for (int i(a); i <= b; ++ i )
// #define dec(i, a, b) for (int i(b); i >= a; -- i )

// #ifdef LOCAL
//   #include <debugger>
//   clock_t start = clock();
// #else
//   #define debug(...) 42
// #endif

// template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
// template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// constexpr int N = 2E5 + 10;

// #define ls(x) (tr[x].l)
// #define rs(x) (tr[x].r)
// #define sum(x) (tr[x].sum)

// struct node {
//   int sum = 0;
//   int l = 0, r = 0;
// } tr[N * 30];

// int tot;

// void pushup(int u) {
//   sum(u) = sum(ls(u)) + sum(rs(u));
// }

// void pushdown(int u) {
//   if (!ls(u)) ls(u) = ++ tot;
//   if (!rs(u)) rs(u) = ++ tot;
// }

// int query(int u, int l, int r, int L, int R) {
//   if (L <= l && r <= R) return sum(u);
//   if (l >= R && r < L) return 0;
//   pushdown(u);
//   int mid = (l + r - 1) / 2;
//   return query(ls(u), l, mid, L, R) + query(rs(u), mid + 1, r, L, R);
// }

// void update(int u, int l, int r, int pos, int k) {
//   if (l == r) {
//     sum(u) += k; return ;
//   }
//   int mid = (l + r - 1) / 2;
//   pushdown(u);
//   if (pos <= mid) update(ls(u), l, mid, pos, k);
//   else update(rs(u), mid + 1, r, pos, k);
//   pushup(u);
// }

// void solve() {
//   int n, q; cin >> n >> q;

// }
// int main() {
//   cin.tie(nullptr)->sync_with_stdio(false);
//   solve();
// #ifdef LOCAL
//   clock_t ends = clock();
//   // cout << "\n\nRunning Time : " << (double) (ends - start) /
//   CLOCKS_PER_SEC * 1000 << "ms" << endl;
// #endif
//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

#define for1(i, a, b) for (int i = a; i <= b; i++)
#define for0(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define mid int m = l + r >> 1
#define tl tree[rt].l
#define tr tree[rt].r

const int N = 5e5 + 5;
const int maxn = 500000 * 32 + 5;
const int MAXR = 1e9;

struct node {
  int l, r;
  int sum;
} tree[maxn];
int sz;

void init() { sz = 2; }

void push_up(int rt) { tree[rt].sum = tree[tl].sum + tree[tr].sum; }

void update(int p, int& rt, int l, int r) {
  if (!rt) {
    rt = sz++;
    tl = tr = tree[rt].sum = 0;
  }
  if (l == r) {
    tree[rt].sum++;
    return;
  }
  mid;
  if (p <= m)
    update(p, tl, l, m);
  else
    update(p, tr, m + 1, r);
  push_up(rt);
}

ll query(int L, int R, int rt, int l, int r) {
  // printf("query[%d,%d]\n",l,r);
  if (!rt) return 0;
  if (L <= l && r <= R) return tree[rt].sum;
  ll ans = 0;
  mid;
  if (L <= m) ans += query(L, R, tl, l, m);
  if (R > m) ans += query(L, R, tr, m + 1, r);
  return ans;
}

int main() {
  init();
  int n;
  scanf("%d", &n);
  ll ans = 0;
  int root = 1;
  for1(i, 1, n) {
    int x;
    scanf("%d", &x);
    if (x + 1 <= MAXR) ans += query(x + 1, MAXR, 1, 1, MAXR);  //防止区间无效
    update(x, root, 1, MAXR);
  }
  printf("%lld\n", ans);
  return 0;
}