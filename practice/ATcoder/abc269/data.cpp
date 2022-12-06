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
  int n = rnd() % 5 + 1, m = rnd() % 5 + 1;
  cout << n << " " << m << " " << "1\n";
  int a, b, c, d;
  a = rnd() % n + 1;
  b = rnd() % n + 1; while (b < a) b = rnd() % n + 1;
  c = rnd() % m + 1;
  d = rnd() % m + 1; while (d < c) d = rnd() % m + 1;
  cout << a << " " << b << " " << c << " " << d << "\n";


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
