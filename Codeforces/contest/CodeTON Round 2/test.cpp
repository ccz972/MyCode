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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n = 4;
  vector<int> a(n);
  for(int i = 0; i < n; i ++ ) {
    a[i] = rng() % 10;
  }   
  debug(a);
  int T = 10;
  while(T -- ) {
    int i, j;
    while(true) {
      i = rng() % n, j = rng() % n; 
      if(i == j) continue;
      if(i > j) swap(i, j);
      if(i == 0 || j == n - 1) continue;
      break;
      //i < j
    }
    int g = rng() % 10 + 1;
    a[i - 1] += g; a[i] -= g;
    a[j + 1] += g; a[j] -= g; 
    debug(a);
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
#endif
  return 0;
}
