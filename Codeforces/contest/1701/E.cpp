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
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << "START\n";
  int T = 10000;
  while(T -- ) {
    int x = rng() % 1000;
    while(x == 1) x = rng() % 1000;
    int y = rng() %  x;
    while(y == 0) y = rng() %  x;
    int l = x / (y + 1) + 1;
    int r = x / y;
    if(x / r != y) continue;
    if(x / l != y || x / r != y || x / (r + 1) == y || (l > 0 && x / (l - 1) == y)) {
      cout << x << " " << y << " " << l << " " << r  << "NO\n";
      break;
    }
  }
  cout << "YES\n";

  return 0;
}