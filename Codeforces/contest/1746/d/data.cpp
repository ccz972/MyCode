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
  cout << "1\n";
  int n = rnd() % 5 + 1, k = rnd() % 10 + 1;
  n = 6;
  cout << n << " " << 32 << "\n";
  for (int i = 2; i <= n; i ++ ) {
    int fa = rnd() % (i - 1) + 1;
    cout << fa << " \n"[i == n];
  }
  for (int i = 1; i <= n; i ++ ) {
    cout << rnd() % 10 + 20 << " \n"[i == n];
  }


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
