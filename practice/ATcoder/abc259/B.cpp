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
const double pi = acos(-1);
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double a, b, d; cin >> a >> b >> d;
  // d %= 360;
  double alpha = pi * d / 180;
  double x = a * cos(alpha) - b * sin(alpha);
  double y = b * cos(alpha) + a * sin(alpha);
  cout << fixed << setprecision(20) << x << " " << y;


  return 0;
}