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
  int n; cin >> n;
  map<int, int> mp;
  vector<int> a(n); for (int &x: a) cin >> x, mp[x] ++; // 第 i 个科学家喜欢的语言

  int m; cin >> m;

  vector<int> b(m); for (int &x: b) cin >> x;
  vector<int> c(m); for (int &x: c) cin >> x;
  array<int, 3> ans{0, 0, 1};
  for (int i = 0; i < m; i ++ ) {
    int x = b[i], y = c[i];
    x = mp[x], y = mp[y];
    if (x > ans[0] || (x == ans[0] && y > ans[1])) {
      ans = {x, y, i + 1};
    }        
  }

  cout << ans[2] << "\n";

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
