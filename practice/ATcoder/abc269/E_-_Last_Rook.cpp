#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int query(int a, int c, int b, int d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  array<int, 2> lt = {1, 1}, rb = {n, n};
  for (int i = 0; i < 20; i ++ ) {
    if (i & 1) {
      //横切 判断上面还是下面

      if (lt[0] == rb[0]) continue;

      auto res = query(lt[0], 1, (rb[0] + lt[0]) / 2, n);
      if (res != (rb[0] + lt[0]) / 2 - lt[0] + 1) {
        rb[0] = (rb[0] + lt[0]) / 2;
      } else {
        lt[0] = (rb[0] + lt[0]) / 2 + 1;
      }

      // auto res = query(lt[0], lt[1], (rb[0] + lt[0]) / 2, rb[1]);
      // if (res != min((rb[0] + lt[0]) / 2 - lt[0] + 1, rb[1] - lt[1] + 1)) {
      //   rb[0] = (rb[0] + lt[0]) / 2;
      // } else {
      //   lt[0] = (rb[0] + lt[0]) / 2 + 1;
      // }

    } else {
      if (lt[1] == rb[1]) continue;

      auto res = query(1, lt[1], n, (rb[1] + lt[1]) / 2);

      if (res != (rb[1] + lt[1]) / 2 - lt[1] + 1) {
        rb[1] = (rb[1] + lt[1]) / 2;
      } else {
        lt[1] = (rb[1] + lt[1]) / 2 + 1;
      }

      // auto res = query(lt[0], lt[1], rb[0], (rb[1] + lt[1]) / 2);
      // if (res != min(rb[0] - lt[0] + 1, (rb[1] + lt[1]) / 2 - lt[1] + 1)) {
      //   rb[1] = (rb[1] + lt[1]) / 2;
      // } else {
      //   lt[1] = (rb[1] + lt[1]) / 2 + 1;
      // }
    }
    // debug(lt, rb);
  } 
  cout << "! " << lt[0] << " " << lt[1] << endl;
}

int main() {
  solve();
  return 0;
}
