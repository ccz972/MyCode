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

int n, x;
map<int, int> a, b;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i ++ ) cin >> x, a[x] ++;
  for (int i = 1; i <= n; i ++ ) cin >> x, b[x] ++;
  ll ans = 0;
  for (auto& [ka, va]: a) {
    for (auto& [kb, vb]: b) {
      int res = sqrt(abs(ka - kb));
      ans += 1ll * va * vb * res;
    }
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
