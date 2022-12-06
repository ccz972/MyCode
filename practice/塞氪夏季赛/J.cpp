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
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  fenwick<int> f(200010);
  
  int ans = 0;
  f.modify(1, 1);
  f.modify(2, -1);

  for(int i = 1; i <= n; i ++ ) if(f.get(i)) {
    f.modify(i + 1, 1);
    f.modify(i + a[1] + 1, -1);
    chkmax(ans, i + a[i]);
  }  
  cout << ans << "\n";

  return 0;
}