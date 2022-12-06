#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  T get(int l, int r) {
    return get(r) - get(l - 1);
  }

};

constexpr int N = 3E4 + 10;
constexpr int M = 1E5 + 10;

struct node {
  int l, r, id;
  bool operator < (const node &T) const {
    if (r != T.r) return r < T.r;
    if (l != T.l) return l < T.l;
    return id < T.id;
  }
} q[M];

int n, m;
int a[N], pre[N];
map<int, int> mp;
long long ans[M];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    pre[i] = mp[a[i]];
    mp[a[i]] = i;
  }
  cin >> m;
  for (int i = 1; i <= m; i ++ ) {
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  
  sort(q + 1, q + 1 + m);

  fenwick<long long> fen(n + 1);

  for (int i = 1, j = 1; i <= m; i ++ ) {
    for ( ; j <= n && j <= q[i].r; j ++ ) {
      if (pre[j]) fen.modify(pre[j], -a[j]);
      fen.modify(j, a[j]);
    }
    ans[q[i].id] = fen.get(q[i].l, q[i].r);
  }

  for (int i = 1; i <= m; i ++ ) {
    cout << ans[i] << "\n";
  }


  mp.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}