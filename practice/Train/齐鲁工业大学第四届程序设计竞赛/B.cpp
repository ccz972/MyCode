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

void solve() {
  int n, m;  cin >> n >> m;
  vector<vector<long long> > a(n, vector<long long>(m));
  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < m; j ++ ) {
      cin >> a[i][j];
    }
  }  
  int h, w; cin >> h >> w;
  swap(h, w);
  // if (h > n || w > m) return cout << "NO\n", void();
  vector<vector<int> > high(n, vector<int>(m, 1));
  for (int i = 1; i < n; i ++ ) {
    for (int j = 0; j < m; j ++ ) {
      if (a[i][j] == a[i - 1][j]) {
        high[i][j] = high[i - 1][j] + 1;
      }
    }
  }
  //0 1 2 
  for (int i = h - 1; i < n; i ++ ) {
    for (int j = 0; j < m; j ++ ) if (high[i][j] >= h) {
      int k = j;
      while (k + 1 < m && high[i][k + 1] >= h && a[i][k + 1] == a[i][j]) {
        ++ k;
      }
      if (k - j + 1 >= w) return cout << "YES\n", void();
      j = k;
    }
  }

  swap(h, w);

  for (int i = h - 1; i < n; i ++ ) {
    for (int j = 0; j < m; j ++ ) if (high[i][j] >= h) {
      int k = j;
      while (k + 1 < m && high[i][k + 1] >= h && a[i][k + 1] == a[i][j]) {
        ++ k;
      }
      if (k - j + 1 >= w) return cout << "YES\n", void();
      j = k;
    }
  }

  cout << "NO\n";

  


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
