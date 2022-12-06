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

ll a[N], b[N];
ll ans[N];
int step[N];

struct segment_tree {
  struct tree {
    int tl, tr;
    ll val, tag, mx;
  } t[N << 2];
  #define l(x) t[(x)].tl
  #define r(x) t[(x)].tr
  #define len(x) (r(x) - l(x) + 1)
  #define val(x) t[(x)].val
  #define mx(x) t[(x)].mx
  #define tag(x) t[(x)].tag
  #define lson k << 1
  #define rson k << 1 | 1
  void pushup(int k) { mx(k) = max(val(lson), val(rson)); val(k) = val(lson) + val(rson); }
  void pushdown(int k) {
    if (tag(k)) {
      mx(lson) += tag(k); mx(rson) += tag(k);
      val(lson) += tag(k) * len(lson), val(rson) += tag(k) * len(rson);
      tag(lson) += tag(k), tag(rson) += tag(k);
      tag(k) = 0;
    }
    // val(lson) += tag(k) * len(lson), val(rson) += tag(k) * len(rson);
    // tag(lson) += tag(k), tag(rson) += tag(k);
    // tag(k) = 0;
  }
  void build(int k, int l, int r) {
    l(k) = l, r(k) = r;
    if (l == r) {
      val(k) = b[l];
      return;
    }
    int Mid = (l + r) >> 1;
    build(lson, l, Mid);
    build(rson, Mid + 1, r);
    pushup(k);
  }
  void update(int k, int l, int r, int z) {
    if (l(k) >= l && r(k) <= r) {
      val(k) += z * len(k), tag(k) += z;
      return;
    }
    if (l(k) > r || r(k) < l) return;
    pushdown(k);
    update(lson, l, r, z);
    update(rson, l, r, z);
    pushup(k);
  }
  int query_mx(int k, int l, int r) {
    if (l(k) >= l && r(k) <= r) return val(k);
    if (l(k) > r || r(k) < l) return 0;
    pushdown(k);
    return max(query_mx(lson, l, r), query_mx(rson, l, r));
  }

  int query_sum(int k, int l, int r) {
    if (l(k) >= l && r(k) <= r) return val(k);
    if (l(k) > r || r(k) < l) return 0;
    pushdown(k);
    return query_sum(lson, l, r) + query_sum(rson, l, r);
  }



  // int binary_search(int k, int l, int r) {
  //   if (l(k) == l && r(k) == r) {
  //     if (query(k, l(k), r(k)) > 0) return l(k);
  //     return -1;
  //   }
  //   if (l(k) > r || r(k) < l) return -1;


  //   if (l(k) >= l && r(k) <= r) return val(k);
    
  //   pushdown(k);
  //   return max(query(lson, l, r), query(rson, l, r));
  //   // if (l(k) == r(k)) {
  //   //   if (query(k, l(k), r(k))) return l(k);
  //   //   return -1;
  //   // } 
  //   // if (query(lson, l(lson), r(lson)) > 0) {
  //   //   return binary_search(lson);
  //   // } else if (query(rson, l(rson), r(rson)) > 0) {
  //   //   return binary_search(rson);
  //   // } else {
  //   //   return -1;
  //   // }
  // }
} T;

void solve() {
  int n, m;
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) b[i] = a[i] - a[i - 1];
  T.build(1, 1, n);
  int idx = 1;
  for (int i = 1; i <= m; i ++ ) {
    T.update(1, 1, n, 1);
    //[idx + 1, n] 有没有大于0的数字，没有就是idx
    // auto t = T.binary_search(1, idx + 1, n);
    if (idx == n) {
      cout << T.query_sum(1, 1, idx) << "\n";
      continue;
    }
    int l = idx + 1, r = n;
    if (T.query_mx(1, l, r) <= 0) {
      cout << T.query_sum(1, 1, idx) << "\n";
    } else {
      debug(l, r);
      while (l < r) {
        int mid = (l + r + 1) / 2;
        if (T.query_mx(1, mid, r) > 0) l = mid;
        else r = mid - 1;
      }
      debug(l);      
      cout << T.query_sum(1, 1, l) << "\n";
      idx = l;
    }
  }
  // idx -> n
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();
  return 0;
}