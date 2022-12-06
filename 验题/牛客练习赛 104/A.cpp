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

void solve() {
  int n, m, k; cin >> n >> m >> k;
  ll a, b, c, d; cin >> a >> b >> c >> d;
  ll lmax = c, rmax = d, lmin = a, rmin = b;
  
  for (int i = 0; i < k; i ++ ) {
    ll a, b; cin >> a >> b;
    chkmin(lmin, a); chkmin(rmin, b);
    chkmax(lmax, a + 1); chkmax(rmax, b + 1);
  }

  cout << (rmax - rmin + lmax - lmin) * 2;
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
