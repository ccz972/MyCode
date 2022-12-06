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
// mt19937 rnd(random_device{}()); 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  // int T = 10;
  // cout << T << "\n";
  // while (T -- ) {
    cout << "1\n";
    int n = rnd() % 2000 + 1;
    cout << n << "\n";
    while (n) {
      int m = rnd() % n + 1;
      for (int i = 0; i < m; i ++ ) cout << "(";
      for (int i = 0; i < m; i ++ ) cout << ")";
      n -= m;
    }
    // cout << "\n";
  // }

}
int main() {

  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
