// #include <bits/stdc++.h>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
// using ll = long long;

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

int n, m;
int z[200200];
int *f = z + 100005;

void solve() {
  cin >> n; m = 100000;
  memset(z, -0x3f, sizeof z);
  f[0] = 0;

  for (int i = 1; i <= n; i ++ ) {
    int v, w; cin >> v >> w;
    if (v >= 0) {
      for (int j = m; j - v >= -m; j -- ) if (f[j - v] >= -0x3f3f3f3f / 2) {
        chkmax(f[j], f[j - v] + w);
      }
    } else {
      for (int j = -m; j - v <= m; j ++ ) if (f[j - v] >= -0x3f3f3f3f / 2) {
        chkmax(f[j], f[j - v] + w);
      }
    }
    
  }
  int ans = 0;
  for (int j = 0; j <= m; j ++ ) if(f[j] >= 0) {
    chkmax(ans, j + f[j]);
  }
  cout << ans << "\n";



}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
