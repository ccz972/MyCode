#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E6 + 10;
constexpr int INF = 1E9 + 10;
struct node {
  int l, r;
  bool operator < (const node &T) const {
    if (l != T.l) return l < T.l;
    return r < T.r;
  }
} a[N];

int n, x, y, z, k, val;

int read() {
  int p, q, r; scanf("%d:%d:%d", &p, &q, &r);
  // cout << p * y * z + q * z + r << endl;
  return p * y * z + q * z + r;
}

void solve() {
  scanf("%d", &n);
  scanf("%d%d%d", &x, &y, &z);  
  scanf("%d%d", &k, &val);  

  for (int i = 0; i < n; i ++ ) {
    a[i] = {read(), read()};
  }
  
  sort(a, a + n);

  long long ans = 0;
  auto [l, r] = a[0];
  a[n] = {INF, INF};
  for (int i = 1; i <= n; i ++ ) {
    auto [nl, nr] = a[i];
    if (nl - r <= k) {
      r = max(nr, r);
    } else { //1  
      r = min(r, x * y * z - 1);
      ans += 1ll * (r + k - l + 1) * val;
      l = nl, r = nr;
    }
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
