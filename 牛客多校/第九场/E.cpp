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

mt19937 rnd(random_device{}()); 


void solve() {
  int n = 8000; cout << n << "\n";
  for(int i = 1; i < n; i ++ ) {
    cout << n - i << " ";
  }
} 

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  freopen("data.txt", "w", stdout);
  // int T; cin >> T;
  // while(T -- )
    solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
