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
  int n = rnd() % 50 + 1, m = rnd() % 50 + 1, h = rnd() % 50 + 1;
  int q = rnd() % 100000 + 1;
  cout << n << " " << m << " " << h << " " << q << "\n";  
  for (int i = 1; i <= q; i ++ ) {
    int op = (rnd() % 10000) & 1, x = rnd() % n + 1, y = rnd() % m + 1, z = rnd() % h + 1;
    if (i == 1) op = 0;
    ++ op;
    cout << op << " " << x << " " << y << " " << z << "\n";
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
