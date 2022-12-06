#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {

  int n = rng() % 10 + 1;
  cout << n << "\n";
  double ans = 0.5;
  for(int i = 1; i <= n; i ++ ) {
    int p = rng() % 100 + 1;
    while(i != n ? (ans - 1.0 / p <= 0) : (ans - 1.0 / p < 0)) p = rng() % 100 + 1;
    ans -= 1.0 / p;
    cout << p << " ";      
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
#endif
  return 0;
}
