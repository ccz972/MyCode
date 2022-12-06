
struct segment_tree {
  constexpr int N = 1E5 + 10;
  int a[N];
  struct tree {int tl, tr, val, tag;} t[N << 2];
  #define l(x) t[(x)].tl
  #define r(x) t[(x)].tr
  #define len(x) (r(x) - l(x) + 1)
  #define val(x) t[(x)].val
  #define tag(x) t[(x)].tag
  #define lson k << 1
  #define rson k << 1 | 1
  void pushup(int k) { val(k)=val(lson)+val(rson); }
  void pushdown(int k) { 
    val(lson) += tag(k) * len(lson), val(rson) += tag(k)*len(rson); 
    tag(lson) += tag(k), tag(rson) += tag(k); tag(k) = 0; 
  }
  void build(int k, int l, int r) {
    l(k) = l, r(k) = r;
    if(l == r) {val(k) = a[l]; return;}
    int Mid = (l + r) >> 1;
    build(lson,l,Mid);
    build(rson, Mid + 1, r); 
    pushup(k);
  } 
  void update(int k, int l, int r, int z) {
    if(l(k) >= l && r(k) <= r) { val(k) += z * len(k), tag(k) += z; return; }
    if(l(k) > r || r(k) < l)return;
    pushdown(k);
    update(lson, l, r, z); update(rson, l, r, z);
    pushup(k);
  }
  int query(int k, int l, int r) {
    if(l(k) >= l && r(k) <= r) return val(k);
    if(l(k) > r || r(k) < l) return 0;
    pushdown(k);
    return query(lson, l, r) + query(rson, l, r);
  }

} T; 