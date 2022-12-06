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
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  int st = 0;
  while(q -- ) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      st -= x;
      st = (st % n + n) % n;
    } else {
      int x; cin >> x;
      cout << s[(st + x - 1 + n) % n] << "\n";
    }
  }

  return 0;
}