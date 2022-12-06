#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  int n = rnd() % 5 + 1;
  cout << n << "\n";
  for(int i = 1; i <= n; i ++ ) {
    int x = rnd() % 5 + 1;
    cout << x << " ";
  }


}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
