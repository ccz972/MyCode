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

struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    siz[y] += siz[x];
    f[x] = y;
    return true;
  }
  int size(int x) { return siz[find(x)]; }
};

constexpr int mod = 1E9 + 7;

ll ksm(ll a, ll b, ll ret = 1) {
  if(!b) return 1;
  if(a == 0) return 0;
  while(b) {
    if(b & 1) ret = ret * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ret;
}

ll inv(ll x) {
  return ksm(x, mod - 2);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll now = 1;
  int n; cin >> n;
  DSU d(n + 10);
  vector<ll> a(n + 1);
  for(int t = 1; t <= n; t ++ ) {
    int op; cin >> op;
    if(op == 1) {
      cin >> a[t];
      now = now * a[t] % mod;
    } else if(op == 2) {
      int l, r; cin >> l >> r;
      for(int i = d.find(l); i <= r; i = d.find(i)) {
        if(a[i])
          now = now * inv(a[i]) % mod;
        if(d.find(i) == i)
          d.merge(i, i + 1);
      }  

      d.merge(t, t + 1);
    } else {
      cout << now << "\n";
    }

  }

  return 0;
}