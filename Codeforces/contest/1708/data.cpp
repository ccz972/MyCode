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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cout << T << "\n";
  while (T -- ) {
    int n = rng() % 1000 + 1, q = rng() % 1000 + 1;
    cout << n << " " << q << "\n";
    for(int i = 1; i <= n; i ++ ) {
      int x = rng() % 1000 + 1;
      cout << x << " \n"[i == n];
    }
  }

  return 0;
}