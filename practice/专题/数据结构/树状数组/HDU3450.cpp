// Counting Sequences
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
constexpr int MOD = 9901;
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
    return (get(r) - get(l - 1) + MOD) % MOD;
  }

};

constexpr int N = 1E5 + 10;

int n, d;
int a[N], b[N];

void solve() {
   
  rep (i, 1, n) cin >> a[i], b[i] = a[i];
  sort(b + 1, b + 1 + n);
  fenwick<long long> fen(n + 1);
  long long sum = 0;
  for (int i = 1; i <= n; i ++ ) {
    int idx = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    int l =   lower_bound(b + 1, b + 1 + n, a[i] - d) - b;
    int r =   upper_bound(b + 1, b + 1 + n, a[i] + d) - b - 1;
    auto now = fen.get(l, r);
    fen.modify(idx, now + 1);
    sum += now;
  }
  cout << sum % MOD << "\n";
  // cout << fen.get(n) << "\n"; 
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  while (cin >> n >> d) solve();
  return 0;
}
