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

constexpr int N = 1E5 + 10;

int n, a[N], s[N];

void solve() {
  cin >> n;
  rep (i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];  
  int ans = 0; 
  int m = 1000010;
  for (int i = 0; i < 20 && (1 << i) <= s[n]; i ++ ) {
    vector<fenwick<int> > f(2, fenwick<int>(m));
    int now = 0;
    f[0].modify(0, 1);
    for (int j = 1; j <= n; j ++ ) {
      int bit = s[j] >> i & 1; //当前位是 1 or 0
      int low = s[j] & ((1 << i) - 1);
      // 如果要让 s[j] ^ s[i] 第 k 位为1
      // s[i] <= s[j],令二者的低 k-1 位的值位a[j] a[i]
      // 当 a[j] >= a[i] 的时候，bit 要找 bit ^ 1
      // 当 a[j] < a[i] 的时候，bit 要找 bit
      auto sum = f[bit ^ 1].get(low) + f[bit].get(low + 1, m - 1);
      now ^= (sum & 1);
      f[bit].modify(low, 1);
    }
    if (now & 1) ans |= 1 << i;
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
