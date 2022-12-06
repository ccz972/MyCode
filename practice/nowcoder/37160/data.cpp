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
  // freopen("data.txt", "w", stdout);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 
  int n = rng() % 1000 + 1; int m = rng() % n + 1;
  cout << n << " " << m << "\n";
  map<int, int> mp;
  for(int i = 0; i < m; i ++ ) {
    int idx = rng() % n + 1;
    while(mp[idx]) {
      idx ++;
      if(idx > n) idx -= n;
    }
    mp[idx] ++;
    cout << idx << " " << ((rng() & 1) ? "L" : "R") << "\n";
  }

  return 0;
}