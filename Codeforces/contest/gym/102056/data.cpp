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
  // freopen("out.txt", "w", stdout);
  // int n = rng() % 10 + 1;
  int n = 5;
  cout << n << "\n";
  for(int i = 1; i <= n; i ++ ) {
    int a = rng() % 20 + 1, b = rng() % 20 + 1, c = rng() % 20 + 1;
    cout << a << " " << b << " " << c << "\n";
  }


  return 0;
}