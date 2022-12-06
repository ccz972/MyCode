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
  int n, m; cin >> n >> m;
  vector<array<int, 2> > a(m);
  for (int i = 0; i < m; i ++ ) cin >> a[i][0];
  for (int i = 0; i < m; i ++ ) cin >> a[i][1];

  sort(a.begin(), a.end(), [&] (array<int, 2> &x, array<int, 2> &y) {
    return x[1] < y[1];
  });

  // vector<int> d(m), p(m);
  // for (int &x: d) cin >> x;
  // for (int &x: p) cin >> x;
  int cnt = 0;
  int ans = INT_MIN;
  for (auto &[d, p] : a) {
    if (d) {
      ++ cnt;
    } else {
      chkmax(ans, p + cnt);
    }
  }
  reverse(a.begin(), a.end());
  
  cnt = 0;

  for (auto &[d, p] : a) {
    if (!d) {
      ++ cnt;
    } else {
      chkmax(ans, n + 1 - p + cnt);
    }
  }

  cout << ans << "\n";

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
