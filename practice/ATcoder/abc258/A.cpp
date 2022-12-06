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

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  int x = 21, y = 0;
  x += n / 60, y += n % 60;
  printf("%02d:%02d", x, y);

  return 0;
}