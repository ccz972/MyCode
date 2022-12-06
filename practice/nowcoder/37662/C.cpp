/***************************************************

@File    : C.cpp
@Time    : 2022/07/15 00:30:02
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

#define int long long

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;
constexpr int M = 4E6 + 10;


int n, q;

int a[N], b[N];
int p[M + 1], prime[M + 1], ct;
bool st[M + 1];
struct segment_tree {
  struct tree {int tl, tr, val, tag;} t[N << 2];
  #define l(x) t[(x)].tl
  #define r(x) t[(x)].tr
  #define len(x) (r(x) - l(x) + 1)
  #define val(x) t[(x)].val
  #define tag(x) t[(x)].tag
  #define lson k << 1
  #define rson k << 1 | 1

  void pushup(int k)
  {val(k)=val(lson)+val(rson);}

  void pushdown(int k) 
  {val(lson) += tag(k) * len(lson), val(rson) += tag(k)*len(rson); 
  tag(lson) += tag(k), tag(rson) += tag(k); tag(k) = 0;}

  void build(int k, int l, int r) {
    l(k) = l, r(k) = r;
    if(l == r) {val(k) = a[l]; return;}
    int Mid = (l + r) >> 1;
    build(lson,l,Mid);
    build(rson, Mid + 1, r); 
    pushup(k);
  } 

  void update(int k, int l, int r, int z) {
    if(l(k) >= l && r(k) <= r) {val(k) += z*len(k), tag(k) += z; return;}
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

int count(int x) {
  int now = 0;
  for(int i = 2; i <= x / i; i ++ ) if(x % i == 0) {
    while(x % i == 0) {
      ++ now;
      x /= i;
    }
  }
  if(x != 1) now ++;
  return now;
}
void init()
{
    for(int i=2;i<M;i++)
    {
        if(!st[i]) 
        {
            f[i] = 1;
            primes[cnt++] = i;
        }
        for(int j=0;i*primes[j]<M;j++)
        {
            st[primes[j]*i] = 1;
            f[primes[j]*i] = f[primes[j]] + f[i];
            if(i%primes[j]==0) break;
        }
    }
}
inline void init() {
  for(int i = 2; i <= M; i ++ )  {
    if(!st[i]) p[i] = 1, prime[ct ++ ] = i;
    for(int j = 1; i * prime[j] <= M; j ++ ) {
      st[prime[j] * i] = 1;
      p[prime[j] * i] = p[i] * p[prime[j]]
      if(i % prime[j] == 0) break;
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  init();
  // for(int i = 1; i <= 10; i ++ ) {
  //   cout << p[i] << " ";
  // }
  // cout << "\n";
  for(int i = 1; i <= n;  i ++ ) {
    cin >> b[i];
    // if(!p[b[i]]) {
    //   p[b[i]] = count(b[i] );
    // }
    a[i] = p[b[i]];
  }

  T.build(1, 1, n);

  cin >> q;

  

  while (q -- ) {
    int op; cin >> op;
    if(op == 1) {
      int l, r; cin >> l >> r;
      cout << T.query(1, l, r) << "\n";
    } else {
      int l, r, w; cin >> l >> r >> w;

      T.update(1, l, r, p[w]);
    }
  }
  return 0;
}