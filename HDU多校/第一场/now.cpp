#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  // bitset<10> f, g;
  // f[0] = 1;
  // f <<= 9;
  // cout << f;
  // cout << (((1 << 10) - 1) ^ ((1 << 10) - 2));
  int mx = 0;
  for(int i = 0; i < (1 << 10); i ++ ) {
    for(int j = 0; j < (1 << 10); j ++ ) {
      chkmax(mx, (i ^ j));
    }
  }
  cout << mx << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
