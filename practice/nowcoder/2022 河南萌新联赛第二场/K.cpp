/***************************************************

@File    : K.cpp
@Time    : 2022/07/17 13:22:24
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

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

constexpr int N = 2E5 + 10;

int a[N];
struct segment_tree {
  struct tree {int tl, tr; ll val1, val2, val; int tag;} t[N << 2];
  #define l(x) t[(x)].tl
  #define r(x) t[(x)].tr
  #define len(x) (r(x) - l(x) + 1)
  #define val(x) t[(x)].val
  #define val1(x) t[(x)].val1
  #define val2(x) t[(x)].val2
  #define tag(x) t[(x)].tag
  #define lson k << 1
  #define rson k << 1 | 1
  void pushup(int k) { val(k)=val(lson)+val(rson); val1(k)=val1(lson)+val1(rson); val2(k)=val2(lson)+val2(rson); }
  void pushdown(int k) { 
    if(tag(k)) {
      ll tmp1 = val1(lson), tmp2 = val2(lson);
      val1(lson) = tmp2 / 2;
      val2(lson) = tmp1 * 2;
      val(lson) = val1(lson) + val2(lson);

      tmp1 = val1(rson), tmp2 = val2(rson);
      val1(rson) = tmp2 / 2;
      val2(rson) = tmp1 * 2;
      val(rson) = val1(rson) + val2(rson);
      tag(lson) ^= 1; tag(rson) ^= 1;
      tag(k) ^= 1;
    }
    // val(lson) += tag(k) * len(lson), val(rson) += tag(k)*len(rson); 
    // tag(lson) += tag(k), tag(rson) += tag(k); tag(k) = 0; 
  }
  void build(int k, int l, int r) {
    l(k) = l, r(k) = r; tag(k) = 0;
    if(l == r) {val1(k) = val(k) = a[l]; val2(k) = 0;  return;}
    int Mid = (l + r) >> 1;
    build(lson,l,Mid);
    build(rson, Mid + 1, r); 
    pushup(k);
  } 

  void update(int k, int l, int r) {
    if(l(k) >= l && r(k) <= r) { 
      ll tmp1 = val1(k), tmp2 = val2(k);
      val1(k) = tmp2 / 2;
      val2(k) = tmp1 * 2;
      val(k) = val1(k) + val2(k);
      // debug(l(k), r(k), val(k));
      tag(k) ^= 1;
      return ;
    }
    if(l(k) > r || r(k) < l) return;
    pushdown(k);
    update(lson, l, r); update(rson, l, r);
    pushup(k);
    // debug(l(k), r(k), val(k));
  }

  ll query(int k, int l, int r) {
    if(l(k) >= l && r(k) <= r) return val(k);
    if(l(k) > r || r(k) < l) return 0;
    pushdown(k);
    return query(lson, l, r) + query(rson, l, r);
  }

} T; 

// int bl[N], a[N];
// ll sum1[N], sum2[N];
// int tag[N];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }

  T.build(1, 1, n);
  // T.update(1, 2, 2);
  // cout << T.query(1, 1, 2) << "\n";
  // int block = sqrt(n) + 1;
  // for(int i = 0; i < n; i ++ ) {
  //   cin >> a[i];
  //   bl[i] = i / block;
  //   sum1[bl[i]] += a[i];
    
  // }

  // T.update(1, 1, 3);
  // debug(">");
  // cout << T.query(1, 1, 1) << "\n";
  // T.update(1, 2, 4);
  // for(int i = 1; i <= n; i ++ )
  // cout << T.query(1, i, i) << "\n";

  while(m -- ) {
    int l, r; cin >> l >> r;
    T.update(1, l, r);
    cout << T.query(1, 1, n) << "\n";
    // -- l, -- r;
    // int idxl = l / block, idxr = r / block;
    // ll ans = 0;
    // if(idxr - idxl <= 2) {
    //   for(int i = l; i <= r; i ++ ) {
        
    //   }
    // }


  }



  return 0;
}

